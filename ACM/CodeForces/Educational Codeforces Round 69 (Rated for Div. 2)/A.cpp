#include<bits/stdc++.h>
//#define _CRT_SECURE_NO_WARNINGS
#define ld long double 
#define ll long long 
//#define int ll
#define eps 1e-11
#define fastio ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
typedef pair<int, int> P;
 
const int maxn = 1e5 + 5;
 
int a[maxn];
 
int main()
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
		cout << min(min(a[n - 1], a[n - 2]) - 1, n-2) << endl;
	}
}
