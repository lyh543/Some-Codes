#define _CRT_SECURE_NO_WARNINGS
#include<bits/stdc++.h>
#define ll long long
const int maxn = 1005;

using namespace std;

int n, m, k;

struct vertex {
	int fa;
}v[maxn];

struct edge {
	int a;
	int b;
	int d;
};

bool operator < (const edge &a, const edge& b)
{
	return a.d > b.d;
}

int findrt(int a)
{
	if (a == v[a].fa)
		return a;
	else
	{
		return v[a].fa = findrt(v[a].fa);
	}
}

int merge(int a, int b)
{
	int ra = findrt(a), rb = findrt(b);
	v[rb].fa = ra;
	return true;
}

bool connected(int a, int b)
{
	return findrt(a) == findrt(b);
}

priority_queue<edge> q;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m >> k;
	
	for (int i = 1; i <= n; i++)
		v[i].fa = i;
	for (int i = 1; i <= m; i++)
	{
		int a, b, d;
		cin >> a >> b >> d;
		q.push({ a,b,d });
	}

	ll ans = 0;
	int i = n;
	while (i > k)
	{
		edge temp = q.top();
		q.pop();

		if (!connected(temp.a, temp.b))
		{
			merge(temp.a, temp.b);
			ans += temp.d;
			i--;
		}
	}
	cout << ans;
 }
