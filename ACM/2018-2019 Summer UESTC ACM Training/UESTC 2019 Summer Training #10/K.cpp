#include<bits/stdc++.h>
//#define _CRT_SECURE_NO_WARNINGS
#define ld long double 
#define ll long long 
#define int ll
#define eps 1e-11
#define fastio ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
typedef pair<int, int> P;
const int maxn = 4000, mod = 1e9 + 7;

signed main()
{
	fastio;
	int T;
	cin >> T;
	while (T--)
	{

		int curscore = 0, cur;
		int ans[10] = { 0 };
		int a, b, n, tmp = 0;
		cin >> a >> b >> n;
		for (int i = 1; tmp <= n; i++)
		{
			int score[10] = { 0 };
			tmp = a * i*i + b * i;
			if (tmp > n)
				break;
			int ttmp = tmp;
			while (ttmp != 0)
			{
				score[ttmp % 10]++;
				ttmp /= 10;
			}
			int curscore = 0;
			vector<int> cur;
			for (int i = 0; i < 10; i++)
			{
				if (score[i] > curscore)
				{
					curscore = score[i];
					cur.clear();
					cur.push_back(i);
				}
				else if (score[i] == curscore)
				{
					cur.push_back(i);
				}
			}
			for (int i : cur)
				ans[i]++;
		}
		for (int i = 0; i < 10; i++)
		{
			if (ans[i] > curscore)
			{
				curscore = ans[i];
				cur = i;
			}
		}
		cout << (curscore ? cur : -1) << endl;
	}
}
