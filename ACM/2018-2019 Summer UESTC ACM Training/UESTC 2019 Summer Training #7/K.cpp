#include<bits/stdc++.h>

#define ld long double 
#define ll long long
#define infty 0x3fffffffll
#define fastio ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;


signed main()
{
	fastio;
	int T;
	cin >> T;
	while (T--)
	{
		int n, k;
		cin >> n >> k;
		if (k >= 32)
			k = 32;
		while (k--)
		{
			n = n / 2 + (n & 1);
		}
		cout << n << endl;
	}
}
