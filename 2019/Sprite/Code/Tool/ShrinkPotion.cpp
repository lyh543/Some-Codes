#include "ShrinkPotion.h"
#include "../GameStatus.h"

using namespace std;

ShrinkPotionClass::ShrinkPotionClass(ACL_Image * _img, ACL_Sound * _potionSound) : ToolClass()
{
#ifdef DEBUG_TOOL
	nextAppearTime = 0;
#else
#ifdef MORE_TOOL
	nextAppearTime = 100 - rand() % 50;
#else
	nextAppearTime = 500 - rand() % 100;
#endif
#endif

	img = _img;
	potionSound = _potionSound;
}

int ShrinkPotionClass::getVirtualKey()       //释放道具的按键（Virtual Key），用于触发道具
{
	return 'X';
}
const char * ShrinkPotionClass::getVirtualKeyString() //释放道具的按键（字符串），用于显示在屏幕上
{
	return "X";
}

int ShrinkPotionClass::getNextAppearTime()
{
	return nextAppearTime;
}

bool ShrinkPotionClass::gain()
{
	assert(status == ONBOARD);

	status = INBAG;

	//使得道具出现在右下角
	position.x = 125;
	position.y = 500;

	return true;
}

static int paintingReleasingTimeCurrent;

bool ShrinkPotionClass::release(GameStatusStruct * gameStatus) //释放道具产生的效果
{
	if (status != INBAG)
		return false;

	status = RELEASING;

	//如果非静音，则播放音效
	if (gameStatus->musicSwitchMode == 0)
		playSound(*potionSound, 0);

	//将已经渲染的次数归零
	paintingReleasingTimeCurrent = 0;

	//调整身材
	rect userPosition = gameStatus->userSprite->getPosition();
	userPosition.width /= 2;
	userPosition.height /= 2;
	gameStatus->userSprite->setPosition(userPosition);

	nextAppearTime = gameStatus->gameClock * 2; //道具生成的迭代函数
	return true;
}

void ShrinkPotionClass::paint(GameStatusStruct * gameStatus)
{
	//只有在 RELEASING 模式下才调用继承类的函数
	if (status != RELEASING)
	{
		ToolClass::paint(gameStatus);
		return;
	}

	paintingReleasingTimeCurrent++;

	if (PaintingReleasingTimeConst == paintingReleasingTimeCurrent)
	{
		status = INVALID;

		//时间到以后，得把尺寸改回来

		rect userPosition = gameStatus->userSprite->getPosition();
		userPosition.width *= 2;
		userPosition.height *= 2;
		gameStatus->userSprite->setPosition(userPosition);
	}
}