#include<bits/stdc++.h>
//#define _CRT_SECURE_NO_WARNINGS
#define ld long double 
#define ll long long 
#define int ll
#define eps 1e-11
#define fastio ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
typedef pair<int, int> P;
const int maxn = 4000, mod = 1e9 + 7;

bool vis[maxn] = { 0 };
int prime[maxn], cnt = 0;
void euler(int n)
{
	for (int i = 2; i < n; i++)
	{
		if (!vis[i]) prime[cnt++] = i, vis[i] = 1;
		for (int j = 0; j < cnt && i * prime[j] < n; j++)
		{
			vis[i*prime[j]] = 1;
			if (i%prime[j] == 0)
				break;
		}
	}
}

ll dp[505][505] = { 0 }, base[505];

signed main()
{
	//ofstream fout("out.txt");
	fastio;
	euler(maxn);
	for (int n = 1; n <= 501; n++)
	{
		dp[n][0] = 1;
		for (int m = 1; m <= 501; m++)
		{
			dp[n][m]  = dp[n - 1][m] + dp[n][m - 1] * prime[n - 1];
			dp[n][m] %= mod;
		}
	}
	base[0] = 1;
	for (int i = 1; i <= 500; i++)
	{
		base[i] = base[i - 1] * (prime[i - 1] - 1);
		base[i] %= mod;
	}
	int T;
	scanf("%lld", &T);

	for (int kase = 1; kase <= T; kase++)
	{
		int k, p;
		scanf("%lld%lld", &k, &p);

		printf("Case %lld: %lld\n", kase, dp[p][k - p] * base[p] % mod);
	}
}
