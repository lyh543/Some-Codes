#include<cstdio>
#include<iostream>

#define debug 

using namespace std;

const int size = 1000000;

int n;
int a[size];

int main()
{
	
#ifndef debug 
	freopen("sum.in", "r", stdin);
	freopen("sum.out", "w", stdout);
#endif

	scanf("%d", &n);
	for (int i = 0; i < n; i++)
		scanf("%d", &a[i]);
	
	int ans=0;
	long long sum = 0;
	for (int i = n-1; i >= 0; i--)
	{
		sum += a[i];
		if (sum >= 0)  
		{
			//Now you can cut in front of a[i]
			sum = 0;
			ans++;
		}
	}
	
	printf("%d",ans);

#ifndef debug	
	fclose(stdin);
	fclose(stdout);
#endif
} 
