#include<cstdio>
#include<cmath>
//#include<windows.h>

struct directS{
	int x;
	int y;
}di[8] = {
	{0,1},{0,-1},{1,0},{1,1},{1,-1},{-1,1},{-1,0},{-1,-1}
};

int m, n; //共M行，每行N个整数
int ch[16][16];

bool legal(int tx, int ty)
{
	//printf("%d%d",tx,ty);
	//system("pause");
	return (ty >= 0 && ty < m && tx >= 0 && tx < n);
}

int getValue(int y, int x, directS d)
{
	int ty = y+d.y, tx = x+d.x;
	if (!legal(tx,ty) || ch[ty][tx] == 0) return 0;
		
	int v = 0, c = ch[ty][tx];
	while(legal(tx,ty) && ch[ty][tx] == c)
	{
		v++;
		ty += d.y;
		tx += d.x;
	}
	
	if (!legal(tx,ty) || ch[ty][tx] + c == 0) //不能延展 
		v--;
	
	return ( v>0 ? pow(10,v-1) : 0 );
	
}

int main()
{
	scanf("%d%d",&m,&n);
	for (int i = 0; i < m; i++)
		for (int j = 0; j < n; j++)
		{
			char c;
			scanf("%c",&c);
			if (c == '\n') scanf("%c",&c);
			switch(c)
			{
				case '.':ch[i][j] = 0;break;
				case 'O':ch[i][j] = 1;break;
				case 'X':ch[i][j] = -1;break;
			}
		}
	
	for (int y = 0; y < m; y++)
	{
		if (y) printf("\n");
		for (int x = 0; x < n; x++)
		{
			if (x) printf(" ");
			
			int ans = 0;
			if (ch[y][x] != 0) 
				ans = -1;
			else
			{
				for (int i = 0; i < 8; i++)
				{
					ans += getValue(y,x,di[i]);
				}
			}
			printf("%d",ans);
		}
	}
}
