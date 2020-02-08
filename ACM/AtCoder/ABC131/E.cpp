#include<bits/stdc++.h>
#define ll long long
using namespace std;
struct point {
	int x;
	int y;
};
list<point> l;
int main()
{
	int n, k;
	cin >> n >> k;
	if ((n - 2)*(n - 1) / 2 < k)
	{
		cout << -1;
		return 0;
	}
	else
	{
		int t = (n - 2)*(n - 1) / 2;
		for (int i = 2; i <= n; i++)
			l.push_back({ 1,i });
		for (int i = 2; i <= n; i++)
		{
			for (int j = i + 1; j <= n; j++)
			{
				if (t == k)
					break;
				l.push_back({ i,j });
				t--;
			}
		}
	}
	cout << l.size() << endl;
	for (point p : l)
	{
		cout << p.x << " " << p.y << endl;
	}
	return 0;
}

