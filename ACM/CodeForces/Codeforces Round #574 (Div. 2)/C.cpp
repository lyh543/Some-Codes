#include<bits/stdc++.h>
#include<unordered_set>
#define ld long double 
#define ll long long
#define infty 0x3fffffffll
#define fastio ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
typedef pair<int, int> P;
 
const int maxn = 100005;
 
ll a[maxn][2] = { 0 };
ll dp[maxn][3] = { 0 };
int main()
{
	
	fastio;
	ll n;
	cin >> n;
	for (int i = 0; i < 2; i++)
		for (int j = 1; j <= n; j++)
			cin >> a[j][i];
	
	for (int i = 1; i <= n; i++)
	{
		dp[i][0] = max(dp[i - 1][1], dp[i - 1][2]) + a[i][0];
		dp[i][1] = max(dp[i - 1][0], dp[i - 1][2]) + a[i][1];
		dp[i][2] = max(max(dp[i - 1][0], dp[i - 1][1]), dp[i - 1][2]);
	}
	cout << max(max(dp[n][0], dp[n][1]), dp[n][2]);
}
