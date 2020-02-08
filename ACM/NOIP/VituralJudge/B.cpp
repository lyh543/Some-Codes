#include<cstdio>

using namespace std;

int main()
{
	int b, s;
	scanf("%d%d",&b,&s);
	while (b != 0 || s != 0)
	{
		bool first = true; 
		b = b * 100;
		for (int i = 0; i < 100; i++)
		{
			if ((b + i) % s == 0) 
			{
				if (first)
					first = false;
				else
					printf(" ");	
				
				if (i < 10) printf("0");
				printf("%d",i);
			}
		}
		printf("\n");
		scanf("%d%d",&b,&s);
	}
}
