#include<iostream>

using namespace std;

const int size = 1000;
int a[size][size] = {0};

int gcd(int m, int n)
{
	
	return n == 0 ? m : gcd(n,m%n);
}

int getGCD(int m, int n)
{
	if (m < size && n < size)
	{
		if (a[m][n]) return a[m][n];
		else return a[m][n] = gcd(m,n);
	}
	return gcd(m,n);
}

int main()
{
	int m, n;
	long long ans = 0;
	//cin >> n >> m;
	m = n = 2000;
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= m; j++)
		{
			ans += gcd(i,j);
		}
	}
	cout << ans;
}
