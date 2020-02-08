#include<iostream>
#include<cstdio>

using namespace std;

int n, m, ask;
int root[101][101]; //每种颜色用一个并查集


int findrt(int a, int * root)
{
	int rt = root[a];
	while (rt != root[rt])
		rt = root[rt];
	
	int temp = root[a], next;
	while (temp != root[temp])
	{
		next = root[temp];
		root[temp] = rt;
		temp = next;
	}
	
	return rt;
}

void join(int a, int b, int * root)
{
	root[findrt(a, root)] = findrt(b, root);
}

int count(int a, int b)
{
	int tot = 0;
	for (int i = 1; i <= m; i++)
	{
		if (findrt(a, root[i]) == findrt(b , root[i]))
		{
			tot++;
			//cout << "\n " << a << " & " << b << " is together in color " << i <<"\n";
		}
	}
	return tot;
}

int main()
{
	scanf("%d%d",&n,&m);
	
	//initialize
	for (int i = 1; i <= m; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			root[i][j] = j;
		}
	}
	
	for (int i = 0; i < m; i++)
	{
		int a, b, color;
		scanf("%d%d%d", &a, &b, &color);
		join(a,b,root[color]);
	}
	
/*	cout << "--------------\n"; 
	for (int i = 1; i <= m; i++)
	{
		for (int j = 1; j <= n; j++)
			cout << root[i][j] << " ";
		cout << endl;
	}
	cout << "--------------\n";
	
	printf("How many ask?");*/ 
	scanf("%d", &ask);
	for (int i = 0; i < ask; i++)
	{
		int a, b;
		scanf("%d%d", &a, &b);
		
		if (i) printf("\n");
		printf("%d", count(a, b));
	}
} 

