#include <ctime>
#include <list>
#include <iostream>
#include "acllib.h"           //调用 Windows 库文件的库

#include "Sprite/Sprite.h"           //精灵基类
#include "Sprite/AutoSprite.h"       //自动移动的精灵类
#include "Sprite/UserSprite.h"       //用户的精灵的类
#include "Sprite/AutoCleverSprite.h" //聪明的自动移动精灵类
#include "Sprite/DemonSprite.h"      //恶魔精灵类

#include "Tool/Tool.h"               //道具类
#include "Tool/Bomb.h"               //炸弹，炸掉一行、一列的精灵
#include "Tool/ShrinkPotion.h"       //缩小药剂，用户精灵的大小减少一半

#include "GameStatus.h"              //储存游戏状态的类
#include "GameConfig.h"              //游戏配置

//游戏的三个流程
void welcome();
void beginGame();
void gameOver();

void timerEvent(int id); //计时事件
void keyEvent(int key, int event); //捕获键盘按键的函数
void mouseEvent(int x, int y, int key, int event); //捕获鼠标按键的函数


static GameStatusStruct * gameStatus = NULL;

//前向声明
namespace gamePainter {};
namespace gameResource {};
namespace mouseCoordinate {};

using namespace std;
using namespace gamePainter;
using namespace gameResource;
using namespace mouseCoordinate;

namespace gameResource //图片的游戏、音乐等资源
{
	//四种精灵的图像信息
	//其中用户精灵有四个方向，自动精灵有两个方向
	//0左 1右 2上 3下
	//添加图片时，除了修改下标，还要修改每个类里的 imgN
	static ACL_Image userSpriteImg[4], autoSpriteImg[2], autoCleverSpriteImg[2], demonSpriteImg[2];
	static ACL_Sound bgm;//背景音乐
	static ACL_Image welcomeBackground, gameBackground;
	static ACL_Image bombImg[2], shrinkPotionImg;
	static ACL_Sound bombSound, potionSound;
};

namespace gamePainter //主程序中各种 paint 函数的合集（当然不包含类里的 paint 函数）
{
	inline void loadResource() //加载图片
	{
		loadImage("Resource//tom//left.bmp", &userSpriteImg[0]);
		loadImage("Resource//tom//right.bmp", &userSpriteImg[1]);
		loadImage("Resource//tom//up.bmp", &userSpriteImg[2]);
		loadImage("Resource//tom//down.bmp", &userSpriteImg[3]);

		loadImage("Resource//jerry//left.bmp", &autoSpriteImg[0]);
		loadImage("Resource//jerry//right.bmp", &autoSpriteImg[1]);

		loadImage("Resource//duck//left.bmp", &autoCleverSpriteImg[0]);
		loadImage("Resource//duck//right.bmp", &autoCleverSpriteImg[1]);

		loadImage("Resource//dog//left.bmp", &demonSpriteImg[0]);
		loadImage("Resource//dog//right.bmp", &demonSpriteImg[1]);

		loadImage("Resource//welcome.bmp", &welcomeBackground);
		loadImage("Resource//background.bmp", &gameBackground);

		loadImage("Resource//tool//bomb//bomb.bmp", &bombImg[0]);
		loadImage("Resource//tool//bomb//explode.bmp", &bombImg[1]);
		loadSound("Resource//tool//bomb//bomb.mp3", &bombSound);

		loadImage("Resource//tool//shrink-potion//shrink-potion.bmp", &shrinkPotionImg);
		loadSound("Resource//tool//shrink-potion//potion.mp3", &potionSound);

		loadSound("Resource//music.mp3", &bgm);
	}
	inline void loadButtonColor(int mode) // 调整按钮的红绿配色和字体
	{
		if (mode == 1) //反色模式，用于鼠标在其上的时候
		{
			setTextColor(GREEN);
			setTextBkColor(RED);
		}
		else
		{
			setTextColor(RED);
			setTextBkColor(GREEN);
		}
		setTextSize(50);
	}
	inline void paintBeginButton(int mode = 0)
	{
		loadButtonColor(mode);
		paintText(570, 420, "BEGIN");
	}
	inline void paintPauseButton(int mode = 0)
	{
		loadButtonColor(mode);
		paintText(570, 420, "PAUSE");
	}
	inline void paintMusicButton(int mode = 0)
	{
		loadButtonColor(mode);
		paintText(564, 480, "MUSIC");
	}
	inline void paintExitButton(int mode = 0)
	{
		loadButtonColor(mode);
		paintText(608, 540, "EXIT");
	}
	inline void paintScore(int score)
	{
		char txt[10];
		sprintf_s(txt, "%d", gameStatus->userSprite->getScore());

		setTextSize(40);
		setTextColor(gameStatus->scoreColor);
		setTextBkColor(WHITE);

		paintText(10, 10, txt);
	}
	inline void paintWelcomeBackground()
	{
		putImageScale(&welcomeBackground, 0, 0, WINDOW_WIDTH, WINDOW_HEIGHT);
	}
	inline void paintGameBackground()
	{
		putImageScale(&gameBackground, 0, 0, WINDOW_WIDTH, WINDOW_HEIGHT);
	}
	inline void paintGamingElements() //输出 Gaming 过程中的所有元素
	{

		beginPaint();

		clearDevice();

		paintGameBackground();
		paintPauseButton(gameStatus->progress == PAUSE_STATUS);
		paintMusicButton(gameStatus->musicSwitchMode);
		paintExitButton(gameStatus->exitSwitchMode);

		//遍历自动精灵链表并输出
		for (auto& autoSprite : gameStatus->autoSpriteList)
			autoSprite->paintSprite();

		//输出道具（包括场上的/工具栏里的，还包括正在释放的道具的效果）
		gameStatus->toolManager->paint(gameStatus);

		//输出用户的精灵和分数
		if (gameStatus->userSprite != NULL)
		{
			gameStatus->userSprite->paintSprite();
			paintScore(gameStatus->userSprite->getScore());//输出分数
		}

		endPaint();
	}
	inline void paintGameOver(int mode = 0)
	{
		if (mode == 0)
		{
			setTextColor(YELLOW);
			setTextBkColor(RED);
		}
		else //反色模式
		{
			setTextColor(RED);
			setTextBkColor(YELLOW);
		}
		setTextSize(50);

		paintText(184, 275, "Game Over!"); //使其在屏幕正中央，Game Over 的大小为 431*50
	}
}

namespace mouseCoordinate
{
	//用截图测量实际像素点的位置

	//Begin 和 Pause 是共用的
	inline bool mouseOnBeginButton(int x, int y)
	{
		return x >= 570 && x <= 780 && y >= 420 && y <= 470;
	}
	inline bool mouseOnMusicButton(int x, int y)
	{
		return x >= 564 && x <= 780 && y >= 480 && y <= 530;
	}
	inline bool mouseOnExitButton(int x, int y)
	{
		return x >= 608 && x <= 780 && y >= 540 && y <= 589;
	}
	inline bool mouseOnGameOverButton(int x, int y)
	{
		return x >= 184 && x <= 615 && y >= 275 && y <= 325;
	}
}


int Setup()
//_WinMain 函数在 acllib.h 库中，他会调用 Setup 函数
//该函数会对程序进行初始化（如加载图片、音乐等）设定
{
	srand((unsigned)time(NULL));

	initWindow("精灵游戏", DEFAULT, DEFAULT, WINDOW_WIDTH, WINDOW_HEIGHT); //初始化窗口

#ifdef DEBUG
	initConsole();  //如果是 debug 模式则启用命令行窗口，方便输出
#endif // DEBUG

	//加载图片和音乐
	loadResource();

	//播放音乐
	playSound(bgm, 1);

	welcome();
	registerMouseEvent(mouseEvent);
	return 0;
}

void welcome()
{
	if (gameStatus != NULL)
		delete gameStatus;
	//清除上一局数据的过程放到这里

	//初始化一堆游戏中的常量
	gameStatus = new GameStatusStruct;
	gameStatus->progress = WELCOME_STATUS;

	//一切 paint 函数必须在 beginPaint 和 endPaint 之间
	beginPaint();
	clearDevice();
	paintWelcomeBackground();

	//更换字体
	setTextFont("Goudy Stout");

	//显示 begin music exit “按钮”
	paintBeginButton();
	paintMusicButton();
	paintExitButton(gameStatus->exitSwitchMode);
	endPaint();
}

void beginGame()
{
	gameStatus->progress = GAMING_STATUS;
	gameStatus->userSprite = new UserSpriteClass(userSpriteImg);

	//道具系统
	vector<ToolClass*> tempToolVector;
	tempToolVector.push_back(new BombClass(bombImg, &bombSound));
	tempToolVector.push_back(new ShrinkPotionClass(&shrinkPotionImg, &potionSound));
	gameStatus->toolManager = new ToolManagerClass(tempToolVector);

	//时钟系统
	registerTimerEvent(timerEvent);
	startTimer(0, GAME_CLOCK_INTERVAL);    //每 40ms 执行一次 timerEvent(0)：精灵移动
	startTimer(1, SPRITE_CREATE_INTERVAL);  //每 1s 执行一次 timerEvent(1)：生成精灵

	registerKeyboardEvent(keyEvent);
}

//游戏结束的函数
void gameOver()
{
	gameStatus->progress = GAME_OVER_STATUS;

	//除了在这里paintGameOver 同时移动鼠标也会 paintGameOver
	beginPaint();
	paintGameOver(0);
	endPaint();

	//停止计时活动
	cancelTimer(0);
	cancelTimer(1);
}

//鼠标移动的事件，处理按键的情况
void mouseEvent(int x, int y, int key, int event)
{
	//music开关控制
	if (mouseOnMusicButton(x, y))
	{
		if (key == LEFT_BUTTON && event == BUTTON_DOWN)
		{
			if (gameStatus->musicSwitchMode == 0)
			{
				stopSound(bgm);    //关闭音乐
				gameStatus->musicSwitchMode = 1;
			}
			else
			{
				playSound(bgm, 1); //重新打开音乐
				gameStatus->musicSwitchMode = 0;
			}
		}

		beginPaint();
		paintMusicButton(gameStatus->musicSwitchMode);
		endPaint();
	}

	// exit 按钮退出
	if (mouseOnExitButton(x, y))
	{
		if (key == LEFT_BUTTON && event == BUTTON_DOWN)
		{
			exit(0);
		}
		else
		{
			//鼠标在 exit 按钮上，按钮变色
			beginPaint();
			gameStatus->exitSwitchMode = 1;
			paintExitButton(gameStatus->exitSwitchMode);
			endPaint();
		}

	}
	else
	{
		//鼠标不在 exit 按钮上，按钮变回原色
		beginPaint();
		gameStatus->exitSwitchMode = 0;
		paintExitButton(gameStatus->exitSwitchMode);
		endPaint();
	}

	//如果在 Welcome 的状态
	if (gameStatus->progress == WELCOME_STATUS)
	{
		//开始界面的 begin 功能实现
		if (mouseOnBeginButton(x, y))
		{
			if (key == LEFT_BUTTON && event == BUTTON_DOWN)
			{
				gameStatus->progress = GAMING_STATUS;
				beginGame();
				return;
			}
			else
			{
				//鼠标在 begin 按钮上，按钮变色
				beginPaint();
				paintBeginButton(1);
				endPaint();
			}
		}
		else
		{
			//鼠标不在 begin 按钮上，按钮变回原色
			beginPaint();
			paintBeginButton(0);
			endPaint();
		}
	}

	//如果在 Gaming 的的状态
	if (gameStatus->progress == GAMING_STATUS)
	{
		//游戏界面的 pause 功能实现
		if (mouseOnBeginButton(x, y) && key == LEFT_BUTTON && event == BUTTON_DOWN)
		{
			//切换状态：暂停游戏
			gameStatus->progress = PAUSE_STATUS;
			cancelTimer(0);
			cancelTimer(1);
			//暂停前得 paint 一次，因为 paint 原本是在计时器里的，计时器被关掉了
			paintGamingElements();
			return;
		}
	}
	
	//如果在 Pause 的的状态
	if (gameStatus->progress == PAUSE_STATUS)
	{
		//暂停界面的 pause 功能实现
		if (mouseOnBeginButton(x, y) && key == LEFT_BUTTON && event == BUTTON_DOWN)
		{
			//切换状态：继续游戏
			gameStatus->progress = GAMING_STATUS;
			startTimer(0, GAME_CLOCK_INTERVAL);    //每 40ms 执行一次 timerEvent(0)：精灵移动
			startTimer(1, SPRITE_CREATE_INTERVAL);  //每 1s 执行一次 timerEvent(1)：生成精灵
			return;
		}
	}


	//如果在 GameOver 的状态
	if (gameStatus->progress == GAME_OVER_STATUS)
	{
		if (mouseOnGameOverButton(x, y))
		{
			//点击 gameOver 按钮，开始下一轮
			if (key == LEFT_BUTTON && event == BUTTON_DOWN)
			{
				gameStatus = 0;
				welcome();
				return;
			}
			else
			{
				//鼠标在 gameOver 按钮上，按钮变色
				beginPaint();
				paintGameOver(1);
				endPaint();
			}
		}
		else
		{
			//鼠标不在 gameOver 按钮上，按钮变回原色
			beginPaint();
			paintGameOver(0);
			endPaint();
		}
		return;
	}
}

//定时事件（生成精灵和精灵移动），由 registerTimerEvent 调用
void timerEvent(int id)
{
	if (id == 0) //每 40ms 讨论精灵移动、是否生成道具
	{
		gameStatus->gameClock++;

		//讨论是否生成道具
		gameStatus->toolManager->putToolOnBoard(gameStatus->gameClock);

		//讨论精灵移动
		int collide = 0;
		for (auto autoSprite : gameStatus->autoSpriteList)
		{
			int returnValue = autoSprite->move(gameStatus->userSprite->getPosition());
			if (returnValue == -1)  //表示有自动精灵碰到用户精灵，需要用户精灵主动结算碰撞
			{
				collide = -1;
			}
		}
		if (collide == -1) //UserSprite 主动结算碰撞
		{
			int returnValue = gameStatus->userSprite->settleScore(gameStatus->autoSpriteList);
			if (returnValue < 0)
			{
				paintGamingElements();
				gameOver();
			}
		}
	}

	if (id == 1) //每 1s，讨论生成精灵
	{
#ifdef DEBUG_DEMON //会提前出恶魔
		if (gameStatus->userSprite->getScore() > gameStatus->demonSpriteN)
#else
		if (gameStatus->userSprite->getScore() > 20 * (gameStatus->demonSpriteN + 1)) //从 20 分开始，玩家每得 20 分，就生成一只恶魔，注意这不是实际恶魔的数量，因为没有考虑炸死的情况，如果考虑了
#endif
		{
			DemonSpriteClass * demonSprite = new DemonSpriteClass(demonSpriteImg);
			while (gameStatus->userSprite->distance(demonSprite->getPosition()) < DANGER_DISTANCE) //如果生成的恶魔直接和用户的距离较近，则重新生成
				*demonSprite = DemonSpriteClass(demonSpriteImg);

			gameStatus->autoSpriteList.push_back(demonSprite);
			gameStatus->demonSpriteN++;
#ifdef ENABLE_SPEED_BOUNS
			//生成恶魔以后，用户精灵的速度也会增加，否则游戏会很难
			gameStatus->userSprite->addSpeed(2);
#endif
			//生成恶魔以后分数颜色闪一下
			gameStatus->scoreColor = RED;
		}
		else if (gameStatus->autoSpriteList.size() < MAX_SPRITE + (long long)gameStatus->demonSpriteN)
		{
			if (rand() % 100 < CLEVER_PROBOBILITY) //有 CLEVER_PROBOBILITY 的概率执行 if 后的语句
				gameStatus->autoSpriteList.push_back(new AutoCleverSpriteClass(autoCleverSpriteImg));
			else
				gameStatus->autoSpriteList.push_back(new AutoSpriteClass(autoSpriteImg));
			gameStatus->scoreColor = BLACK;
		}
	}
	paintGamingElements();
}

//讨论有按键，玩家移动
void keyEvent(int key, int event)
{
	if (gameStatus->progress != GAMING_STATUS) //如果不是游戏中的状态，就直接结束
		return;
	if (event != KEY_DOWN)
		return;

	//如果是方向键，就使用户精灵移动
	//否则尝试使用道具
	if (key == VK_UP || key == VK_DOWN || key == VK_LEFT || key == VK_RIGHT)
		gameStatus->userSprite->move(key);
	else
		gameStatus->toolManager->use(key, gameStatus);
	paintGamingElements();

	//需要先 paint 再结束游戏，否则会造成实际玩家死亡但是并没有被 paint 到屏幕上的情况
	if (gameStatus->userSprite->settleScore(gameStatus->autoSpriteList) < 0) //对玩家撞到的怪物进行结算
	{
		gameOver();
		return;
	}
	gameStatus->toolManager->settleTool(gameStatus->userSprite->getPosition());
}
