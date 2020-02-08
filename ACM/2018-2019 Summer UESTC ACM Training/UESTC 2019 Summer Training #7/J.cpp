#include<bits/stdc++.h>
#define ld long double 
#define ll long long
#define infty 0x3fffffffll
#define fastio ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;

const int maxn = 2e5 + 5;

char s[maxn];

signed main()
{
	fastio;
	int T;
	cin >> T;
	while (T--)
	{
		int k, m, n;
		cin >> k;
		cin >> s;
		cin >> n >> m;
		for (int i = 0; i < m; i++)
		{
			int a, b;
			cin >> a >> b;
		}
		cout << '3' - s[(m - n + 1)%k] << endl;
	}
}
