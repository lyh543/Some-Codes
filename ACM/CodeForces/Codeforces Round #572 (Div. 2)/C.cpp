#include<bits/stdc++.h>
#define long double ld
#define long long ll
 
using namespace std;
 
const int maxn = 1e5 + 5;
int a[maxn], presum[maxn] = {0};
 
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
 
	int n, q;
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		cin >> a[i];
		presum[i] = a[i] + presum[i - 1];
	}
	cin >> q;
	for (int i = 0; i < q; i++)
	{
		int k, j;
		cin >> k >> j;
		cout << (presum[j] - presum[k - 1]) / 10 << endl;
	}
 
}
