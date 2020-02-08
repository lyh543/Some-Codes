#include<bits/stdc++.h>
#include<unordered_map>
#define ll long long
#define ld long double
#define fastio ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);

using namespace std;
typedef pair<int, int> P;

int main()
{
	int n, sqrtn;
	cin >> n;
	if (n == 2) {
		cout << 1;
		return 0;
	}
	else if (n % 2 == 0)
	{
		cout << 2;
		return 0;
	}
	sqrtn = sqrt(n) + 1;
	int flag1 = 1, flag2 = 1;
	for (int i = 2; i <= sqrtn; i++)
	{
		if (n % i == 0)
		{
			flag1 = 0;
		}
		else if ((n - 2) % i == 0)
		{
			flag2 = 0;
		}
	}
	if (flag1)
		cout << 1;
	else if (flag2)
		cout << 2;
	else
		cout << 3;
}
