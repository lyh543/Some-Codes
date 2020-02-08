#include<cstdio>

int solve()
{
	int cnt[10] = {0};
	char c;
	while ((c = getchar()) >= '0' && c <= '9')
	{
		cnt[c-'0']++;
	}
	
	int n = 0;
	bool unfinished = true;
	while(unfinished)
	{
		n++;
		for (int k = n; k != 0; k /= 10)
		{
			cnt[k%10]--;
		}
		
		unfinished = false;
		for (int i = 0; i < 10; i++)
		{
			if (cnt[i] > 0)
				unfinished = true;
			if (cnt[i] < 0)
			{
				printf("-1\n");
				return 0;
			}
		}
	}
	
	printf("%d\n",n);
	return 0;
}

int main()
{
	int question;
	scanf("%d", &question);
	getchar();
	
	for (int i = 0; i < question; i++)
	{
		solve();
	}
	
}
