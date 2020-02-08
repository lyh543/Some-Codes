#include<bits/stdc++.h>
#define ll long long
#define ld double
using namespace std;

const int maxn = 1e6 + 5, maxq = 10005;


int main()
{
	ll x, y, X, Y, equal = 0;
	cin >> X >> Y >> x >> y;
	cout << X * Y / 2 << (X*Y % 2 ? ".5 " : " ") << ((2 * x == X) && (2 * y == Y));


}

