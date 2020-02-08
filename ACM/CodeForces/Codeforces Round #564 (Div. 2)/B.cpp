#include <bits/stdc++.h>
#define ll long long
#define ld long double
using namespace std;
 
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
 
	int n;
	cin >> n;
	int m = n / 2 + 1;
	cout << m << endl;
	for (int i = 1; i <= m; i++)
	{
		cout << 1 << " " << i << endl;
	}
	for (int i = 2; i <= n-m+1; i++)
	{
		cout << i << " " << m << endl;
	}
}
