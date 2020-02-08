#include<iostream>
#include<cstring>
#define debug

using namespace std;

const int xsize = 10005, ysize = 1005, inf = 0x7fffffff;

struct gapStruct{
	int up;
	int down;
}gap[xsize]; //up, down两边都不能碰到 
struct moveStuct{
	int touch;
	int nothing;
}move[xsize];

int UIx, UIy, gapN, cross = 0; 
int matrix[xsize][ysize] ={{0}};

int legal(int x, int y)
{
	return (matrix[x][y] != UIx && y > gap[x].down && y < gap[x].up);
}

int main()
{
#ifdef debug
	freopen("input.txt","r",stdin);
#endif
	
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> UIx >> UIy >> gapN;
	for (int i = 0; i < UIx; i++)
	{
		cin >> move[i].touch >> move[i].nothing;
		gap[i].down = 0;
		gap[i].up = UIy;
	}
	for (int i = 0; i < gapN; i++)
	{
		int p;
		cin >> p;
		cin >> gap[p].down >> gap[p].up;
	}
	for (int x = 1; x <= UIx; x++)
	{
		for (int y = 0; y <= UIy; y++)
			matrix[x][y] = UIx;
	}
	
	for (int x = 0; x < UIx; x++)
	{
		bool canCross = false;
		for (int y = gap[x].down + 1; y < gap[x].up; y++)
		{
			if (matrix[x][y] == UIx)
				continue;
			
			if (legal(x+1,y-move[x].nothing)) //如果不跳合法的话
			{
				canCross = true;
				if (matrix[x+1][y-move[x].nothing] > matrix[x][y])
					matrix[x+1][y-move[x].nothing] = matrix[x][y];
			}
			
			int jump = 1;//跳几次的话 
			int ty = y + move[x].touch; 
			while (ty <= UIy)
			{
				if (legal(x,ty))
				{
					canCross = true;
					if (matrix[x+1][ty] > matrix[x][y] + jump)
					{
						matrix[x+1][ty] = matrix[x][y] + jump;
					}
				}
				jump++;
				if (ty == UIy) break;
				ty += move[x].touch;
				if (ty > UIy) ty = UIy;
			}
			
			
		}
		if (!canCross) 
		{
			cout << "0 " << x;
#ifdef debug
			cout << "\nMatrix:\n";
			for (int x = 0; x <= UIx; x++)
			{
				for (int y = UIy; y >= 0; y--)
				{
					cout << matrix[x][y] << " ";
				}
				cout << endl;
			}
#endif
			return 0;
		}
		if (gap[x].down != 0 || gap[x].up != inf) cross++;
	}
	
	int min = matrix[UIx][0];
	for (int y = 1; y <= UIy; y++)
	{
		if (min > matrix[UIx][y])
			min = matrix[UIx][y];
	}
	
	cout << "1 " << min;
} 
