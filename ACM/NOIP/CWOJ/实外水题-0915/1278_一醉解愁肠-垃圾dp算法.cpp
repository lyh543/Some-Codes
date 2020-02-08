//各种TLE 
#include<cstdio>

using namespace std;

struct bottleS{
	int h;
	int ans_up; //当前高于两边时最大值 
	int ans_down;
}bottle[1000000];

int main()
{
	int n;
	scanf("%d",&n);

	int upMax = 0, downMax = 0; //整个数列中ans_up和ans_down的最大值 
	for (int i = 0; i < n; i++)
	{
		scanf("%d",&bottle[i].h);
		bool up = true, down = true; //是否还需要判断up/down 
		for (int j = i-1; j >= 0; j--)
		{
			if (!up && !down) break;
			if (up && bottle[j].h > bottle[i].h)
			{
				if (bottle[i].ans_down < bottle[j].ans_up)
					bottle[i].ans_down = bottle[j].ans_up;
					
				if (bottle[j].ans_up == downMax) down=false;
			}
			else if (down && bottle[j].h < bottle[i].h)
			{
				if (bottle[i].ans_up < bottle[j].ans_down)
					bottle[i].ans_up = bottle[j].ans_down;
					
				if (bottle[j].ans_down == upMax) up=false;
			}
		}
		
		if (++bottle[i].ans_up > upMax) upMax = bottle[i].ans_up;
		if (++bottle[i].ans_down > downMax) downMax = bottle[i].ans_down;	
	}
	
	if (bottle[n-1].ans_down >= bottle[n-1].ans_up)
		printf("%d",bottle[n-1].ans_down);
	else printf("%d",bottle[n-1].ans_up);
}
