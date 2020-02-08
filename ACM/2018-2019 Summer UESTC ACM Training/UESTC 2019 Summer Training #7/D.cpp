#include<bits/stdc++.h>
#define ld long double 
#define ll long long
#define int long long
#define infty 0x3fffffffll
#define fastio ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
typedef pair<ll, ll> P;

const int maxn = 105, mod = 998244353;

ll C[maxn][maxn] = { 0 };

void init()
{
	C[0][0] = 1;
	for (int n = 1; n <= 103; n++)
	{
		C[n][0] = 1;
		for (int m = 1; m <= n; m++)
		{
			C[n][m] = (C[n - 1][m] + C[n - 1][m - 1])% mod;
		}
	}
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

int inv(int a)
{
	return quickpow(a, mod - 2);
}

ll dp[maxn][maxn] = { 0 };

signed main()
{
	fastio;
	init();
	int T;
	cin >> T;
	while (T--)
	{
		memset(dp, 0, sizeof(dp));
		ll n, k, m;
		cin >> n >> k >> m;
		string s1, s2;
		cin >> s1 >> s2;
		int changed = 0;
		for (int i = 0; i < n; i++)
		{
			changed += (s1[i] != s2[i]);
		}
		dp[0][0] = 1;
		for (int round = 1; round <= k; round++)
		{
			for (int j = 0; j <= n; j++)
			{
				for (int t = 0; t <= n; t++)
				{
					if ((m+j-t)%2 == 1 || (m + j - t) < 0 || (m - j + t) < 0)
						continue;
					dp[round][j] += dp[round - 1][t] 
						* C[t][(m - j + t) / 2] % mod * C[n - t][(m + j - t) / 2] % mod;
					dp[round][j] %= mod;
				}
			}
		}
		cout << dp[k][changed]*inv(C[n][changed])%mod << endl;
	}

