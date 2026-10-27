# xhs-sticker-fetcher

从小红书网页版的单聊或群聊里，抓取最近 N 张表情包并下载到本地。

```
$ xhs-stickers "https://www.xiaohongshu.com/chat/6174a6a10000000000000000" -n 10
正在读取聊天记录（会话 6174a6a10000000000000000，cookies www.xiaohongshu.com_cookies.txt）…
[1/10] 2026-10-27 11:40  432×432  → stickers/01_26043.png
[2/10] 2026-10-27 11:27  432×420  → stickers/02_26038.jpg
...
完成：已保存 10 张表情包到 /path/to/stickers
```

没找到表情包时会给出扫描范围，便于判断是会话里确实没有，还是翻页不足：

```
$ xhs-stickers "https://www.xiaohongshu.com/chat/137971102058545497"
正在读取聊天记录（会话 137971102058545497，cookies www.xiaohongshu.com_cookies.txt）…
没有找到表情包消息。
已扫描 30 条消息，最早到 2026-06-12 20:33。
```


## 准备 cookies

1. 用 Chrome 登录 <https://www.xiaohongshu.com>（手机号 / 扫码均可）。
2. 安装浏览器插件 **[Get cookies.txt LOCALLY](https://chromewebstore.google.com/detail/get-cookiestxt-locally/cclelndahbckbenkjhflpdbgdldlbecc?pli=1)**，导出 `www.xiaohongshu.com` 的 cookies。
3. 把导出的文件保存为 `www.xiaohongshu.com_cookies.txt` 或 `cookies.txt`，
   放在运行命令的目录下（或用 `--cookies-txt` 指定任意路径）。

cookies 文件必须包含 `web_session`、`a1`、`webId` 等字段。登录态过期后重新导出即可。

## 运行

需要 Python 3.10+。

```bash
python3 -m venv .venv
.venv/bin/pip install -e .
```

安装后可直接使用 `.venv/bin/xhs-stickers`，或激活虚拟环境后使用 `xhs-stickers`。

也可以不安装，直接运行 `python3 xhs_stickers.py ...`（需先 `pip install xhshow requests`）。

也可以不安装，直接用 uv 运行：

```bash
uv run xhs_stickers.py "https://www.xiaohongshu.com/chat/<会话ID>" -n 10
# 或（uv 会把 pyproject.toml 里的脚本入口装进项目环境）
uv run xhs-stickers "https://www.xiaohongshu.com/chat/<会话ID>" -n 10
```


## 用法

```bash
xhs-stickers <聊天页URL> [选项]
```

单聊和群聊都支持，按 URL 里的会话 ID 自动识别（24 位十六进制 = 单聊用户，纯数字 = 群聊），
识别后第一页拿不到消息时还会自动换另一种接口重试。

| 参数 | 默认值 | 说明 |
| --- | --- | --- |
| `chat_url` | 必填 | 聊天页 URL，形如 `https://www.xiaohongshu.com/chat/<会话ID>`；也可直接传会话 ID |
| `-n, --count` | `10` | 要下载的表情包数量 |
| `--cookies-txt` | 自动查找 | cookies 文件路径；未指定时依次查找 `www.xiaohongshu.com_cookies.txt`、`cookies.txt`，都找不到会报错 |
| `-o, --output` | `stickers` | 图片保存目录 |

示例：

```bash
# 下载最近 10 张到 ./stickers
xhs-stickers "https://www.xiaohongshu.com/chat/6174a6a10000000000000000"

# 下载最近 20 张到 ./out
xhs-stickers "https://www.xiaohongshu.com/chat/6174a6a10000000000000000" -n 20 -o out

# 指定 cookies 文件
xhs-stickers "https://www.xiaohongshu.com/chat/6174a6a10000000000000000" --cookies-txt ~/xhs.txt
```

### 输出

- 文件名为 `序号_storeId.扩展名`（如 `01_26043.png`），序号 1 为最新一张。
- 群聊会显示发送者昵称（如 `@Joyyy`）；单聊接口不返回昵称，不显示。
- 扩展名按下载响应的 Content-Type 判定（`.jpg` / `.png` / `.webp` / `.gif`）。
- 下载的是原图，分辨率通常大于聊天界面里的缩略图。
- 同一条表情包消息发多次会各保存一份（按消息计数）。

## 工作原理

1. 从 URL 中取出会话 ID。
2. 拉取聊天历史：
   - 单聊：`GET /api/im/web/messages/history`，参数 `chat_user_id`
   - 群聊：`GET /api/im/web/red/group/messages/history`，参数 `group_id`
   - 两者其余参数相同：`last_id`、`start_id=0`、`limit=30`；返回结构也相同
     （`data.out_message_list`）。`last_id` 是游标：传 0 取最新一页，
     取 `store_id ≤ last_id` 的记录，翻页时用本页最小的 `store_id - 1`。
3. 消息的 `content` 是 JSON 字符串，`content_type == 16` 即为表情包，
   内层 JSON 的 `url` 指向 `msg-img.xhscdn.com` 上的图片。
4. 每个请求都用 [xhshow](https://github.com/Cloxl/xhshow)（MIT）生成
   `x-s` / `x-s-common` / `x-t` 签名头，无需浏览器。

## 常见问题

| 现象 | 原因与处理 |
| --- | --- |
| `code -101 无登录信息` | cookies 过期或未登录导出，重新导出 cookies |
| `未找到 cookies 文件` | 按提示放置 `www.xiaohongshu.com_cookies.txt` / `cookies.txt`，或用 `--cookies-txt` |
| `只找到 N 张表情包（请求 M 张），已翻到 <时间>` | 会话里的表情包不足 M 张，已翻到底；时间是最早扫描到的一条消息 |
| `没有找到表情包消息` | 该会话没有表情包，或对方发送的是文字表情（如 `[喝咖啡H]`，不是图片）。若同时显示“已扫描 N 条消息，最早到 <时间>”，说明确实翻到了那个时间点仍没有；若提示“没有返回任何消息”，多半是链接或 cookies 无效 |

## 说明

- 仅供个人备份自己有权访问的聊天内容使用。请遵守小红书用户协议，控制请求频率。
- cookies 文件包含登录凭证，已在 `.gitignore` 中排除，请勿提交或分享。
