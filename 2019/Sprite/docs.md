# 精灵游戏文档

## 游戏配置的实现

所有宏定义配置都在 `GameConfig.h`中，方便游戏设置的统一管理。

## 精灵类及其继承类的实现

### 精灵类 SpriteClass

精灵类是游戏中所有精灵类的基类，是抽象类。

具有成员 `position`（包括精灵目前的 x、y 坐标和宽高）和 x、y 轴上的移动速度 `dx`、`dy`，以及精灵不同姿态的照片（实现了精灵移动方向不同时，显示的图片也不同），还有当前姿态的图片标号。

图片标号用枚举类型实现（`LEFT` = 0, `RIGHT` = 1, `UP` = 2, `DOWN` = 3），就可以做到文字和 int 数值的互化。

精灵类的构造函数是随机生成坐标。

除构造函数和析构函数外，`SpriteClass` 还提供了以下成员函数：

1. 返回精灵的坐标的 `getPosition()` 函数；
2. 调用 `Acllib.h` 绘制精灵的 `paintSprite()` 函数；
3. 判断两个精灵是否碰撞的 `collision()` 函数；
4. 计算两个精灵的距离的 `distance()` 函数；
5. 精灵移动的 `move()` 纯虚函数；
6. 返回精灵类型的 `getSpriteKind()` 的纯虚函数（返回值同样为枚举类型，包含目前涉及到的所有精灵类型）；
7. 返回该种精灵的不同的图片数量 `getImgN()` 函数；
8. 对越界精灵调整坐标的两个方案的 `positionCheck()` 和 `positionCheck2()` 函数，两个方案分别是禁止精灵越界和将精灵传送到到另一边的界内。
9. 
### 玩家精灵类 UserSpriteClass

玩家精灵类公开继承于精灵类 `SpriteClass`。

除了基类的成员以外，还加入了 `score`，表示玩家目前的得分。

除构造函数、析构函数和基类提供的函数外，`UserSpriteClass` 还提供了以下成员函数：

1. `getImgN()` 函数返回 4；
2. 设置坐标的 `setPosition()` 函数，这是保护成员函数，只有他和缩小药水类 `ShrinkPotionClass`（友元类）能够访问；
3. `getSpriteKind()` 函数返回 `USER_SPRITE`；
4. 根据 `Acllib.h` 捕获到的键盘按键来移动的 `move()` 函数，`move()` 以后会调用 `positionCheck()`。  
在移动前，如果有 `SHIFT_SPEED_UP` 宏定义，并且检测到 `Shift` 被按下，则移动速度会乘 2，这是作弊机制的实现。  
由于基类的 `move()` 函数和该 `move()` 函数参数不同，而玩家精灵类不需要该成员函数，但是需要实例化该类，因此必须实例化该虚函数，函数内容为空；
5. 给玩家加速的 `addSpeed()` 函数，额外功能中的加速正是靠此实现；
6. 返回目前玩家分数的 `getScore()` 函数；
7. 玩家抓捕精灵以后增加得分的 `addScore()` 函数；
8. 玩家移动以后结算与精灵相撞的 `settleScore()` 函数，参数为一个链表的引用，元素为指向自动精灵 `AutoSpriteClass` 类的指针，实现方法为：遍历链表，判断链表中每一个指针指向的精灵是否和玩家相撞；如果相撞，则通过 `getSpriteKind()` 判断该精灵的类型是否为恶魔精灵；如果是则返回 -1，否则将精灵的分数加到玩家的分数上，并对该精灵进行析构、释放内存；

### 自动精灵类 AutoSpriteClass

自动精灵类公开继承于精灵类 `SpriteClass`。除了基类的成员以外，还加入了 `score`，表示捕获该精灵的收益。

除构造函数、析构函数和基类提供的函数外，`AutoSpriteClass` 还提供了以下成员函数：

1. `getImgN()` 函数返回 4；
2. `getSpriteKind()` 函数返回 `AUTO_SPRITE`；
3. `move()` 函数，其实现为到达边界以后转向，然后将坐标移动 `(x+=dx, y+=dy)`。

### 聪明的自动精灵类 AutoCleverSpriteClass

聪明的自动精灵类公开继承于自动精灵类 `AutoSpriteClass`。

除构造函数、析构函数和基类提供的函数外，`AutoCleverSpriteClass` 还提供了以下成员函数：

1. `getImgN()` 函数返回 2；
2. `getSpriteKind()` 函数返回 `AUTO_CLEVER_SPRITE`；
3. `danger()` 函数，返回值为真，当且仅当该精灵与玩家精灵的距离小于“危险距离”（宏定义为 150）。
4. `move()` 函数，其实现为：如果 `danger()` 为真，则进行反向加速，走着正常移动。然后进行 `positionCheck()`；
5. 
### 恶魔精灵类 DemonSpriteClass

恶魔精灵类公开继承于自动精灵类 `AutoSpriteClass`。

除构造函数、析构函数和基类提供的函数外，`DemonSpriteClass` 还提供了以下成员函数：

1. `getImgN()` 函数返回 2；
2. `getSpriteKind()` 函数返回 `DEMON_SPRITE`；
3. `move()` 函数，其实现为：直接朝向玩家精灵移动。然后进行 `positionCheck2()`；

## 工具类及其继承类的实现

### 道具类ToolClass

道具类是游戏中各类道具类的基类，是抽象类。具有成员 `status`（是枚举类，包括 `INVALID` 不合法、`ONBOARD` 在场上、`INBAG` 在包里、`RELEASING` 正在释放中）、`position`（包括道具目前的 x、y 坐标和宽高），以及道具的照片。

除构造函数和析构函数外，`ToolClass`还提供了以下成员函数：

1. 返回道具的坐标的 `getPosition()` 函数；
2. 判断道具和精灵是否碰撞的 `collision()` 函数；
3. 返回释放道具的按键的纯虚函数 `int getVirtualKey()`；
4. 返回释放道具的按键的字符串的纯虚函数 `const char * getVirtualKeyChar()`；该函数在调用 `paintText()` 时直接作为字符串参数。
5. 返回道具下一次出现的时刻的纯虚函数 `getNextAppearTime()`；
6. 使道具出现在场上随机位置，将其状态由 `INVALID` 改为 `ONBOARD` 的函数 `appear()`;
7. 得到该道具，将其状态由 `ONBOARD` 改为 `INBAG` 的纯虚函数 `gain()`。由于这个函数涉及到将道具放到每种道具对应坐标，因此在基类设为纯虚函数，在各个子类中实现。
8. 释放道具的纯虚函数 `release()`；每个道具的释放过程不同，实现也不同；注意，由于认为炸弹有极高的权限，可以修改游戏中的任意状态，因此函数参数是直接将整个 `gameStatus` 的指针传过去。
9. 绘制道具的虚函数 `paint()`，注意这个虚函数在基类是有实现的，在非 `RELEASING` 状态下的绘制都是常规的，只有在 `RELEASING` 状态下的绘制才需要交给各子类函数实现，各子类也会在被调用前判断是否是 `RELEASING` 状态，如果不是则会调用 `ToolClass::paint()`；

注意，以上成员函数都是 `protected`的，只对友元类 `ToolManagerClass` 开放，这也是为了让 `ToolManager` 完全管理所有 `Tool`。

### 炸弹类 BombClass

炸弹类公开继承于工具类 `ToolClass`。他的作用是炸掉同行、同列的精灵。
炸弹类还增加了以下成员：

1. 下一次出现的时间 `nextAppearTime`，以 40ms 为一个单位；
2. 炸弹爆炸的效果照片 `explodeImg`、爆炸的音效 `explodeSound`；
3. 炸弹释放的时间 `PaintingReleasingTimeConst`，以 40ms 为一个单位；

除构造函数、析构函数和基类提供的函数外，`BombClass` 还提供了以下成员函数：

1. `getVirtualKey()` 函数返回字符 `Z`，用以和虚拟按键比对；
2. `getVirtualKeyString()` 函数返回字符串 `Z`，用以显示到屏幕上；
3. `getNextAppearTime()` 函数返回 `nextAppearTime`；
4. 得到该道具，将其状态由 `ONBOARD` 改为 `INBAG`，并将做坐标改为 `(20,500)` 的 `gain()` 函数。
5. 炸弹道具的释放函数 `release()`。需要修改状态为 `R`ELEASING`，播放音效，将渲染爆炸效果的次数（cpp 文件中的一个静态全局变量）归零，然后遍历杀死同行同列的精灵，最后根据迭代函数算出下一次炸弹出现的时间点。
6. 绘制炸弹效果的函数 `paint()`。仅在 `RELEASING` 状态下执行。即将橙色的纯色图片用 `putImageScale()` 拉伸为一个横条和一个竖条打印出来，实现炸弹的效果。打印一次以后将“渲染爆炸效果的次数”增加1，当其到达 `PaintingReleasingTimeConst` 时，则将 `status` 置为`INVALID`。

注意，和基类函数相同，以上成员函数都是 `protected` 的，只对友元类 `ToolManagerClass` 开放。

### 缩小药剂类 ShrinkPotionClass

缩小药剂类类公开继承于工具类 `ToolClass`。他的作用是使玩家缩小一段时间，更难被恶魔捕捉。

缩小药剂类还增加了以下成员：

1. 下一次出现的时间 `nextAppearTime`，以40ms为一个单位；
2. 药水的音效 `potionSound`；
3. 药水生效的时间 `PaintingReleasingTimeConst=400`，以 40ms 为一个单位，即 16s；
4. 
除构造函数、析构函数和基类提供的函数外，`BombClass` 还提供了以下成员函数：

1. `getVirtualKey()` 函数返回字符 `C`，用以和虚拟按键比对；
2. `getVirtualKeyString()` 函数返回字符串 `C`，用以显示到屏幕上；
3. `getNextAppearTime()` 函数返回 `nextAppearTime`；
4. 得到该道具，将其状态由 `ONBOARD` 改为 `INBAG`，并将做坐标改为 `(125,500)`的 `gain()` 函数。
5. 药水道具的释放函数 `release()`。需要修改状态为 `RELEASING`，播放音效，将渲染药水效果的次数（cpp 文件中的一个静态全局变量）归零，将玩家精灵的大小设为原来的一半（因此 `ShrinkPotionClass` 是 `UserSpriteClass` 的友元类，能调用其不公开的 `setPosition()` 函数），最后根据迭代函数算出下一次药水出现的时间点。
6. 绘制药水效果的函数 `paint()`。仅在 `RELEASING` 状态下执行。由于药水释放过程中只是修改了玩家精灵的大小不需要额外的绘制，将“渲染药水效果的次数”增加 1，当其到达 `PaintingReleasingTimeConst` 时，则将 `status` 置为 `INVALID`，并将玩家精灵的大小设为此时的两倍。

注意，和基类函数相同，以上成员函数都是 `protected` 的，只对友元类 `ToolManagerClass` 开放。

### 道具管理器类ToolManagerClass

`ToolManagerClass` 用于实现游戏流程中所有与道具交互的过程。他拥有一个成员 `toolList`，装了目前已经存在的两种道具。

除构造函数、析构函数和基类提供的函数外，`BombClass`还提供了以下成员函数：

1. 根据当前时间，检查是否有道具需要被放到场上的 `putToolOnBoard()` 函数；
2. 玩家移动以后需要结算获得的道具，这里将玩家的坐标传给 `ToolManagerClass` 的 `settleTool()` 函数来进行结算；
3. 玩家按下按键，将按键传给 `use()` 函数，让 `ToolManagerClass` 判断应该释放哪一个对应的道具；
4. `paint()` 函数负责遍历所有道具，调用他们的 `paint()` 函数。

## 游戏资源、元素的实现

一切图片、音乐等都可以调用 `Acllib.h` 提供的函数。

1. 对于音乐，可创建 `ACL_Sound` 类，调用 `loadSound()` 函数即可将其与音乐文件绑定，然后调用 `playSound()` 和 `stopSound()` 可以实现音乐的播放和关闭；
2. 对于图片，可创建 `ACL_Image` 类，调用 `loadImage()` 函数即可将其与 bmp 文件绑定，然后调用putImage () 和 putImageScale() 可以实现显示图片；这也是显示一切图片元素，包括精灵的各个形态、背景图所调用的函数。
所有ACL_Sound和ACL_Image变量装在名为gameResource的namespace中。
3. 对于在窗口上显示文字，可以调用paintText() 即可在指定位置输出指定字符串。可在输出前调用setTextSize(), setTextColor(), setTextBkColor()来调整字体、大小、颜色。
4. 对于处理鼠标移动的情况，将鼠标移动的事件写为一个mouseEvent() 函数中，然后程序开始时执行registerMouseEvent(mouseEvent) 即可捕捉鼠标的移动、点击事件。
5. 对于按钮，可以绘制文本框了以后，通过测量文本框的坐标，在鼠标移动事件里写如果鼠标在这个范围并且发生了左键单击事件，则视为点击按钮，执行对应的操作。为统一维护，将每个按钮的“在这个范围”写为了一个bool函数，并且装在mouseCoordinate 名称空间中。  
本游戏中涉及到的按键有：
* MUSIC按钮：控制背景音乐和音效的开关
* EXIT按钮：退出游戏
* BEGIN按钮：（仅WELCOME_STATUS）进入游戏
* PAUSE按钮：（仅GAMING_STATUS和PAUSE_STATUS）暂停/继续游戏
* GAME OVER按钮：（仅GAME_OVER_STATUS）开始下一轮游戏
在上面的基础上还可以进行改进：在鼠标落入范围但没有进行点击时，绘制该文本框时进行反色（交换文字颜色和背景颜色），实现了鼠标落在按钮上（但没有进行点击）时给用户的反馈。
6. 对于处理有键盘按键的情况，将键盘按键的事件写为一个keyEvent() 函数，然后程序开始时执行registerkeyEvent(keyEvent) 即可捕捉键盘的按键事件。该程序中主要是捕捉了方向键和工具对应的释放按键。处理的方法是直接将对应的按键传给对应的函数。  
本游戏涉及到的操作有：
* 玩家移动，交给UserSpriteClass提供的函数
* 使用道具，交给ToolManagerClass提供的函数
7. 对于处理时间相关的情况，将多个时间任务写为一个timerEvent(int id) 函数（每个id对应一项时间任务，用if分开），然后程序开始时执行registerTimerEvent(timerEvent); startTimer(0, 1000); startTimer(1,40); 即可定时执行任务，任务0每秒执行一次，任务1每40ms执行一次。  
在游戏中，涉及到的操作有：
* 每1s生成一个精灵。先判断恶魔数量是否和分数匹配，如果不，则生成恶魔并装进精灵链表std::list<SpriteClass*>，并将分数的颜色变红；否则按概率生成一个AutoSpriteClass或AutoCleverSpriteClass，并装进精灵链表，并将分数的颜色变黑（实现分数闪烁的效果）。装进链表的操作和此后精灵的操作都是由虚函数（动态多态）来实现，统一管理。
* 每40ms自动精灵移动一次，重新绘制一次页面。具体的来说：先让时间+1，然后调用toolManager的putToolOnBoard() 函数讨论在这个时间点是否需要生成道具；然后遍历精灵链表，执行move() 函数（注意由于链表中装了三种精灵，这里的move() 函数需要用虚函数在各类中分别实现，调用的时候统一调用）。在这个过程中一旦有自动精灵与玩家发生碰撞，则需要在所有自动精灵移动完以后，让玩家主动结算和自动精灵的碰撞（调用 userSprite->settleScore() 函数）。如果结算的过程中出现玩家和恶魔碰撞，则进入GameOver() 函数。

## 游戏流程的实现
游戏中的所有状态都被包含在一个GameStatusStruct结构体中，这样是为了整合这些状态，并且可以用构造函数和析构函数来集中管理这些状态。这其中包含了：

* musicSwitchMode，存储目前音乐的开关状态；
* exitSwitchMode = 0，存储EXIT按键当前的状态（鼠标是否在之上）；
* progress，存储游戏流程，在下面会详细说道；
* scoreColor，存储分数的颜色（默认为黑）；
* demonSpriteN，存储已经召唤的恶魔的数量；
* gameClock，存储游戏时钟，以40ms为单位；
* userSprite，一个指针，指向用户精灵的对象；
* autoSpriteList，一个std::list，链表元素为每一个自动精灵的指针；
* toolManager，一个指针，指向工具管理器。

游戏主要分为四个流程：欢迎界面、游戏进行界面、暂停界面和游戏结束界面。GameStatusStruct中的progress以枚举量（INVALID_STATUS, WELCOME_STATUS, GAMING_STATUS, PAUSE_STATUS, GAME_OVER_STATUS）存储了当前调度界面。

在每个界面的按钮不同，于是mouseEvent() 函数判断光标是否在某按键上时，也需要判断该按键是否应该存在于当前状态上。同理，键盘按键也需要进行类似判断。

0.	程序从Setup() 开始执行，执行了一系列初始化以后进入welcome() 函数。
1.	welcome() 函数new了游戏状态、修改了游戏进程为WELCOME_STATUS、绘制了欢迎界面的图片和按钮以后即可结束。由于进入游戏是靠点击按钮，跳转到下一个阶段的操作交给mouseEvent() 函数。 
2.	下一个阶段是GAMING_STATUS，由beginGame() 开始，修改游戏进程、初始化userSprite、toolManager以后，启动时钟事件、键盘事件即可结束。剩下的操作，自动精灵的移动交给timerEvent() 函数中对应的操作，而玩家的移动交给keyEvent() 函数中捕获。
3.	GAMING_STATUS和PAUSE_STATUS可以通过单击PAUSE按钮来切换。
4.	当触发玩家精灵和恶魔精灵碰撞时，调用gameOver() 函数。该函数修改游戏进程为 GAME_OVER_STATUS，然后停止计时活动（由于绘制函数在计时函数里，这样界面就不会进行重新绘制了）、绘制GameOver按钮。跳到下一个状态由于是靠单击按钮触发，因此也交给了mouseEvent() 函数。同时，mouseEvent() 保证鼠标在GameOver按钮上时会变色，不在其上时会变回来。
5.	当鼠标左键单击GameOver按钮时，程序析构gameStatus，同时跳转到beginGame() 函数，重新构建gameStatus，游戏从WELCOME_STATUS重新开始。
