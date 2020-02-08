#include <bits/stdc++.h>

using namespace std;

const int maxn = 17;
const int inf = (int)1e9;
int relation[maxn][2];

bool valid[1 << maxn] = { 0 };
int dis[1 << maxn];
int visited[1 << maxn] = { 0 };

struct edge {
	int b;
	int d;
};
bool operator < (edge a, edge b)
{
	return a.d > b.d;
}

vector<edge> neigh[1 << maxn];
priority_queue<edge> q;

int m, n, k;

int main()
{
	cin >> n >> m >> k;
	for (int i = 0; i < m; i++)
	{
		cin >> relation[i][0] >> relation[i][1];
	}
	for (int i = 0; i < (1 << (n+1)); i++)
	{
		valid[i] = true;
		for (int j = 0; j < m; j++)
		{
			int a = (i >> relation[j][0]) & 1;
			int b = (i >> relation[j][1]) & 1;
			int jj = i & 1;
			if ((a&&b && (!jj)) || ((!a) && (!b) && jj))
			{
				valid[i] = false;
				break;
			}
		}
	}

	for (int i = 0; i < (1 << (n+1)); i++)
	{
		if (!valid[i])
			continue;
		dis[i] = inf;
		for (int j = i+1; j < (1 << (n+1)); j++)
		{
			if (!valid[j])
				continue;
			int det = i ^ j;
			if ((det & 1)==0 || max(i, j) - det != min(i, j))
				continue;
			int t = 0;
			while (det)
			{
				t += det & 1;
				det >>= 1;
			}
			if (t <= k)
			{
				neigh[i].push_back({ j,t });
				neigh[j].push_back({ i,t });
			}
		}
	}

	dis[0] = 0;
	q.push({ 0,0 });

	while (!q.empty())
	{
		int oper = q.top().b;
		q.pop();
		if (!visited[oper])
		{
			for (edge i : neigh[oper])
			{
				int tempd = i.d + dis[oper];
				if (tempd < dis[i.b])
				{
					dis[i.b] = tempd;
					q.push({ i.b,dis[i.b] });
				}
			}
			visited[oper] = true;
		}
	}

	if (dis[(1 << (n + 1)) - 1 ] == inf)
		cout << "mole";
	else
		cout << dis[(1 << (n + 1)) -1 ];
	cout << endl;

}


