#include<bits/stdc++.h>
//#define _CRT_SECURE_NO_WARNINGS
#define ld long double 
#define ll long long 
#define int ll
#define eps 1e-11
#define fastio ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
typedef pair<int, int> P;
const int maxn = 4000, mod = 1e9 + 7;

int gcd(int a, int b)
{
	return b == 0 ? a : gcd(b, a%b);
}

signed main()
{
	fastio;
	int T;
	cin >> T;
	while (T--)
	{
		int n;
		cin >> n;
		int b, sum, g;
		cin >> b;
		sum = g = b;
		for (int i = 1; i < n; i++)
		{
			cin >> b;
			sum += b;
			g = gcd(b, g);
		}
		cout << sum << " " << g << endl;
	}
}
