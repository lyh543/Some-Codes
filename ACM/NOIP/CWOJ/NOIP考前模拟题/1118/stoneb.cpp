#include<iostream>
#include<cstdio>
#include<algorithm>

using namespace std;

const int weightSize = 2523, stoneSize = 233;

int stoneN, maxStoneN, weightN, ans=0;

int stone[stoneSize];
int dp[weightSize] = {0};

int main()
{
	freopen("stonea.in", "r", stdin);
	freopen("stonea.out", "w", stdout);
	
	scanf("%d%d%d", &stoneN, &maxStoneN, &weightN);
	for (int i = 0; i < stoneN; i++)
		scanf("%d", &stone[i]);
		
	for (int cur = 0; cur < stoneN; cur++)
	{
		ans += stone[cur];
	}
	
	printf("%d", ans);
	
	fclose(stdin);
	fclose(stdout);
}
