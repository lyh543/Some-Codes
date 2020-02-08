#include<bits/stdc++.h>
#define ld long double 
#define ll long long 
//#define int ll
#define eps 1e-11
#define fastio ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
typedef pair<ll, int> P;
 
const int maxn = 2e5+5, infty = 100000;
 
const string p = "RGB";
 
int dp[maxn][3];
 
int main()
{
	fastio;
	int T;
	cin >> T;
	while (T--)
	{
		string s;
		int n, k, ans;
		cin >> n >> k >> s;
		ans = k;
		dp[0][0] = dp[0][1] = dp[0][2] = 0;
		for (int t = 0; t < 3; t++)
		{
			for (int j = 0; j < k; j++)
			{
				if (s[j] != p[(j + t) % 3])
					dp[0][t]++;
			}
			ans = min(dp[0][t], ans);
		}
		for (int i = 1; i <= n - k; i++)
		{
			for (int t = 0; t < 3; t++)
			{
				dp[i][t] = dp[i - 1][t] - (s[i - 1] != p[(t + i - 1) % 3]) + (s[i + k - 1] != p[(t + i + k - 1) % 3]);
				ans = min(dp[i][t], ans);
			}
		}
		cout << ans << endl;
	}
 
}
