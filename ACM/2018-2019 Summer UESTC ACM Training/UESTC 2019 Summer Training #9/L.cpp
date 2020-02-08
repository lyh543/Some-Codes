//L
#include<bits/stdc++.h>
#include<unordered_set>
#define ld long double 
#define ll long long
#define int ll
#define infty 0x3fffffffll
#define fastio ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;

const int maxn = 200005, mod = 998244353;

struct point
{
	int x, y;
};
int dmult(point p1, point p2, point p0)
{
	return (p1.x - p0.x)*(p2.x - p0.x) + (p1.y - p0.y)*(p2.y - p0.y);
}

int xmult(point p1, point p2, point p0)
{
	return (p1.x - p0.x)*(p2.y - p0.y) - (p2.x - p0.x)*(p1.y - p0.y);
}
bool operator < (point a, point b)
{
	return xmult(b, a, { 0,0 }) < 0;
}

point arr[maxn];

signed main()
{
	fastio;
	int n;
	cin >> n;
	point p0;
	cin >> p0.x >> p0.y;
	for (int i = 1; i < n; i++)
	{
		cin >> arr[i].x >> arr[i].y;
		arr[i].x -= p0.x;
		arr[i].y -= p0.y;
	}
	arr[0] = { 0,0 };
	int ans = LLONG_MAX;
	for (int i = 0; i < n; i++)
	{
		ans = min(ans, abs(xmult(arr[i], arr[(i + 1) % n], arr[(i + 2) % n])));
	}
	cout << ans;
}
