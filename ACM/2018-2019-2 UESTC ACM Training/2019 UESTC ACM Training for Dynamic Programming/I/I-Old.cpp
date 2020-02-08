//#define debug
#include<bits/stdc++.h>
#define int long long
using namespace std;
const int maxn = 6000;

struct meizi {
	int weight;
	int value;
	int d;
}mz[maxn];

set<int> s;

int n, m, k, x, y, a, b, c, d, ans = INT_MIN;

int dp[2][maxn];

int bag(int weight, int maxd)
{
	memset(dp, 0, sizeof(dp));
	int cur = 0;
	for (int i = 1; i <= n; i++)
	{
		if (mz[i].d > maxd)
			continue;
		for (int w = 0; w <= weight; w++)
		{
			if (w >= mz[i].weight)
				dp[cur][w] = max(dp[!cur][w],
					dp[!cur][w - mz[i].weight] + mz[i].value);
			else
				dp[cur][w] = dp[!cur][w];
		}
		cur = !cur;
	}
	return dp[!cur][weight];
}

signed main()
{
	cin.sync_with_stdio(0);
	cin.tie(0);

	s.insert(0);

	cin >> n >> m >> k >> x >> y;
	for (int i = 1; i <= n; i++)
	{
		cin >> a >> b >> c >> d;
		mz[i].value = a;
		mz[i].weight = c - b > 0 ? c - b : 0;
		mz[i].d = d - k > 0 ? d - k : 0;
		if (d > k)
			s.insert(d - k);
	}

	if (y == 0)
	{
		int ans = 0;
		for (int i = 1; i <= n; i++)
			if (x*mz[i].d <= m)
				ans += mz[i].value;
		cout << ans;
		return 0;
	}
	if (x == 0)
	{
		cout << bag(m, INT_MAX);
		return 0;
	}

	set<int>::iterator iter = s.begin();
	while (iter != s.end() && (*iter)*x <= m)
	{
		ans = max(bag((m - (*iter)*x) / y, *iter), ans);

#ifdef debug
		cout << " chrisma+=" << (*iter) << " money=" << (m - (*iter)*x) / y
			<< " bag=" << bag((m - (*iter)*x) / y, *iter) << endl;
#endif // debug

		iter++;
	}
	cout << ans;
	return 0;
}
