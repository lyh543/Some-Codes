#include<bits/stdc++.h>
#define ld long double 
#define ll long long 
#define int ll
#define eps 1e-11
#define fastio ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
typedef pair<int, int> P;

const int mod = 1e9 + 7;

struct matrix
{
	ll v[5][5];
	ll * operator[](int i)
	{
		return v[i];
	}
};

matrix operator * (const matrix &a, const matrix &b)
{
	matrix c;
	memset(c.v, 0, sizeof(c.v));
	for (int i = 0; i < 5; i++)
		for (int j = 0; j < 5; j++)
			for (int k = 0; k < 5; k++)
			{
				c.v[i][j] += a.v[i][k] * b.v[k][j] % (mod-1);
				c.v[i][j] %= (mod-1);
			}
	return c;
}

matrix quickpow(matrix base, long long n) {
	matrix ans;
	memset(ans.v, 0, sizeof(ans.v));
	for (int i = 0; i < 5; i++)
		ans.v[i][i] = 1;
	while (n) {
		if (n % 2 == 1) ans = base * ans;
		n /= 2;
		base = base * base;
	}
	return ans;
}

long long quickpow(long long base, long long n) {
	long long ans = 1;
	while (n) {
		if (n % 2 == 1) ans = ans * base % mod;
		n /= 2;
		base = base * base % mod;
	}
	return ans;
}

matrix baseM =
{
	{{1,1,1,1,0},
	{1,0,0,0,0},
	{0,1,0,0,0},
	{0,0,0,1,1},
	{0,0,0,0,1}}
};


signed main()
{
	fastio;
	int n, f[4];
	cin >> n >> f[0] >> f[1] >> f[2] >> f[3];
	matrix matrix0 = { {{2,3,4,14},{1,2,2,6},{1,1,1,2},{0,0,0,8},{0,0,0,2}} };
	matrix a = quickpow(baseM, n - 4) * matrix0;
	ll ans = 1;
	for (int i = 0; i < 4; i++)
	{
		ans *= quickpow(f[i], a[2][i]);
		ans %= mod;
	}
	cout << ans << endl;
	//for (int i = 5; i < 20; i++)
	//{
	//	matrix0 = baseM * matrix0;
	//	cout << i << "\t"<<matrix0[2][0] << "\t" << matrix0[2][1] << "\t" << matrix0[2][2] << "\t" << matrix0[2][3] << endl;
	//}
}
