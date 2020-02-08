#pragma once
#include "Sprite.h"
#include "AutoSprite.h"

class UserSpriteClass : public SpriteClass
{
	friend class ShrinkPotionClass;
protected:
	int getImgN() { return 4; }     //返回当前类的图片数量，之所以写成函数而不是 const int，是为了在基类调用成员函数时，能调用该虚函数
	void setPosition(const rect & _position); //设置坐标和大小
	
public:
	UserSpriteClass(rect _position, int _dx, int _dy, ACL_Image* _imgArray, int _score = 0);
	UserSpriteClass(ACL_Image* _imgArray); //随机生成用户精灵并绑定图片
	~UserSpriteClass();

	virtual SpriteKind getSpriteKind() { return USER_SPRITE; }

	int move(int key);               //进行移动
	int move(const rect & userPosition);     //虚函数的实现，留空

	void addSpeed(int bonus);
	void addScore(int bouns);
	int settleScore(std::list<AutoSpriteClass*> & autoSpriteList); //用户移动以后，对撞到的精灵进行结算，游戏结束时返回 -1
};
