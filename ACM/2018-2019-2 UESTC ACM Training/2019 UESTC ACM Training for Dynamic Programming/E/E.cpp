#define _CRT_SECURE_NO_WARNINGS
#include<bits/stdc++.h>
using namespace std;

const int maxn = 2000;

int matrix[maxn];
char str[maxn];
int n,k;

int dp[maxn][27];
//dp[l][j]: if line l remove j due to upper lines
//the longest combo the lower line l have.
//j==26 if line l don't remove anything

int dfs(int line, int mov)
{
	if (line == n-1)
		return 0;
	if (dp[line][mov] != 0)
		return dp[line][mov];
	
	int temp = matrix[line] & matrix[line + 1];

	//if the cur line has the mov and other alphas, move th mov
	//It's for those who has only one letter, that can be choosed both at beginning and end
	if (matrix[line] ^ (1 << mov) &&mov != 26) 
		temp &= ~(1 << mov);

	dp[line][mov] = dfs(line+1,26);
	for (int i = 0; i < 26; i++)
	{
		if (temp&(1 << i))
			dp[line][mov] = max(dp[line][mov], dfs(line + 1, i)+1); //remove i
	}
	return dp[line][mov];
}

int main()
{
	int T;
	scanf("%d", &T);
	for (int kase = 0; kase < T; kase++)
	{
		int ans = 0;
		memset(matrix, 0, sizeof(matrix));
		memset(dp, 0, sizeof(dp));
		scanf("%d%s", &k,str);
		n = strlen(str) / k;
		int l = 0;
		for (int i = 0; i < n; i++)
			for (int j = 0; j < k; j++)
			{
				int t = str[i*k + j] - 'a';
				if ((matrix[i]&(1<<t))== 0)
				{
					ans++;
					matrix[i] |= (1 << t);
				}
			}
		printf("%d\n", ans - dfs(0,26));
	}
	return 0;
}