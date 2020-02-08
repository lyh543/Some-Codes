#include<bits/stdc++.h>
 
using namespace std;
 
int main()
{
	cin.sync_with_stdio(0);
	cin.tie(0);
 
	int n, t;
	cin >> n >> t;
	int maxn = INT_MAX, index, b ,k, tt;
	for (int i = 0; i < n; i++)
	{
		cin >> b >> k;
		if (b < t)
		{
			tt = ((t - b) % k == 0) ? t : (1+(t - b)/k)*k+b;
		}
		else
		{
			tt = b;
		}
		if (tt < maxn)
		{
			maxn = tt;
			index = i;
		}
	}
	cout << index+1;
}
