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

const int maxn = 5e4+5;

vector<int> nei[maxn];
int color[maxn] = { 0 }, used = 0;

int neicolor[maxn], k;

int dfs(int cur)
{
	if (color[cur] != 0)
		return 0;
	memset(neicolor, 0, sizeof(neicolor));
	for (int i : nei[cur])
	{
		neicolor[color[i]] = 1;
	}
	for (int i = 1; i <= used; i++)
	{
		if (neicolor[i] == 0)
		{
			color[cur] = i;
			break;
		}
	}
	if (color[cur] == 0)
	{
		color[cur] = ++used;
		if (used > k)
			return 1;
	}
	for (int i : nei[cur])
	{
		if (dfs(i))
			return 1;
	}
	return 0;
}

signed main()
{
	int n, m;
	cin >> n >> m >> k;
	for (int i = 0; i < m; i++)
	{
		int a, b;
		cin >> a >> b;
		nei[a].push_back(b);
		nei[b].push_back(a);
	}
	for (int i = 1; i <= n; i++)
	{
		if (dfs(i))
		{
			cout << -1;
			return 0;
		}
	}
	for (int i = 1; i <= n; i++)
	{
		cout << color[i] << endl;
	}
}
