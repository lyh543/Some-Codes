#include<cstdio>

int sum = 0, o = 0;
char c;

int main()
{
	while((c = getchar()) != EOF)
		if (c == 'O') 
		{
			o++;
			sum += o;
		}
		else
			o = 0;
	printf("%d",sum); 
	
}
