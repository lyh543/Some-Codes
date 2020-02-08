#include "AutoSprite.h"

AutoSpriteClass::AutoSpriteClass(rect _position, int _dx, int _dy, ACL_Image* _imgArray, int _score) :
	SpriteClass(_position, _dx, _dy, _imgArray, _score)
{
	;
}
AutoSpriteClass::AutoSpriteClass(ACL_Image* _imgArray) : 
	SpriteClass()
{
	position.x = rand() % WINDOW_WIDTH - DEFAULT_SPRITE_WIDTH;
	if (position.x < 0)
		position.x = 0;
	position.y = rand() % WINDOW_HEIGHT - DEFAULT_SPRITE_HEIGHT;
	if (position.y < 0)
		position.y = 0;
	dx = rand() % 5 + 1;
	dy = rand() % 5 + 1;
	currentImg = RIGHT; //默认向右
	score = 1;
	imgArray = _imgArray;
}

AutoSpriteClass::~AutoSpriteClass()
{
	;
}

int AutoSpriteClass::move(const rect & userPosition) 
{
	//到达边界以后转向
	if (position.x<0 || position.x + position.width > WINDOW_WIDTH)
	{
		dx *= -1;
		currentImg = Direction((LEFT + RIGHT) - currentImg); // 左右相互切换
	}
	if (position.y<0 || position.y + position.height > WINDOW_HEIGHT) 
		dy *= -1;
	position.x += dx;
	position.y += dy;

	if (collision(userPosition))
		return -1;
	//不需要检查边界
	else
		return 0;
}