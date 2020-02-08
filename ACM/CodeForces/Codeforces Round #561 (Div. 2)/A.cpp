//#define debug
#include<bits/stdc++.h>
 
using namespace std;
const int maxn = 6000;
 
int a[26];
 
int main()
{
	cin.sync_with_stdio(0);
	cin.tie(0);
 
	int n;
	cin >> n;
	string str;
 
	for (int i = 0; i < n; i++)
	{
		cin >> str;
		a[str[0] - 'a']++;
	}
 
	int ans = 0;
	for (int i = 0; i < 26; i++)
	{
		int t1 = a[i] / 2, t2 = a[i] - t1;
		ans += (t1 - 1)*t1 / 2 + (t2 - 1)*t2 / 2;
	}
 
	cout << ans;
}
