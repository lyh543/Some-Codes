#include <bits/stdc++.h>
#define ll long long
using namespace std;
 
const int  maxn = 200005;
 
	ll n, m, ta, tb, k;
	ll a[maxn], b[maxn];
 
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
 
 
	cin >> n >> m >> ta >> tb >> k;
	for (int i = 0; i < n; i++)
	{
		cin >> a[i];
		a[i] += ta;
	}
	for (int i = 0; i < m; i++)
	{
		cin >> b[i];
	}
 
	sort(a, a + n);
	sort(b, b + m);
 
	if (k >= m || k >= n)
	{
		cout << -1;
		return 0;
	}
 
	ll ans = 0;
 
	for (int i = 0; i <= k; i++) //del i flights from a, and (k-i) from b
	{
		int t = lower_bound(b, b + m, a[i]) - b;
		if (t + k - i >= m)
		{
			cout << -1;
			return 0;
		}
		else
		{
			ans = max(b[t+k-i], ans);
		}
 
	}
	cout << (ans == 6e9 ? -1 : ans + tb);
	return 0;
}
