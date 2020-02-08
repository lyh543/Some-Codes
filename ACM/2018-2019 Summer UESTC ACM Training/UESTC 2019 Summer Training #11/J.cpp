#include<bits/stdc++.h>
#include<unordered_set>
//#define _CRT_SECURE_NO_WARNINGS
#define ld long double 
#define ll long long 
//#define int ll
#define eps 1e-11
#define fastio ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
typedef pair<ll, ll> P;

const ll maxn = 3005, mod = 998244353;

signed main()
{
	fastio;
	int T;
	cin >> T;
	while (T--)
	{
		int n, m;
		cin >> n >> m;
		int flag = 0;
		for (int i = 0; i < m; i++)
		{
			int a, b;
			cin >> a >> b;
			if (a == 1 && b == n)
				flag = 1;
		}
		cout << (flag ? "Jorah Mormont" : "Khal Drogo") << endl;
	}
}
