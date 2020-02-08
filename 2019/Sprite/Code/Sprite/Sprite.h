#pragma once
#include <vector>
#include <list>
#include <exception>
#include <stdexcept>
#include <cassert>
#include <iostream>
#include <cmath>
#include "../acllib.h"
#include "../GameConfig.h"

enum Direction
{
	LEFT = 0,
	RIGHT = 1,
	UP = 2,
	DOWN = 3
};

enum SpriteKind
{
	USER_SPRITE = 0,
	AUTO_SPRITE = 1,
	AUTO_CLEVER_SPRITE = 2,
	DEMON_SPRITE = 3
};

class SpriteClass
{
protected:
	rect position;       //精灵的当前位置，包括左上角的坐标 x, y 和图片的长宽 width, height
	int dx, dy;          //移动的速度
	ACL_Image * imgArray;//图片信息，是一个数组，存储了精灵不同方向的图片
	Direction currentImg;             //当前精灵状态的图片下标， 0左 1右 2上 3下
	int score;

	virtual int getImgN() = 0;        //用虚函数实现，使得父类能得到子类的图片数量，判断是否越界

	void positionCheck();              //调整坐标（禁止继续移动），使坐标合法
	void positionCheck2();             //调整坐标（通过穿墙），使坐标合法
public:
	SpriteClass(const rect & _position, int _dx, int _dy, ACL_Image* _imgArray, int _score);
	SpriteClass(); //生成随机的精灵
	~SpriteClass();

	virtual SpriteKind getSpriteKind() = 0;

	void paintSprite();

	rect getPosition();
	int getScore();
	bool collision(const rect & position2);   //判断两个精灵是否相交，true 表示相交
	float distance(const rect & position2);

	virtual int move(const rect & userPosition) = 0;
	//返回 -1 表示有发生碰撞；返回 0 表示无碰撞
};

