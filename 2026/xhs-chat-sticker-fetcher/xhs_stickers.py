#!/usr/bin/env python3
"""从小红书聊天记录中抓取最近的表情包。

用法::

    xhs-stickers https://www.xiaohongshu.com/chat/6174a6a1000000000201fbb0 -n 10

依赖 ``xhshow`` 生成 ``x-s`` 签名，``requests`` 负责请求与下载。
"""

from __future__ import annotations

import argparse
import http.cookiejar
import json
import re
import sys
from dataclasses import dataclass
from datetime import datetime
from pathlib import Path
from typing import Any, Sequence

try:
    import requests
    from xhshow import Xhshow
except ImportError as exc:  # pragma: no cover - 依赖缺失时的友好提示
    raise SystemExit(
        f"缺少依赖：{exc.name}。请先运行 pip install xhshow requests"
    ) from exc

API_HOST = "https://edith.xiaohongshu.com"
#: 单聊历史
HISTORY_PATH = "/api/im/web/messages/history"
#: 群聊历史
GROUP_HISTORY_PATH = "/api/im/web/red/group/messages/history"

#: 表情包消息的 content_type
STICKER_CONTENT_TYPE = 16

#: 单页条数与翻页上限（防御性上限：50 页 ≈ 1500 条消息）
PAGE_LIMIT = 30
MAX_PAGES = 50

#: ``--cookies-txt`` 未指定时按顺序查找的文件名
DEFAULT_COOKIE_FILES = ("www.xiaohongshu.com_cookies.txt", "cookies.txt")

USER_AGENT = (
    "Mozilla/5.0 (X11; Linux x86_64) AppleWebKit/537.36 "
    "(KHTML, like Gecko) Chrome/123.0.0.0 Safari/537.36"
)

CHAT_ID_RE = re.compile(r"/chat/([0-9a-zA-Z]+)")
#: 用户 ID 为 24 位十六进制；群聊 ID 为纯数字（实测 18 位，放宽以兼容变化）
BARE_USER_ID_RE = re.compile(r"^[0-9a-fA-F]{24}$")
BARE_GROUP_ID_RE = re.compile(r"^\d{10,}$")


class FetchError(RuntimeError):
    """抓取过程中的可预期错误。"""


@dataclass(frozen=True)
class Sticker:
    """聊天记录里的一条表情包消息。"""

    store_id: int
    sender_id: str
    created_at: int
    url: str
    is_gif: bool
    width: int | None
    height: int | None
    smile_id: str
    #: 群聊消息里带发送者昵称，单聊通常为空
    nickname: str = ""

    @property
    def posted_at(self) -> str:
        if not self.created_at:
            return "未知时间"
        return datetime.fromtimestamp(self.created_at / 1000).strftime("%Y-%m-%d %H:%M")


def format_timestamp(ms: int) -> str:
    if not ms:
        return "未知时间"
    return datetime.fromtimestamp(ms / 1000).strftime("%Y-%m-%d %H:%M")


@dataclass
class ScanResult:
    """一次向前翻页扫描的结果。"""

    stickers: list[Sticker]
    #: 实际扫描到的消息条数
    scanned: int
    #: 扫描到的最早一条消息的时间戳（毫秒），0 表示没有消息
    earliest_at: int


# --------------------------------------------------------------------------- #
# cookies
# --------------------------------------------------------------------------- #


def resolve_cookies_path(explicit: str | None) -> Path:
    """确定 cookies.txt 路径；显式指定时必须是已存在的文件。"""
    if explicit:
        path = Path(explicit).expanduser()
        if not path.is_file():
            raise FetchError(f"指定的 cookies 文件不存在：{path}")
        return path

    searched = [Path(name) for name in DEFAULT_COOKIE_FILES]
    for path in searched:
        if path.is_file():
            return path

    names = " / ".join(str(p) for p in searched)
    raise FetchError(
        f"未找到 cookies 文件（已查找 {names}）。\n"
        "请用浏览器插件 “Get cookies.txt LOCALLY” 导出 www.xiaohongshu.com 的 cookies，"
        "保存为上述任一文件名，或用 --cookies-txt 指定路径。"
    )


def load_cookies(path: Path) -> http.cookiejar.MozillaCookieJar:
    """按 Netscape 格式解析 cookies.txt。

    注意：插件导出的域名通常带前导点（``.xiaohongshu.com``），
    必须原样保留，否则 requests 不会把 cookie 发给 ``edith.xiaohongshu.com``。
    """
    jar = http.cookiejar.MozillaCookieJar(str(path))
    try:
        jar.load(ignore_discard=True, ignore_expires=True)
    except (OSError, http.cookiejar.LoadError) as exc:
        raise FetchError(f"无法解析 cookies 文件 {path}：{exc}") from exc

    values = {c.name: c.value for c in jar}
    if not values.get("web_session"):
        raise FetchError(
            f"cookies 文件 {path} 中没有有效的 web_session，"
            "请确认导出时已登录小红书。"
        )
    if not values.get("a1"):
        raise FetchError(
            f"cookies 文件 {path} 中缺少 a1（请求签名必需），"
            "请重新导出 www.xiaohongshu.com 的完整 cookies。"
        )
    return jar


# --------------------------------------------------------------------------- #
# 聊天 URL 解析
# --------------------------------------------------------------------------- #


def parse_chat_id(raw: str) -> str:
    """从聊天页 URL（或直接给的 ID）中取出会话 ID（用户 ID 或群 ID）。"""
    value = raw.strip()
    match = CHAT_ID_RE.search(value)
    if match:
        return match.group(1)
    if BARE_USER_ID_RE.match(value) or BARE_GROUP_ID_RE.match(value):
        return value
    raise FetchError(
        f"无法从 {raw!r} 解析会话 ID，"
        "应形如 https://www.xiaohongshu.com/chat/6174a6a1000000000201fbb0"
    )


def looks_like_group(chat_id: str) -> bool:
    """群聊 ID 为纯数字，单聊用户 ID 为 24 位十六进制。

    这只是快速判断；不在第一页拿到消息时还会用另一个接口重试。
    """
    return bool(BARE_GROUP_ID_RE.match(chat_id))


# --------------------------------------------------------------------------- #
# API 客户端
# --------------------------------------------------------------------------- #


class ChatClient:
    """带 x-s 签名的聊天记录客户端。"""

    def __init__(self, cookie_path: Path) -> None:
        self._cookies = load_cookies(cookie_path)
        self._cookie_dict = {c.name: c.value for c in self._cookies}
        self._signer = Xhshow()
        self._session = requests.Session()
        self._session.cookies = self._cookies
        self._session.headers.update(
            {
                "user-agent": USER_AGENT,
                "accept": "application/json, text/plain, */*",
                "referer": "https://www.xiaohongshu.com/",
                "origin": "https://www.xiaohongshu.com",
            }
        )

    def fetch_history(
        self, chat_id: str, last_id: int, *, is_group: bool = False
    ) -> list[dict[str, Any]]:
        """取 ``store_id <= last_id`` 的最近一页消息（``last_id=0`` 表示最新一页）。

        群聊走 ``/red/group/messages/history?group_id=``，单聊走
        ``/messages/history?chat_user_id=``；两者返回结构一致。
        """
        if is_group:
            path = GROUP_HISTORY_PATH
            params = {
                "group_id": chat_id,
                "last_id": str(last_id),
                "start_id": "0",
                "limit": str(PAGE_LIMIT),
            }
        else:
            path = HISTORY_PATH
            params = {
                "chat_user_id": chat_id,
                "last_id": str(last_id),
                "start_id": "0",
                "limit": str(PAGE_LIMIT),
            }
        try:
            headers = self._signer.sign_headers_get(
                uri=path, cookies=self._cookie_dict, params=params
            )
        except ValueError as exc:
            raise FetchError(f"生成请求签名失败：{exc}") from exc
        response = self._session.get(
            API_HOST + path, params=params, headers=headers, timeout=20
        )

        if response.status_code in (461, 471):
            raise FetchError(
                f"触发平台风控（HTTP {response.status_code}），"
                "请稍后再试；若持续出现，请重新导出 cookies。"
            )

        try:
            payload = response.json()
        except ValueError as exc:
            raise FetchError(
                f"聊天记录接口返回了非 JSON 内容（HTTP {response.status_code}）"
            ) from exc

        code = payload.get("code")
        if code == -101:
            raise FetchError(
                "登录态无效（code -101）。cookies 可能已过期，请重新用 "
                "“Get cookies.txt LOCALLY” 导出。"
            )
        if code != 0 or not payload.get("success", True):
            message = payload.get("msg") or payload.get("message") or "未知错误"
            raise FetchError(f"聊天记录接口返回错误（code={code}）：{message}")

        data = payload.get("data") or {}
        messages = data.get("out_message_list") or []
        return [m for m in messages if isinstance(m, dict)]

    def download(self, url: str) -> tuple[bytes, str]:
        """下载图片，返回 ``(内容, Content-Type)``。"""
        response = self._session.get(
            url,
            timeout=30,
            headers={"referer": "https://www.xiaohongshu.com/"},
        )
        response.raise_for_status()
        return response.content, response.headers.get("Content-Type", "")

    def close(self) -> None:
        self._session.close()


# --------------------------------------------------------------------------- #
# 消息解析
# --------------------------------------------------------------------------- #


def _to_int(value: Any, default: int = 0) -> int:
    try:
        return int(value)
    except (TypeError, ValueError):
        return default


def _inner_content(message: dict[str, Any]) -> dict[str, Any] | None:
    """消息的 ``content`` 是一层 JSON 字符串，解析成 dict。"""
    raw = message.get("content")
    if isinstance(raw, dict):
        return raw
    if not isinstance(raw, str):
        return None
    try:
        parsed = json.loads(raw)
    except ValueError:
        return None
    return parsed if isinstance(parsed, dict) else None


def to_sticker(message: dict[str, Any]) -> Sticker | None:
    """把一条消息转成 Sticker；不是表情包或已撤回时返回 None。"""
    if message.get("revoked"):
        return None

    outer = _inner_content(message)
    if not outer or outer.get("content_type") != STICKER_CONTENT_TYPE:
        return None

    # 表情包消息的 content 里还套了一层 JSON：{"url": ..., "isGif": ...}
    inner = outer.get("content")
    if isinstance(inner, str):
        try:
            inner = json.loads(inner)
        except ValueError:
            return None
    if not isinstance(inner, dict):
        return None

    url = inner.get("url")
    if not isinstance(url, str) or not url:
        return None

    store_id = _to_int(message.get("store_id"))
    if store_id <= 0:
        return None

    return Sticker(
        store_id=store_id,
        sender_id=str(message.get("sender_id") or ""),
        created_at=_to_int(message.get("created_at")),
        url=url,
        is_gif=inner.get("isGif") in (1, True, "1"),
        width=_to_int(inner.get("width")) or None,
        height=_to_int(inner.get("height")) or None,
        smile_id=str(inner.get("smileId") or ""),
        # 群聊的发送者昵称在外层 JSON 上（单聊没有这个字段）
        nickname=str(outer.get("nickname") or ""),
    )


def scan_stickers(client: ChatClient, chat_id: str, count: int) -> ScanResult:
    """从最新消息向前翻页，收集最多 ``count`` 张表情包（按时间倒序）。

    同时统计扫描过的消息条数和其中最早的时间，便于在“没找到”时排查。
    """
    is_group = looks_like_group(chat_id)
    stickers: list[Sticker] = []
    seen: set[int] = set()
    scanned = 0
    earliest_at = 0
    last_id = 0
    can_retry_other_kind = True

    for _ in range(MAX_PAGES):
        messages = client.fetch_history(chat_id, last_id, is_group=is_group)

        if not messages and last_id == 0 and can_retry_other_kind:
            # ID 形态判断可能不准（例如群聊 ID 不是纯数字），换另一种接口再试
            can_retry_other_kind = False
            messages = client.fetch_history(chat_id, last_id, is_group=not is_group)
            if messages:
                is_group = not is_group
        if not messages:
            break

        for message in messages:
            scanned += 1
            created_at = _to_int(message.get("created_at"))
            if created_at and (earliest_at == 0 or created_at < earliest_at):
                earliest_at = created_at

            sticker = to_sticker(message)
            if sticker is None or sticker.store_id in seen:
                continue
            seen.add(sticker.store_id)
            stickers.append(sticker)
            if len(stickers) >= count:
                return ScanResult(stickers, scanned, earliest_at)

        store_ids = [
            sid for m in messages if (sid := _to_int(m.get("store_id"))) > 0
        ]
        if not store_ids:
            break
        # 接口返回 store_id <= last_id 的记录，翻页要跳过本页最早的一条
        next_last_id = min(store_ids) - 1
        if next_last_id <= 0:
            break
        # 仅在已有游标后校验前进性；首轮 last_id=0 只是“最新一页”的哨兵
        if last_id > 0 and next_last_id >= last_id:
            break
        last_id = next_last_id

    return ScanResult(stickers, scanned, earliest_at)


# --------------------------------------------------------------------------- #
# 下载
# --------------------------------------------------------------------------- #

EXT_BY_CONTENT_TYPE = {
    "image/jpeg": ".jpg",
    "image/jpg": ".jpg",
    "image/png": ".png",
    "image/gif": ".gif",
    "image/webp": ".webp",
}


def pick_extension(sticker: Sticker, content_type: str) -> str:
    base = content_type.split(";")[0].strip().lower()
    if base in EXT_BY_CONTENT_TYPE:
        return EXT_BY_CONTENT_TYPE[base]
    if sticker.is_gif:
        return ".gif"
    return ".jpg"


def save_stickers(
    client: ChatClient, stickers: Sequence[Sticker], out_dir: Path
) -> list[Path]:
    """下载并保存表情包，返回实际写出的文件路径。"""
    out_dir.mkdir(parents=True, exist_ok=True)
    saved: list[Path] = []
    total = len(stickers)

    for index, sticker in enumerate(stickers, start=1):
        prefix = f"[{index}/{total}]"
        try:
            content, content_type = client.download(sticker.url)
        except requests.RequestException as exc:
            print(f"{prefix} 下载失败（store_id={sticker.store_id}）：{exc}", file=sys.stderr)
            continue

        ext = pick_extension(sticker, content_type)
        filename = f"{index:02d}_{sticker.store_id}{ext}"
        path = out_dir / filename
        try:
            path.write_bytes(content)
        except OSError as exc:
            print(f"{prefix} 保存失败（{path}）：{exc}", file=sys.stderr)
            continue

        size = f"{sticker.width}×{sticker.height}" if sticker.width and sticker.height else "尺寸未知"
        who = f" @{sticker.nickname}" if sticker.nickname else ""
        print(f"{prefix} {sticker.posted_at}{who}  {size}  → {path}")
        saved.append(path)

    return saved


# --------------------------------------------------------------------------- #
# CLI
# --------------------------------------------------------------------------- #


def build_parser() -> argparse.ArgumentParser:
    parser = argparse.ArgumentParser(
        prog="xhs-stickers",
        description="从小红书的单聊或群聊记录里下载最近的表情包。",
    )
    parser.add_argument(
        "chat_url",
        help="聊天页 URL（单聊或群聊），"
        "例如 https://www.xiaohongshu.com/chat/6174a6a1000000000201fbb0",
    )
    parser.add_argument(
        "-n",
        "--count",
        type=int,
        default=10,
        help="下载的表情包数量（默认 10）",
    )
    parser.add_argument(
        "--cookies-txt",
        default=None,
        metavar="PATH",
        help="Get cookies.txt LOCALLY 导出的 cookies 文件；"
        "默认依次查找 www.xiaohongshu.com_cookies.txt、cookies.txt",
    )
    parser.add_argument(
        "-o",
        "--output",
        default="stickers",
        metavar="DIR",
        help="图片保存目录（默认 ./stickers）",
    )
    return parser


def main(argv: list[str] | None = None) -> int:
    args = build_parser().parse_args(argv)

    if args.count <= 0:
        print("错误：--count 必须是正整数", file=sys.stderr)
        return 2

    try:
        chat_id = parse_chat_id(args.chat_url)
        cookie_path = resolve_cookies_path(args.cookies_txt)
        client = ChatClient(cookie_path)
    except FetchError as exc:
        print(f"错误：{exc}", file=sys.stderr)
        return 2

    try:
        print(f"正在读取聊天记录（会话 {chat_id}，cookies {cookie_path}）…", flush=True)
        result = scan_stickers(client, chat_id, args.count)
        stickers = result.stickers
        if not stickers:
            print("没有找到表情包消息。", file=sys.stderr)
            if result.scanned:
                print(
                    f"已扫描 {result.scanned} 条消息，最早到 "
                    f"{format_timestamp(result.earliest_at)}。",
                    file=sys.stderr,
                )
            else:
                print(
                    "该会话没有返回任何消息：请确认链接对应本账号可访问的会话，"
                    "且 cookies 未过期。",
                    file=sys.stderr,
                )
            return 1
        if len(stickers) < args.count:
            reached = (
                f"，已翻到 {format_timestamp(result.earliest_at)}"
                if result.earliest_at
                else ""
            )
            print(
                f"只找到 {len(stickers)} 张表情包（请求 {args.count} 张）{reached}。",
                file=sys.stderr,
            )

        out_dir = Path(args.output).expanduser()
        saved = save_stickers(client, stickers, out_dir)
    except FetchError as exc:
        print(f"错误：{exc}", file=sys.stderr)
        return 1
    except requests.RequestException as exc:
        print(f"错误：网络请求失败：{exc}", file=sys.stderr)
        return 1
    finally:
        client.close()

    print(f"\n完成：已保存 {len(saved)} 张表情包到 {out_dir.resolve()}")
    return 0 if saved else 1


if __name__ == "__main__":
    raise SystemExit(main())
