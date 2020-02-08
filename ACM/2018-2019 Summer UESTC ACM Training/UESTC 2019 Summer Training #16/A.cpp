#include<iostream>
#include<iomanip>
#include<string>
#define ld long double 
#define ll long long
//#define lll __int128 
//#define int ll
#define eps 1e-11
#define fastio ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
typedef pair<int, int> P;

const int maxn = 1e6+5;

ld ans[maxn] = { 0 };

signed main()
{
	fastio;
	string s;
	cout << fixed << setprecision(5);
	for (int i = 1; i < maxn; i++)
	{
		ans[i] = ans[i - 1] + 1.0/(ld) i / i;
	}
	while(cin >> s)
	{
		ll n;
		if (s.length() > 6)
			n = maxn - 5;
		else
			n = atol(&s[0]);
		cout <<ans[n] << "\n";
	} 
	return 0;
}
