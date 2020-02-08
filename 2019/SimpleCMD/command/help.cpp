#include"help.h"

using namespace std;

const string helpDocument =
R"6(查看帮助命令。

cd D:\            更改当前文件夹到 D:\
cd cpp            更改当前文件夹到 cpp 文件夹
cd ..             更改当前文件夹到上一级
tree              显示当前文件夹的文件、子文件夹和大小
tree D:\          显示 D:\ 的文件、子文件夹和大小
exit              退出程序
help              显示该帮助
<Command> >a.txt  将 <Command> 的输出重定向到 a.txt
<Ohter Command>   调用 CMD 执行命令

项目地址： https://github.com/lyh543/SimpleCMD
)6";


//帮助命令
int Command_HELP(ostream& out, const vector<string>& argument)
{
	out << helpDocument << endl;
	return 0;
}
