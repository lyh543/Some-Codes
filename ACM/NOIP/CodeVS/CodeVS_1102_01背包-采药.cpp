//http://codevs.cn/problem/1102/ 
#include<iostream>

using namespace std;

int t, m, NeedTime[105], EveryValue[105]; //条件
int ValueCanGet[1001][101]; //ValueCanGet[i][j] 表示在 i 时间里从前 j 棵草药中能得到的价值
//int getPlant(int,int,int);

int main()
{
	cin >> t >> m;
	for (int i = 1; i <= m; i++)
	{
		cin >> NeedTime[i] >> EveryValue[i];
	}

	for (int i = 1; i <= m; i++)
	{
		ValueCanGet[i][0] = 0; //从前 0 棵草药中时得不到东西
	}
	for (int timeRemaining = 1; timeRemaining <= t; timeRemaining++)
	{
		for (int n = 1; n <= m; n++)
		{
			int value = ValueCanGet[timeRemaining][n-1];
			//拿不到第 n 棵草药，就等同于拿 n - 1 棵草药的情况
			if (timeRemaining >= NeedTime[n] 
			//如果能拿到第 n 棵草药
			&& value < ValueCanGet[timeRemaining - NeedTime[n]][n - 1] + EveryValue[n])
			//并且拿第 n 棵草后的价值（扣除拿第 n 棵草的时间后能拿到的草的价值加第 n 棵草的价值）超过不拿的价值
				value = ValueCanGet[timeRemaining - NeedTime[n]][n - 1] + EveryValue[n];
			ValueCanGet[timeRemaining][n] = value;
		}
	}
	cout << ValueCanGet[t][m];
	return 0;
}


