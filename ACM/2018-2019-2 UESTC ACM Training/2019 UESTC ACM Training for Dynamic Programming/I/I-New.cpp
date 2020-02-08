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

bool cmp(meizi a, meizi b)
{
	return a.d < b.d;
}

int n, m, k, x, y, a, b, c, d, ans = INT_MIN;


signed main()
{
	cin.sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m >> k >> x >> y;
	for (int i = 1; i <= n; i++)
	{
		cin >> a >> b >> c >> d;
		mz[i].value = a;
		mz[i].weight = (c - b > 0) ? (c - b) : 0;
		mz[i].d = (d - k > 0) ? (d - k) : 0;
	}

	sort(mz+1, mz + n+1, cmp);

	int curd = 0, bp[maxn] = { 0 }, curm = m;
	for (int i = 1; i <= n; i++)
	{
		if (mz[i].d > curd) 
		{
			//for (int j = (mz[i].d - curd)*x; j <= curm; j++)
			//	bp[j - (mz[i].d - curd)*x] = bp[j];
				//minus money, that is to move the array left
#ifdef debug
			for (int j = curm - (mz[i].d - curd)*x + 1; j <= m && j >= 0; j++)
				bp[j] = 0;
#endif
			curm -= (mz[i].d - curd)*x;
			curd = mz[i].d;
		}
		for (int j = curm; j >= y * mz[i].weight; j--)
		{
			bp[j] = max(bp[j], bp[j - y * mz[i].weight] + mz[i].value);
			ans = max(ans, bp[j]);
			//if i < needed money, we can't get the i-th meizi
			//and we just don't need to move the array
			// and we don't even need to start the for(j) from 0
		}
	}

	cout << ans;
}