#include<iostream>
#include<cstdio>
#include<algorithm>

using namespace std;

const int weightSize = 23;

int stoneN, maxStoneN, weightN, ans=0;

int stone[weightSize];


bool cmp(int a, int b)
{
	return a > b;
}

int getAns(int position, int remainStone, int nowWeight)
{
	if (nowWeight > weightN) return 0;
	if (remainStone == 0)
	{
		if (ans < nowWeight) ans = nowWeight;
		return 1;
	}
	if (position == stoneN)
		return 0;
	
	getAns(position+1, remainStone, nowWeight); //give up the stone
	getAns(position+1, remainStone-1, nowWeight+stone[position]);//get the stone 
}

int main()
{
	freopen("stonea.in", "r", stdin);
	freopen("stonea.out", "w", stdout);
	
	scanf("%d%d%d", &stoneN, &maxStoneN, &weightN);
	for (int i = 0; i < stoneN; i++)
		scanf("%d", &stone[i]);
		
	sort(stone, stone + stoneN, cmp);
	
	getAns(0, maxStoneN, 0);
	
	printf("%d", ans);
	
	fclose(stdin);
	fclose(stdout);
}
