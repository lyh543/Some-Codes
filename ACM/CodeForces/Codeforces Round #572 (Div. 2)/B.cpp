#include<bits/stdc++.h>
#define long double ld
#define long long ll
 
using namespace std;
 
const int maxn = 1e5 + 5;
int a[maxn];
 
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
 
	int n, t = 0;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> a[i];
	}
	sort(a, a + n);
	if (a[n-1] >= a[n - 3] + a[n - 2])
	{
		cout << "NO";
	}
	else
	{
		cout << "YES" << endl << a[n-2] << " " << a[n-1] << " ";
		for (int i = n - 3; i >= 0; i--)
			cout << a[i] << " ";
	}
 
}
