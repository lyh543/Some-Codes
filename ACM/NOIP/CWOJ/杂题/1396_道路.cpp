//一楼献给学长 
#include<iostream>
#include<cstdio>

using namespace std;

const int matrixSize = 150, inf = 0x7fffffff;
const int xadd[4]={1,0,0,-1}, yadd[4] = {0,-1,1,0};
int n, ans, matrix[matrixSize][matrixSize] = {{0}},numberSize = 0;
bool visited[matrixSize][matrixSize];

bool legal(int x, int y)
{
	return (x >=0 && y >= 0 && x < n && y < n);
}

bool dfs(int x, int y)
{
	visited[x][y] = true;
	for (int direct = 0; direct < 4; direct++)
	{
		int tx = x + xadd[direct], ty = y + yadd[direct];
		if (legal(tx,ty) && visited[tx][ty] == false)
		{
			if (tx + 1 == n && ty + 1 == n) return true;
			if (dfs(tx, ty)) return true;
		}
	}
	return false;
}

bool across(int min, int max)
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			visited[i][j] = (matrix[i][j] < min || matrix[i][j] > max); //不符合范围的直接标为true 
		}
	}
	return (!visited[0][0] && dfs(0,0));
}

int bs(int min, int l, int r) //学长所说的二分。返回的是一个合适的最大值，l和r两边都可以取 
{
	if (l == r)
	{
		return across(min, l) ? l : inf;
	}
	int m = (l + r) / 2;
	if (across(min, m))
	{
		//cout << min << "~" << m << "is OK\n";
		return bs(min, l, m);
	}
	else
	{
		//cout << min << "~" << m << "is not OK\n";
		return bs(min, m+1, r);
	}
}

/*for (int max = min; max <= numberSize && max < ans + min; max++)
	{
		if (across(min,max))
			{
				if (max - min < ans)
				{
					ans = max - min;
					cout << min << "~" << max << "is OK\n"; 
					break;
				}
			}
			//else cout << min << "~" << max << "is not OK\n"; 
	}*/
int main()
{
	
	//freopen("road8.in", "r", stdin);
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cin >> matrix[i][j];
			numberSize = max(numberSize, matrix[i][j]);
		}
	}
	ans = numberSize;
	
	for (int min = 0; min <= numberSize; min++) //学长说的枚举 
	{
		//拒绝二分的方法 
		/*for (int max = min; max <= numberSize && max < ans + min; max++)
		{
			if (across(min,max))
			{
				if (max - min < ans)
				{
					ans = max - min;
					cout << min << "~" << max << "is OK\n"; 
					break;
				}
			}
			//else cout << min << "~" << max << "is not OK\n"; 
		}*/
		
		//学长说必须用二分
		int t = bs(min, min, numberSize);
		if (t - min < ans) ans = t - min;
	}

	cout << ans;
}


