#include<bits/stdc++.h>
#include<unordered_set>
#define ld long double 
#define ll long long
#define infty 0x3fffffffll
#define fastio ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
typedef pair<ll, ll> P;

const int maxn = 100005, maxlog = 17;
const ll maxans = (ll)1e10 + 1;


int main()
{
	fastio;
	int T;
	cin >> T;
	while (T--)
	{
		int L[2], R[2], p[2], d[2];
		for (int i = 0; i < 2; i++)
		{
			cin >> L[i] >> R[i] >> p[i] >> d[i];
			d[i] = (d[i] ? 1 : -1);
		}
		int k, ans = 0;
		cin >> k;
		for (int t = 1; t <= k; t++)
		{
			for (int i = 0; i < 2; i++)
			{
				if (L[i] == p[i])
					d[i] = 1;
				else if (R[i] == p[i])
					d[i] = -1;
				p[i] += d[i];
			}
			if (p[1] == p[0])
				ans++;
		}
		cout << ans << endl;
	}
}
