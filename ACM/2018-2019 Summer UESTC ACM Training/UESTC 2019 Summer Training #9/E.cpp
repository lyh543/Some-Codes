#include<bits/stdc++.h>
#include<unordered_set>
#define ld long double 
#define ll long long
#define int ll
#define infty 0x3fffffffll
#define fastio ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;

const int maxn = 100005, mod = 998244353;

int a, num[maxn];

int degree[maxn];
signed main()
{
	fastio;
	int n;
	cin >> n;
	for (int i = 1; i < n; i++)
	{
		int a, b;
		cin >> a >> b;
		degree[a]++;
		degree[b]++;
	}
	vector<int> degree1;
	int degree3 = 0;
	for (int i = 1; i <= n; i++)
	{
		if (degree[i] >= 3)
		{
			if (degree3 != 0)
			{
				cout << "No";
				return 0;
			}
			else
			{
				degree3 = i;
			}
		}
		else if (degree[i] == 1)
			degree1.push_back(i);
	}
	if (degree3 == 0)
	{
		cout << "Yes\n1\n" << degree1[0] << " " << degree1[1];
	}
	else
	{
		cout << "Yes\n" << degree[degree3] << endl;
		for (int i : degree1)
		{
			cout << degree3 << " " << i << endl;
		}
	}
}
