#include<bits/stdc++.h>
//#define _CRT_SECURE_NO_WARNINGS
#define ld long double 
#define ll long long 
//#define int ll
#define eps 1e-11
#define fastio ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
typedef pair<int, int> P;
const int maxn = 4000, mod = 1e9 + 7;

signed main()
{

	fastio;
	int T;
	cin >> T;
	cout << fixed << setprecision(6);
	while (T--)
	{
		unordered_map<string, ld> m;
		int n, M;
		cin >> n >> M;
		ld ans = 0;
		m[string("JD")] = 1;
		for (int i = 0; i < n; i++)
		{
			string s;
			ld t;
			cin >> s >> t;
			m[s] = t;
		}
		for (int i = 0; i < M; i++)
		{
			string s;
			ld t;
			cin >> t >> s;
			ans += m[s] * t;
		}
		cout <<  ans << endl;
	}
}
