#include<bits/stdc++.h>
#define ld long double 
#define ll long long 
//#define int ll
#define eps 1e-11
#define fastio ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
typedef pair<ll, int> P;
 
const int maxn = 1000, infty = 100000;
 
const string p = "RGB";
 
int main()
{
	fastio;
	int T;
	cin >> T;
	while (T--)
	{
		string s;
		int n, k, ans;
		cin >> n >> k >> s;
		ans = k;
		for (int i = 0; i <= n - k; i++)
		{
			for (int t = 0; t < 3; t++)
			{
				int cur = 0;
				for (int j = 0; j < k; j++)
				{
					if (s[i + j] != p[(j+t) % 3])
						cur++;
				}
				ans = min(cur, ans);
			}
		}
		cout << ans << endl;
	}
	
}
