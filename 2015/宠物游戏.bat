::变量：
::一、关于工作：
::set job=
::set salary=
::set jobDiploma=
::set jobEnergy=
::记者  教练  律师  警察  漫画家  编辑  摄影家  教官  法官  老师  建筑师  歌手  演员  指挥家  词曲家  公务员  售货员

::二、关于学习
::set subject=
::set fee=
::set studyDiploma=
::set studyKnowledge=

::三、关于吃饭
::set dish=
::set dishPrice=
::set dishHungry=
::set dishKnowledge=

::四、个人数据（按显示顺序排序）：    name	day		money	diploma	energy	hungry
::对应中文：						姓名	日期	金币	学历	体力	饱食度

::五、其他临时变量： var  var2 ...... file  place  choice  page   slprice  stockchange  scolor  stocks  sprice  buy  buy2  command

::六、测试方法：在changeplace处输入d，即可进入debug模式，输入命令直接执行，输入exit返回到changeplace

::七、更新历记录
::v1.0---------------------------------------2015.5.24
::v1.1---------------------------------------2015.7.7
::	增加股票功能
:: 	增加debug模式
:: 	增加研究生
::	调整数据，修复几个bug，美化界面
	
::八、仍没有解决的bug：
::pause后如果敲击空格，会导致choice发出警报声



@echo off&setlocal enabledelayedexpansion
ver | find "5.4" >nul 2>nul && echo 本游戏不支持Windows XP系统，请升级系统&&pause&&exit

::变量设置
set save=存档
set school=学校
set office=工作
set home=回家
set restaurant=餐馆
set stockex=证券交易所

set jobs=5

set job1=搬运工
set salary1=10
set jobDiploma1=0
set jobEnergy1=50

set job2=木匠
set salary2=15
set jobDiploma2=40
set jobEnergy2=45

set job3=园丁
set salary3=20
set jobDiploma3=100
set jobEnergy3=45

set job4=清洁工
set salary4=20
set jobDiploma4=500
set jobEnergy4=35

set job5=保安
set salary5=40
set jobDiploma5=2000
set jobEnergy5=40

set subjects=6

set subject1=幼儿园
set fee1=0
set studyDiploma1=0
set studyKnowledge1=5

set subject2=小学
set fee2=0
set studyDiploma2=20
set studyKnowledge2=10

set subject3=初中
set fee3=0
set studyDiploma3=80
set studyKnowledge3=40

set subject4=高中
set fee4=10
set studyDiploma4=200
set studyKnowledge4=100

set subject5=本科
set fee5=50
set studyDiploma5=500
set studyKnowledge5=500

set subject6=研究生
set fee6=50
set studyDiploma6=5000
set studyKnowledge6=1000

set dishes=3

set dish1=米饭
set dishPrice1=5
set dishHungry1=50
set dishKnowledge1=0


set dish2=水果
set dishPrice2=10
set dishHungry2=20
set dishKnowledge2=10


set dish3=鸡
set dishPrice3=40
set dishHungry3=100
set dishKnowledge3=50

:welcome

cls
color 57
title 宠物游戏 v1.1
echo.&echo.&echo.&echo.&echo.
echo 				欢迎来到宠物游戏！
echo			新建用户请按“1”		已有存档请按“2”
echo			查看更新历史请按“3”
choice /c 123 /n
if errorlevel 3 goto updhistory
if errorlevel 2 goto load
goto create

:create

cls
echo.&echo.&echo.&echo.&echo.
set /p name=您的姓名是：
if "%name%"=="" goto create
set energy=100
set hungry=100
set day=1
set diploma=0
set money=0
set slprice=0
set sprice=2%random:~-1,1%
set stocks=0
::股票定价在20-29范围
goto home

:load

cls
echo.&echo.&echo.
if not exist *.lyh (echo.&echo.&echo 没有存档，即将创建角色&pause&goto create)
echo 存档名		用户名		金钱		经验	体力	饱食度
for /f %%i in ('dir /b *.lyh')  do (
	for /f "tokens=1,2,3,4,5" %%a in (%%i)  do (echo %%i		%%a		%%b		%%c	%%d	%%e)
)
echo 请输入存档名并敲击回车（无需输入.lyh后缀）
echo 如需查看更多信息，请输入“*”（不包括引号）
set /p file=
if %file%==* (
 	cls
	echo.&echo.&echo.
	echo 存档名		用户名		股票数		昨日股价	今日股价
	for /f %%i in ('dir /b *.lyh')  do (
		for /f "tokens=1,6,7,8" %%a in (%%i)  do (echo %%i		%%a		%%b		%%c		%%d)
	)
	echo 请输入存档名并敲击回车（无需输入.lyh后缀）
	echo 如需查看更多信息，请输入“*”（不包括引号）
	set /p file=
)
if exist %file%.lyh  (
	for /f "tokens=1,2,3,4,5,6,7,8" %%a in ( %file%.lyh) do (
		set name=%%a
		set money=%%b
		set diploma=%%c
		set energy=%%d
		set hungry=%%e
		set stocks=%%f
		set slprice=%%g
		set sprice=%%h
	)
	goto home
) else (
	echo 输入有误，请重新输入
	pause
	goto load
)

:home

cls
title %name%--在家
echo.&echo.&echo.
echo					%name%  的第%day%天
echo.
if %sprice% leq 0 (
	echo				抱歉，股票大跌，已经亏空
	set sprice=2%random:~-1,1%
	set stocks=0
	set slprice=0
	timeout /t 3 >nul
)
echo.
echo				金币：	%money%	经验：	%diploma%
echo.			
echo				体力：	%energy%	饱食度：%hungry% 
echo.
echo				去学校请按 1 	去工作请按    2
echo				去餐馆请按 3	去证券所请按  4
echo				睡觉请按   5
echo				存档请按   6	改名请按      7
choice /c 1234567 /n
if %errorlevel%==1 set place=school
if %errorlevel%==2 set place=office
if %errorlevel%==3 set place=restaurant
if %errorlevel%==4 set place=stockex
if %errorlevel%==5 goto sleep
if %errorlevel%==6 goto save
if %errorlevel%==7 goto  rename
cls
echo.&echo.&echo.
echo				去!%place%!的路上 …
timeout /t 1 >nul
cls
echo.&echo.&echo.
echo				去!%place%!的路上 ……
timeout /t 1 >nul
goto %place%

:sleep
cls
echo.&echo.&echo.
echo				睡觉ing …
timeout /t 1 >nul
cls
echo.&echo.&echo.
echo				睡觉ing ……
timeout /t 1 >nul
cls
echo.&echo.&echo.
echo				睡觉ing ………
timeout /t 1 >nul
set energy=100
set /a day+=1
set slprice=%sprice%
::slprice指stock_last_price
if %sprice% leq 10 set /a sprice+=2
set /a sprice=%sprice%+%random%%%11-5
::每次股票浮动在5之内
goto home

:save

cls
echo.&echo.&echo.&echo.&echo.
set /p file=请输入存档文件名并敲击回车（无需输入后缀）
if exist %file%.lyh (
	echo 您将要覆盖一个存档，如确定，输入ok并敲击回车
	echo 如返回，请输入其他字符并敲击回车
	set /p choice=
	if not /i !choice!==ok goto save
)
echo	%name%	%day%	%money%	%energy%	%hungry%	%stocks%	%slprice%	%sprice% >%file%.lyh 2>nul
::		姓名			天		金钱			精力			饱食度		股票数		昨日股价		今日股价
if not exist %file%.lyh (echo 文件名非法，请重新输入&pause&goto save)
cls
echo.&echo.&echo.&echo.&echo.
echo 			存档完毕。请按任意键继续游戏……
pause>nul
goto changeplace

:changeplace

echo.
echo			去学校请按 1 	去工作请按    2
echo			去餐馆请按 3	去证券所请按  4
echo			回家请按   5
choice /c 12345d /n
if %errorlevel%==1 set place=school
if %errorlevel%==2 set place=office
if %errorlevel%==3 set place=restaurant
if %errorlevel%==4 set place=stockex
if %errorlevel%==5 set place=home
if %errorlevel%==6 ( cls&goto debug )
cls
echo.&echo.&echo.
echo				去!%place%!的路上 …
timeout /t 1 >nul
cls
echo.&echo.&echo.
echo				去!%place%!的路上 ……
timeout /t 1 >nul
color 57
goto %place%

:rename

set /p var=请输入新姓名并敲击回车
if "%var%"=="" goto rename
set name=%var%
goto home

:office

set page=1
title %name%--办公室

:officeloop

cls
echo.&echo.&echo.
echo			金币：	%money%	经验：	%diploma%
echo.			
echo			体力：	%energy%	饱食度：	%hungry% 
echo.
echo.				第%page%页
echo 序数	工作	工资		所需经验		消耗体力、饱食度
set var=1

:loop
set /a var2=%page%*9-9+%var%
 if defined  job%var2%   (
	echo %var%	!job%var2%!	!salary%var2%!		!jobDiploma%var2%!			!jobEnergy%var2%!
) else (
	goto choosejob
)
	set /a var+=1
if not %var%==10 goto loop

:choosejob
choice /n /c 1234567890ad /m 请输入想要的工作的序数(翻到前一页请按a，翻到后一页请按d，去其他地方请按0)
set choice=%errorlevel%
if %choice%==10 goto changeplace
if %choice%==11 (
	if %page%==1 (
		echo 已是第一页
		pause
	)  else (
		set /a page-=1
	)
	goto officeloop
)
if %choice%==12 (
	set /a b=%page%*9+1
	if defined job!b! (
		set /a page+=1
	)  else (
		echo 已是最后一页
		pause
	)
	goto officeloop
)
if %choice% leq %jobs% if %choice% gtr 0 goto startwork

:startwork

if %diploma%	lss	!jobDiploma%choice%!	(echo 经验不够，请努力学习&pause&goto office)
if %energy%	lss	!jobEnergy%choice%!		(echo 体力不够，请回家休息&pause&goto office)
if %hungry%	lss	!jobEnergy%choice%!		(echo 饱食度不够，请去餐馆吃饭&pause&goto office)
cls
echo.&echo.&echo.
echo				工作ing …
timeout /t 1 >nul
cls
echo.&echo.&echo.
echo				工作ing ……
timeout /t 1 >nul
set /a energy-=!jobEnergy%choice%!
set /a hungry-=!jobEnergy%choice%!
set /a money+=!salary%choice%!
goto office

:school

cls
title %name%--学校
echo.&echo.&echo.
echo			金币：	%money%		经验：	%diploma%
echo.			
echo			体力：	%energy%		饱食度：%hungry% 
echo.
echo 序数	科目	学费	所需经验	增加经验	消耗体力、饱食度
for /l %%a in (1,1,6) do (echo %%a	!subject%%a!	!fee%%a!	!studyDiploma%%a!		!studyKnowledge%%a!		30)
choice /n /c 123450 /m 请输入想学习的科目的序号（想去其他地方请按0）
if errorlevel 6 goto changeplace
set choice=%errorlevel%
goto startstudy

:startstudy

if %diploma%  lss	!studyDiploma%choice%!	(echo 经验不够，请努力学习其他科目&pause&goto school)
if %energy%   lss	30	(echo 体力不够，请回家休息&pause&goto school)
if %hungry%   lss	30	(echo 饱食度不够，请去餐馆吃饭&pause&goto school)
if %money%   lss	!fee%choice%!		(echo 钱不够交学费，请努力挣钱&pause&goto school)
cls
echo.&echo.&echo.
echo				学习ing …
timeout /t 1 >nul
cls
echo.&echo.&echo.
echo				学习ing ……
timeout /t 1 >nul
set /a energy-=30
set /a hungry-=30
set /a money-=!fee%choice%!
set /a diploma+=!studyKnowledge%choice%!
goto school

:restaurant

cls
title %name%--餐馆
echo.&echo.&echo.
echo			金币：	%money%	经验：%diploma%
echo.			
echo			体力：	%energy%	饱食度：	%hungry% 
echo.
echo 序数		菜名		价格		增加经验	增加饱食度
for /l %%a in (1,1,3) do (echo %%a		!dish%%a!		!dishPrice%%a!		!dishKnowledge%%a!		!dishHungry%%a!)
choice /n /c 1230 /m 请输入想食用的菜品的序号（想去其他地方请按0）
if errorlevel 4 goto changeplace
set choice=%errorlevel%
goto starteat

:starteat

if %money%   lss	!dishPrice%choice%!  (echo 钱不够呀，请努力挣钱&pause&goto restaurant)
cls
echo.&echo.&echo.
echo				吃饭ing …
timeout /t 1 >nul
cls
echo.&echo.&echo.
echo				吃饭ing ……
timeout /t 1 >nul
set /a hungry+=!dishHungry%choice%!
set /a money-=!dishPrice%choice%!
set /a diploma+=!dishKnowledge%choice%!
if %hungry% gtr 100 set hungry=100
goto restaurant

:stockex

title %name%--证券交易所
cls
if %sprice% leq 0 (
	set stockchange=
) else (
	if %slprice% leq 0 (
		set stockchange=
	) else (
		if %sprice% lss %slprice% (
			set stockchange=↓
			color 27
		) else (
			if %sprice% == %slprice% (
				set stockchange=
			) else (
				set stockchange=↑
				color 47
			)
		)
	)
)
set /a var=%money%/%sprice%
echo.&echo.&echo.
echo			现有金钱：		%money%
echo			昨日股价：		%slprice%
echo			今日股价：		%sprice%
echo			您拥有的股票数：	%stocks%
echo			您能够买的股票数：	%var%
echo			请输入购买的数目并敲击回车（如需卖出，请输入负数；想去其他地方请按0）
set /p buy=
set /a "buy2=%buy%"
if not "%buy%"=="%buy2%"  ( echo 输入有误，请重新输入&pause&goto stockex )  
if %buy%==0 goto changeplace
if %buy% gtr %var% (echo 您的钱太少了，买不了这么多股票&pause&goto stockex)
if -%buy% gtr %stocks%  (echo 您没有这么多股票&pause&goto stockex)
set /a var2=%money%-%sprice%*%buy%
set /a var3=%stocks%+%buy%
echo			购买（卖出）后，您将有：
echo			金钱：	%var2%
echo			股票：	%var3%
set /p choice=如无误，请输入ok再敲击回车以确认
if /i "%choice%"=="ok" (
	set money=%var2%
	set stocks=%var3%
	echo 操作完成。
) else (
	echo 操作已取消。
)
pause
goto stockex

:debug
title debug模式
set /p command=请输入命令(输入exit退出)：
if "%command%"=="exit" (goto changeplace)
%command%
goto debug

