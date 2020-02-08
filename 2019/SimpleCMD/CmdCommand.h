#pragma once
#include<iostream>
#include<fstream>
#include<sstream>
#include<iomanip>
#include<Windows.h>
#include<time.h>
#include<string>
#include<vector>
#include<map>
#include<cassert>
#include"Command/cd.h"    //更改当前目录
#include"Command/exit.h"  //退出
#include"Command/help.h"  //帮助命令
#include"Command/tree.h"  //显示当前文件夹的所有子文件夹及文件

//错误返回值的含义
#define COMMAND_ERROR -1
#define REDIRECT_ERROR -2
#define ARGUMENT_ERROR -3
#define PRIVILEDGE_ERROR -4

using namespace std;

//类似于命令提示符中，显示当前文件夹，并提示进行输入的功能
void WaitUserInput();

//用户输入命令，进行初步处理（计时、判断语法错错、发送给对应的命令函数）
int UserInputCommand(const string& command);