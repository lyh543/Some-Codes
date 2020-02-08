//◊œ ÈP45 
#include<iostream>
#include<cstdio>

using namespace std;

int main()
{
	FILE * f;
	char c;
	bool quote = false;
	f = fopen("Tex.txt","r");
	while ((c = fgetc(f)) != EOF)
	{
		if (c == '\"')
		{
			if (quote)
				cout << "''";
			else
				cout << "``";
			quote = !quote;
		}
		else
			cout << c;
	}
}
