#include "DemonSprite.h"

DemonSpriteClass::DemonSpriteClass(rect _position, int _dx, int _dy, ACL_Image* _imgArray, int _score) :
	AutoSpriteClass(_position, _dx, _dy, _imgArray, _score)
{
	;
}
DemonSpriteClass::DemonSpriteClass(ACL_Image* _imgArray) :
	AutoSpriteClass(_imgArray)//随机生成一个精灵并绑定图片
{
	dx = dy = 2; //比 UserSpriteClass 慢，不然这游戏太难玩了
	score = 0;
}
DemonSpriteClass::~DemonSpriteClass()
{
	;
}

inline int sign(int x)
{
	if (x == 0)
		return 0;
	else if (x > 0)
		return 1;
	else
		return -1;
}

int DemonSpriteClass::move(const rect & userPosition)
{
	//设定为朝向玩家走来
	if (position.x > userPosition.x + dx)  // 如果不加 dx, 二者的差可能在正负数之间反复横跳，导致看起来疯狂转向
		currentImg = LEFT; //调整为向左形态
	else
		currentImg = RIGHT; //调整为向右形态

	position.x += dx * sign(userPosition.x - position.x);
	position.y += dy * sign(userPosition.y - position.y);

	positionCheck2();

	if (collision(userPosition))
		return -1;
	else
		return 0;
}