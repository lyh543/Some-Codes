#pragma once
#include "AutoSprite.h"

class AutoCleverSpriteClass : public AutoSpriteClass
{
protected:
	bool danger(const rect & userPosition); //（智能）判断用户是否在周围
	int getImgN() { return 2; }     //返回当前类的图片数量，之所以写成函数而不是 const int，是为了在基类调用成员函数时，能调用该虚函数
public:
	AutoCleverSpriteClass(rect _position, int _dx, int _dy, ACL_Image* _imgArray, int _score);
	AutoCleverSpriteClass(ACL_Image* _imgArray);
	~AutoCleverSpriteClass();

	virtual SpriteKind getSpriteKind() { return AUTO_CLEVER_SPRITE; }

	int move(const rect & userPosition);
};