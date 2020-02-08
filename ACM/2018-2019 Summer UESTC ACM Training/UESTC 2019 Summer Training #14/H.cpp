#include<bits/stdc++.h>
#define ld long double 
#define ll long long 
//#define int ll
#define eps 1e-11
#define fastio ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
typedef pair<ll, int> P;

const ll maxn = 5e5 + 5, mod = 1e9 + 7;

set<int> info[2][2];

int cnt = 0;

int main()
{
	fastio;
	int n;
	cin >> n;
	int t = n, tmax = 0, ans = 0, missing = 0;
	while (t != 0)
	{
		tmax++;
		t >>= 1;
	}
	for (int i = 1; i <= n; i++)
		info[1][0].insert(i);

	for (int i = 0; i < tmax; i++)
	{
		int temp = 1 << (i - 1);
		info[i % 2][0].clear();
		info[i % 2][1].clear();
		//cout << "Size: " << info[(j + 1) % 2][missing].size() - temp << endl;
		for (const int j : info[(i + 1) % 2][missing])
		{
			cnt++;
			if (cnt > 2 * n + 19)
			{
				return 20001228;
			}
			cout << "? " << j << " " << i << endl;
			cout.flush();
			int a;
			cin >> a;
			info[i % 2][a].insert(j);
			/*if (info[j % 2][1].size() == info[(j + 1) % 2][missing].size() + 1 - temp || info[j % 2][0].size() == temp)
				break;*/
		}
		if (info[i % 2][0].size() > info[i%2][1].size())
		{
			missing = 1;
		}
		else
		{
			missing = 0;
		}
		ans += missing << i;
	}
	cout << "! " << ans << endl;
	cout.flush();
}
