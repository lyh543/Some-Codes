#include<iostream>

using namespace std;

const int size = 1000;

int matrix[size][size] = {{0}};

int main()
{
	ios::sync_with_stdio();
	cin.tie(0);
	
	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cin >> matrix[i][j];
		}
	}
	
	for (int k = 0; k < n; k++)
	{
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
			{
				if (matrix[i][j] > matrix[i][k] + matrix[k][j])
					matrix[i][j] = matrix[i][k] + matrix[k][j];
			}
		}
	}
	
	int askN;
	cin >> askN;
	
	for (int i = 0; i < askN; i++)
	{
		int a, b;
		cin >> a >> b;
		cout << matrix[--a][--b] << endl;
	}
}

