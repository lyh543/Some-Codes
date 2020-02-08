#include<bits/stdc++.h>
#include<unordered_set>
#define ld long double 
#define ll long long
#define int ll
#define infty 0x3fffffffll
#define fastio ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;

const int maxn = 100005, mod = 998244353;

int a, num[maxn];

int degree[maxn];
signed main()
{
	fastio;
	int n,g;
	cin >> n >> g;
	if (n % g || n == g)
	{
		cout << -1;
	}
	else
	{
		cout << g <<" "<< n - g;
	}
	
}
