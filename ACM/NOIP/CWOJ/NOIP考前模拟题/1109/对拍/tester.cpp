#include<iostream>
#include<fstream>
#include<ctime>
#include<cstdlib>

using namespace std;

void makedata()
{
	ofstream out;
	out.open("input.txt");
	int n = rand() % 3 + 3;
	int d = rand() % 20 + 20;
	
	out << n << " " << d;
	
	for (int i = 0; i < n; i++)
	{
		if (rand()%2)
		{
			out << "\nTime " << rand() % 40 + 1;
		}
		else
		{
			out << "\nDist " << rand() % d + 1;
		}
	}
}

int main()
{
	srand(time(NULL));
	do
	{
		makedata();
		system("dig.exe <input.txt >ans(wa).txt");
		system("t123yh.exe <input.txt >ans(t123yh).txt");
	}
	while(!system("fc ans(wa).txt ans(t123yh).txt"));
	cout << "WA";
}
