#include<bits/stdc++.h>
#define ll long long
#define ld long double
using namespace std;
 
const int maxn = 1e6 + 5;
 
char a[maxn], b[maxn];
 
int c(ld a)
{
	int sgn = a > 0 ? 1 : -1;
	if (int(a) == a)
		return int(a);
	else
		return int(a) + sgn;
}
 
int f(ld a)
{
	return int(a);
}
 
int main()
{
	ld sum = 0, t;
	ll sumi = 0, n, tc, tf;
	
	ios::sync_with_stdio();
	cin.tie(0);
 
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> t;
		sum += t;
		tc = c(t);
		tf = f(t);
		if (fabs(sumi + tc - sum) < fabs(sumi + tf - sum))
		{
			cout << tc << endl;
			sumi += tc;
		}
		else
		{
			cout << tf << endl;
			sumi += tf;
		}
	}
	return 0;
}
