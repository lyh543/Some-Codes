#include "Sprite.h"            //精灵的基类

SpriteClass::SpriteClass(const rect & _position, int _dx, int _dy, ACL_Image* _imgArray, int _score) :
	position(_position), dx(_dx), dy(_dy), imgArray(_imgArray), currentImg(LEFT), score(_score)
{
	;
}
SpriteClass::SpriteClass() : dx(0), dy(0), imgArray(NULL), currentImg(LEFT)
{
	position.x = position.y = 0;
	position.height = DEFAULT_SPRITE_HEIGHT;
	position.width = DEFAULT_SPRITE_WIDTH;
}
SpriteClass::~SpriteClass()
{
	;
}

rect SpriteClass::getPosition()
{
	return position;
}
int SpriteClass::getScore()
{
	return score;
}
bool SpriteClass::collision(const rect & position2) //判断两个精灵是否相交
{
	if ((
		(position.x <= position2.x && position2.x <= position.x + position.width) ||
		(position2.x <= position.x && position.x <= position2.x + position2.width)
		) // 单看 x 坐标，相交了
		&&
		(
		(position.y <= position2.y && position2.y <= position.y + position.height) ||
			(position2.y <= position.y && position.y <= position2.y + position2.height)
			)) // 单看 y 坐标，相交了
	{
		return true;
	}
	return false;
}
float SpriteClass::distance(const rect & position2)
{

	int center_x = position.x + position.width / 2;
	int center_y = position.y + position.height / 2;
	int user_center_x = position2.x + position2.width / 2;
	int user_center_y = position2.y + position2.height / 2;

	double dist = sqrt(pow((double)center_x - user_center_x, 2) + pow((double)center_y - user_center_y, 2));

	return dist;
}

//绘制精灵
void SpriteClass::paintSprite()
{
	assert(currentImg < getImgN());
	putImageScale(&imgArray[currentImg], position.x, position.y, position.width, position.height);
}

void SpriteClass::positionCheck()  //调整坐标（禁止继续移动），使坐标合法
{
	if (position.x < 0)
		position.x = 0;
	else if (position.x + position.width > WINDOW_WIDTH)
		position.x = (WINDOW_WIDTH - position.width);
	if (position.y < 0)
		position.y = 0;
	else if (position.y + position.height > WINDOW_HEIGHT)
		position.y = (WINDOW_HEIGHT - position.height);
}
void SpriteClass::positionCheck2()  //调整坐标（通过穿墙），使坐标合法
{
	if ((dx < 0) && (position.x < -position.width / 2))
		position.x = WINDOW_WIDTH - position.width / 2;
	if ((dx > 0) && (position.x > (WINDOW_WIDTH - position.width / 2)))
		position.x = -position.width / 2;
	if ((dy < 0) && (position.y < -position.height / 2))
		position.y = WINDOW_HEIGHT - position.height / 2;
	if ((dy > 0) && (position.y > (WINDOW_HEIGHT - position.height / 2)))
		position.y = -position.height / 2;
}