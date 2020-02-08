#include <bits/stdc++.h>
#define ll long long 
#define ld long double
using namespace std;

const int maxn = 10001;


int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		int a, b, c;
		cin >> a >> b >> c;
		if (!(a + b > c && b + c > a && a + c > b))
		{
			cout << "NO";
			return 0;
		}
	}
	cout << "YES";
}
