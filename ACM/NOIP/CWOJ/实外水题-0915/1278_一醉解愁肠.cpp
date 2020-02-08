#include<cstdio>

using namespace std;

int main()
{
	int n,h,lh;
	int tot = 1;
	bool up = true,first = false;
	scanf("%d%d%d",&n,&lh,&h);
	int i = 2;
	
	while(h == lh)
	{
		if (i == n)
		{
			printf("1");
			return 0;
		}
		i++;
		scanf("%d",&h);
	}
	
	up = (h > lh);
	
	while(i < n)
	{
		lh = h;
		scanf("%d",&h);
		if ((!up && (h >lh)) || (up && (h < lh)))
		{
			//printf("num %d is got\n",i);
			up = !up;
			tot++;
		}
		i++;
	}
	
	tot++;
	
	printf("%d",tot);
} 
