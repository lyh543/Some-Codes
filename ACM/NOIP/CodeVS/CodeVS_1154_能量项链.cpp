//http://codevs.cn/problem/1154/
#include<iostream>

using namespace std;

int main()
{
	int n;
	cin >> n;
	int p[100];
	long long power[100][100] = {{0}};
	for (int i = 0; i < n; i++)
	{
		cin >> p[i];
	}
	
	for (int d = 2; d <= n; d++) // d ָ right - left
	{
		for (int l = 0; l < n; l++)
		{
			int r = (l + d) % n;
			long long max = 0;
			for (int m = (l+1)%n; m != r; m = (m+1)%n)
			{
				int temp = power[l][m] + power[m][r]
							+ p[l] * p[m] * p[r];
				if (temp > max) max = temp;
			}
			power[l][r] = max;
		}
	}
	
	long long maxp = 0;
	for (int i = 0; i < n; i++)
		maxp = power[i][i] > maxp ? power[i][i] : maxp;
	cout << maxp;
}
