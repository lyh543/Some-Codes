#include<bits/stdc++.h>
 
using namespace std;
 
int main()
{
	cin.sync_with_stdio(0);
	cin.tie(0);
	char cur;
	int di8 = 0, di0 = 0;
	int n, del;
	cin >> n;
	del = n - 10;
	for (int i = 0; i < del; i++)
	{
		cin >> cur;
		if (cur == '8')
		{
			di8++;
		}
		else
		{
			di0++;
		}
	}
	cout << (di8 > di0 ? "YES" : "NO");
	return 0;
}
