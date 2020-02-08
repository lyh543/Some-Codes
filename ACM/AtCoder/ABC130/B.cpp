#include<bits/stdc++.h>
#define ll long long
#define ld double
using namespace std;

const int maxn = 1e6+5, maxq = 10005;


int main()
{
	int n, x,d = 0,l;
	cin >> n >> x;
	for (int i = 1; i <= n; i++)
	{
		cin >> l;
		d += l;
		if (d > x)
		{
			cout << i;
			return 0;
		}
	}
	cout << n + 1;
}

