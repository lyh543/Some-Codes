#include<bits/stdc++.h>
#define ll long long

using namespace std;

const ll mod = 1e9 + 7, msize = 105;

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

int main()
{
	ll dp[msize] = { 1 };

	ios::sync_with_stdio(0);
	cin.tie(0);

	ll n, m, p1, p2;
	double d1, d2;
	cin >> n >> m;
	cin >> d1 >> d2;
	p1 = 1000 * d1 + 0.5;
	p2 = 1000 * d2 + 0.5;

	
	for (int i = 1; i <= n; i++)
		for (int j = m; j > 0; j--)
				dp[j] = (j * p2 * dp[j - 1] + (1000 - j * p2) * dp[j]) % mod;
	cout << (dp[m] + quickpow(1000,n) - quickpow(1000-p1,n) + mod) % mod;

}
