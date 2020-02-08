#include<bits/stdc++.h>

using namespace std;

const int maxn = 1e5 + 1, maxa = 1e4 + 1, mina = -1e4-1;

int a[maxn];

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n, mini = maxa, minp, maxi = mina, maxp;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> a[i];
		if (a[i] < mini)
		{
			mini = a[i];
			minp = i;
		}
		else if (a[i] > maxi)
		{
			maxi = a[i];
			maxp = i;
		}
	}
	int t1 = maxi, t2 = mini;
	for (int i = 0; i < n; i++)
	{
		if (i == minp || i == maxp)
			continue;
		if (a[i] >= 0)
		{
			t2 -= a[i];
		}
		else
		{
			t1 -= a[i];
		}
	}
	cout << t1  - t2 << "\n";
	for (int i = 0; i < n; i++)
	{
		if (i == minp || i == maxp)
			continue;
		if (a[i] >= 0)
		{
			cout << mini << " " << a[i] << "\n";
			mini -= a[i];
		}
		else
		{
			cout << maxi << " " << a[i] << "\n";
			maxi -= a[i];
		}
	}
	cout << maxi << " " << mini << "\n";
}

