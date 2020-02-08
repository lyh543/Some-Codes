#include<bits/stdc++.h>
#include<unordered_set>
#define ld long double 
#define ll long long
#define infty 0x3fffffffll
#define fastio ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
typedef pair<ll, ll> P;

const int maxn = 1005, mod = 7901;

ll fact[maxn];

void init()
{
	fact[0] = 1;
	for (int n = 1; n < 1003; n++)
	{
		fact[n] = fact[n - 1] * n % mod;
	}
}


int main()
{
	fastio;
	init();
	int T;
	cin >> T;
	while (T--)
	{
		int bucket[maxn] = { 0 };
		int n;
		cin >> n;
		for (int i = 0; i < n; i++)
		{
			int a;
			cin >> a;
			bucket[a]++;
		}
		int ans =1;
		for (int i = 1; i <= 1000; i++)
			ans = ans * fact[bucket[i]] % mod;
		cout << ans << endl;
	}
}
