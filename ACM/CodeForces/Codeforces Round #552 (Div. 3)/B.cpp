#include<bits/stdc++.h>
 
using namespace std;
 
int main()
{
	cin.sync_with_stdio(0);
	cin.tie(0);
 
	long long n, a[100], ans[3] = { -1,-1,-1 };
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> a[i];
		for (int j = 0; j < 3; j++)
		{
			if (ans[j] == -1)
			{
				ans[j] = a[i];
				break;
			}
			else
			{
				if (ans[j] == a[i])
					break;
				if (j == 2)
				{
					cout << -1;
					return 0;
				}
			}
		}
 
	}
	if (ans[2] == -1)
	{
		if (ans[1] == -1)
		{
			cout << 0;
			return 0;
		}
		else
		{
			long long t = abs(ans[0] - ans[1]);
			cout << (t & 1 ? t : t / 2);
			return 0;
		}
	}
 
	sort(ans, ans + 3);
		if ((ans[0] + ans[2]) == 2 * ans[1])
		{
			cout << ans[2]-ans[1];
		}
		else
		{
			cout << -1;
		}
		return 0;
}
