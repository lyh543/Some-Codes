#include<bits/stdc++.h>
#include<unordered_set>
#define ld long double 
#define ll long long
#define infty 0x3fffffffll
#define j (len - i - 1)
#define fastio ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
typedef pair<ll, ll> P;

const int maxn = 105;

int main()
{
	fastio;
	int T;
	cin >> T;
	while (T--)
	{
		int n;
		cin >> n;
		int a[maxn] = { 0 };
		int sum = 0, mins = 1e6 + 5;
		for (int i = 0; i < n; i++)
		{
			cin >> a[i];
			sum += a[i];
			mins = min(mins, a[i]);
		}
		if (n % 2 == 1 || mins == 0)
		{
			cout << (sum % 2 ? "Yalalov" : "Shin") << endl;
		}
		else
		{
			int ans;
			if (mins % 2 == 0)
			{
				ans = (sum - mins * n) % 2;
			}
			else
			{
				ans = 1;
			}
			cout << (ans ? "Yalalov" : "Shin") << endl;
		}

	}
}
