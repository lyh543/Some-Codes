#include<bits/stdc++.h>
#include<unordered_map>

#define ld long double 
#define ll long long
#define infty 0x3fffffffll
#define fastio ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
typedef pair<int, int> P;

const int maxn = 305;

int gcd(int a, int b)
{
	return b == 0 ? a : gcd(b, a%b);
}

map<int, int> m;

//gcd to money

int v[maxn], c[maxn], sufgcd[maxn];

signed main()
{
	fastio;
	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> v[i];
	}
	for (int i = 0; i < n; i++)
	{
		cin >> c[i];
	}

	for (int i = 0; i < n; i++)
	{
		for (auto cur : m)
		{
			int g = gcd(cur.first, v[i]);
			auto iter = m.find(g);
			if (iter == m.end() || iter->second == 0 || iter->second > cur.second + c[i])
				m[g] = cur.second + c[i];
		}
		auto iter = m.find(v[i]);
		if (iter == m.end() || iter->second == 0 || iter->second > c[i])
			m[v[i]] = c[i];
	}

	cout << (m[1] != 0 ? m[1] : -1);
}
