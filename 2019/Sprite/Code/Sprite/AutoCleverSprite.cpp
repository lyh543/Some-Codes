#include "AutoCleverSprite.h"
#include<math.h>

AutoCleverSpriteClass::AutoCleverSpriteClass(rect _position, int _dx, int _dy, ACL_Image* _img, int _score) :
	AutoSpriteClass(_position, _dx, _dy, _img, _score)
{
}
AutoCleverSpriteClass::AutoCleverSpriteClass(ACL_Image* _img): AutoSpriteClass(_img)
{
	score = 5;
}
AutoCleverSpriteClass::~AutoCleverSpriteClass()
{
	;
}

int AutoCleverSpriteClass::move(const rect & userPosition)
{
	if (danger(userPosition)) //如果危险，则需要反向加速
	{
		if (position.x < userPosition.x)
		{
			dx = -abs(dx);
			currentImg = LEFT; //调整为向左形态
		}
		else
		{
			dx = abs(dx);
			currentImg = RIGHT; //调整为向右形态
		}

		if (position.y < userPosition.y)
			dy = -abs(dy);
		else
			dy = abs(dy);

		position.x += int(1.5 * dx);
		position.y += int(1.5 * dy);
	}
	else
	{
		position.x += dx;
		position.y += dy;
	}

	positionCheck2();

	if (collision(userPosition))
		return -1;
	else
	return 0;
}

bool AutoCleverSpriteClass::danger(const rect & userPosition)
{
	return distance(userPosition) < DANGER_DISTANCE;
}
