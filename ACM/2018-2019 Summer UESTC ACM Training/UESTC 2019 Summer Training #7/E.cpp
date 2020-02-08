#include<bits/stdc++.h>

#define ld long double 
#define ll long long
#define infty 0x3fffffffll
#define fastio ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;

map<ll, ll> m;

signed main()
{
	fastio;
	int T;
	cin >> T;
	while (T--)
	{
		m.clear();
		ll n, sum = 0;
		cin >> n;
		for (int i = 0; i < n; i++)
		{
			ll a;
			cin >> a;
			sum += a;
			m[a]++;
		}
		ll remove = 0;
		ll dest = sum / n;
		map<ll,ll>::iterator iter = --m.end();
		for (; iter->first > dest; iter--)
		{
			remove += iter->second * (iter->first - dest);
		}
		cout << remove << endl;
	}
}
