#include<bits/stdc++.h>
 
using namespace std;
 
 
int main()
{
	cin.sync_with_stdio(0);
	cin.tie(0);
 
	int n, maxa, maxb;
	cin >> n >> maxa >> maxb;
	int a = maxa, b = maxb, i;
	char t;
	for (i = 0; i < n; i++)
	{
		cin >> t;
		if (t == '0')
		{
			if (b != 0)
				b--;
			else if (a != 0)
				a--;
			else
			{
				cout << i;
				return 0;
			}
		}
		else
		{
			if (b == maxb)
				b--;
			else if (a != 0)
			{
				a--;
				if (b != maxb)
					b++;
			}
			else if (b != 0)
				b--;
			else
			{
				cout << i;
				return 0;
			}
		}
	}
	cout << i;
	return 0;
}
