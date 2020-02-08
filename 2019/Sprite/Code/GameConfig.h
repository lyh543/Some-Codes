#pragma once
//一些游戏设定

//游戏窗口设定
#define WINDOW_WIDTH 800            //窗口宽度
#define WINDOW_HEIGHT 600           //窗口高度
#define DEFAULT_SPRITE_WIDTH 100    //默认精灵宽度
#define DEFAULT_SPRITE_HEIGHT 100   //默认精灵高度
#define DEFAULT_TOOL_WIDTH 100      //默认道具宽度
#define DEFAULT_TOOL_HEIGHT 100     //默认道具高度

//游戏时间设定
#define GAME_CLOCK_INTERVAL 40      //游戏的单位时间，精灵移动的时间间隔（单位 ms）
#define SPRITE_CREATE_INTERVAL 1000 //精灵产生的时间间隔（单位 ms）

//游戏规则的参数设定
#define MAX_SPRITE 10               //同屏的自动精灵最大数（不包含恶魔）
#define CLEVER_PROBOBILITY 20       //产生 AutoSprite 时，产生 Clever 的概率为 20%
#define DANGER_DISTANCE 150         //被认为是“危险”的距离（聪明精灵到玩家的距离、玩家到恶魔的距离）
#define TOOL_N 2                    //道具的总数

//作弊模式
#define SHIFT_SPEED_UP              //开启以后，按住 Shift 可以加速用户精灵移动
#define MORE_TOOL                   //使道具掉落的略频繁
#define ENABLE_SPEED_BOUNS          //在出现恶魔以后，用户精灵会加速（由于道具的存在，开启该模式会使游戏变简单）


//调试模式
//#define NDEBUG                    //用于禁用所有 assert 判定
//#define DEBUG                     //开启命令行等调试常用功能
#ifdef DEBUG                        //开启以下功能的前提是开启调试命令
#define DEBUG_TOOL                  //对道具功能进行测试，道具会直接掉落
//#define DEBUG_DEMON               //对恶魔部分进行调试时可以打开，使得恶魔会出更快
#endif