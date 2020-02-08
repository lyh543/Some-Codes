#pragma once
#include <list>
#include "../Acllib.h"
#include "../GameConfig.h"

#include "../Sprite/UserSprite.h"
#include "../Sprite/AutoSprite.h"

enum ToolStatus
{
	INVALID,
	ONBOARD,  //在场上（还没有得到）
	INBAG,    //在包里
	RELEASING //释放中
};

class ToolManagerClass; //前向声明
struct GameStatusStruct;

class ToolClass
{
	friend class ToolManagerClass;
protected:
	ToolStatus status;          //道具的状态
	rect position;              //道具的坐标
	ACL_Image* img;             //道具的图形


	ToolStatus getStatus();

	rect getPosition();
	bool collision(const rect & position2);

	virtual int getVirtualKey() = 0;       //释放道具的按键（Virtual Key），用于触发道具
	virtual const char * getVirtualKeyString() = 0; //释放道具的按键（字符串），用于显示在屏幕上

	virtual int getNextAppearTime() = 0;
	bool appear();                  //道具出现
	virtual bool gain() = 0;        //得到道具，由于涉及到在背包中的坐标，因此基类设为虚函数，由集成类实现
	virtual bool release(GameStatusStruct * gameStatus) = 0; //释放道具产生的效果

	virtual void paint(GameStatusStruct * gameStatus); //用 Acllib.h 里的函数输出图像（和右下角的示意触发字母）

public:
	ToolClass();
};

class ToolManagerClass   //工具栏，用于管理所有道具
{
private:
	std::vector<ToolClass*> toolList;
public:
	ToolManagerClass();
	ToolManagerClass(const std::vector<ToolClass*> & _toolList);
	~ToolManagerClass();

	void putToolOnBoard(int gameClock); //按照游戏时间和各道具的 nextTime，尝试将道具放在场上
	void settleTool(const rect & userPosition); //结算玩家是否获得道具
	bool use(int virtualKey, GameStatusStruct * gameStatus);  //尝试使用道具（按虚拟按键来识别），成功返回 true，失败返回 false
	void paint(GameStatusStruct * gameStatus);  //打印道具

};