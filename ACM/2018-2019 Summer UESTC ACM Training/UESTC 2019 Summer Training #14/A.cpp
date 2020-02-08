#include<bits/stdc++.h>
#define ld long double 
#define ll long long 
//#define int ll
#define eps 1e-11
#define fastio ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
typedef pair<ll, int> P;

const ll maxn = 5e5+5, mod = 1e9 + 7;

int pass[maxn], pos[maxn] = { 0 }, maxdi[maxn], ans[maxn];

int main()
{
	fastio;
	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> pass[i];
	int maxd = n - 1;
	for (int i = n - 1; i >= 0; i--)
	{
		
		if (pass[i] > 0)
			pos[pass[i]] = i;
		else
			if (pos[-pass[i]])
				maxd = min(pos[-pass[i]]-1, maxd);
		ans[i] = maxd - i + 1;
	}
	for (int i = 0; i < n; i++)
		cout << ans[i] << " ";
}
