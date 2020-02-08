#include<cstdlib>
#include<fstream>
#include<iostream>
#include<ctime>
//#include<Windows.h>
#include<cstring>

using namespace std;

//const int maxLengthOfOutput = 1000;	//输出文件的最大字符数 
const char exe1[100] = "1009__AC.exe";			//两个exe文件的名字 
const char exe2[100] = "1009_信息传递.exe";

ofstream out;

void createRandom() 					//创造随机输入的函数，用out输出 
{
	int n = rand()%10 + 1;
	out << n << "\n";
	for (int i = 0; i < n; i++)
	{
		out << rand()%n+1 << " ";
	}
}

//以下内容无需修改 

const char arg1[] = " <input.txt >output1.txt";
const char arg2[] = " <input.txt >output2.txt";

bool checkExist(const char *);

int main()
{
	if (!checkExist(exe1) || !checkExist(exe2))
		return 1;
	system("title Answer Tester");
	srand(time(NULL));
	//char ans1[maxLengthOfOutput], ans2[maxLengthOfOutput];
	int RightTime = 0;
	
	
	char cmd1[1000], cmd2[1000];
	strcpy(cmd1,exe1);
	strcpy(cmd2,exe2);
	strcat(cmd1,arg1);
	strcat(cmd2,arg2);
	
	cout << "Initialization over...\n";
	while (true)
	{
		out.open("input.txt");
		createRandom();
		out.close();
		//getAns(exe1,ans1);
		//getAns(exe2,ans2);
		
		//cout << "running 1"; 
		system(cmd1);
		//cout << "running 2";
		system(cmd2);
		//cout << "Over";
		if (!system("fc output1.txt output2.txt >nul"))
			cout << "Right" << ++RightTime << endl;
		else
		{
			cout << "------------------------\n"
				 << "Something happened!!!\n\n"
				 << "Input:\n\n";
			system("type input.txt");
			cout << "\n\nAnswer from " << exe1 << ":\n\n";
			system("type output1.txt");
			cout << "\n\nAnswer from " << exe2 << ":\n\n";
				system("type output2.txt");
			cout << "\n\n";
			system("pause");
			return 1;
		}
	}
}

bool checkExist(const char * filename)
{
	fstream f;
	f.open(filename);
	if (!f)
	{
		cout << filename << " does not exist\n";
		system("pause");
		return false;
	}
	else return true;
}
