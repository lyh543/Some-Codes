#include<bits/stdc++.h>
#define ll long long
#define ld double
using namespace std;

const int maxn = 1e5+5, maxq = 10005;

ll a[maxn], pre[maxn] = { 0 } ,ans = 0;


int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	ll n, k;
	cin >> n >> k;
	for (int i = 0; i < n; i++)
	{
		cin >> a[i];
		pre[i + 1] = a[i] + pre[i];
	}
	for (int i = 0; i <= n; i++)
	{
		ll * t = lower_bound(pre, pre + n + 1, pre[i] + k);
		ans += pre + n + 1 - t;
	}
	cout << ans;
}

