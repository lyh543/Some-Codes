#include<bits/stdc++.h>
#define ll long long
using namespace std;
int main()
{
	int a;
	cin >> a;
	if (a < 100)
	{
		cout << "Bad";
		return 0;
	}
	while (a >= 10)
	{
		if (a / 10 % 10 == a % 10)
		{
			cout << "Bad";
			return 0;
		}
		a /= 10;
	}
	cout << "Good";
	return 0;
}

