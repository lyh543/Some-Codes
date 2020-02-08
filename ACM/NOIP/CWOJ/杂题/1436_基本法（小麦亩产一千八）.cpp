//t123yh just ACed the problem, so I just come to %% t123yh
//算了说中文了，就是列方程、解方程
//另外，强烈要求改回原题：小麦亩产一千八 
 
#include<cstdio>
#include<iostream>

const int asize = 25; 

using namespace std;

struct x_struct{
	int k; //constant value
	int b;
}unknown[asize];

long double abs(double n)
{
	return n >= 0 ? n : -n;
}

int main()
{
	unknown[0].b = 1;
	unknown[0].k = 0;
	unknown[1].k = 1;
	unknown[1].b = 0; //设第1格里有x个麦子
	for (int i = 2; i < asize; i++)
	{
		unknown[i].b = unknown[i-1].b + unknown[i-2].b; 
		unknown[i].k = unknown[i-1].k + unknown[i-2].k; 
	}
	
	long long a, na, b;
	while(scanf("%lld%lld%lld",&a,&na,&b) != EOF)
	{
		if ( (na-unknown[a].b) % unknown[a].k)
		{
			printf("-1\n");
			continue;
		}
		else
		{
			long long x = (na-unknown[a].b) / unknown[a].k;
			printf("%lld\n",unknown[b].k * x + unknown[b].b);
		}
	}
	return 0;
}

/*
0:      1
1:  x
2:  x + 1
3: 2x + 1
4: 3x + 2
5: 5x + 3
6: 8x + 5
7:13x + 8
*/
