#include<bits/stdc++.h>
#define ld long double 
#define ll long long 
//#define int ll
#define eps 1e-11
#define fastio ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
typedef pair<int, int> P;

const ll maxn = 1e7+5, mod = 1e9 + 7;

ll arr[maxn] = { 0 };


int main()
{
	fastio;
	ll p, n;
	cin >> p >> n;
	n = min(n, p);
	for (ll i = 0; i <= n; i++)
	{
		arr[i*(i + 1) / 2 % p] = 1;
	}
	int ans = 0;
	for (int i = 0; i < p; i++)
		if (arr[i]) ans++;
	cout << ans;
}
