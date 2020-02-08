#include<bits/stdc++.h>
#define ld long double 
#define ll long long 
 
using namespace std;
 
int mj[100] = { 0 };
 
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
 
	int a, ans = 0;
	char c;
	for (int i = 0; i < 3; i++)
	{
		cin >> a >> c;
		if (c == 's')
			a += 11;
		else if (c == 'p')
			a += 22;
		mj[a]++;
		ans = max(ans, mj[a]);
	}
 
	int last = 0;
	for (int i = 1; i <= 50; i++)
	{
		if (mj[i])
			last++;
		else
		{
			if (last == 1 && mj[i + 1])
				last++;
			ans = max(ans, last);
			last = 0;
		}
	}
 
	cout << 3 - min(ans, 3);
}

