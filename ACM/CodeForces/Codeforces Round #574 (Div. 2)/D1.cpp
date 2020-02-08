#include<bits/stdc++.h>
#include<unordered_set>
#define ld long double 
#define ll long long
#define int ll
#define infty 0x3fffffffll
#define fastio ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
 
const int maxn = 3005, mod = 998244353;
 
int a, num[100][10] = { 0 };
 
signed main()
{
	fastio;
	
	int n, len;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> a;
		int j = 0;
		while (a != 0)
		{
			num[j][a % 10]++;
			a /= 10;
			j++;
			len = j;
		}
	}
 
	int ans = 0, base = 1;
	for (int j = 0; j < len; j++)
	{
		int nt = n, curans = 0;
		for (int i = 0; i < 10; i++)
		{
			curans += 11 * n * num[j][i] *i;
			curans %= mod;
		}
		ans += curans * base;
		ans %= mod;
		base *= 100;
		base %= mod;
	}
	cout << ans;
	return 0;
}
