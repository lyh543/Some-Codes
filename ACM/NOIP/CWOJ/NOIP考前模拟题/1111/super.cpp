#include<iostream>
#include<cstdio>

using namespace std;

long long delete0(long long d)
{
	long long t = d, ans = 0;
	int base = 1;
	while(t != 0)
	{
		if (t % 10 != 0)
		{
			ans +=  t % 10 * base;
			base *= 10;
		}
		t = t / 10;
	}
	return ans;
}

int main()
{
	freopen("super.in","r",stdin);
	freopen("super.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int T;
	cin >> T;
	long long a, b;
	for (int i = 0; i < T; i++)
	{
		cin >> a >> b;
		if (delete0(a) + delete0(b) == delete0(a+b))
			cout << "YES\n";
		else
			cout << "NO\n";
	}
//	long long a;
//	cin >> a;
//	cout << delete0(a);
}
