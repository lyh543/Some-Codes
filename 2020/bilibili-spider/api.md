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

## API(4)

https://github.com/Richasy/BiliBili-UWP/blob/master/BiliBili-Lib/Models/Others/Api.cs

```cs
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace BiliBili_Lib.Models.Others
{
    public class Api
    {
        /*
         * @pn: 页码，从1开始
         * @ps: 一页条目数量
         */
        public const string _apiBase = "https://api.bilibili.com";
        public const string _appBase = "https://app.bilibili.com";
        public const string _vcBase = "https://api.vc.bilibili.com";
        public const string _liveBase = "https://api.live.bilibili.com";
        public const string _passBase = "https://passport.bilibili.com";
        public const string _bangumiBase = "https://bangumi.bilibili.com";

        #region 验证
        /// <summary>
        /// 字符串加密
        /// </summary>
        public const string PASSPORT_KEY_ENCRYPT = _passBase + "/api/oauth2/getKey";
        /// <summary>
        /// 登录
        /// </summary>
        public const string PASSPORT_LOGIN = _passBase + "/api/v3/oauth2/login";
        /// <summary>
        /// 刷新令牌信息
        /// </summary>
        public const string PASSPORT_REFRESH_TOKEN = _passBase + "/api/oauth2/refreshToken";
        /// <summary>
        /// 验证令牌是否有效
        /// </summary>
        public const string PASSPORT_CHECK_TOKEN = _passBase + "/api/oauth2/info";
        /// <summary>
        /// SSO
        /// </summary>
        public const string PASSPORT_SSO = _passBase + "/api/login/sso";
        /// <summary>
        /// 获取验证码
        /// </summary>
        public const string PASSPORT_CAPTCHA = _passBase + "/captcha";
        #endregion

        #region 分区 Region
        /// <summary>
        /// 分区索引（包含子项）
        /// </summary>
        public const string REGION_INDEX = _appBase + "/x/v2/region/index";
        /// <summary>
        /// 分区初始加载
        /// </summary>
        public const string REGION_DYNAMIC_INIT = _appBase + "/x/v2/region/dynamic";
        /// <summary>
        /// 分区初始增量加载
        /// </summary>
        public const string REGION_DYNAMIC_REFRESH = _appBase + "/x/v2/region/dynamic/list";
        /// <summary>
        /// 分区子项初始加载
        /// </summary>
        public const string REGION_DYNAMIC_CHILD_INIT = _appBase + "/x/v2/region/dynamic/child";
        /// <summary>
        /// 分区子项初始增量加载
        /// </summary>
        public const string REGION_DYNAMIC_CHILD_REFRESH = _appBase + "/x/v2/region/dynamic/child/list";
        /// <summary>
        /// 分区子项按照一定规则排序后加载，分页
        /// </summary>
        public const string REGION_DYNAMIC_CHILD_SORT = _appBase + "/x/v2/region/show/child/list";
        /// <summary>
        /// 分区排行榜
        /// </summary>
        public const string REGION_PART_RANK = _apiBase + "/x/web-interface/ranking/region";
        /// <summary>
        /// 总排行榜
        /// </summary>
        public const string REGION_TOTAL_RANK = _apiBase + "/x/web-interface/ranking";
        #endregion

        #region 账户 Account
        /// <summary>
        /// 我的信息
        /// </summary>
        public const string ACCOUNT_MINE = _appBase + "/x/v2/account/mine";
        /// <summary>
        /// 查询用户信息，使用vmid
        /// </summary>
        public const string ACCOUNT_INFO = _appBase + "/x/v2/space";
        /// <summary>
        /// 查询用户动态，使用vmid
        /// </summary>
        public const string ACCOUNT_USER_DYNAMIC = _vcBase + "/x/v2/space";
        /// <summary>
        /// 关注用户
        /// </summary>
        public const string ACCOUNT_FOLLOW_USER = _vcBase + "/feed/v1/feed/follow";
        /// <summary>
        /// 取消关注用户
        /// </summary>
        public const string ACCOUNT_UNFOLLOW_USER = _vcBase + "/feed/v1/feed/unfollow";
        /// <summary>
        /// 获取收藏夹列表
        /// </summary>
        public const string ACCOUNT_FAVORITE_LIST = _apiBase + "/x/v3/fav/folder/created/list";
        /// <summary>
        /// 获取收集列表
        /// </summary>
        public const string ACCOUNT_COLLECT_LIST = _apiBase + "/x/v3/fav/folder/collected/list";
        /// <summary>
        /// 历史记录
        /// </summary>
        public const string ACCOUNT_HISTORY = _apiBase + "/x/v2/history";
        /// <summary>
        /// 清空历史记录
        /// </summary>
        public const string ACCOUNT_HISTORY_CLEAR = _apiBase + "/x/v2/history/clear";
        /// <summary>
        /// 删除历史记录
        /// </summary>
        public const string ACCOUNT_HISTORY_DEL = _apiBase + "/x/v2/history/del";
        /// <summary>
        /// 稍后观看记录
        /// </summary>
        public const string ACCOUNT_VIEWLATER = _apiBase + "/x/v2/history/toview";
        /// <summary>
        /// 添加稍后观看记录
        /// </summary>
        public const string ACCOUNT_VIEWLATER_ADD = _apiBase + "/x/v2/history/toview/add";
        /// <summary>
        /// 删除稍后观看记录
        /// </summary>
        public const string ACCOUNT_VIEWLATER_DEL = _apiBase + "/x/v2/history/toview/del";
        /// <summary>
        /// 清空稍后观看记录
        /// </summary>
        public const string ACCOUNT_VIEWLATER_CLEAR = _apiBase + "/x/v2/history/toview/clear";
        /// <summary>
        /// 我的综合播单信息
        /// </summary>
        public const string ACCOUNT_MEDIALIST = _apiBase + "/x/v3/fav/folder/space";
        /// <summary>
        /// 稍后再看记录
        /// </summary>
        public const string ACCOUNT_VIEW_LATER = _apiBase + "/x/v2/history/toview";
        /// <summary>
        /// 收藏的专栏文章
        /// </summary>
        public const string ACCOUNT_FAVORITE_DOCUMENT = _apiBase + "/x/v2/favorite/article";
        /// <summary>
        /// 我的追番
        /// </summary>
        public const string ACCOUNT_FAVOROTE_ANIME = _apiBase + "/pgc/app/follow/v2/bangumi";
        /// <summary>
        /// 我的追剧
        /// </summary>
        public const string ACCOUNT_FAVOROTE_CINEMA = _apiBase + "/pgc/app/follow/v2/cinema";
        /// <summary>
        /// 收藏夹视频索引
        /// </summary>
        public const string ACCOUNT_FAVORITE_IDS = _apiBase + "/medialist/gateway/base/resource/ids";
        /// <summary>
        /// 收藏夹视频详情
        /// </summary>
        public const string ACCOUNT_FAVORITE_INFO = _apiBase + "/medialist/gateway/base/resource/infos";
        /// <summary>
        /// 删除收藏夹内视频
        /// </summary>
        public const string ACCOUNT_FAVORITE_VIDEO_DELETE = _apiBase + "/medialist/gateway/coll/resource/batch/del";
        /// <summary>
        /// 用户空间
        /// </summary>
        public const string ACCOUNT_USER_SPACE = _appBase + "/x/v2/space";
        /// <summary>
        /// 用户投稿视频
        /// </summary>
        public const string ACCOUNT_USER_ARCHIVE = _appBase + "/x/v2/space/archive";
        /// <summary>
        /// 获取用户的表情包
        /// </summary>
        public const string ACCOUNT_EMOJI_PANEL = _apiBase + "/x/emote/user/panel";
        /// <summary>
        /// 获取账户的未读消息
        /// </summary>
        public const string ACCOUNT_UNREAD = _apiBase + "/x/msgfeed/unread";
        /// <summary>
        /// 获取我的粉丝
        /// </summary>
        public const string ACCOUNT_RELATION_FANS = _apiBase + "/x/relation/followers";
        /// <summary>
        /// 获取关注列表的标签
        /// </summary>
        public const string ACCOUNT_RELATION_FOLLOW_TAGS = _apiBase + "/x/relation/tags";
        /// <summary>
        /// 获取关注列表的详情
        /// </summary>
        public const string ACCOUNT_RELATION_FOLLOW_DETAIL = _apiBase + "/x/relation/tag";
        /// <summary>
        /// 获取回复列表
        /// </summary>
        public const string ACCOUNT_FEEDBACK_REPLY = _apiBase + "/x/msgfeed/reply";
        /// <summary>
        /// 获取At列表
        /// </summary>
        public const string ACCOUNT_FEEDBACK_AT = _apiBase + "/x/msgfeed/at";
        /// <summary>
        /// 获取点赞列表
        /// </summary>
        public const string ACCOUNT_FEEDBACK_LIKE = _apiBase + "/x/msgfeed/like";
        #endregion

        #region 频道 Channel
        /// <summary>
        /// 获取热门频道（通过offset进行刷新，一次+5）
        /// </summary>
        public const string CHANNEL_HOT = _appBase + "/x/v2/channel/recommend2";
        /// <summary>
        /// 获取频道页综合信息（包括订阅，热门频道，浏览的信息等）
        /// </summary>
        public const string CHANNEL_SQUARE = _appBase + "/x/v2/channel/square2";
        /// <summary>
        /// 获取频道的详细说明
        /// </summary>
        public const string CHANNEL_DETAIL = _appBase + "/x/v2/channel/detail";
        /// <summary>
        /// 获取频道下的视频列表
        /// </summary>
        public const string CHANNEL_VIDEO = _appBase + "/x/v2/channel/multiple";
        /// <summary>
        /// 取消频道订阅
        /// </summary>
        public const string CHANNEL_UNSUBSCRIBE = _appBase + "/x/channel/cancel";
        /// <summary>
        /// 添加频道订阅
        /// </summary>
        public const string CHANNEL_SUBSCRIBE = _appBase + "/x/channel/add";
        /// <summary>
        /// 获取频道列表分类
        /// </summary>
        public const string CHANNEL_TABS = _appBase + "/x/v2/channel/tab3";
        /// <summary>
        /// 获取某分类下频道列表
        /// </summary>
        public const string CHANNEL_LIST = _appBase + "/x/v2/channel/list";
        /// <summary>
        /// 获取我订阅的频道（包括标签）
        /// </summary>
        public const string CHANNEL_MYSUBSCRIBE = _appBase + "/x/v2/channel/mine";
        /// <summary>
        /// 搜索频道
        /// </summary>
        public const string CHANNEL_SEARCH = _appBase + "/x/v2/search/channel2";
        /// <summary>
        /// 标签基础信息
        /// </summary>
        public const string CHANNEL_TAG_TAB = _appBase + "/x/channel/feed/tab";
        /// <summary>
        /// 标签推荐视频
        /// </summary>
        public const string CHANNEL_TAG_RECOMMEND = _appBase + "/x/channel/feed/index";
        #endregion

        #region 应用 Application
        /// <summary>
        /// 热搜及其它搜索条目
        /// </summary>
        public const string APP_SEARCH_HOT = _appBase + "/x/v2/search/square";
        /// <summary>
        /// 综合搜索
        /// </summary>
        public const string APP_SEARCH_COMPLEX = _appBase + "/x/v2/search";
        /// <summary>
        /// 特殊类目搜索
        /// </summary>
        public const string APP_SEARCH_TYPE = _appBase + "/x/v2/search/type";
        /// <summary>
        /// 用户搜索
        /// </summary>
        public const string APP_SEARCH_USER = _appBase + "/x/v2/search/user";
        /// <summary>
        /// 获取搜索建议
        /// </summary>
        public const string APP_SEARCH_SUGGEST = "http://s.search.bilibili.com/main/suggest";
        /// <summary>
        /// 获取全部emoji表情
        /// </summary>
        public const string APP_EMOJI = _apiBase + "/x/v2/reply/v2/emojis";
        /// <summary>
        /// 获取关注用户未读消息数
        /// </summary>
        public const string APP_FOLLOWER_UNREAD = _apiBase + "/x/relation/followers/unread/count";
        #endregion

        #region 视频 Video
        /// <summary>
        /// 推荐视频
        /// </summary>
        public const string VIDEO_RECOMMEND = _appBase + "/x/v2/feed/index";
        /// <summary>
        /// 不喜欢推荐视频
        /// </summary>
        public const string VIDEO_RECOMMEND_DISLIKE = _appBase + "/x/feed/dislike";
        /// <summary>
        /// 视频分P列表
        /// </summary>
        public const string VIDEO_PART = _apiBase + "/x/player/pagelist";
        /// <summary>
        /// 视频详细信息
        /// </summary>
        public const string VIDEO_DETAIL_INFO = _appBase + "/x/v2/view";
        /// <summary>
        /// 视频收藏夹
        /// </summary>
        public const string VIDEO_FAVORITE_LIST = _apiBase + "/medialist/gateway/base/created";
        /// <summary>
        /// 视频简易信息
        /// </summary>
        public const string VIDEO_SLIM_INFO = _apiBase + "/x/web-interface/archive/stat";
        /// <summary>
        /// 关联视频
        /// </summary>
        public const string VIDEO_RELATED = _apiBase + "/x/web-interface/archive/related";
        /// <summary>
        /// 获取播放地址
        /// </summary>
        public const string VIDEO_PLAY = _apiBase + "/x/player/playurl";
        /// <summary>
        /// 是否已点赞（视频）
        /// </summary>
        public const string VIDEO_IS_LIKE = _apiBase + "/x/web-interface/archive/has/like";
        /// <summary>
        /// 是否已投币（视频）
        /// </summary>
        public const string VIDEO_IS_COIN = _apiBase + "/x/web-interface/archive/coins";
        /// <summary>
        /// 是否已收藏（视频）
        /// </summary>
        public const string VIDEO_IS_FAVORITE = _apiBase + "/x/v2/fav/video/favoured";
        /// <summary>
        /// 点赞视频
        /// </summary>
        public const string VIDEO_LIKE = _appBase + "/x/v2/view/like";
        /// <summary>
        /// 投币
        /// </summary>
        public const string VIDEO_COIN = _appBase + "/x/v2/view/coin/add";
        /// <summary>
        /// 添加收藏夹
        /// </summary>
        public const string VIDEO_FAVORITE = _apiBase + "/medialist/gateway/coll/resource/deal";
        /// <summary>
        /// 一键三连
        /// </summary>
        public const string VIDEO_TRIPLE = _appBase + "/x/v2/view/like/triple";
        /// <summary>
        /// 添加观看记录
        /// </summary>
        public const string VIDEO_ADD_WATCH = _apiBase + "/x/v2/history/report";
        /// <summary>
        /// 获取互动视频选项
        /// </summary>
        public const string VIDEO_INTERACTION_EDGE = _apiBase + "/x/stein/edgeinfo_v2";
        /// <summary>
        /// 发送弹幕
        /// </summary>
        public const string VIDEO_SEND_DANMAKU = _apiBase + "/x/v2/dm/post";
        /// <summary>
        /// 获取视频字幕
        /// </summary>
        public const string VIDEO_SUBTITLE = _apiBase + "/x/player.so";
        /// <summary>
        /// 视频分享转发
        /// </summary>
        public const string VIDEO_REPOST = _vcBase + "/dynamic_repost/v1/dynamic_repost/share";
        #endregion

        #region 话题及动态 Topic Dynamic
        /// <summary>
        /// 获取动态
        /// </summary>
        public const string TOPIC_COMPLEX = _vcBase + "/topic_svr/v1/topic_svr/fetch_dynamics";
        /// <summary>
        /// 点赞动态
        /// </summary>
        public const string DYNAMIC_LIKE = _vcBase + "/dynamic_like/v1/dynamic_like/thumb";
        /// <summary>
        /// 获取新动态
        /// </summary>
        public const string DYNAMIC_NEW = _vcBase + "/dynamic_svr/v1/dynamic_svr/dynamic_new";
        /// <summary>
        /// 获取历史动态
        /// </summary>
        public const string DYNAMIC_HISTORY = _vcBase + "/dynamic_svr/v1/dynamic_svr/dynamic_history";
        /// <summary>
        /// 用户空间动态
        /// </summary>
        public const string DYNAMIC_USER_HISTORY = _vcBase + "/dynamic_svr/v1/dynamic_svr/space_history";
        /// <summary>
        /// 转发动态
        /// </summary>
        public const string DYNAMIC_REPOST = _vcBase + "/dynamic_repost/v1/dynamic_repost/repost";
        #endregion

        #region 动漫 Anime
        /// <summary>
        /// 番剧综合信息
        /// </summary>
        public const string ANIME_JP_SQUARE = _apiBase + "/pgc/app/v2/page/bangumi/jp";
        /// <summary>
        /// 刷新动漫区块信息
        /// </summary>
        public const string ANIME_EXCHANGE = _apiBase + "/pgc/app/v2/page/exchange";
        /// <summary>
        /// 国创综合信息
        /// </summary>
        public const string ANIME_CHN_SQUARE = _apiBase + "/pgc/app/v2/page/bangumi/chn";
        /// <summary>
        /// 获取播放地址
        /// </summary>
        //public const string ANIME_PLAY = _apiBase + "/pgc/player/api/playurl";
        public const string ANIME_PLAY = _bangumiBase + "/player/web_api/v2/playurl";
        /// <summary>
        /// 获取动漫详情
        /// </summary>
        public const string ANIME_DETAIL = _apiBase + "/pgc/view/app/season";
        /// <summary>
        /// 检查用户是否投币
        /// </summary>
        public const string ANIME_CHECK_COIN = _apiBase + "/pgc/season/episode/coin/user/number";
        /// <summary>
        /// 追番/追剧
        /// </summary>
        public const string ANIME_FOLLOW = _apiBase + "/pgc/app/follow/add";
        /// <summary>
        /// 取消追番/追剧
        /// </summary>
        public const string ANIME_UNFOLLOW = _apiBase + "/pgc/app/follow/del";
        /// <summary>
        /// 番剧索引限制条件
        /// </summary>
        public const string ANIME_INDEX_CONDITION = _apiBase + "/pgc/season/index/condition";
        /// <summary>
        /// 番剧索引搜索结果
        /// </summary>
        public const string ANIME_INDEX_RESULT = _apiBase + "/pgc/season/index/result";
        /// <summary>
        /// 动漫时间表
        /// </summary>
        public const string ANIME_TIMELINE = _apiBase + "/pgc/app/timeline";
        #endregion

        #region 回复 Reply
        /// <summary>
        /// 获取回复列表
        /// </summary>
        public const string REPLY_LIST = _apiBase + "/x/v2/reply/main";
        /// <summary>
        /// 获取某回复详情
        /// </summary>
        public const string REPLY_DETAIL = _apiBase + "/x/v2/reply/detail";
        /// <summary>
        /// 点赞评论
        /// </summary>
        public const string REPLY_LIKE = _apiBase + "/x/v2/reply/action";
        /// <summary>
        /// 添加评论
        /// </summary>
        public const string REPLY_ADD = _apiBase + "/x/v2/reply/add";
        /// <summary>
        /// 删除评论
        /// </summary>
        public const string REPLY_DELETE = _apiBase + "/x/v2/reply/del";
        #endregion

        #region 直播 Live
        /// <summary>
        /// 获取直播首页信息
        /// </summary>
        public const string LIVE_SQUARE = _liveBase + "/xlive/app-interface/v2/index/getAllList";
        #endregion

        #region 其它
        public const string OTHER_ZONE = _apiBase + "/x/web-interface/zone";
        #endregion
    }
}
```

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