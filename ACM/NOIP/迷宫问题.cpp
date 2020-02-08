#include<iostream>
//迷宫问题 
//示例输入：
/*
8 5
0 0 1 1 1 1 1 1
1 0 0 1 0 1 1 0
0 1 0 0 1 1 0 0
1 1 1 0 1 0 1 0
1 0 0 1 0 1 1 0
*/
//表示8行5列，左上角为入口，右下角为出口，0为路，1为墙 
using namespace std;

const int Ndirection = 8;
struct add{
	int x;
	int y;
};
add direction[Ndirection] = {
	{ 1 , 0 },
	{ 1 , 1 },
	{ 0 , 1 },
	{ -1 , 1 },
	{ -1 , 0 },
	{ -1 , -1 },
	{ 0 , -1 },
	{ 1 , -1 }
};

const int xMax = 10,yMax = 10;
int maze[xMax+2][yMax+2];

struct road{
	int x;
	int y;
	int pre;
};
road record[xMax*yMax] = {{1,1,-1}};
int rear = 0, front = 0;

int xm, ym;

void output(int l)
{
	cout << endl; 
	for (int i = l; i <= ym+1-l; i++)
	{
		for (int j = l; j <= xm+1-l; j++)
			cout << maze[i][j] << "\t";
		cout << endl;
	}
}

void outputRecord()
{
	for (int i = 0; i <= rear; i++)
	{
		cout << i << ":{" << record[i].x << "," << record[i].y << "," << record[i].pre << "}\n"; 
	}
}

void route()
{
	int iroute[yMax*xMax];
	int step = 0;
	while (rear >= 0)
	{
		iroute[step] = rear;
		rear = record[rear].pre;
		step++;
	}
	cout << "You need at least " << step << " step";
	if (step > 1) cout << "s";
	cout << " to escape the maze.\n"
		 << "The route is";
	for (int i = step - 1; i >= 0; i--)
		cout << " (" << record[iroute[i]].x << "," << record[iroute[i]].y << ")";
}

int main()
{
	cin >> xm >> ym;
	for (int i = 0; i <= xm+1; i++)
	{
		maze[0][i] = 1;
		maze[ym+1][i] = 1;
	}
	for (int i = 0; i <= ym+1; i++)
	{
		maze[i][0] = 1;
		maze[i][xm+1] = 1;
	 } 
	 //边界设为1
	 
	for (int i = 1; i <= ym; i++)
	 	for (int j = 1; j <= xm; j++)
		 	cin >> maze[i][j];
	//输入迷宫的墙
	
	maze[1][1] = -1;
	while (front <= rear)
	{
		int x, y;
		x = record[front].x;
		y = record[front].y;
		for (int k = 0; k < Ndirection; k++)
		{
			int x2 = x + direction[k].x;
			int y2 = y + direction[k].y;
			if (maze[y2][x2] == 0)
				{
				rear++;
				record[rear] = { x2, y2, front };
				maze[y2][x2] = -1;
			}
			if (x2 == xm && y2 == ym)
			{
				//outputRecord();
				route();
				return 0;
			}
		}
		front++;
	}
	cout << "I'm sorry that you can't escape the maze.";
	return 0;
}
