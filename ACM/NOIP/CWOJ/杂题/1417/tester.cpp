#include<iostream>
#include<fstream>
#include<cstdlib>
#include<ctime>

using namespace std;

void init()
{
	srand(time(NULL));
}

void makedata()
{
	ofstream out;
	out.open("input.txt");
	
	for (int n = 2; n < 1000; n++)
	{
		out << n << endl;
		for (int i = 0; i < n; i++)
			out << rand() << " ";
	}
	out.close();
}

int main()
{
	init();
	
	do
	{
		cout << "O";
		makedata();
		system("my.exe <input.txt >my.txt");
		system("vio.exe <input.txt >vio.txt");
	}
	while(!system("fc my.txt vio.txt >nul"));
}
