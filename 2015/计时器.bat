title 计时器
: start
echo 可以输入具体时间，如“08:00”“20:00”
echo 也可以输入倒计时，在最后加入“h”表示时,或“m”表示分
set /p want=请输入……
if %want:~-1% == h goto h
if %want:~-1% == m goto m
set nowh=%time:~0,2%
set nowm=%time:~3,2%
set nows=%time:~6,2%
set wanth=%want:~0,2%
set wantm=%want:~3,2%
set /a daojishi=(%wanth%-%nowh%)*3600+(%wantm%-%nowm%)*60-%nows%
:: 计算和现在的时间差
goto daojishi
: h
set /a daojishi=3600*%want:~0,-1%
:: 计算和现在的时间差
goto daojishi
: m
set /a daojishi=60*%want:~0,-1%
:: 计算和现在的时间差
: daojishi
echo 倒计时%daojishi%秒
ping /n  %daojishi% 127.0.0.1 >nul
:: 暂停
echo msgbox "%want%已经到了！",,"计时器" >tishi.vbs
:: 调用vbs显示对话框
start tishi.vbs
ping /n 2 127.0.0.1 >nul
del tishi.vbs /q
goto start
