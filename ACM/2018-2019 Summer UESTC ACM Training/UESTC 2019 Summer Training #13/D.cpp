#include<bits/stdc++.h>
//#define _CRT_SECURE_NO_WARNINGS
#define ld long double 
#define ll long long 
//#define int ll
#define eps 1e-11
#define fastio ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
typedef pair<int, int> P;

const ll maxn = 1e5 + 5, mod = 1e9+7;


long long quickpow(long long base, long long n) {
	long long ans = 1;
	while (n) {
		if (n % 2 == 1) ans = ans * base % mod;
		n /= 2;
		base = base * base % mod;
	}
	return ans;
}

int main()
{
	fastio;
	ll x, k;
	cin >> x >> k;
	if (x != 0)
		cout << (quickpow(2, k)*((x%mod * 2 + mod - 1) % mod) + 1) % mod;
	else
		cout << 0;
}
