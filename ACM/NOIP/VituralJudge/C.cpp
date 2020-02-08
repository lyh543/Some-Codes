#include<cstdio>

using namespace std;

int max(int a, int b)
{
	return a>b?a:b;
}

int main()
{
	int n, space;
	scanf("%d%d",&n,&space);
	
	int maxi[13000] = {0}; //i质量能存的最大值 
	
	for (int i = 0; i < n; i++)
	{
		int w,v;
		scanf("%d%d",&w,&v);
		for (int j = space; j >= w; j--)
		{
			maxi[j] =max(maxi[j], maxi[j-w]+v);
		}
	}
	
	printf("%d",maxi[space]);
}
