#include<bits/stdc++.h>
#define ld long double 
#define ll long long
#define infty 0x3fffffffll
#define fastio ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;

const int maxn = 110;



int dfs(int cur, vector<int> * edge, int (&vis)[maxn][maxn], int n)
{
	for (vector<int>::iterator i  = edge[cur].begin(); i != edge[cur].end(); i++)
	{
		if (vis[cur][*i])
			continue;
		vis[cur][*i] = 1;
		dfs(*i, edge, vis,n);
		for (int j = 1; j <= n; j++)
		{
			if (*i == j || cur == j)
			{
				continue;
			}
			if (vis[*i][j])
				vis[cur][j] = 1;
		}
	}
	//return level[cur];
	return 0;
}

int topo(int degree[], vector<int> edge[], int n,int m)
{
	queue<int> q;
	for (int i = 1; i <= n; i++)
	{
		if (degree[i] == 0)
			q.push(i);
	}
	while (!q.empty())
	{
		int t = q.front();
		q.pop();
		for (vector<int>::iterator i = edge[t].begin(); i != edge[t].end(); i++)
		{
			degree[*i]--;
			if (degree[*i] == 0)
				q.push(*i);
			m--;
		}
	}
	return m == 0;
}

signed main()
{
	fastio;
	int T;
	cin >> T;
	while (T--)
	{
		vector<int> nei[maxn], inverse[maxn];
		int degin[maxn] = { 0 }, degout[maxn] = { 0 };
		int up[maxn] = { 0 }, down[maxn] = { 0 };
		int vis1[maxn][maxn] = { 0 }, vis2[maxn][maxn] = { 0 };
		int n, m;
		cin >> n >> m;
		for (int i = 0; i < m; i++)
		{
			int a, b;
			cin >> a >> b;
			degin[b]++;
			degout[a]++;
			nei[a].push_back(b);
			inverse[b].push_back(a);
		}
		for (int i = 1; i <= n; i++)
		{
			if (degin[i] == 0)
				dfs(i, nei, vis1,n);
			if (degout[i] == 0)
				dfs(i, inverse, vis2,n);
		}
		int mid = (n-1) / 2;
		if (!topo(degin,nei,n,m))
		{
			for (int i = 1; i <= n; i++)
				cout << 0;
		}
		else for (int i = 1; i <= n; i++)
		{
			for (int j = 1; j <= n; j++)
			{
				if (vis1[i][j])
					up[i]++;
				if (vis2[i][j])
					down[i]++;
			}
			if (up[i] <= mid && down[i] <= mid)
				cout << 1;
			else
				cout << 0;
		}
		cout << endl;
	}
}
