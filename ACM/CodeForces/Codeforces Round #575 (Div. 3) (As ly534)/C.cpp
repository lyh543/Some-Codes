#include<bits/stdc++.h>
#define ld long double 
#define ll long long 
//#define int ll
#define eps 1e-11
#define fastio ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
typedef pair<ll, int> P;
 
const int maxn = 1000, infty = 100000;
 
int main()
{
	fastio;
	int T;
	cin >> T;
	while (T--)
	{
		int n, flag = 1;
		int xless = infty, xmore = -infty, yless = infty, ymore = -infty;
		cin >> n;
		for (int i = 0; i < n; i++)
		{
			int x, y, l,u,r,d;
			cin >> x >> y >> l >> u >> r >> d;
			if (l == 0)
			{
				xmore = max(xmore, x);
			}
			if (r == 0)
			{
				xless = min(xless, x);
			}
			if (u == 0)
			{
				yless = min(yless, y);
			}
			if (d == 0)
			{
				ymore = max(ymore, y);
			}
		}
		if (xless >= xmore && yless >= ymore)
		{
			cout << 1 << " " << xmore << " " << ymore << endl;
		}
		else
		{
			cout << 0 << endl;
		}
	}
	
}
