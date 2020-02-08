#include<bits/stdc++.h>
#include<unordered_map>
#define ll long long
#define ld long double
#define fastio ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);

using namespace std;

const int maxn = 2e5 + 5;
const ll mod = 1e9 + 7;

ll ans[maxn] = { 1 };

int main()
{
	ll a, b, sum = 1, lastsum = 0, used = 0;
	cin >> a >> b;
	ll floor = 1;
	while (sum != 0)
	{
		lastsum = sum;
		sum = 0;
		for (int i = a; i >= 0; i--)
		{
			if (b - (used - i) < floor)
				ans[i] = 0;
			if (i >= floor)
				ans[i] += ans[i - floor];
			ans[i] %= mod;
			sum += ans[i];
		}
		sum %= mod;
		used += floor;
		floor++;
	}
	cout << lastsum;
}
