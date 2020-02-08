#include<bits/stdc++.h>
#define ld long double 
#define ll long long
#define infty 0x3fffffffll
#define fastio ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
typedef pair<ll, ll> P;

const int maxn = 1e5+5;

P operator + (P a, P b)
{
	return make_pair(a.first + b.first, a.second + b.second);
}

P operator * (ll t, P a)
{
	return make_pair(t*a.first, t*a.second);
}

ll abs(P a)
{
	return abs(a.first) + abs(a.second);
}

P seq[maxn];

map<char, P> m;

signed main()
{
	fastio;
	m['U'] = make_pair(0, 1);
	m['D'] = make_pair(0, -1);
	m['L'] = make_pair(-1, 0);
	m['R'] = make_pair(1, 0);
	int T;
	cin >> T;
	while (T--)
	{
		ll n, k, ans = 0;
		string s;
		cin >> n >> k >> s;
		seq[0] = make_pair(0,0);
		for (int i = 1; i <= n; i++)
		{
			seq[i] = m[s[i-1]] + seq[i - 1];
			ans = max(ans, abs(seq[i]));
		}
		for (int i = 1; i <= n; i++)
		{
			ans = max(ans, abs((k -1)* seq[n] + seq[i]));
		}
		cout << ans << endl;
	}
}
