//I just learned from VIJOS 1446
//Dalaos in CWOJ, can you make your codes OpenSource?
#include<iostream>
#include<cstdio>

using namespace std;

const int pointSize= 110; 

int dis[pointSize][pointSize];

int main()
{
	//freopen("input.txt","r",stdin);
	
	int pointN, lineN;
	scanf("%d%d", &pointN, &lineN);
	for (int i = 1; i <= pointN; i++)
		for (int j = 1; j <= pointN; j++)
			if (i == j) dis[i][j] = 0;
			else dis[i][j] = pointSize; //initialization
	
	int a, b;
	for (int i = 0; i < lineN; i++) //input
	{
		scanf("%d%d", &a, &b);
		dis[a][b] = dis[b][a] = 1;
	}
	
	for (int k = 1; k <= pointN; k++) //Floyd
		for (int j = 1; j <= pointN; j++)
			for (int i = 1; i <= pointN; i++)
				if (dis[i][k] + dis[k][j] < dis[i][j])
					dis[i][j] = dis[i][k] + dis[k][j];
					
	int askN;
	scanf("%d",&askN);
	for (int cnt = 0; cnt < askN; cnt++)
	{
		int ans = 0, a, b;
		scanf("%d%d", &a, &b);
		for (int i = 1; i <= pointN; i++)
		{
			if (dis[a][b] == dis[a][i] + dis[i][b])
			{
				ans++;//SPECTACULAR!
				//printf("For %d-%d, %d is OK\n",a,b,i);
			}
		}
		printf("%d\n", ans); //2: start & end point
	}
	
	return 0;
}
