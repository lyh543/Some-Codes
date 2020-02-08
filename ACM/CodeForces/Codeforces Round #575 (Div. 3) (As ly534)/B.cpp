#include<bits/stdc++.h>
#define ld long double 
#define ll long long 
//#define int ll
#define eps 1e-11
#define fastio ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
typedef pair<ll, int> P;
 
const int maxn = 1000;
 
int main()
{
	fastio;
	int T;
	cin >> T;
	while (T--)
	{
		int n, k;
		cin >> n >> k;
		vector<int> ans;
		ll sum = 0;
		for (int i = 1; i <= n; i++)
		{
			int  a;
			cin >> a;
			sum ^= a & 1;
			if (k > 1 && sum == 1)
			{
				ans.push_back(i);
				sum = 0;
				k--;
			}
		}
		if (sum == 0)
		{
			cout << "NO\n";
		}
		else
		{
			cout << "YES\n";
			for (int i : ans)
				cout << i << " ";
			cout << n << endl;
		}
	}
	
}
