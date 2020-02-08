#include<bits/stdc++.h>

const int maxn = 1005, maxm = 5005;
using namespace std;

int relation[maxn][maxm] = { {0} };
int lre[maxn] = { 0 };
int degree[maxn] = { 0 };
int weight[maxn] = { 0 };
int fa[maxn];
stack<int> zeros;

int vertex, edge;

int findrt(int a)
{
	return fa[a] == a ? a : fa[a] = findrt(fa[a]);
}

void merge(int a, int b)
{
	int ra = findrt(a);
	int rb = findrt(b);
	fa[ra] = rb;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> vertex >> edge;
	for (int i = 1; i <= vertex; i++)
		fa[i] = i;

	int a[maxm][2] = { 0 }, la = 0;
	for (int i = 1; i <= edge; i++)
	{
		int t, b, o;
		cin >> o >> t >> b;
		if (o == 3)
		{
			merge(t, b);
			continue;
		}
		if (o == 1)
			swap(t, b);
		a[la][0] = t;
		a[la++][1] = b;
		
	}
	
	for (int i = 0; i < la; i++)
	{
		int f = findrt(a[i][0]), s = findrt(a[i][1]);
		relation[f][lre[f]++] = s;
		degree[s]++;
	}

	for (int i = 1; i <= vertex; i++)
		if (i == findrt(i) && degree[i] == 0)
			zeros.push(i);

 	while (!zeros.empty())
	{
		int t = zeros.top();
		zeros.pop();

		t = findrt(t);
		for (int i = 0; i < lre[t]; i++)
		{
			int d = relation[t][i];
			weight[d] = max(weight[d], weight[t] + 1);
			degree[d]--;
			if (degree[d] == 0)
				zeros.push(d);
		}
	}
	int ans = 0;
	for (int i = 1; i <= vertex; i++)
	{
		if (degree[findrt(i)] != 0)
		{
			cout << -1;
			return 0;
		}
 		ans += weight[findrt(i)] + 1;
	}
	cout << ans;
	return 0;
}