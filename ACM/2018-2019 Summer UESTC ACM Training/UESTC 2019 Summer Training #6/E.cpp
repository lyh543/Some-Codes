#include<bits/stdc++.h>
#define ld long double 
#define ll long long
#define int long long
#define infty 0x3fffffffll
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

int dfs(int n,int upper)
{
	if (n == 0)
		return 0;
	if (upper < 0)
		return infty;
	int ans = infty;
	int t = n, i = 1, lastt  = 0;
	while (t >= 10)
	{
		lastt = t % 10;
		t /= 10;
		i++;
	}
	if (lastt > t)
		t++;
	int n1 = abs(n - make1(i)*t);
	int n3 = abs(n - make1(i)*(t - 1));
	int n2 = abs(n - make1(i + 1));
	ans = min(ans, t * i + dfs(n1,upper-t*i));
	if (t > 1)
		ans = min(ans, (t*i) - i + dfs(n3, min(ans, upper)-(t*i)+i));
	ans = min(ans, 1+i + dfs(n2,min(ans,upper)-i-1));
	return ans;
}

signed main()
{
	fastio;
	int n, ans = 0;
	cin >> n;
	cout << dfs(n,infty);
	return 0;
}
