#include<bits/stdc++.h>
#define ld long double 
#define ll long long
#define fastio ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;

const int maxn = 2e5 + 5;

int make1(int n)
{
	int ans = 1;
	for (int i = 1; i < n; i++)
	{
		ans = ans * 10 + 1;
	}
	return ans;
}

int main()
{
	fastio;
	ld x, y;
	cin >> x >> y;
	ld l = x * log(y), r = y * log(x);
	if (fabs(l - r) < 1e-8)
		cout << "=";
	else
		cout << (l < r ? ">" : "<");
}
