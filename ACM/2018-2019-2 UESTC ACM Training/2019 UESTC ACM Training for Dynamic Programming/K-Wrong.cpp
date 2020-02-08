#include<bits/stdc++.h>
#define ll long long

using namespace std;

const ll mod = 1e9 + 7, msize = 105;

int m, n;
struct Matrix{
	ll v[msize][msize] = { {0} };
	Matrix operator * (Matrix & b)
	{
		Matrix ans;
		for (int i = 0; i <= m; i++)
		{
			for (int j = 0; j <= m; j++)
			{
				for (int k = 0; k <= m; k++)
				{
					ans.v[i][j] = (ans.v[i][j] + v[i][k] * b.v[k][j]) % mod;
				}
			}
		}
		return ans;
	}
};

ll quickpow(ll a, ll b)
{
	ll base = a, ans = 1;
	while (b)
	{
		if (b & 1)
			ans = ans * base % mod;
		base = base * base % mod;
		b >>= 1;
	}
	return ans;
}

Matrix quickpow(Matrix base, int p)
{
	Matrix ans;
	for (int i = 0; i <= m; i++)
	{
		ans.v[i][i] = 1;
	}
	while (p)
	{
		if (p & 1)
			ans = ans * base;
		base = base * base;
		p >>= 1;
	}
	return ans;
}

int main()
{
	ll dp[msize] = { 1 };

	

	ll n, m, p1, p2;
	scanf("%d%d 0.%d 0.%d", n, m, p1, p2);

	Matrix A;
	for (int i = 1; i <= m; i++)
	{
		for (int j = 1; j < i; j++)
		{
			A.v[i][j] = A.v[i - 1][j] * (1000 - p2) % mod;
		}
		A.v[i][i] = p2;
	}
	/* 坐标  0	1	2	3	4
	   第0行 0	0	0	0	0
	   第1行 0	p	0	0	0	+ 第零行的(1-p)倍
	   第2行 0	0	2p	0	0	+ 第一行的(1-2p)倍
	*/

	Matrix An = quickpow(A,)


	cout << (dp[m] + quickpow(1000, n) - quickpow(1000 - p1, n) + mod) % mod;

}
