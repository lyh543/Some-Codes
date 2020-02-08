#include<bits/stdc++.h>
#include<unordered_map>

#define ld  long double
#define ll long long
#define eps 1e-8
#define fastio ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
//#define debug

using namespace std;
const int maxn = 3e5 + 4;

struct nodeS {
	ll ans = 0;
	int depth = 0;
	list<int> nei;
	int father = 0;
	unordered_map<int, ll> add;
}node[maxn];

int maxdepth = 1;

void getDepth(int f, int d)
{
	node[f].depth = d;
	maxdepth = max(maxdepth, d);
	auto iter = node[f].nei.begin();
	while(iter != node[f].nei.end())
	{
		if (node[f].father == *iter)
		{
			auto temp = iter;
			iter++;
			node[f].nei.erase(temp);
		}
		else
		{
			node[*iter].father = f;
			getDepth(*iter, d + 1);
			iter++;
		}
	}
}

void dfs(int f)
{
	queue<int> q;
	q.push(f);
	while (!q.empty())
	{
		int f = q.front();
		q.pop();
		for (unordered_map<int, ll>::iterator iter = node[f].add.begin(); iter != node[f].add.end(); iter++)
		{
			node[f].ans += iter->second;
			if (iter->first > 0)
				for (auto son = node[f].nei.begin(); son != node[f].nei.end(); son++)
					node[*son].add[iter->first - 1] += iter->second;
		}

		for (auto son : node[f].nei)
			q.push(son);
		node[f].add.clear();
		node[f].nei.clear();
	}
}

signed main()
{
	int n;
	scanf("%d", &n);

	for (int i = 1; i < n; i++)
	{
		int a, b;
		scanf("%d%d", &a, &b);
		node[a].nei.push_back(b);
		node[b].nei.push_back(a);
	}

	int q;

	scanf("%d", &q);
	
	getDepth(1, 1);

	for (int i = 0; i < q; i++)
	{
		int a, d, x;
		scanf("%d%d%d", &a, &d, &x);
		if (node[a].depth + d > maxdepth)
		{
			d = maxdepth - node[a].depth;
		}
		node[a].add[d] += x;
	}


	dfs(1);

	for (int i = 1; i <= n; i++)
	{
		printf("%I64d ", node[i].ans);
	}
}
