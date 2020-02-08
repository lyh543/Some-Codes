//◊œ ÈP47 
#include<cstdio>
#include<iostream>

using namespace std;

char keyboard[]="QWERTYUIOP[]\\ASDFGHJKL;'ZXCVBNM,./";

int main()
{
	char c;
	while ((c = getchar()) != '\n')
	{
		if (c == ' ')
			cout << ' ';
		else
			for (int i = 0; i < sizeof(keyboard); i++)
			{
				if (c == keyboard[i])
				{
					cout << keyboard[i - 1];
					break;
				}
			}
	}
}
