#include<bits/stdc++.h>
//#define _CRT_SECURE_NO_WARNINGS
#define ld long double 
#define ll long long 
#define int ll
#define eps 1e-11
#define fastio ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
typedef pair<int, int> P;
 
const int maxn = 1e6+5;
 
char str[maxn];
vector<P> v;
 
signed main()
{
	fastio;
	cin >> str;
	int len = strlen(str);
	int sum = 0, temp = 0, ans = 0;
	for (int i = 0; i < len; i++)
	{
		if (str[i] == 'o')
		{
			if (temp > 0)
			{
				sum += temp - 1;
				int k = 1;
				while (str[i + 1] == 'o')
					i++, k++;
				v.push_back({ temp - 1,k });
				temp = 0;
			}
		}
		else
		{
			temp++;
		}
	}
	if (temp > 1)
	{
		sum += temp - 1;
		v.push_back({ temp - 1,1 });
	}
	int sum2 = 0;
	for (auto i : v)
	{
		sum2 += i.first;
		ans += sum2 * i.second * (sum-sum2);
	}
	cout << ans;
}
