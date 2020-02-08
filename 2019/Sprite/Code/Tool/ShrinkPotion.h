#pragma once
#include "Tool.h"

//缩小药水，会使玩家的大小缩小一段时间，更难被恶魔精灵捕捉
class ShrinkPotionClass : public ToolClass
{
	friend class ToolManagerClass;
private:
	ACL_Sound * potionSound;
	int nextAppearTime; //下一次出现的时间，以 40ms 为单位
	const int PaintingReleasingTimeConst = 400;  //释放的时候绘制 400 次，即 16000 ms

	int getVirtualKey();       //释放道具的按键（Virtual Key），用于触发道具
	const char * getVirtualKeyString(); //释放道具的按键（字符串），用于显示在屏幕上

	int getNextAppearTime();
	bool gain();
	bool release(GameStatusStruct * gameStatus); //释放道具产生的效果
	void paint(GameStatusStruct * gameStatus);
public:
	ShrinkPotionClass(ACL_Image * _img, ACL_Sound * _potionSound);
};