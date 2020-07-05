# bilibili API

真就一地的 API 啊。

不过 `*.bilibili.cn` 的 API 均已失效，而 `api.bilibili.com` 的 API 也不能调用太频繁，国外单线程访问刚刚好，国内绝对不要开多线程，否则分分钟 ERROR 412。

## API(1)

https://www.bilibili.com/read/cv5363590/
```cs
//主站
const URL_INDEX="https://www.bilibili.com";
const URL_INDEX_MOBILE="https://m.bilibili.com/index.html"
//主站分区排行
const URL_MAIN_RANKING = "https://m.bilibili.com/ranking.html";
//排行榜 rid分区，day最近几天(3,7)
const URL_RANKING_PARTITION ="https://api.bilibili.com/x/web-interface/ranking/region?rid={rid}&day={day}";
//首页轮播
const URL_ROUND_SOWING = "https://api.bilibili.com/x/web-show/res/loc?pf=7&;id=1695";
//热搜
const URL_HOT_WORD = "https://s.search.bilibili.com/main/hotword";
//搜索
const URL_SEARCH="https://api.bilibili.com/x/web-interface/search/all/v2";
const URL_SEARCH="https://api.bilibili.com/x/web-interface/search/all/v2?keyword={keywd}&page={pg}&pagesize={pgsize}&search_type={stype}&order={order}";
const URL_SEARCH_1="https://api.bilibili.com/x/web-interface/search/type?keyword={keywd}&page={pg}&pagesize={pgsize}&search_type={stype}&order={order}";
/**视频详情 aid是视频id(手机版接口统一)
* 用URL_VIDEO_DETAIL查询出aid和cid
*把aid和cid放进URL_VIDEO_PLAYURL里面查询播放地址
* 把aid和cid放进URL_VIDEO_TYPE里面查询是什么视频（普通视频还是互动视频）(返回XML)
* 互动视频有个graph_version参数是视频id（json）
*互动视频的参数：aid：av号，edge_id：节点编号，1为开头（json）
* 旧版下面接新版API，B站于2020年3月23更新
*/
const URL_VIDEO_DETAIL="https://m.bilibili.com/video/av{aid}?p={p}";
const URL_VIDEO_DETAIL_NEW="https://m.bilibili.com/video/BV1k7411R7kj";//（BV1k7411R7kj是一个整体）
const URL_VIDEO_PLAYURL="https://api.bilibili.com/x/player/playurl?cid={cid}&qn=1&type=&otype=json&avid={aid}";
const URL_VIDEO_PLAYURL_NEW="https://api.bilibili.com/x/player/playurl?cid={cid}&qn=1&type=&otype=json&avid={aid}";
const URL_VIDEO_PAGELIST="https://api.bilibili.com/x/player/pagelist?bvid={bvid}&jsonp=jsonp";
const URL_VIDEO_TYPE="https://api.bilibili.com/x/player.so?id=cid%3A{cid}&aid={av}";
const URL_VIDEO_TYPE_NEW="https://api.bilibili.com/x/player.so?id=cid%3A{cid}&bvid={bvid}";
const URL_INTERACT_VIDEO="https://api.bilibili.com/x/stein/edgeinfo_v2?aid={aid}&bvid=&edge_id={eid}&graph_version={gvid}";
const URL_INTERACT_VIDEO_NEW="https://api.bilibili.com/x/stein/edgeinfo_v2?aid={aid}&bvid=&edge_id={eid}&graph_version={gvid}";
//番剧（时间线）点进去就放
const URL_VIDEO_BANGUMI="https://bangumi.bilibili.com/api/timeline_v2_global";
//视频弹幕
const URL_DANMAKU="https://api.bilibili.com/x/v1/dm/list.so?oid={oid}";
// 用户基本信息
const URL_UP_USER_STATUS = "https://api.bilibili.com/x/space/acc/info?mid={uid}&jsonp=jsonp";
//用户顶置视频
const URL_TOP_VIDEO="https://api.bilibili.com/x/space/top/arc?vmid={uid}&jsonp=jsonp";
const URL_TOP_VIDEO_GUEST="https://api.bilibili.com/x/space/masterpiece?vmid={uid}&jsonp=jsonp";
//用户上传的视频
const URL_USER_UP_VIDER="https://api.bilibili.com/x/space/arc/search?mid={uid}&pn=1&ps={ps}&jsonp=jsonp";
//我的关注
const URL_USER_FOLLOW="https://api.vc.bilibili.com/dynamic_svr/v1/dynamic_svr/dynamic_new?uid={uid}&type=2&from=header";
//正在播放的番剧__PGC_USERSTATE__判断大会员<script>1，__playinfo__当前p资料2，__BILI_CONFIG__不知3，__INITIAL_STATE__番剧状态4
export const URL_PLAYING_BANGUMI="https://www.bilibili.com/bangumi/play/ep{ep}";
//番剧详情页
const URL_BANGUMI_DETAIL="https://www.bilibili.com/bangumi/media/md{md}";
const URL_BANGUMI_SECTION="https://api.bilibili.com/pgc/web/season/section?season_id={sid}";//当季的每一P
//直播首页
const URL_LIFE_INDEX="https://api.live.bilibili.com/room/v2/AppIndex/getAllList";
// 分类
const URL_LIVE_AREA = "https://api.live.bilibili.com/room/v1/AppIndex/getAreas?device=phone&;platform=ios&scale=3&build=1000";
// 直播地址
const URL_LIVE_URL = "https://api.live.bilibili.com/room/v1/Room/playUrl?cid={roomid}&platform=h5&otype=json&quality=0";
// 礼物
const URL_LIVE_GIFT = "https://api.live.bilibili.com/appIndex/getAllItem?scale=1";
// 房间列表
const URL_ROOM_LIST = "https://api.live.bilibili.com/room/v2/Area/getRoomList";
// 房间信息
const URL_ROOM_INFO = "https://api.live.bilibili.com/room/v1/Room/get_info?device=phone&;platform=ios&scale=3&build=10000&room_id={roomid}";
// 弹幕配置
const URL_DANMMU_CONFIG = "https://api.live.bilibili.com/room/v1/Danmu/getConf?room_id={roomid}&platform=h5";
//评论区
const URL_VIDEO_COMMENT="https://api.bilibili.com/x/v2/reply?jsonp=jsonp&;pn=1&type=1&oid={aid}&sort=0";
```

## API(2)
https://www.bilibili.com/read/cv3430609

```
UP主、视频API (所有标明此颜色的需替换)
http://api.bilibili.com/archive_stat/stat?aid=AV号&type=jsonp
视频基本信息(AV号、观看、弹幕、评论、收藏、硬币、分享、喜欢、版权[1自制2转载])
https://api.bilibili.com/x/space/upstat?mid=UUID&jsonp=jsonp
UP主信息(视频总播放数、文章总浏览数)
https://api.bilibili.com/x/relation/stat?vmid=UUID&jsonp=jsonp
UP主信息2(UUID、关注数、黑名单、粉丝数)
http://api.bilibili.com/x/elec/show?aid=AV号
视频充电
http://api.bilibili.com/x/tag/archive/tags?aid=AV号&jsonp=jsonp
视频标签Tag
http://api.live.bilibili.com/bili/living_v2/UUID?callback=liveXhrDone
UP主直播间地址
http://api.bilibili.com/x/v2/reply?jsonp=jsonp&;pn=1&type=1&oid=AV号
视频评论
http://space.bilibili.com/ajax/member/getSubmitVideos?mid=UUID&;pagesize=单页显示数&page=页数
UP主视频列表(分页)
https://api.bilibili.com/x/web-interface/archive/desc?&;aid=AV号
视频简介(\n为换行符)
主站API
https://api.bilibili.com/x/web-interface/online?&;jsonp=jsonp
在线人数(网页在线、未知[play_online])
https://api.bilibili.com/x/web-show/res/locs?pf=0&;ids=142%2C2837%2C2836%2C2870%2C2953%2C2954%2C2955%2C2956&jsonp=jsonp
BW
https://api.bilibili.com/x/web-interface/dynamic/region?&;jsonp=jsonp&ps=10&rid=1
主页视频信息
```

## API(3)

https://github.com/Vespa314/bilibili-api

## B 站 av bv 号互换

```py
table='fZodR9XQDSUm21yCkr6zBqiveYah8bt4xsWpHnJE7jL5VG3guMTKNPAwcF'
tr={}
for i in range(58):
	tr[table[i]]=i
s=[11,10,3,8,4,6]
xor=177451812
add=8728348608

def dec(x):
	r=0
	for i in range(6):
		r+=tr[x[s[i]]]*58**i
	return (r-add)^xor

def enc(x):
	x=(x^xor)+add
	r=list('BV1  4 1 7  ')
	for i in range(6):
		r[s[i]]=table[x//58**i%58]
	return ''.join(r)

print(dec('BV17x411w7KC'))
print(dec('BV1Q541167Qg'))
print(dec('BV1mK4y1C7Bz'))
print(enc(170001))
print(enc(455017605))
print(enc(882584971))
```