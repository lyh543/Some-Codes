//C
#include<bits/stdc++.h>
#define ld long double 
#define ll long long 
//#define int ll
#define eps 1e-11
#define fastio ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
typedef pair<int, int> P;

const int maxn = 1005, infty = 100000;

vector<int> nei[maxn];

int ds[maxn] = { 0 }, dt[maxn] = { 0 };

priority_queue<P> q;

bool operator < (P a, P b)
{
	return a.second > b.second;
}

int main()
{
	fastio;
	int n, m, s, t;
	cin >> n >> m >> s >> t;
	for (int i = 1; i <= m; i++)
	{
		int a, b;
		cin >> a >> b;
		nei[a].push_back(b);
		nei[b].push_back(a);
	}

	for (int i = 1; i <= n; i++)
		ds[i] = dt[i] = infty;

	q.push({ s,0 });
	while (!q.empty())
	{
		P temp = q.top();
		q.pop();
		if (ds[temp.first] <= temp.second)
			continue;
		ds[temp.first] = temp.second;
		for (int j : nei[temp.first])
		{
			if (ds[temp.first] + 1 < ds[j])
				q.push({ j,temp.second + 1 });
		}
	}

	q.push({ t,0 });
	while (!q.empty())
	{
		P temp = q.top();
		q.pop();
		if (dt[temp.first] <= temp.second)
			continue;
		dt[temp.first] = temp.second;
		for (int j : nei[temp.first])
		{
			if (dt[temp.first] + 1 < dt[j])
				q.push({ j,temp.second + 1 });
		}
	}
	
	if (ds[t] != dt[s])
		return 20001228;

	//cout << "ans:\n";
	int ans = 0;
	for (int i = 1; i <= n; i++)
	{
		int a[maxn] = { 0 };
		for (int k : nei[i])
			a[k] = 1;
		for (int j = i + 1; j <= n; j++)
			if (a[j] == 0 && ds[t] <= ds[i] + dt[j] + 1 && ds[t] <= ds[j] + dt[i] + 1)
				ans++;//, cout<<i << " " << j <<endl;
	}
	cout << ans;
}
