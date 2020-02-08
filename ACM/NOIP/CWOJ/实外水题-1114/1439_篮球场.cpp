#include<cstdio>

int nx, ny, k, x, y, ans=0;

int min(int x, int y)
{
	return x > y ? y : x;
}

int score(int x, int y)
{
	if (x * 2 <= nx)
	{
		if (y * 2 <= ny) // left up
		{
			return min(x, y);
		}
		else // left down
		{
			return min(x, ny-y+1);
		}
	}
	else
	{
		if (y * 2 <= ny) //right up
		{
			return min(nx-x+1, y);
		}
		else//right down
		{
			return min(nx-x+1, ny-y+1);
		}
	}
	
}

int main()
{
	scanf("%d%d%d",&nx,&ny, &k);
	
	for (int i = 0; i < k; i++)
	{
		scanf("%d%d", &x, &y);
		//printf("%d\n", score(x,y));
		ans += score(x,y);
	}
	
	printf("%d",ans);
}

