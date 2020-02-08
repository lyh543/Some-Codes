#include<bits/stdc++.h>
#include<unordered_set>
#define ld long double 
#define ll long long
#define infty 0x3fffffffll
#define fastio ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
typedef pair<ll, ll> P;

const int maxn = 100005, maxlog = 17;
const ll maxans = (ll)1e10 + 1;
struct edgeS {
	int point;
	ll distance;
};
list<edgeS> neigh[maxn];
edgeS up[maxn][maxlog] = { 0 };
int depth[maxn];
int circle[2];
ll shortpath;

int dfs(int cur, int father)
{
	int i = 1;
	while ((1 << i) < depth[cur])
	{
		up[cur][i] = {
			up[up[cur][i - 1].point][i - 1].point,
			up[cur][i - 1].distance + up[up[cur][i - 1].point][i - 1].distance
		};
		i++;
	}
	list<edgeS>::iterator iter;
	for (iter = neigh[cur].begin(); iter != neigh[cur].end(); iter++)
	{
		if (iter->point != father)
		{
			if (depth[iter->point] != 0)
			{
				circle[0] = cur;
				circle[1] = iter->point;
				shortpath = iter->distance;
			}
			else
			{
				depth[iter->point] = depth[cur] + 1;
				up[iter->point][0] = { cur, iter->distance };
				dfs(iter->point, cur);
			}
		}
	}
	return 0;
}

ll dist(int a, int b)
{
	ll ans = 0;
	if (depth[a] > depth[b]) swap(a, b);// make sure b is deeper than a
	int diff = depth[b] - depth[a];
	int  j = 0;
	while (diff != 0)
	{
		if (diff & (1 << j))
		{
			ans = ans + up[b][j].distance;
			b = up[b][j].point;
			diff ^= (1 << j);
		}
		j++;
	}
	if (a == b)
	{
		return ans;
	}
	for (int i = maxlog - 1; i >= 0; i--)
	{
		if (up[a][i].point != up[b][i].point) // excluding overflow that are both 0
		{
			ans = ans + up[a][i].distance + up[b][i].distance;
			a = up[a][i].point;
			b = up[b][i].point;
		}
	}
	//LCA==up[a][0].point;
	ans = ans + up[a][0].distance + up[b][0].distance;
	return ans;
}

int main()
{
	fastio;
	int T;
	cin >> T;
	while (T--)
	{
		memset(up, 0, sizeof(up));
		memset(depth, 0, sizeof(depth));
		for (int i = 0; i < maxn; i++)
		{
			neigh[i].clear();
		}
		int n, q;
		cin >> n >> q;
		for (int i = 0; i < n; i++)
		{
			int a, b, d;
			cin >> a >> b >> d;
			neigh[a].push_back({ b, d });
			neigh[b].push_back({ a, d });
		}
		depth[1] = 1;
		dfs(1, 0);

		for (int i = 0; i < q; i++)
		{
			int a, b;
			ll ans = maxans;
			cin >> a >> b;
			ans = min(ans, dist(a, b));
			ans = min(ans, dist(a, circle[1]) + dist(b, circle[0]) + shortpath);
			ans = min(ans, dist(a, circle[0]) + dist(b, circle[1]) + shortpath);
			cout << ans << "\n";
		}
	}
	return 0;
}
