//I
#include<bits/stdc++.h>
//#define _CRT_SECURE_NO_WARNINGS
#define ld long double 
#define ll long long 
//#define int ll
#define eps 1e-11
#define fastio ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
typedef pair<int, int> P;

const int maxn = 1e6+5;

char str[maxn] = { 0 };

signed main()
{
	fastio;
	ll n;
	cin >> n;
	ll sum = (n + 1)*n / 2;
	if (sum % 2)
	{
		cout << -1;
		return 0;
	}
	sum /= 2;
 	for (int i = n; sum > i; i--)
	{
		str[i] = '+';
		sum -= i;
	}
	str[sum] = '+';
	for (int i = 1; i <= n; i++)
	{
		cout << (str[i] == '+' ? '+' : '-');
	}
}
