#include<bits/stdc++.h>
 
using namespace std;
 
int main()
{
	cin.sync_with_stdio(0);
	cin.tie(0);
	char last, cur;
	int n;
	cin >> n;
	cin >> last;
	for (int i = 2; i <= n; i++)
	{
		cin >> cur;
		if (cur < last)
		{
			cout << "YES" << endl << i - 1 << " " << i;
			return 0;
		}
		last = cur;
	}
	cout << "NO";
	return 0;
}
