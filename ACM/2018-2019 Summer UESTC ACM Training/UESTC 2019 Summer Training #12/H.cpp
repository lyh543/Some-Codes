//I
#include<bits/stdc++.h>
//#define _CRT_SECURE_NO_WARNINGS
#define ld long double 
#define ll long long 
//#define int ll
#define eps 1e-11
#define fastio ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
typedef pair<int, int> P;

const int maxn = 1e6+5;

int dire[4][2] = { {0,1},{1,0},{0,-1},{-1,0} };

int ans[4] = { 0 };

signed main()
{
	fastio;
	ll x0, y0, x1, y1;
	char dire0;
	cin >> x0 >> y0 >> dire0 >> x1 >> y1;
	x1 -= x0;
	y1 -= y0;
	int direindex;
	if (dire0 == 'E')
		direindex = 1;
	if (dire0 == 'O')
		direindex = 3;
	if (dire0 == 'N')
		direindex = 0;
	if (dire0 == 'S')
		direindex = 2;
	int maxans = 0, order = 0;
	for (int i = 0; i < 4; i++)
	{
		int d = (direindex + i) % 4;
		if (d == 0)
		{
			if (y1 > 0)
				ans[i] = y1, order++,maxans = i;
		}		
		if (d == 2)
		{
			if (y1 < 0)
				ans[i] = -y1, order++,maxans = i;
		}		
		if (d == 1)
		{
			if (x1 > 0)
				ans[i] = x1, order++,maxans = i;
		}		
		if (d == 3)
		{
			if (x1 < 0)
				ans[i] = -x1, order++,maxans = i;
		}
	}
	cout << order + maxans << endl;
	for (int i = 0; i < maxans; i++)
	{
		if (ans[i])
			cout << "A " << ans[i] << endl;
		cout << "D" << endl;
	}
	if (ans[maxans])
		cout << "A " << ans[maxans];

}
