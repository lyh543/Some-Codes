#include"CmdCommand.h"

//#define ENABLE_ESCAPE_MODE
using namespace std;

const int maxDirectoryStringLength = 1000;
const int maxCommandStringLength = 1000;

//用 std::map 将字符串和函数对应起来，就可以实现用字符串识别函数，从而避免用一万个 if 拉到底
const map<string,
	int (*) (ostream&, const vector<string>&) > commandString2Function =
{
{"cd", Command_CD},
{"tree", Command_TREE},
{"exit", Command_EXIT},
{"help", Command_HELP}
};

//对命令进行解析，包括识别命令、识别参数，其中 int (*&commandFunction)(ostream&, const vector<string>&) 是函数指针的引用
int AnalyseInputCommand(const string& commandStringFull, int (*&commandFunction)(ostream&, const vector<string>&), vector<string>& argumentVector, string& outputFileName);


//类似于命令提示符中，显示当前文件夹，并提示进行输入的功能
void WaitUserInput()
{
	char currentDirectoryString[maxDirectoryStringLength];
	char command[maxCommandStringLength];
	while (true)
	{
		int dwRet = GetCurrentDirectoryA(maxDirectoryStringLength, currentDirectoryString);

		if (dwRet == 0)
		{
			cout << "无法获取当前文件夹（错误代码：" << GetLastError() << "）。程序即将退出。\n\n";
			system("pause");
			return;
		}

		cout << currentDirectoryString << ">";
		cin.getline(command, maxCommandStringLength);
		UserInputCommand(command);
	}
	return;
}

//用户输入命令，进行初步处理（计时、判断语法错误、发送给对应的命令函数）
int UserInputCommand(const string& commandString)
{
	int startTime = clock();  //开始计时

	int returnValue = 0;

	string outputFileName;
	vector<string> argumentVector; //将每个参数解析为为一个 string，将原命令解析为 string 数组
	ostream * outStreamPointer = &cout;
	ofstream fileOutStream;
	int (*commandFunction)(ostream&, const vector<string>&) = NULL;

	//对命令进行解析，包括识别命令、识别参数
	returnValue = AnalyseInputCommand(commandString, commandFunction, argumentVector, outputFileName);
	if (returnValue == COMMAND_ERROR)
	{
		returnValue = system(commandString.c_str());
	}
	else if (returnValue == ARGUMENT_ERROR)
	{
		cout << "参数格式不正确。\n\n";
		returnValue =  ARGUMENT_ERROR;
	}
	else
	{
		//创建输出文件并将输出流指向文件
		if (!outputFileName.empty())
		{
			fileOutStream.open(outputFileName);
			if (!fileOutStream.is_open()) //无法打开文件？
			{
				cout << "无法打开输出文件 " << outputFileName << "。请检查是否有写入权限。\n\n";
				returnValue = REDIRECT_ERROR;
			}
			else
			{
				outStreamPointer = &fileOutStream; //将 outStreamPointer 指向文件输出流，而不是标准输出
			}
		}

		//执行命令
		returnValue = commandFunction(*outStreamPointer, argumentVector);
	}
	//停止计时
	int endTime = clock();
	cout << "用时 " << double((endTime) - double(startTime)) / CLOCKS_PER_SEC << " 秒。" << endl;
	return returnValue;
}

int AnalyseInputCommand(const string& commandStringFull, int (*&commandFunction)(ostream&, const vector<string>&), vector<string>& argumentVector, string& outputFileName)
{
	istringstream commandStringStream(commandStringFull);
	outputFileName.clear();
	string command;

	commandStringStream >> command;

	//在 map 中寻找命令
	map<string,
		int (*) (ostream&, const vector<string>&) >::const_iterator commandString2FunctionIterator =
		commandString2Function.find(command);
	if (commandString2FunctionIterator == commandString2Function.end()) //没有找到这条命令，则调用系统执行命令
	{
		return COMMAND_ERROR;
	}

	//commandFunction 即是命令对应的函数
	commandFunction = (commandString2FunctionIterator->second);

	//下面开始对参数进行解析
	//本来是支持用 "\" 符号转义，但是发现 cmd 本身不支持，所以改回来了
	//支持的话，如下代码会有歧义：tree D:\ >a.txt
	//其中 \ 后的空格不应该被视为“被转义”了
	string argumentTemp("");
	char charTemp;
#ifdef ENABLE_ESCAPE_MODE
	bool escapeMode = false; //转义模式，为 true 表示上一个字符是转义符号 "\"
#endif
	bool quoteMode = false; //引号模式，为 true 表示一个引号还没有结束

	while (commandStringStream.get(charTemp) && charTemp != '\0')
	{
#ifdef ENABLE_ESCAPE_MODE
		if (escapeMode)
		{
			argumentTemp += charTemp;
			escapeMode = false;
		}
		else 
#endif 
		if (charTemp == '\"')
		{
			argumentTemp += charTemp;
			quoteMode = !quoteMode;
		}
#ifdef ENABLE_ESCAPE_MODE
		else if (charTemp == '\\')
		{
			escapeMode = true;
		}
#endif
		else if (charTemp == ' ')//分三种情况
		{
			if (argumentTemp.empty()) //空字符串则直接忽略
			{
				;
			}
			else if (quoteMode) //一个引号还没有结束
			{
				argumentTemp += charTemp;
			}
			else //否则标志该参数结束
			{
				argumentVector.push_back(argumentTemp);
				argumentTemp.clear();
			}
		}
		else
		{
			argumentTemp += charTemp;
		}
	}

	//讨论引号模式是否结束
	//在这里，我们认为最后一个字符是未经转义的 \ 是正确的语法，因为 "cd D:\" 这样的语法是正确的 
	//if (escapeMode || quoteMode)
	if (quoteMode)
	{
		return ARGUMENT_ERROR;
	}
	if (!argumentTemp.empty()) //最后一个字符串（如果不为空）还没有被加入 ArgumentVector 呢
	{
		argumentVector.push_back(argumentTemp);
		argumentTemp.clear();
	}

	//参数的分割完成，讨论是否有重定向
	//0.没有参数的可以直接返回了
	size_t argumentVectorSize = argumentVector.size();
	if (argumentVectorSize != 0)
	{
		//1.先把参数中的 '>' 去掉，讨论两种情况
		size_t lastArgumentStringSize = argumentVector[argumentVectorSize - 1].size();
		if (argumentVectorSize >= 1 && argumentVector[argumentVectorSize - 1][0] == '>')	//讨论最后一个参数是 '>test.txt' 的情况
		{
			outputFileName = argumentVector[argumentVectorSize - 1].substr(1, lastArgumentStringSize - 1);
			argumentVector.pop_back();
			lastArgumentStringSize--;
		}
		else if (argumentVectorSize >= 2 && argumentVector[argumentVectorSize - 2] == ">") // 讨论最后两个参数是 '>' 'test.txt' 的情况
		{
			outputFileName = argumentVector[argumentVectorSize - 1];
			argumentVector.pop_back();
			argumentVector.pop_back();
		}
		//两个 if 没过，可认为没有参数是”重定向“

		//2.再把参数中的首尾 " （如果有）去掉
		if (!outputFileName.empty() && outputFileName[0] == '"')
		{
			assert(outputFileName[lastArgumentStringSize - 1] == '"'); //最后一个字符也应当是 "，否则不配对，应该在上面返回
			outputFileName = outputFileName.substr(1, lastArgumentStringSize - 2);
		}
	}

	return 0;
}
