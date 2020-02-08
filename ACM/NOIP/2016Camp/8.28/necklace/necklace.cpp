#include<cstdio>

using namespace std;

const int pearl_size = 1000;
const int name_size = 50;

int pearl_n;
int pearl[name_size+1][name_size+1] = {0};
int rt[name_size+1];
int used[name_size+1] = {false}; //表示使用的标号 
void getName(int a, int b)
{
	pearl[a][b]++;
	pearl[b][a]++;
}

int findrt(int a)
{
	int root = a;
	while (rt[root] != root)
		root = rt[root];
		
	int temp = a;
	while (rt[temp] != temp)
	{
		int next = rt[temp];
		rt[temp] = root;
		temp = next;
	}
	
	return root;
}

void unionFind(int a, int b)
{
	int ra = findrt(a);
	int rb = findrt(b);
	
	rt[ra] = rb;
}

bool unionCheck()
{
	int root = findrt(1);
	for (int i = 2; i <= name_size; i++)
	{
		if (used[i] && root != findrt(i)) return false;
	}
	return true;
}

bool pearlCheck()
{
	for (int i = 1; i <= name_size; i++)
	{
		int sum = 0;
		for (int j = 1; j <= name_size; j++)
		{
			//printf("%d ",pearl[i][j]);
			sum += pearl[i][j]; 
		}
		if (sum % 2 == 1) return false;
		//printf("\n");
	}
	return true;
}

int main()
{
	for (int i = 0; i < name_size; i++)
		rt[i] = i;
		
	scanf("%d",&pearl_n);
	for (int i = 1; i <= pearl_n; i++)
	{
		int a, b; 
		scanf("%d%d", &a, &b);
		getName(a, b);
		unionFind(a, b);
		used[a] = used[b] = true;
	}
	
	if (unionCheck() && pearlCheck())
	{
		int count
	}
	else
	{
		printf("some beads may be lost");
	}
	
}
