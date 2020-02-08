#include<iostream>
#include<cstdio>
#include<algorithm>

using namespace std;

const int size = 100233;

struct chopsticksStruct{
	int start;
	int end;
	
	bool operator < (chopsticksStruct & b)
	{
		return end < b.end;
	}
}chop[size];

int n, ans = 0;

int main()
{
	freopen("chopsticks.in","r",stdin);
	freopen("chopsticks.out", "w", stdout);
	
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
	{
		scanf("%d%d", &chop[i].start, &chop[i].end);
	}
	
	sort(chop, chop+n);
	
	int nowEnd = chop[0].end;
	for (int i = 1; i < n; i++)
	{
		if (nowEnd > chop[i].start)
		{
			ans++;
		}
		else
		{
			nowEnd = chop[i].end;
		}
	}
	
	printf("%d", ans);
	
	fclose(stdin);
	fclose(stdout);
}
