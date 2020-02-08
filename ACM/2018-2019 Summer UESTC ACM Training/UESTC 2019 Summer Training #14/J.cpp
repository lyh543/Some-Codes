#include<bits/stdc++.h>
#define ld long double 
#define ll long long 
//#define int ll
#define eps 1e-11
#define fastio ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
typedef pair<ll, int> P;

const ll maxn = 5e5+5, mod = 1e9 + 7;

ll sum[maxn], def2[maxn], def[maxn];


int main()
{
	fastio;
	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		ll a[3];
		cin >> a[0] >> a[1] >> a[2];
		sum[i] = a[0] + a[1] + a[2];
		def[i] = sum[i] - max(a[0], max(a[1], a[2]));
		def2[i] = def[i];
	}
	sort(def, def + n);
	for (int i = 0; i < n; i++)
	{
		int ans = upper_bound(def, def + n, sum[i] - 2) - def - (sum[i] - def2[i] >= 2);
		if (ans < 0) ans = 0;
		cout << ans << " ";
	}
	
}