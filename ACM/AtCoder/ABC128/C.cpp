#include<bits/stdc++.h>
using namespace std;

vector<int> s[10];

int main()
{
	int n, m, p[10];
	cin >> m >> n;
	for (int i = 0; i < n; i++)
	{
		int k;
		cin >> k;
		for (int j = 0; j < k; j++)
		{
			int a;
			cin >> a;
			s[i].push_back(a);
		}
	}
	for (int i = 0; i < n; i++)
	{
		cin >> p[i];
	}

	int ans = 0;
	for (int state = 0; state < (1 << m); state++)
	{
		bool flag = true;
		for (int i = 0; i < n; i++)
		{
			int t = 0;
			for (int j = 0; j < s[i].size(); j++)
			{
				if (state&(1<<(s[i][j]-1))) t++;
			}
			if (t % 2 != p[i])
			{
				flag = false;
				break;
			}
			if (flag == false)
				break;
		}
		if (flag == true)
			ans++;
	}

	cout << ans;
}

