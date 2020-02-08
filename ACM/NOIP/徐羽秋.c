#include<stdio.h>
#include<string.h>

int m;
double highest = 0,highest_people = 1;
double average[2000];
double sum[2000];
int people[2000];
char highest_classname[101],classname[101];

int main()
{
	freopen("input.txt","r",stdin);
	memset(sum,0,sizeof(sum));
	scanf("%d",&m);
	int i;
	for (i = 0; i < m; i++)
	{
		double sum = 0;
		scanf("%d%s",&people[i],&classname);
		
		int j = 0;
		for (j = 0; j < people[i]; j++)
		{
			double height;
			double sum[10];
			scanf("%lf",&height);
			sum[i] = sum[i] + height;
		}
		average[i] = sum / (double)people;
		
		double dif = sum[i] * highest_people - highest * people[i];
		if (dif > 0)
		{
			highest = sum[i];
			highest_people = people[i]; 
			strcpy(highest_classname, classname);
		}
		else if (dif == 0)
		{
			if (strcmp(classname, highest_classname) < 0)
			{
				strcpy(highest_classname, classname);
			}
		}
	}
	
	printf("%s\n",highest_classname);
	int i = 0;
	for (i = 0; i < m; i++)
	{
		printf("%.2f\n",average[i]);
	}
}
