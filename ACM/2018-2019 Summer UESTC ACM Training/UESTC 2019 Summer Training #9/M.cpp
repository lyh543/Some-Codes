#include<bits/stdc++.h>
#include<unordered_set>
#define ld long double 
#define ll long long
#define int ll
#define infty 0x3fffffffll
#define fastio ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;

const int maxn = 200005, mod = 998244353;

int arr[maxn];

signed main()
{
	fastio;
	int n,k, ans = 0;
	cin >> n >> k;
	for (int i = 0; i  < n; i++)
		cin >> arr[i];
	for (int i = n - 1; i >= 0; i--)
	{
		if (arr[i] <= k - 1)
			k--;
		else if (i+1 == k)
		{
			ans++;
			k--;
		}
	}
	cout << ans;
}
