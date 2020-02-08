#pragma once
#include "AutoSprite.h"

class DemonSpriteClass : public AutoSpriteClass
{
	int getImgN() { return 2; } //返回当前类的图片数量，之所以写成函数而不是 const int，是为了在基类调用成员函数时，能调用该虚函数
public:
	DemonSpriteClass(rect _position, int _dx, int _dy, ACL_Image* _imgArray, int _score);
	DemonSpriteClass(ACL_Image* _imgArray); //随机生成一个精灵并绑定图片

	~DemonSpriteClass();

	virtual SpriteKind getSpriteKind() { return DEMON_SPRITE; }

	virtual int move(const rect & userPosition);
};