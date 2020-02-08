#include<bits/stdc++.h>
//#define _CRT_SECURE_NO_WARNINGS
#define ld long double 
#define ll long long 
//#define int ll
#define eps 1e-11
#define fastio ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
typedef pair<int, int> P;

const int maxn = 105;

signed main()
{
	fastio;
	int n;
	cin >> n;
	int a, b, t, ans = 0;
	while(cin >> a >> b)
	{
		t = a * a + b * b;
		int st = sqrt(double(t));
		if (st * st == t && st != 0)
		{
			st--;
		}
		if (st / n <= 10)
			ans += 10 - st / n;
	}
	cout << ans;
}
