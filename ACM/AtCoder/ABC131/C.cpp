#include<bits/stdc++.h>
#define ll long long
using namespace std;


ll a, b, c, d;

ll divide(ll t)
{
	return b / t - (a - 1) / t;
}

ll gcd(ll a, ll b)
{
	return (b == 0 ? a : gcd(b, a%b));
}

int main()
{
	cin >> a >> b >> c >> d;
	cout << (b - a + 1 - divide(c) - divide(d) + divide(c*d/gcd(c,d)));
}
//
//struct work
//{
//	int t;
//	int e;
//};
//
//bool operator < (work t, work e)
//{
//	return t.e < e.e;
//}
//
//int main()
//{
//	int n;
//	cin >> n;
//	fo
//}

