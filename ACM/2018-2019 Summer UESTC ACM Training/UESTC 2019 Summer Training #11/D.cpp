#include<bits/stdc++.h>
#include<unordered_set>
//#define _CRT_SECURE_NO_WARNINGS
#define ld long double 
#define ll long long 
#define int ll
#define eps 1e-11
#define fastio ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
typedef pair<int, int> P;

const int maxn = 5005, mod = 998244353;

int a[maxn];

signed main()
{
	fastio;
	int T;
	cin >> T;
	while (T--)
	{
		int n;
		cin >> n;
		for (int i = 0; i < n; i++)
			cin >> a[i];
		sort(a, a + n);
		int sum = 0;
		for (int i = 0; i < n/2; i++)
		{
			sum += a[n - i - 1] - a[i];
		}
		cout << sum << endl;
	}
}
