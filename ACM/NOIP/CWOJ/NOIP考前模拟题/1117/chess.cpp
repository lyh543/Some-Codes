#include<iostream>
#include<cstdio>

//#define debug

using namespace std;

const int size = 10;

int chessN, boardN, chessIn = 0;
int board[size];
bool hole[size][size] = {{false}};

bool legal(int x, int y)
{
	if (hole[x][y]) return false;
	for (int i = 0; i < x; i++)
		if (board[i] == y) return false; 
	
	board[x] = y; 
	return true;
}

int getRidOf(int n)
{
	board[n] = -1;
}

int dfs(int n,int k)
{
	if  (k == chessN)
	{
		//cout << "Ans:";
		//for (int i = 0; i < boardN; i++) if (board[i] == -1) cout << 'x'; else cout << board[i];
		//cout << endl;
		return 1;
	}
	if (n == boardN)
		return 0;

	int ans = 0;
	for (int i = 0; i < boardN; i++)
	{
		if(legal(n+1, i))
		{
			ans += dfs(n+1, k+1);
		}
	}
	getRidOf(n);
	ans += dfs(n+1, k);
	return ans;
}

int main()
{
#ifndef debug
	freopen("chess.in", "r", stdin);
	freopen("chess.out", "w", stdout);
#endif

	scanf("%d%d", &boardN, &chessN);
	
	char c;
	for (int i = 0; i < boardN; i++)
	{
		int j = 0;
		c = getchar();
		while (j < boardN)
		{
			switch(c)
			{
				case '.' : hole[i][j] = true;
				case '#' : j++;
			}
			c = getchar();
		}
	}
	for (int i = 0; i < boardN; i++) board[i] = -1;
	
	printf("%d", dfs(0, 0));

#ifndef debug
	fclose(stdin);
	fclose(stdout);
#endif
}
