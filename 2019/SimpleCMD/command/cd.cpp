#include"cd.h"

using namespace std;

//更改当前目录
int Command_CD(ostream& out, const vector<string>& argument)
{
    string path;
    if (argument[0][0] == '"')
    {
        size_t pathLength = argument[0].length() - 2;
        path = argument[0].substr(1, pathLength);
    }
    else
    {
        path = argument[0];
    }
    if (!SetCurrentDirectory(path.c_str()))
    {
        out << "无法更改当前文件夹到 " << path << "（错误代码：" << GetLastError() << "）。\n";
        return GetLastError();
    }
	return 0;
}

