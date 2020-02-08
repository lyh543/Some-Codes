#include "Bomb.h"
#include "../GameStatus.h"

using namespace std;

BombClass::BombClass(ACL_Image * _img, ACL_Sound * _explodeSound): ToolClass()
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
	explodeImg = _img + 1;
	explodeSound = _explodeSound;
}


int BombClass::getVirtualKey()       //释放道具的按键（Virtual Key），用于触发道具
{
	return 'Z';
}
const char * BombClass::getVirtualKeyString() //释放道具的按键（字符串），用于显示在屏幕上
{
	return "Z";
}

int BombClass::getNextAppearTime()
{
	return nextAppearTime;
}

bool BombClass::gain()
{
	assert(status == ONBOARD);

	status = INBAG;

	//使得道具出现在右下角
	position.x = 20;
	position.y = 500;

	return true;
}

static int paintingReleasingTimeCurrent;

bool BombClass::release(GameStatusStruct * gameStatus) //释放道具产生的效果
{
	if (status != INBAG)
		return false;

	status = RELEASING;

	//如果非静音，则播放音效
	if (gameStatus->musicSwitchMode == 0)
		playSound(*explodeSound, 0);

	//将已经渲染的次数归零
	paintingReleasingTimeCurrent = 0;

	//下面杀死同行、同列的所有怪物，并且强制结算恶魔
	rect userPosi = gameStatus->userSprite->getPosition();
	auto autoSpriteIter = gameStatus->autoSpriteList.begin();
	while (autoSpriteIter != gameStatus->autoSpriteList.end())
	{
		rect autoPosi = (*autoSpriteIter)->getPosition();
		if (
			(userPosi.x <= autoPosi.x && autoPosi.x <= userPosi.x + userPosi.width) ||
			(autoPosi.x <= userPosi.x && userPosi.x <= autoPosi.x + autoPosi.width) ||
			(userPosi.y <= autoPosi.y && autoPosi.y <= userPosi.y + userPosi.height) ||
			(autoPosi.y <= userPosi.y && userPosi.y <= autoPosi.y + autoPosi.height)
			) // 单看 x 坐标 或 y 坐标，相交了
		{
			int bouns = (*autoSpriteIter)->getScore();
			gameStatus->userSprite->addScore(bouns);
			delete *autoSpriteIter;
			autoSpriteIter = gameStatus->autoSpriteList.erase(autoSpriteIter);
		}
		else
		{
			autoSpriteIter++;
		}
	}

	nextAppearTime = gameStatus->gameClock * 2; //道具生成的迭代函数
	return true;
}

void BombClass::paint(GameStatusStruct * gameStatus)
{
	//只有在 RELEASING 模式下才调用继承类的函数
	if (status != RELEASING)
	{
		ToolClass::paint(gameStatus);
		return;
	}

	rect userPosi = gameStatus->userSprite->getPosition();

	putImageScale(explodeImg, 0, userPosi.y, WINDOW_WIDTH, userPosi.height);
	putImageScale(explodeImg, userPosi.x, 0, userPosi.width, WINDOW_HEIGHT);

	paintingReleasingTimeCurrent++;

	if (PaintingReleasingTimeConst == paintingReleasingTimeCurrent)
		status = INVALID;

}