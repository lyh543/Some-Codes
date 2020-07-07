#!/usr/bin/env python3
'''
Bilibili 各分区视频数量查询脚本
作者: WuSiYu(wu.siyu@hotmail.com)
日期: 2018-07-26 00:54

本脚本参考了uupers团队的研究: https://github.com/uupers/BiliSpider/wiki
'''
from urllib import request
import json

ALL_RID = (12, 15, 16, 17, 19, 20, 21, 22, 24, 25, 26, 27, 28, 29, 30, 31, 32, 33, 37, 39, 41, 46, 47, 50, 51, 53, 54, 56, 59, 60, 65, 67, 71, 74, 75, 76, 77, 79, 80, 82, 83, 85, 86, 94, 95, 96, 98, 114, 116, 118, 120, 121, 122, 124, 125, 126, 127, 128, 130, 131, 134, 135, 136, 137, 138, 139, 141, 145, 146, 147, 152, 153, 154, 156, 157, 158, 159, 161, 162, 163, 164, 166, 168, 169, 170, 171, 172, 173, 174, 175, 176, 178, 179, 180, 182, 183, 184, 185, 187)
videoCounts = {}

regionCount = len(ALL_RID)
i = 1

for rid in ALL_RID :
	print('Getting data form bilibili... (' + str(i) + '/' + str(regionCount) + ')', end="\r")
	apiURL = 'http://api.bilibili.com/x/web-interface/newlist?ps=1&pn=1&rid=' + str(rid)
	req = request.Request(apiURL)
	req.add_header('User-Agent', 'Mozilla/5.0 (X11; Linux x86_64; rv:62.0) Gecko/20100101 Firefox/62.0')
	f = request.urlopen(req)
	data = json.loads( f.read() )
	videoCounts[rid] = data['data']['page']['count']
	i += 1

print('Getting data form bilibili... done    ')
print('''
	1: 动画
		24:MAD·AMV  \t\t视频数 = ''' + str( videoCounts[24] ) + '''
		25: MMD·3D  \t\t视频数 = ''' + str( videoCounts[25] ) + '''
		47: 短片·手书·配音  \t视频数 = ''' + str( videoCounts[47] ) + '''
		27: 综合  \t\t视频数 = ''' + str( videoCounts[27] ) + '''

	13: 番剧
		33: 连载动画  \t\t视频数 = ''' + str( videoCounts[33] ) + '''
		32: 完结动画  \t\t视频数 = ''' + str( videoCounts[32] ) + '''
		51: 资讯  \t\t视频数 = ''' + str( videoCounts[51] ) + '''
		152: 官方延伸  \t\t视频数 = ''' + str( videoCounts[152] ) + '''

	167：国创
		153: 国产动画  \t\t视频数 = ''' + str( videoCounts[153] ) + '''
		168: 国产原创相关  \t视频数 = ''' + str( videoCounts[168] ) + '''
		169: 布袋戏  \t\t视频数 = ''' + str( videoCounts[169] ) + '''
		170: 资讯  \t\t视频数 = ''' + str( videoCounts[170] ) + '''

	3: 音乐
		28: 原创音乐  \t\t视频数 = ''' + str( videoCounts[28] ) + '''
		31: 翻唱  \t\t视频数 = ''' + str( videoCounts[31] ) + '''
		30: VOCALOID·UTAU  \t视频数 = ''' + str( videoCounts[30] ) + '''
		59: 演奏  \t\t视频数 = ''' + str( videoCounts[59] ) + '''
		29: 三次元音乐  \t视频数 = ''' + str( videoCounts[29] ) + '''
		54: OP/ED/OST  \t\t视频数 = ''' + str( videoCounts[54] ) + '''
		130: 音乐选集  \t\t视频数 = ''' + str( videoCounts[130] ) + '''

	129：舞蹈
		20: 宅舞  \t\t视频数 = ''' + str( videoCounts[20] ) + '''
		154: 三次元舞蹈  \t视频数 = ''' + str( videoCounts[154] ) + '''
		156: 舞蹈教程  \t\t视频数 = ''' + str( videoCounts[156] ) + '''

	4: 游戏
		17: 单机联机  \t\t视频数 = ''' + str( videoCounts[17] ) + '''
		171: 电子竞技  \t\t视频数 = ''' + str( videoCounts[171] ) + '''
		172: 手机游戏  \t\t视频数 = ''' + str( videoCounts[172] ) + '''
		65: 网络游戏  \t\t视频数 = ''' + str( videoCounts[65] ) + '''
		173: 桌游棋牌  \t\t视频数 = ''' + str( videoCounts[173] ) + '''
		121: GMV  \t\t视频数 = ''' + str( videoCounts[121] ) + '''
		136: 音游  \t\t视频数 = ''' + str( videoCounts[136] ) + '''
		19: Mugen  \t\t视频数 = ''' + str( videoCounts[19] ) + '''

	36：科技
		124: 趣味科普人文  \t视频数 = ''' + str( videoCounts[124] ) + '''
		122: 野生技术协会  \t视频数 = ''' + str( videoCounts[122] ) + '''
		39: 演讲· 公开课  \t视频数 = ''' + str( videoCounts[39] ) + '''
		96: 星海  \t\t视频数 = ''' + str( videoCounts[96] ) + '''
		95: 数码  \t\t视频数 = ''' + str( videoCounts[95] ) + '''
		98: 机械  \t\t视频数 = ''' + str( videoCounts[98] ) + '''
		176: 汽车  \t\t视频数 = ''' + str( videoCounts[176] ) + '''

	160：生活
		138: 搞笑  \t\t视频数 = ''' + str( videoCounts[138] ) + '''
		21: 日常  \t\t视频数 = ''' + str( videoCounts[21] ) + '''
		76: 美食圈  \t\t视频数 = ''' + str( videoCounts[76] ) + '''
		75: 动物圈  \t\t视频数 = ''' + str( videoCounts[75] ) + '''
		161: 手工  \t\t视频数 = ''' + str( videoCounts[161] ) + '''
		162: 绘画  \t\t视频数 = ''' + str( videoCounts[162] ) + '''
		175: ASMR  \t\t视频数 = ''' + str( videoCounts[175] ) + '''
		163: 运动  \t\t视频数 = ''' + str( videoCounts[163] ) + '''
		174: 其他  \t\t视频数 = ''' + str( videoCounts[174] ) + '''

	119：鬼畜
		22: 鬼畜调教  \t\t视频数 = ''' + str( videoCounts[22] ) + '''
		26: 音MAD  \t\t视频数 = ''' + str( videoCounts[26] ) + '''
		126: 人力VOCALOID  \t视频数 = ''' + str( videoCounts[126] ) + '''
		127: 教程演示  \t\t视频数 = ''' + str( videoCounts[127] ) + '''

	155：时尚
		157: 美妆  \t\t视频数 = ''' + str( videoCounts[157] ) + '''
		158: 服饰  \t\t视频数 = ''' + str( videoCounts[158] ) + '''
		164: 健身  \t\t视频数 = ''' + str( videoCounts[164] ) + '''
		159: 资讯  \t\t视频数 = ''' + str( videoCounts[159] ) + '''

	165：广告
		166: 广告  \t\t视频数 = ''' + str( videoCounts[166] ) + '''

	5: 娱乐
		71: 综艺  \t\t视频数 = ''' + str( videoCounts[71] ) + '''
		137: 明星  \t\t视频数 = ''' + str( videoCounts[137] ) + '''
		131: Korea相关  \t视频数 = ''' + str( videoCounts[131] ) + '''

	181：影视
		182: 影视杂谈  \t\t视频数 = ''' + str( videoCounts[182] ) + '''
		183: 影视剪辑  \t\t视频数 = ''' + str( videoCounts[183] ) + '''
		85: 短片  \t\t视频数 = ''' + str( videoCounts[85] ) + '''
		184: 预告 资讯  \t视频数 = ''' + str( videoCounts[184] ) + '''
		86: 特摄  \t\t视频数 = ''' + str( videoCounts[86] ) + '''

	放映厅:
	177：纪录片
		37: 人文历史  \t\t视频数 = ''' + str( videoCounts[37] ) + '''
		178: 科学探索  \t\t视频数 = ''' + str( videoCounts[178] ) + '''
		179: 热血军事  \t\t视频数 = ''' + str( videoCounts[179] ) + '''
		180: 舌尖上的旅行  \t视频数 = ''' + str( videoCounts[180] ) + '''

	23：电影
		147: 华语电影  \t\t视频数 = ''' + str( videoCounts[147] ) + '''
		145: 欧美电影  \t\t视频数 = ''' + str( videoCounts[145] ) + '''
		146: 日本电影  \t\t视频数 = ''' + str( videoCounts[146] ) + '''
		83: 其他国家  \t\t视频数 = ''' + str( videoCounts[83] ) + '''

	11: 电视剧
		185: 国产剧  \t\t视频数 = ''' + str( videoCounts[185] ) + '''
		187: 海外剧  \t\t视频数 = ''' + str( videoCounts[187] ) + '''
''')