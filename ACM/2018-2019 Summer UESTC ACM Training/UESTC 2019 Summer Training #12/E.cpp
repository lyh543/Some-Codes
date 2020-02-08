//C
#include<bits/stdc++.h>
//#define _CRT_SECURE_NO_WARNINGS
#define ld long double 
#define ll long long 
//#define int ll
#define eps 1e-11
#define fastio ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
typedef pair<int, int> P;

const int maxn = 1e5+5, primen = 7, maxmask = (1<<primen) - 1;

ll ans = 0;

ll temp[maxn];

signed main()
{
	fastio;
	int n;
	cin >> n;
	if (n == 1)
	{
		int a;
		cin >> a;
		cout << a;
		return 0;
	}
	for (int i = 0; i < n; i++)
	{
		cin >> temp[i];
	}
	sort(temp, temp + n);
	int head = 0, end = n;
	int dl = 0;
	while (end - head != 2)
	{
		if (dl == 0)
		{
			ans += temp[head] + temp[head + 1];
			dl = temp[head+1]; //À≠ªÿ»•?
			temp[head + 1] = temp[head];
			temp[head] = 0;
			head++;
		}
		else if (temp[end-2] + temp[head] < 2*dl)
		{
			ans += temp[head] + temp[end - 1];
			temp[--end] = 0;
		}
		else
		{
			ans += dl + temp[end - 1];
			temp[--head] = dl;
			if (temp[head] > temp[head + 1])
				swap(temp[head], temp[head + 1]);
			dl = 0;
			temp[end - 1] = temp[end - 2] = 0;
			end -= 2;
		}
	}
	/*if (end - head == 3)
	{
		ll t1 = temp[head] + temp[head + 1] + temp[head + 2];
		if (dl != 0)
			t1 = min(t1, temp[head + 2] + 2 * dl);
		ans += t1;
	}*/
	ans += max(temp[head],temp[head + 1]);
	cout << ans;
}
