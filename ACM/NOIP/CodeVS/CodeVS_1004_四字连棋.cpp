// http://codevs.cn/problem/1004/
#include<iostream>

using namespace std;

const int limit = 100000;
char ch[limit][4][4];

bool operate(int point, int next, int & last, bool * black);
bool move(int point, int & last, int x1, int x2, int y1, int y2, bool * black);
bool check(int point, int mx, int my);

bool operate(int point, int next, int & last, bool * black)
{
	for(int x = 0; x < 4; x++)
	{
		for (int y = 0; y < 4; y++)
		{
			if (ch[point][x][y] != 'O') continue;
			
			if (x != 0) if(move(point, last, x-1, x, y, y, black)) return true; //尝试将(x-1,y)的棋移到(x,y)的空位上 
			if (x != 3) if(move(point, last, x+1, x, y, y, black)) return true;
			if (y != 0) if(move(point, last, x, x, y-1, y, black)) return true; 
			if (y != 3) if(move(point, last, x, x, y+1, y, black)) return true; 
		}
	}
	return false;
}

bool move(int point, int & last, int x1, int x2, int y1, int y2, bool * black)
{
	if ((ch[point][x1][y1] == 'W' && black[point] == false) || 
		(ch[point][x1][y1] == 'B' && black[point] == true))
	{
		last++;
		for (int i = 0; i < 4; i++)
			for (int j = 0; j < 4; j++)
				ch[last][i][j] = ch[point][i][j];
		ch[last][x2][y2] = ch[last][x1][y1];
		ch[last][x1][y1] = 'O';
		
/*		cout << point << "->" << last << ":\n";
		for (int i = 0; i < 4; i++)
		{
			for (int j = 0; j < 4; j++)
				cout << ch[last][i][j];
			cout << endl;
		}
*/		
		if (check(last, x2, y2))
		{
//			cout << "true"; 
			return true;
		}
//		cout << endl;
		
		black[last] = !black[point];
	}
	return false;
}

bool check(int point, int mx, int my)//检查棋盘是否符合条件,mx, my指被移动的棋子的坐标 
{
	bool right = true;
	for (int i = 0; i < 4; i++)
		if (ch[point][mx][i] != ch[point][mx][my]) right = false;
	if (right) return true;
	
	right = true;
	for (int i = 0; i < 4; i++)
		if (ch[point][i][my] != ch[point][mx][my]) right = false;
	if (right) return true;
	
	if (mx == my)
	{
		right = true;
		for (int i = 0; i < 4; i++)
			if (ch[point][i][i] != ch[point][mx][my]) right = false;
		if (right) return true;
	}
	
	if (mx + my == 3)
	{
		right = true;
		for (int i = 0; i < 4; i++)
			if (ch[point][i][3-i] != ch[point][mx][my]) right = false;
		if (right) return true;
	}
	
	return false;
}
 
int main()
{
	bool black[limit] = {true,false}; //此时是否该黑棋走棋 
	int point = 0, next = 2, last = 1, ans = 1;
	
	for (int i = 0; i < 4; i++)
		cin >> ch[0][i];
		
	for (int i = 0; i < 4; i++)
		for (int j = 0; j < 4; j++)
			ch[1][i][j] = ch[0][i][j];
	
	if (check(0,0,0) || check(0,1,2) || check(0,2,1) || check(0,3,3)) //原棋盘是否满足条件 
	{
		cout << 0;
		return 0;
	}
	while (true)
	{
		if(operate(point, next, last, black))
		{
			cout << ans;
			return 0;
		}
		point++;
		if (point == next)
		{
			ans++;
			next = last + 1;
		}
	}
}

/* test data:
BWBO
WBWB
BWBW
WBWO
*/
