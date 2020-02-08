//B题良心样例，5组数据错了4个，修了以后就AC了

#include<bits/stdc++.h>
#define LL long long
using namespace std;

const int maxn = 100005, maxlog = 17, maxans = (int)1e9+1;

struct edgeS {
	int point;
	int distance;
};

list<edgeS> neigh[maxn];
edgeS up[maxn][maxlog] = { 0 };
int depth[maxn]; 

int dfs(int cur, int father)
{
	int i = 1;
	while ((1<<i) < depth[cur])
	{
		up[cur][i] = {
			up[up[cur][i-1].point][i-1].point,
			min(up[cur][i-1].distance, up[up[cur][i - 1].point][i - 1].distance)
		};
		i++;
	}
	list<edgeS>::iterator iter;
	for (iter = neigh[cur].begin(); iter != neigh[cur].end(); iter++)
	{
		if (iter->point != father)
		{
			depth[iter->point] = depth[cur] + 1;
			up[iter->point][0] = { cur, iter->distance };
			dfs(iter->point, cur);
		}
	}
	return 0;
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n, q;
	cin >> n >> q;

	for (int i = 1; i < n ; i++)
	{
		int a, b, d;
		cin >> a >> b >> d;
		neigh[a].push_back({ b, d });
		neigh[b].push_back({ a, d });
	}

	depth[1] = 1;
	for (int i = 1; i <= n; i++)
		for (int j = 0; j < maxlog; j++)
			up[i][j].distance = maxans;
	dfs(1,0);

	for (int i = 0; i < q; i++)
	{
		int a, b, ans = maxans;
		cin >> a >> b;

		if (depth[a] > depth[b]) swap(a, b); // make sure b is deeper than a
		int diff = depth[b] - depth[a];
		int  j = 0;
		while (diff != 0)
		{
			if (diff & (1<<j))
			{
				ans = min(ans, up[b][j].distance);
				b = up[b][j].point;
				diff ^= (1 << j);
			}
			j++;
		}
		if (a == b)
		{
			cout << ans << endl;
			continue;
		}

		for (int i = maxlog-1; i >= 0; i--)
		{
			if (up[a][i].point != up[b][i].point) // excluding overflow that are both 0
			{
				ans = min(min(ans, up[a][i].distance), up[b][i].distance);
				a = up[a][i].point;
				b = up[b][i].point;
			}
		}

		ans = min(min(ans, up[a][0].distance), up[b][0].distance);

		cout << ans << "\n";
	}

}
