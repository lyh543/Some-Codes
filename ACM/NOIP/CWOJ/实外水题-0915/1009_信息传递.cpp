#include<cstdio>

int main()
{
	freopen("input.txt", "r",stdin);
	
	const int size = 200001;
	
	int n, nowt=1, ans = size;
	int next[size], time[size] = {0};
	//time指计数器，next指该人的传递对象
	
	scanf("%d",&n);
	for (int i = 1; i <= n; i++)
	{
		scanf("%d",&next[i]);
	}
	
	int start = 1;
	while (start <= n)
	{
		if (time[start])
		{
			start++;
			continue;
		}
		
		int i = start;
		time[i] = nowt;
		nowt++;
		
		while (!time[next[i]])
		{
			i = next[i];
			time[i] = nowt;
			nowt++;
		}
		
		if (time[next[i]] >= time[start])
		{
			int t = time[i] - time[next[i]] + 1;
			if (t < ans) ans = t;
		}
	}
	
//	printf("time:\n");
//	for (int i = 1; i<= n; i++) printf("%d ",time[i]);
//	printf("\nans:");
	printf("%d",ans);
}


/*
6
6 1 6 1 5 3
*/
