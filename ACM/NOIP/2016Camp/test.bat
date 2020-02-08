@echo off & setlocal enabledelayedexpansion
for /f "delims=." %%a in ('dir /b *.exe') do ( 
set filename=%%a
)
for /l %%a in (1,1,10) do (
	echo ---------------
	echo Test %%a:
	%filename%.exe  < %filename%%%a.in
	echo.
	type %filename%%%a.out
	echo.
	pause
	echo.
)