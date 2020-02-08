#include<bits/stdc++.h>
#define ld long double 
#define ll long long 
//#define int ll
#define eps 1e-11
#define fastio ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
typedef pair<ll, int> P;

const ll maxn = 5e5+5, mod = 1e9 + 7;

int main()
{
	fastio;
	ll a, b;
	cin >> a >> b;
	ll ans = a - b;
	for (a = a - b; a > 0; a -= b)
	{
		ans += 2*a;
	}
	cout << ans;
}
