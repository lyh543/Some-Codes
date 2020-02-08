#include<iostream>
#include<iomanip>
#include<string>
#include<algorithm>
#define ld long double 
#define ll long long
//#define lll __int128 
//#define int ll
#define eps 1e-11
#define fastio ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
typedef pair<int, int> P;

const int maxn = 1e5 + 5, maxk = 21, infty = 100000, mod = 1125899839733759;

int bits[1 << maxk] = { 0 };

inline int simi(int a, int b)
{
	return maxk - bits[a^b];
}

int arr[maxn];

signed main()
{
	ld pi = 3.1415926535897932384626433832795;
	fastio;
	int T;
	cin >> T;
	cout << fixed << setprecision(6);
	while (T--)
	{
		ld a, b;
		cin >> a >> b;
		ld ans = 2 * b + pi * a;
		ll ans0 = ans * 1e6;
		cout << ans0 / 1e6 << endl;
	}
}
