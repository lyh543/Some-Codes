#include<bits/stdc++.h>
#define ld long double 
#define ll long long
#define fastio ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
 
const int maxn = 105;
 
char s[maxn], t[maxn], p[maxn];
 
int main()
{
	fastio;
	int T;
	cin >> T;
	for (int i = 0; i < T; i++)
	{
		int alpha[26] = { 0 };
		int ans = 1;
		cin >> s >> t >> p;
		if (strlen(s) > strlen(t))
		{
			cout << "No\n";
			continue;
		}
		for (int x = 0; p[x] != 0; x++)
		{
			alpha[p[x] - 'a']++;
		}
		int j = 0, k = 0;
		while (s[j] != 0 && t[k] != 0)
		{
			if (s[j] == t[k])
			{
				j++, k++;
				continue;
			}
			else if (alpha[t[k] - 'a'])
			{
				alpha[t[k] - 'a']--;
				k++;
			}
			else
			{
				cout << "No\n";
				ans = 0;
				break;
			}
		}
		if (ans == 0)
			continue;
		if (t[k] == 0 && s[j] != 0)
		{
			cout << "No\n";
			continue;
		}
		while (t[k] != 0)
		{
			if (alpha[t[k] - 'a'])
			{
				alpha[t[k] - 'a']--;
				k++;
			}
			else
			{
				cout << "No\n";
				ans = 0;
				break;
			}
		}
		if (ans != 0)
			cout << "Yes\n";
	}
}
