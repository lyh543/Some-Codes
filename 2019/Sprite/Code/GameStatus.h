#pragma once
#include "acllib.h"

#include "Sprite/AutoSprite.h"
#include "Sprite/UserSprite.h"

class ToolManagerClass; //前向声明

enum ProgressStatus
{
	INVALID_STATUS,
	WELCOME_STATUS,
	GAMING_STATUS,
	PAUSE_STATUS,
	GAME_OVER_STATUS
};

struct GameStatusStruct               //包含每一局游戏状态的参数
{
	int musicSwitchMode;             //歌曲开关键的状态（0 表示开，1 表示关）
	int exitSwitchMode;              //exit 开关的状态
	ProgressStatus progress;         //目前游戏界面
	COLORREF scoreColor;             //显示分数的颜色
	int demonSpriteN;                //场上的恶魔数
	int gameClock;                   //游戏的时钟，每 40ms 为一个 CLOCK，进行一次移动、结算、输出
	UserSpriteClass* userSprite;     //用户的精灵
	std::list<AutoSpriteClass*> autoSpriteList; //自动精灵的链表，链表元素为指针，才可以进行动态多态
	ToolManagerClass* toolManager;   //管理道具的类

	GameStatusStruct();
	~GameStatusStruct();
};