#include<iostream>

using namespace std;

int ym, xm;
int xadd[8] = {0,0,1,1,1,-1,-1,-1};
int yadd[8] = {1,-1,1,0,-1,1,0,-1};

bool legal(int y, int x)
{
	return (x >= 0 && y >= 0 && x < xm && y < ym);
}

int main()
{	
	int map[100][100] = {{0}};
	char c;
	cin >> ym >> xm;
	for (int y = 0; y < ym; y++)
	{
		for (int x = 0; x < xm; x++)
		{
			cin >> c;
			if (c == '*')
			{
				map[y][x] = 10;
				for (int i = 0; i < 8; i++)
				{
					if (c == '*' && y >= 10)
					{
						cout << "";
						cout << "";
					}
					if(legal(y+yadd[i],x+xadd[i]))
						map[y+yadd[i]][x+xadd[i]]++;
				}
			}
		}
	}
	
	for (int y = 0; y < ym; y++)
	{
		for (int x = 0; x < xm; x++)
		{
			if(map[y][x] >= 10)
				cout << "*";
			else
				cout << map[y][x]; //<< "\t";
		}
		cout << endl;
	}
}
