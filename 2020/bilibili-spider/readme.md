# B 站爬虫

## bilibili_online 每日登陆人数

完整数据见 [bilibili_online/bilibili_online.txt](bilibili_online/bilibili_online.txt)。样例数据如下：

```
07.03,00:30,105,0,8,47,8,88,38,1157,0,9,255,1,282,35,1,0,370,193,1262,254,77,64,
07.03,00:31,108,0,7,48,8,89,40,1184,0,9,261,1,285,36,1,0,375,202,1296,257,79,66,
```

07.03 表示七月三日，00:31 表示时间（可能有重复），后面的数字分别表示[分区id](#分区id)为 `1,11,119,129,13,138,155,160,165,167,17,177,181,188,202,23,3,36,4,5,75,76` 的区的每日登陆人数。

每一项人数是单调递增的，由此猜测可能记录的是从 0 点开始的登陆人数。

区编号见后。

不保证每一分钟无重复、无遗漏。

## bilibili_watching 在线观看人数

日期、时间和此刻 https://www.bilibili.com/online.html 的 20 个视频的在线观看人数总和。

不保证每一分钟无重复、无遗漏。完整数据见 [bilibili_watching/bilibili_watching.txt](bilibili_watching/bilibili_watching.txt)。样例数据：

```
07.03,17:07,74508
07.03,17:07,75494
07.03,17:08,73516
```

## zone 分区 id 和 名字对应关系

B 站的分区向来很迷，也不公开。这里有两份不完全的分区表：

> https://github.com/Vespa314/bilibili-api/blob/master/api.md  
> https://wusiyu.me/bilibili-video-count/

以逗号分割形式的完整数据见 [zone/zone.txt](zone/zone.txt)。以下为样例数据：

```
#tid	name	link	parent
1	动画	http://www.bilibili.com/video/douga.html	null
3	音乐	http://www.bilibili.com/video/music.html	null
4	游戏	http://www.bilibili.com/video/game.html	null
5	娱乐	http://www.bilibili.com/video/ent.html	null
9	意见留言簿	http://www.bilibili.complus/guestbook.php	null
11	电视剧	http://www.bilibili.com/video/teleplay.html	null
12	公告	http://www.bilibili.com/list.php?tid=	null
13	番剧	http://www.bilibili.com/video/bangumi.html	null
15	连载剧集	http://www.bilibili.com/video/soap-three-1.html	11
```

## bilibili_zone_videos 分区视频数

见 https://wusiyu.me/bilibili-video-count/。

## bilibili_100up 百大 UP 主

找了一部分百大 up 主的名单。昵称、mid 均在 [bilibili_upstat/bilibili_100up](bilibili_upstat/bilibili_100up/) 下。

这里的实现方法是，在网上找到一份百大 up 名单的[图]，ocr 了一部分得到 [100up_namelist.txt]，再通过 [get_mid.py] 使用哔哩哔哩的搜索功能的爬虫，得到 `(搜索结果昵称, 搜索 keyword 昵称, 搜索结果 mid)` 的串，保存在 [100up_info.txt]。

[图]:bilibili_upstat/bilibili_100up/bilibili_100.webp
[100up_namelist.txt]:bilibili_upstat/bilibili_100up/100up_namelist.txt
[get_mid.py]:bilibili_upstat/bilibili_100up/get_mid.py
[100up_info.txt]:bilibili_upstat/bilibili_100up/100up_info.txt

## bilibili_upstat up 主信息

由于 B 站限制，API 调用不能太频繁，加上项目时间有限，只爬取了部分用户的数据（约 26 万）。

每一项为用户 mid（不保证无重复、无遗漏）、用户名（经 base64 编码）、粉丝数、上传视频数、发布文章数。

完整数据见 [bilibili_upstat/data](bilibili_upstat/data) 下的所有 txt。样例数据：

```
200096,aGFkZXN6aGFuZw==,0,0,0
200097,5bCP6bif5ri45YWJ,0,0,0
200098,5Z+D54m55r2Y,0,0,0
200099,6aSF6aOf44G54piG44GL44KI44Gh5o6o44GX,3,3,0
```

代码见 [bilibili_upstat/bilibili_upstat.py]。此外，还有防 API 调用太频繁，[使用代理的版本]（但是貌似都是透明代理，没用）、以[百大 up 主]为爬虫名单的[版本]。

~~其实三份代码应该相同的代码合并为一个模块，就可以实现代码复用。不过小工程就算了~~

[bilibili_upstat/bilibili_upstat.py]:bilibili_upstat/bilibili_upstat.py
[使用代理的版本]:bilibili_upstat/bilibili_upstat_proxy.py
[百大 up 主]:#bilibili_100up-百大-up-主
[版本]:bilibili_upstat/bilibili_upstat_100up.py

## bilibili_danmaku

哔哩哔哩的弹幕可在 bilibilijj.com 下载，格式为 XML。原始数据见 [bilibili_danmuku/origin](bilibili_danmaku/origin)。

弹幕的格式可参考[链接](https://zhangshuqiao.org/2018-03/Bilibili弹幕文件的解析/)。

```
<d p="4.67700,5,18,65280,1436288497,0,38c54267,1003967892">04.脑内电脑网路为基础的体感线上游戏。在脑内电脑网路的效果下</d>
```

从左到右依次为：

* 弹幕出现的时间，以秒为单位
* 弹幕的模式：1～3 滚动弹幕 4 底端弹幕 5 顶端弹幕 6 逆向弹幕 7 精准定位 8 高级弹幕
* 字号：12 非常小 16 特小 18 小 25 中 36 大 45 很大 64 特别大
* 字体的颜色：将 HTML 六位十六进制颜色转为十进制表示，例如 #FFFFFF 会被存储为 16777215
* Unix 时间戳，以毫秒为单位，基准时间为 1970-1-1 08:00:00
* 弹幕池：0 普通池 1 字幕池 2 特殊池（注：目前特殊池为高级弹幕专用）
* 发送者的 ID，用于「屏蔽此弹幕的发送者」功能
* 弹幕在弹幕数据库中 rowID，用于「历史弹幕」功能

这里写一个 [bilibili_danmaku/bilibili_danmaku_parser.py](bilibili_danmaku/bilibili_danmaku_parser.py) 作为解析弹幕 xml 的示例。

## base64 编码、解码

```py
>>> import base64
>>> s = '我是字符串'
>>> a = base64.b64encode(s.encode())
>>> print a
ztLKx9fWt/u0rg==
>>> print(base64.b64decode(a).decode())
我是字符串
```

## 参考链接

https://www.bilibili.com/online.html
https://github.com/Vespa314/bilibili-api/blob/master/api.md
https://zhangshuqiao.org/2018-03/Bilibili弹幕文件的解析/
https://wusiyu.me/bilibili-video-count/
https://github.com/uupers/BiliSpider/wiki