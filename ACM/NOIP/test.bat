@echo off & setlocal enabledelayedexpansion

for /f "delims=." %%a in ('dir /b *.exe') do ( 
	set filename=%%a
)

echo Answer Tester
title Answer Tester
echo Execute Filename: %filename%
echo.

for /f "delims=." %%a in ('dir /b *.in') do ( 
	echo ---------------
	echo Test %%a:
	%filename%.exe  < %%a.in > temp.out
	fc /w %%a.out temp.out >nul
	if errorlevel 1 (
		echo.
		type temp.out
		echo.
		echo.
		type %%a.out
	) else (
		echo AC
	)
	
	echo.
	pause
	echo.	
)