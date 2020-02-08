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
		int n, last, cur, up = 1, flag = 1;
		cin >> n;
		cin >> last;
		for (int i = 1; i < n; i++)
		{
			cin >> cur;
			if (flag)
			{
				if (up == 1)
				{
					if (last == cur || (last > cur && i == 1))
					{
						flag = 0;
					}
					else if (last > cur)
					{
						up = -1;
					}
				}
				else
				{
					if (last <= cur)
					{
						flag = 0;
					}
				}
				last = cur;
			}
		}
		if(flag && up == -1)cout << "Yes\n";
		else cout << "No\n";
	}
}