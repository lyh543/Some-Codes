#include<bits/stdc++.h>
#define ld long double 
#define ll long long 
//#define int ll
#define eps 1e-11
#define fastio ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
typedef pair<ll, int> P;

const int maxn = 2e5+5, infty = 100000;

int main()
{
	fastio;
	int n;
	string s;
	cin >> n >> s;
	for (int i = s.length() / 2; i > 0; i--)
	{
		int flag = 1;
		for (int j = 0; j < i; j++)
		{
			if (s[i + j] != s[j])
			{
				flag = false;
				break;
			}
		}
		if (flag)
		{
			cout << s.length() - i + 1;
			return 0;
		}
	}
	cout << s.length();
}
