#include<bits/stdc++.h>

#define ll long long
#define ld long double
using namespace std;

const int maxn = 1e5 + 5;

#define int long long 

signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int T;
	cin >> T;
	for (int t = 0; t < T; t++)
	{
		int n, m;
		int a[maxn];
		int sum = 0;
		cin >> n >> m;
		for (int i = 0; i < n; i++)
			cin >> a[i];
		sort(a, a + n);
		for (int i = 0; i < m; i++)
		{
			sum += a[i] * a[2 * m -1-i];
		}
		cout << sum << endl;
	}

}
