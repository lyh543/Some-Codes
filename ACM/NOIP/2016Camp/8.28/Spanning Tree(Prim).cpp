#include<iostream>
#include<algorithm>

using namespace std;

const int point_size = 100, line_size = 100;
const int INF = 99999;
int point_n, line_n, inTree_n = 0;
bool inTree[point_size] = {0};
int dis[point_size+1][point_size+1] = {0};
int disToSys[point_size+1];

int calculateMin()
{
	int sum = 0;
	inTree[1] = true;
	inTree_n = 1;
	for (int i = 2; i <= point_n; i++)
		disToSys[i] = dis[1][i];
	
	int min_p;
	while (inTree_n < point_n)
	{
		int min = INF;
		for (int i = 1; i <= point_n; i++)
			if (!inTree[i] && disToSys[i] < min)
			{
				min = disToSys[i];
				min_p = i;
			}
		
		inTree[min_p] = true;
		inTree_n++;
		sum += disToSys[min_p];
		
		for (int i = 1; i <= point_n; i++)
			if (!inTree[i] && disToSys[i] > dis[i][min_p])
			{
				disToSys[i] = dis[i][min_p];
			}
	}
	
	return sum;
}

int main()
{
	cin >> point_n >> line_n;
	
	for (int i = 1; i <= point_n; i++)
		for (int j = 1; j <= point_n; j++)
			if (i != j) dis[i][j] = INF; // initialise


	for (int i = 0 ; i < line_n; i++)
	{
		int a, b, d;
		cin >> a >> b >> d;
		dis[a][b] = dis[b][a] = d;
	}
	
	cout << calculateMin(); 
	
}

/*

input data:

6 11
1 2 6
1 2 9
1 3 3
2 3 4
3 3 1 
4 3 3
2 4 2
5 1 7
5 3 8
6 2 5
6 4 2
		_
	   / \
	  1---2 
	 /|	  |\ 
	5 |   | 6
	 \|   |/
	 _3---4
	/ |
	\_/
answer: 17
*/



