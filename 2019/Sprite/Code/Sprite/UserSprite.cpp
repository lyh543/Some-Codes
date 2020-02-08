#include "UserSprite.h"

UserSpriteClass::UserSpriteClass(rect _position, int _dx, int _dy, ACL_Image* _img, int _score /* = 0 */) :
	SpriteClass(_position, _dx, _dy, _img, _score)
{
	;
}
UserSpriteClass::UserSpriteClass(ACL_Image* _img)
{
	position.x = rand() % WINDOW_WIDTH - DEFAULT_SPRITE_WIDTH;
	if (position.x < 0)
		position.x = 0;
	position.y = rand() % WINDOW_HEIGHT - DEFAULT_SPRITE_HEIGHT;
	if (position.y < 0)
		position.y = 0;
	dx = 5;
	dy = 5;
	imgArray = _img;
	score = 0;
}
UserSpriteClass::~UserSpriteClass()
{
	;
}

void UserSpriteClass::setPosition(const rect & _position) //设置坐标和大小
{
	position = _position;
	positionCheck();
}
int UserSpriteClass::move(int key)  //进行移动
{
	int speedRatio = 1; //加速倍率

#ifdef SHIFT_SPEED_UP
	if (GetKeyState(VK_SHIFT) & 0x80) //如果允许加速，且 Shift 被按下
		speedRatio = 2;
#endif

	if (key == VK_UP)
		position.y -= speedRatio * dy, currentImg = UP;
	else if (key == VK_DOWN)
		position.y += speedRatio * dy, currentImg = DOWN;
	else if (key == VK_LEFT)
		position.x -= speedRatio * dx, currentImg = LEFT;
	else if (key == VK_RIGHT)
		position.x += speedRatio * dx, currentImg = RIGHT;
	positionCheck();

	return 0;
}

//理论上这个函数永远不会被调用，只是为了能够实例化，而实现了父类的虚函数。
int UserSpriteClass::move(const rect & rectangle)
{
	assert(0);
	return 0;
}

void UserSpriteClass::addSpeed(int bonus)
{
	dx += bonus;
	dy += bonus;
}
void UserSpriteClass::addScore(int bouns)
{
	score += bouns;
}

//遍历所有自动精灵，看是否有相撞的，如果有，则要讨论加分、删除、游戏结束，游戏结束时返回 -1
int UserSpriteClass::settleScore(std::list<AutoSpriteClass*>& autoSpriteList)
{
	auto autoSpriteIter = autoSpriteList.begin();
	while (autoSpriteIter != autoSpriteList.end())
	{
		if (this->collision((*autoSpriteIter)->getPosition()))
		{
			int bouns = (*autoSpriteIter)->getScore();
			if ((*autoSpriteIter)->getSpriteKind() == DEMON_SPRITE)  //如果撞到的是恶魔，就结束游戏
				return -1;
			this->addScore(bouns);
			delete* autoSpriteIter;
			autoSpriteIter = autoSpriteList.erase(autoSpriteIter);
		}
		else
		{
			autoSpriteIter++;
		}
	}
	return 0;
}