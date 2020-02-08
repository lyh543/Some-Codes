#include<cstdio>

using namespace std;

int main()
{
	int n;
	scanf("%d",&n);
	for (int i = 0; i < n; i++)
	{
		char s[15] = "";
		scanf("%s",s);
		printf("6");
		for (int i = 6; i < 11; i++)
			printf("%c",s[i]);
		printf("\n");
	}
}
