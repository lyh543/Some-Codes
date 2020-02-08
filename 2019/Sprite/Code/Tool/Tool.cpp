#include "Tool.h"
#include "Bomb.h"
#include "ShrinkPotion.h"

using namespace std;

//ToolClass 部分

ToolClass::ToolClass() : status(INVALID), img(NULL)
{
	position.x = position.y = -1;
	position.height = DEFAULT_TOOL_HEIGHT;
	position.width = DEFAULT_TOOL_WIDTH;
}

ToolStatus ToolClass::getStatus()
{
	return status;
}

rect ToolClass::getPosition()
{
	return position;
}
bool ToolClass::collision(const rect & position2) //判断两个精灵是否相交
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

void ToolClass::paint(GameStatusStruct * gameStatus)
{
	if (status == INBAG || status == ONBOARD)
		putImageScale(img, position.x, position.y, position.width, position.height);

	//如果在工具栏中，还要打印对应的按键
	if (status == INBAG)
	{
		const int textSize = 30;
		setTextBkColor(WHITE);
		setTextColor(BLACK);
		setTextSize(textSize);
		paintText(
			position.x + position.width - textSize,
			position.y + position.height - textSize,
			getVirtualKeyString()
		); //保证输出的字母在道具图片的右下角
	}
}

bool ToolClass::appear()
{
	if (status != INVALID)
		return false;

	status = ONBOARD;

	//在场上随机掉落道具
	position.x = rand() % WINDOW_WIDTH - DEFAULT_TOOL_WIDTH;
	if (position.x < 0)
		position.x = 0;
	position.y = rand() % WINDOW_HEIGHT - DEFAULT_TOOL_HEIGHT;
	if (position.y < 0)
		position.y = 0;

	return true;
}

//ToolManagerClass 部分

ToolManagerClass::ToolManagerClass()
{
	toolList.resize(TOOL_N);
}
ToolManagerClass::ToolManagerClass(const std::vector<ToolClass*>& _toolList)
{
	toolList = _toolList;
}
ToolManagerClass::~ToolManagerClass()
{
	for (ToolClass* tool : toolList)
		delete tool;
}

void ToolManagerClass::putToolOnBoard(int gameClock)
{
	for (int i = 0; i < TOOL_N; i++)
	{
		if (toolList[i]->getStatus() == INVALID &&
			gameClock >= toolList[i]->getNextAppearTime())
		{
			toolList[i]->appear();
		}
	}
}

void ToolManagerClass::settleTool(const rect & userPosition)
{
	for (ToolClass * tool : toolList)
	{
		if (tool->getStatus() == ONBOARD && tool->collision(userPosition))
		{
			tool->gain();
		}
	}
}

bool ToolManagerClass::use(int virtualKey, GameStatusStruct * gameStatus
)
{
	//递归遍历
	for (int i = 0; i < TOOL_N; i++)
	{
		if (virtualKey == toolList[i]->getVirtualKey())
		{
			return toolList[i]->release(gameStatus);
		}
	}
	return false;
}

void ToolManagerClass::paint(GameStatusStruct * gameStatus)
{	
	for (ToolClass* tool : toolList)
		tool->paint(gameStatus);
}