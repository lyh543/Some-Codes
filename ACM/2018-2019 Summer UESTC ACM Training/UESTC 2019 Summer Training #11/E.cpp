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

const int maxn = 100005, mod = 998244353;

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
		int i = 0, j = n-1, ans=0;
		while (i < j)
		{
			if (a[i] == a[j])
				i++, j--;
			else if (a[i] > a[j])
			{
				a[j - 1] += a[j], ans++; j--;
			}
			else
			{
				a[i + 1] += a[i];
				ans++;
				i++;
			}
		}
		cout << ans << endl;
	}
}
