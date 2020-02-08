:: 本程序用以将软媒软件改成中文，并删除无用软件
@echo off
del /q  3gmanager.exe  burnmaster.exe ithome.exe mydesk.exe mytime.exe >nul 2>nul
del /q  pcmaster.exe pcmasterdata.dll pcmastersvc.exe rmup.exe softmastergreen.dll winstart.exe >nul 2>nul
del /q  starttweaker.exe winguard.dll winguard.exe winguard_x64.dll winguard_x64.exe >nul 2>nul
rd /s /q config
rd /s /q plugins
for /f "tokens=1,2 delims=：，。" %%a in (读我.txt) do (
move /y %%a %%b.exe
)

