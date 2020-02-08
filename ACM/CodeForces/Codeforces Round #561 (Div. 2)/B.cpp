//#define debug
#include<bits/stdc++.h>
 
using namespace std;
 
char s[10005][10005] = { 0 };
char vo[] = "aeiou";
 
int main()
{
	cin.sync_with_stdio(0);
	cin.tie(0);
 
	int n;
#ifdef debug
	for (int n = 1; n <= 10000; n++)
	{
#else
	cin >> n;
#endif
	memset(s, 0, sizeof(s));
	int row = 0, column;
	int sn = sqrt(n) + 1;
	for (int i = 5; i <= sn; i++)
	{
		if (n%i == 0)
		{
			row = i;
			column = n / i;
			//colomn >= row
			break;
		}
	}
	if (row == 0 || column < 5)
	{
		cout << -1;
#ifndef debug
		return 0;
#else
		cout << " " << n << endl;
		continue;
#endif
	}
 
	for (int r = 0; r < row; r++)
	{
		for (int i = 0; i < 5; i++)
		{
			int c = (r + i) % row;
			s[r][c] = vo[i];
		}
	}
 
	for (int c = row; c < column; c++)
	{
		for (int r = 0; r < 5; r++)
			s[r][c] = vo[r];
	}
 
	for (int r = 0; r < row; r++)
		for (int c = 0; c < column; c++)
			if (s[r][c] == 0)
				s[r][c] = vo[rand()%5];
#ifndef debug
	for (int i = 0; i < row; i++)
		cout << s[i];
#else
	bool ac = true;
	for (int i = 0; i < row; i++)
	{
		int a[5] = { 0 };
		for (int j = 0; j < column; j++)
		{
			for (int k = 0; k < 5; k++)
			{
				if (s[i][j] == vo[k])
					a[k] = 1;
			}
		}
		for (int j = 0; j < 5; j++)
			if (a[j] == 0)
				ac = false;
	}
	for (int i = 0; i < column; i++)
	{
		int a[5] = { 0 };
		for (int j = 0; j < row; j++)
		{
			for (int k = 0; k < 5; k++)
			{
				if (s[j][i] == vo[k])
					a[k] = 1;
			}
		}
		for (int j = 0; j < 5; j++)
			if (a[j] == 0)
				ac = false;
	}
	if (!ac)
	{
		cout << n << endl;
		for (int i = 0; i < row; i++)
			cout << s[i] << endl;
	}
	}
#endif
 
}
