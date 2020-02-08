#include<bits/stdc++.h>
//#define _CRT_SECURE_NO_WARNINGS
#define ld long double 
#define ll long long 
//#define int ll
#define eps 1e-11
#define fastio ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
typedef pair<int, int> P;
 
const int maxn = 3e5 + 5;
 
ll a[maxn], diff[maxn];
 
int main()
{
	fastio;
	int n, k;
	cin >> n >> k;
	cin >> a[0];
	for (int i = 1; i < n; i++)
	{
		cin >> a[i];
		diff[i] = a[i] - a[i - 1];
	}
	sort(diff+1, diff+n);
	ll ans = a[n - 1] - a[0];
	for (int i = n - 1; i > n - k; i--)
		ans -= diff[i];
	cout << ans;
}
