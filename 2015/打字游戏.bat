@echo off
title 打字游戏
::if %time:~0,2% gtr 22 echo 凌晨还玩游戏,快睡觉&shutdown /s&pause&exit
if %time:~0,2% lss 6 echo 凌晨还玩游戏,快睡觉&shutdown /s&pause&exit
: game
choice /m 欢迎进入打字游戏!按1进入字母模式.按2进入计算模式 /c 12
set e= %errorlevel%
set n=0
cls
echo.
echo.
echo.
echo.
echo.
echo    				倒计时
ping /n 2 127.0.0.1>nul
pause
echo.
echo.
echo.
echo.
echo.
echo					3
ping /n 2 127.0.0.1>nul
echo.
echo.
echo.
echo.
echo.
echo					2
ping /n 2 127.0.0.1>nul
echo.
echo.
echo.
echo.
echo.
echo					1
ping /n 1 127.0.0.1>nul
set tbeg=%time%
goto %e%
: 1
set /a ran=%random%%%26+1
for /f "tokens=%ran%" %%a in ("Q W E R T Y U I O P A S D F G H J K L Z X C V B N M") do set ranal=%%a
cls
echo.
echo.
echo.
echo.
echo.
choice /m 请按---------------------------------- /c %ranal%
set /a n+=1
if 10==%n% (goto end) else (goto 1)
:2
set /a n+=1
set /a a1=%random%%%10+1
set /a a2=%random%%%10+1
set /a calc=%random%%%4+1
for /f "tokens=%calc%" %%a in ("+ - * /") do set symbol=%%a
set /a ans=%a1%%symbol%%a2%
:3
cls
set /p cho=%a1% %symbol% %a2%
if not %cho%==%ans% echo 答错了&goto 3
if 10==%n% (goto end) else (goto 2)
:end
set tend=%time%
set /a ms=(%tend:~0,2%-%tbeg:~0,2%)*360000+(%tend:~3,2%-%tbeg:~3,2%)*6000+(%tend:~6,2%-%tbeg:~6,2%)*100+%tend:~9,2%-%tbeg:~9,2%
if exist type%e%.lyh (
	for /f %%a in (type%e%.lyh) do (
		if %%a gtr %ms% (
			echo %ms%>type%e%.lyh
			attrib +h type%e%.lyh
			echo 您刷新了记录!您的成绩是%ms%毫秒/个
		)
		else(
			echo 您的成绩是%ms%毫秒/个
			echo 您的记录是%%a毫秒/个
		)
	)
) else (
	echo %ms%>type%e%.lyh
	attrib +h type%e%.lyh
	echo 您的成绩是%ms%毫秒/个
)
choice /m 再来一局？
if not errorlevel 2 cls&goto game