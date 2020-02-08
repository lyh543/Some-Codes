#pragma once
#include "Tool.h"

//炸弹道具，用于炸掉同行、同列的精灵
class BombClass : public ToolClass
{
	friend class ToolManagerClass;
private:
	int nextAppearTime; //下一次出现的时间
	ACL_Image * explodeImg;
	ACL_Sound * explodeSound;
	const int PaintingReleasingTimeConst = 15;  //释放的时候绘制 15 次，即 600ms

	int getVirtualKey();       //释放道具的按键（Virtual Key），用于触发道具
	const char * getVirtualKeyString(); //释放道具的按键（字符串），用于显示在屏幕上

	int getNextAppearTime();
	bool gain();
	bool release(GameStatusStruct * gameStatus); //释放道具产生的效果
	void paint(GameStatusStruct * gameStatus);

public:
	BombClass(ACL_Image * _img, ACL_Sound * _explodeSound);
};