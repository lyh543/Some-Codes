#include <bits/stdc++.h>
#define ll unsigned long long 
#define ld long double
using namespace std;

ll cutN[100];

inline ll cut(ll n)
{
	return (n > 32) ? ULLONG_MAX : cutN[n];
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	for (int i = 0; i < 32; i++)
	{
		cutN[i] = ((1ull << (2 * i)) - 1) / 3;
		//cout << i << "c:" << cutN[i] << endl;
	}

	int T;
	cin >> T;
	for (int t = 0; t < T; t++)
	{
		ll n, k, cuts = 0;
		cin >> n >> k;
		ll i = 1;
		while (i <= n && k > 0)
		{
			k -= (1 << i) - 1;
			if (k < 0)
			{
				cout << "NO\n";
				break;
			}
			cuts += ((1 << (i+1))-3)*cut(n - i);
			if (cuts >= k)
			{
				cout << "YES " << n-i << "\n";
				break;
			}
			i++;
		}
		if (i > n)
			cout << "NO\n";
	}
}
