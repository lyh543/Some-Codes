#include<bits/stdc++.h>

#define ld long double 
#define ll long long
#define infty 0x3fffffffll
#define fastio ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;

const string weekday[5] = { "Monday", "Tuesday", "Wednesday", "Thursday", "Friday" };

signed main()
{
	fastio;
	int T;
	cin >> T;
	while (T--)
	{
		ll y1, y2, m1, m2, d1, d2, times;
		string str;
		cin >> y1 >> m1 >> d1 >> str >> y2 >> m2 >> d2;
		times = ((y2 - y1) * 12 + m2 - m1) * 30 + d2 - d1;
		times %= 5;
		for (int i = 0; i < 5; i++)
		{
			if (str == weekday[i])
				times += i;
		}
		times = (times + 5) % 5;
		cout << weekday[times] << endl;
	}
}
