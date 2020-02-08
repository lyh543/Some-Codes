@echo off
setlocal enabledelayedexpansion
title 求质数
set /p n=要求多少以内的质数？输入0则从已有的质数表中查找质数
if %n%==0 goto find
set timeBegin=%time:08=8%

::算法开始

echo 2 > 质数表.txt
for /l %%b in (3,2,%n%) do (
	if not "!array%%b!"=="1" (
		echo %%b >> 质数表.txt
		set /a start=%%b*%%b
		set /a step=2*%%b
		for /l %%a in (!start!,!step!,%n%) do (set array%%a=1)	
	)
)

::算法结束

set timeEnd=%time:08=8%
::获取结束时间

set timeBegin=%timeBegin:09=9%
set timeEnd=%timeEnd:09=9%
for /f "tokens=1-8 delims=:. " %%a in ("%timeBegin% %timeEnd%") do (
	set /a "secondThrough=3600*(%%e-%%a)+60*(%%f-%%b)+ (%%g-%%c)"
	set /a "milliSecondThrough=10*(%%h-%%d)"
)
echo 已找完,用时%secondThrough%秒%milliSecondThrough%毫秒
pause

:find

if not exist 质数表.txt echo 没有找到质数表，自动进入“求质数”模式&set tbeg=%time%&goto main
set /p find=给个数呀?!
if %find% lss 2 echo %find%既不是质数，也不是合数
findstr /x /c:"%find% " 质数表.txt >nul 2>nul
if errorlevel 1 (echo %find%是合数) else (echo %find%是质数)
pause
cls
goto find