#include <bits/stdc++.h>
#define ll long long
#define ld long double
using namespace std;
 
int main()
{
	int a, b, c;
	char ans;
	cin >> a >> b >> c;
	if (a > b + c)
	{
		ans = '+';
	}
	else if (a + c < b)
	{
		ans = '-';
	}
	else if (a == b && c == 0)
	{
		ans = '0';
	}
	else ans = '?';
	cout << ans;
}
