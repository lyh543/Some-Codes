#include<bits/stdc++.h>
#include<unordered_set>
#define ld long double 
#define ll long long
#define infty 0x3fffffffll
#define fastio ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
typedef pair<int, int> P;
 
const int maxn = 1005;
 
int a[maxn] = { 0 };
 
int main()
{
	
	fastio;
	//euler(100001);
	int n, k;
	cin >> n >> k;
	for (int i = 0; i < n; i++)
	{
		int t;
		cin >> t;
		a[t]++;
	}
	int ans = 0, sets = (n + 1) / 2;
	for (int i = 1; i <= k; i++)
	{
		if (a[i] >= 2)
		{
			ans += a[i] / 2 * 2;
			sets -= a[i] / 2;
		}
	}
	cout << ans + sets;
}

