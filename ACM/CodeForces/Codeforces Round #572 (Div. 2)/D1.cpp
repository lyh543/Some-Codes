#include<bits/stdc++.h>
#define long double ld
#define long long ll
 
using namespace std;
 
const int maxn = 1e5 + 5;
int d[maxn] = { 0 }, d2 = 0;
 
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
 
	int n;
	cin >> n;
	for (int i = 1; i < n; i++)
	{
		int a, b;
		cin >> a >> b;
		if (d[a] == 1)
			d2++;
		else if (d[a] == 2)
			d2--;
 
		if (d[b] == 1)
			d2++;
		else if (d[b] == 2)
			d2--;
 
		d[a]++, d[b]++;
	}
	cout << ((d2 == 0) ? "YES" : "NO");
 
}
