#include<bits/stdc++.h>
#define ll long long

using namespace std;

const int maxn = 17;

int x[maxn], y[maxn], dis[maxn][maxn];
ll dp[1 << maxn][maxn] = {0}; //dp[state][t]表示已经遍历完 state 中位为1的城市，正在t城市，还需要的最小花费
int n, s;

//直接递归做，最多只有18层，而且能忽略掉从 s 开始时不可能发生的情形
ll bfs(int state, int cur)
{
	if (dp[state][cur] != 0)
		return dp[state][cur];
	if (state + 1 == (1 << n)) // all are visited
		return 0;
	dp[state][cur] = LLONG_MAX;
	for (int next = 0; next < n; next++)
	{
		if ((state&(1<<next))==0) //next is not visited
			dp[state][cur] = min(dp[state][cur],
				bfs(state | (1 << next), next) + dis[cur][next]);//go from cur to next, and use bfs to visit remaining cities starting from next
	}
	return dp[state][cur];
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	//我偏要用0标号，因为用1开始，第0个格子会浪费掉，空间会x2
	cin >> n >> s;
	s--;
	for (int i = 0; i < n;i++)
	{
		cin >> x[i] >> y[i];
	}
	for (int i = 0; i < n; i++)
	{
		dis[i][i] = -1;
		for (int j = i + 1; j < n; j++)
			dis[i][j] = dis[j][i] = abs(x[i] - x[j]) + abs(y[i] - y[j]);//与处理一下任意两点的距离
	}

	cout << bfs(1 << s, s);
	return 0;
}
