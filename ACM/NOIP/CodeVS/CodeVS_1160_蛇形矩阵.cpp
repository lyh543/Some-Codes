//http://codevs.cn/problem/1160/
//¡Ìº˚◊œ ÈP39 
#include<iostream>
using namespace std;

int matrix[100][100] = {0};

int main()
{
	int n, x, y, square, point = 1, sum = 0;
	cin >> n;
	x = y = (n - 1) / 2;
	matrix[x][y] = 1;
	square = n * n;
	while (point <= square)
	{
		while (x <= y         && point <= square){matrix[++x][y] = ++point;}
		while (x + y >= n     && point <= square){matrix[x][--y] = ++point;}
		while (x > y          && point <= square){matrix[--x][y] = ++point;}
		while (x + y + 2 <= n && point <= square){matrix[x][++y] = ++point;}
	}
	
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (i == j || i + j + 1 == n)
				sum += matrix[j][i];
			if (j) cout << " ";
			cout << matrix[j][i];
		}
		cout << endl;
	}
	cout << sum;
}
