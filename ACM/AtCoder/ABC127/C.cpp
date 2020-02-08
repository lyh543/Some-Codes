#include<bits/stdc++.h>
#define ll long long
using namespace std;



int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int m, n;
	cin >>  n >> m;
	int a = 1, b = n, c, d;
	for (int i = 1; i <= m; i++)
	{
		cin >> c >> d;
		a = max(a, c);
		b = min(b,  d);
	}
	int ans = 0;
 	if (b >= a)
		ans = (b - a + 1);
	cout << ans;
}

