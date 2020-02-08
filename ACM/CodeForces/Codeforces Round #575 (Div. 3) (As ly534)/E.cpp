#include<bits/stdc++.h>
#define ld long double 
#define ll long long 
//#define int ll
#define eps 1e-11
#define fastio ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
typedef pair<ll, int> P;
 
const int maxn = 1000, infty = 100000;
 
const string p = "RGB";
 
int main()
{
	fastio;
	int T;
	cin >> T;
	while (T--)
	{
		int b, w;
		cin >> b >> w;
		if (b > 3 * w + 1 || w > 3 * b + 1)
		{
			cout << "NO\n";
			continue;
		}
		cout << "YES\n";
		if (b >= w)
		{
			for (int i = 1; i <= w; i++)
			{
				cout << 3 << " " << 2 * i + 1 << endl;
			}
			int m = min(b, w+1);
			for (int j = 1; j <= m; j++)
			{
				cout << 3 << " " << 2 * j << endl;
			}
			b -= m;
			if (b == 0)
				continue;
			 m = min(b, w);
			for (int j = 1; j <= m; j++)
			{
				cout << 2 << " " << 2 * j + 1 << endl;
			}
			b -= m;
			if (b == 0)
				continue;
			 m = min(b, w);
			for (int j = 1; j <= m; j++)
			{
				cout << 4 << " " << 2 * j + 1 << endl;
			}
		}
		else
		{
			swap(b, w);
			for (int i = 1; i <= w; i++)
			{
				cout << 2 << " " << 2 * i + 1 << endl;
			}
			int m = min(b, w + 1);
			for (int j = 1; j <= m; j++)
			{
				cout << 2 << " " << 2 * j << endl;
			}
			b -= m;
			if (b == 0)
				continue;
			 m = min(b, w);
			for (int j = 1; j <= m; j++)
			{
				cout << 1 << " " << 2 * j + 1 << endl;
			}
			b -= m;
			if (b == 0)
				continue;
			 m = min(b, w);
			for (int j = 1; j <= m; j++)
			{
				cout << 3 << " " << 2 * j + 1 << endl;
			}
		}
	}
	
}
