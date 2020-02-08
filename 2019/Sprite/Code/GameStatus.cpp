#include "GameStatus.h"
#include "Tool/Tool.h"

GameStatusStruct::GameStatusStruct()
{
	musicSwitchMode = 0;
	exitSwitchMode = 0;
	progress = INVALID_STATUS;
	scoreColor = BLACK;
	demonSpriteN = 0;
	gameClock = 0;
	userSprite = NULL;
	autoSpriteList.clear();
	toolManager = NULL;
}

GameStatusStruct::~GameStatusStruct()
{
	delete userSprite;
	for (auto autoSprite : autoSpriteList)
		delete autoSprite;
	delete toolManager;
}