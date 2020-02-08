#include<bits/stdc++.h>
#include<unordered_set>
#define ld long double 
#define ll long long
#define int ll
#define infty 0x3fffffffll
#define fastio ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
typedef pair<int, int> P;
 
const int maxn = 3005;
 
int arr[maxn][maxn] = { 0 }, min1[maxn][maxn] = { 0 }, min2[maxn][maxn] = { 0 };
 
deque<int> q;
 
signed main()
{
	fastio;
	int n, m, a, b, g0, x, y, z, ans = 0;
	cin >> n >> m >> a >> b >> g0 >> x >> y>>z;
	//对每一行维护一个长度为 b 的单调栈，得到i行中 j 开始每 b 个数的最小值，存进 min2[j][i]，再在 min2[j] 用单调栈求长度为 a 的最小值
	
	int last ;
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++)
		{
			if (i == 1 && j == 1)
				last = arr[i][j] = g0;
			else
				last = arr[i][j] = (last * x + y) % z;
		}
 
	for (int i = 1; i <= n; i++)
	{
		q.clear();
		int endp = 1;
		for (; endp < b; endp++)
		{
			while (!q.empty() && arr[i][endp] < arr[i][q.back()])
				q.pop_back();
			q.push_back(endp);
		}
		
		for (; endp <= m; endp++)
		{
			if (!q.empty() && q.front() <= endp - b)
				q.pop_front();
			while (!q.empty() && arr[i][endp] < arr[i][q.back()])
				q.pop_back();
			q.push_back(endp);
			min1[endp-b+1][i] = arr[i][q.front()];
		}
	}
 
	for (int i = 1; i <= m; i++)
	{
		q.clear();
		int endp = 1;
		for (; endp < a; endp++)
		{
			while (!q.empty() && min1[i][endp] < min1[i][q.back()])
				q.pop_back();
			q.push_back(endp);
		}
 
		for (; endp <= n; endp++)
		{
			if (!q.empty() && q.front() <= endp - a)
				q.pop_front();
			while (!q.empty() && min1[i][endp] < min1[i][q.back()])
				q.pop_back();
			q.push_back(endp);
			ans += min1[i][q.front()];
			//cout << min1[i][q.front()] << endl;
		}
	}
	cout << ans;
	return 0;
}
