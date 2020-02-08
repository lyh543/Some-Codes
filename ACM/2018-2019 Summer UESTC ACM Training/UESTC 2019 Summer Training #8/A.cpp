#include<bits/stdc++.h>
#include<unordered_set>
#define ld long double 
#define ll long long
#define infty 0x3fffffffll
#define fastio ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
typedef pair<ll, ll> P;

const ll maxn = 2000005;

signed main()
{
	fastio;
	int T;
	cin >> T;
	while (T--)
	{
		ll R, r;
		cin >> R >> r;
		cout << 2 - (R*R - r * r * 2 > 0) << endl;
	}
}
