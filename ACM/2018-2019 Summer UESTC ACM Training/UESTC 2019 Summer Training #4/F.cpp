#include<iostream>
#include<algorithm>
#include<cstring>
#define _CRT_SECURE_NO_WARNINGS
#define ld long double 
#define ll long long 
#define eps 1e-11
#define fastio ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
const int maxn = 1e3 + 5;

struct S
{
	int index;
	char s[10];
	ll a;
	ll c;
}p[maxn];

bool cmp(const S &a, const S &b)
{
	ll a1c2 = a.a*b.c, a2c1 = a.c*b.a;
	if (a1c2 == a2c1)
	{
		//return (strcmp(a.s, b.s) < 0);
		return a.index < b.index;
	}
	else
		return a1c2 < a2c1;
}

int main()
{
	fastio

	int n;
	while (cin >> n)
	{
		for (int i = 1; i <= n; i++)
		{
			ll b;
			cin >> p[i].a >> b >> p[i].c;
			p[i].a += b;
			p[i].index = i;
			sprintf(p[i].s, "%d", i);
		}

		sort(p + 1, p + n + 1, cmp);
		for (int i = 1; i <= n; i++)
			cout << (i == 1 ? "" : " ") << p[i].index;
		cout << endl;
	}
}
