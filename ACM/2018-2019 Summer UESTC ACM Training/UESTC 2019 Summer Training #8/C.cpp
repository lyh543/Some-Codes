#include<bits/stdc++.h>
#include<unordered_set>
#define ld long double 
#define ll long long
#define infty 0x3fffffffll
#define j (len - i - 1)
#define fastio ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
typedef pair<ll, ll> P;


int main()
{
	fastio;
	int T;
	cin >> T;
	while (T--)
	{
		string a, b;
		cin >> a >> b;
		int len = a.length(), inv = 0, ans = 0;
		int i = len / 2 - 1;
		if (a[len / 2] != b[len / 2])
		{
			cout << -1 <<endl;
			continue;
		}
		for (i = 0; i <=  len/2-1; i++)
		{
			if (inv)
			{
				if (a[i] == b[j] && a[j] == b[i])
					continue;
				else if (a[i] == b[i] && a[j] == b[j])
				{
					inv = 0;
					ans++;
				}
				else
				{
					ans = -1;
					break;
				}
			}
			else
			{
				if (a[i] == b[i] && a[j] == b[j])
					continue;
				else if (a[i] == b[j] && a[j] == b[i])
				{
					inv = 1;
					ans++;
				}
				else
				{
					ans = -1;
					break;
				}
			}
		}
		cout << ans << endl;
	}
}
