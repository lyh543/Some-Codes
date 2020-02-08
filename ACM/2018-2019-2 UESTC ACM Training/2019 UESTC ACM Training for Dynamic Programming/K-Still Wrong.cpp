#define _CRT_SECURE_NO_WARNINGS
//#define debug
#include<bits/stdc++.h>
#define ll long long

using namespace std;

const ll mod = 1000000007, msize = 105;

ll m, n,p1,p2;

struct Matrix {
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

ostream & operator << (ostream & out, Matrix a)
{
	out << "A:" << endl;
	for (int i = 0; i <= m; i++)
	{
		for (int j = 0; j <= m; j++)
			out << a.v[i][j] << " ";
		out << endl;
	}
	return out;
}

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

Matrix quickpow_m(Matrix base, ll p)
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
#ifdef debug
		cout << ans;
#endif

	}
	return ans;
}

int main()
{
	//ll dp[msize] = { 1 };

	int a, b;
	long double d1, d2;
	scanf("%lld %lld %Lf %Lf", &n, &m, &d1, &d2);
	p1 = 1000 * d1;
	p2 = 1000 * d2;

	Matrix A;
	A.v[0][0] = 1000 - m * p2;
	for (int i = 1; i <= m; i++)
	{
		A.v[i][i - 1] = (m - i + 1)*p2;
		A.v[i][i] = 1000 - (m - i)*p2;
	}
	/* 坐标  0			1			2			3	4	...		m-1			m
	   第0行 1-m*p2		0			0			0	0			0			0
	   第1行 m*p2		1-(m-1)p2	0			0	0			0			0
	   第2行 0			(m-1)p2		1-(m-2)p2	0	0			0			0
	   ...
	   第m行	0			0			0			0	0			p2			1-0*p2
	*/

	Matrix An = quickpow_m(A, n);
#ifdef debug
	cout << "A:\n" << A;
	cout << "An:\n" << An;
	cout << An.v[m][0] << endl;
	cout << quickpow(1000, n) << endl
		<< quickpow(1000 - p1, n);
#else
	cout << (An.v[m][0] + quickpow(1000, n) - quickpow(1000 - p1, n) + mod) % mod << "\n";
#endif
}