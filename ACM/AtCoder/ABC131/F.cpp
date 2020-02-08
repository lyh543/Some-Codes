#include<bits/stdc++.h>
#define ll long long
using namespace std;

const int maxn = 1e5 + 5;

int xfa[maxn] = { 0 }, yfa[maxn] = {0};
ll xsize[maxn] = { 0 }, ysize[maxn] = {0};
int vis[maxn] = { 0 };
struct point {
	int x;
	int y;
}p[maxn];
list<int>xcolumn[maxn];
list<int>yrow[maxn];

int xfindrt(int p)
{
	return (p == xfa[p] ? p :xfa[p]= xfindrt(xfa[p]));
}
int xmerge(int a, int b)
{
	int fa = xfindrt(a), fb = xfindrt(b);
	if (fa == fb)
		return 1;
	xfa[fb] = fa;
	xsize[fa] += xsize[fb];
	xsize[fb] = 0;
	return 0;
}
int yfindrt(int p)
{
	return (p == yfa[p] ? p : yfa[p] = yfindrt(yfa[p]));
}
int ymerge(int a, int b)
{
	int fa = yfindrt(a), fb = yfindrt(b);
	if (fa == fb)
		return 1;
	yfa[fa] = fb;
	ysize[fb] += ysize[fa];
	ysize[fa] = 0;
	return 0;
}

int main()
{
	int n;
	cin >> n;

	for (int i = 0; i < n; i++)
	{
		int a, b;
		cin >> a >> b;
		p[i] = { a,b };
		xcolumn[a].push_back(b);
		yrow[b].push_back(a);

		xsize[a] = ysize[b] = 1;
		xfa[a] = a;
		yfa[b] = b;
	}
	for (int i = 1; i < maxn; i++)
	{
		if (xcolumn[i].size()<=1)
			continue;
		int t = xcolumn[i].front();
		for (int k : xcolumn[i])
		{
			ymerge(t, k);
		}
	}
	for (int i = 1; i <maxn; i++)
	{
		if (yrow[i].size()<=1)
			continue;
		int t = yrow[i].front();
		for (int k : yrow[i])
		{
			xmerge(t, k);
		}
	}
	ll ans = 0;
	for (int i = 0; i < n; i++)
	{
		int  a = xfindrt(p[i].x), b = yfindrt(p[i].y);
		if (vis[a] == 0)
		{
			ans += xsize[a] * ysize[b];
			vis[a] = 1;
		}
	}
	cout << ans - n;
}

