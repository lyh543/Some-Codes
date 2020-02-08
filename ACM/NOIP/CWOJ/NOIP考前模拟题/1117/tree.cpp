#include<iostream>
#include<cstdio>
#include<algorithm>

//#define debug 

using namespace std;

const int pointSize = 123, lineSize = 5000, inf = 10000000;

int pointN, lineN;
struct lineStruct
{
	int a;
	int b;
	int d;
	bool operator < (const lineStruct a) const
	{
		return d < a.d;
	}
}line[lineSize];

struct Union_Find_Set_Struct
{
	int root[pointSize];
	
	void init(int n)
	{
		for (int i = 0; i < n; i++) root[i] = i;
	}
		
	int findrt(int a)
	{
		return (root[a] == a ? a : (root[a] = findrt(root[a])));
	}
	
	bool isConnect(int a, int b)
	{
		return findrt(a) == findrt(b);
	}
	
	void connect(int a, int b)
	{
		root[findrt(a)] = findrt(b);
	}
}ufs;

int main()
{
#ifndef debug
	freopen("tree.in", "r", stdin);
	freopen("tree.out", "w", stdout);
#endif

	while (scanf("%d%d", &pointN ,&lineN) != EOF)
	{
		if (pointN == 0 & lineN == 0) break;
		
		for (int i = 0; i < lineN; i++)
			scanf("%d%d%d", &line[i].a, &line[i].b, &line[i].d);
		
		sort(&line[0], &line[lineN]); //Kruskal
		
		int min = inf;
		//int maxs = lineN - pointN + 2; // maxs = lineN - (pointN - 1) + 1  
		for (int s = 0; s < lineN; s++) //use line[i] as the shortest 
		{
			ufs.init(pointN);
			int cnt = 0;
			for (int cur = s; cur < lineN; cur++)
			{
				if (ufs.isConnect(line[cur].a, line[cur].b))
					continue;
				
				ufs.connect(line[cur].a, line[cur].b);
				cnt++;
				if (cnt == pointN - 1)
				{
					if (min > line[cur].d - line[s].d)
					{
						min = line[cur].d - line[s].d;
						//cout << line[cur].d << " - " <<  line[s].d << " = " << min << endl;
					}
					break;
				}
			}
		}
		printf("%d\n", min == inf ? -1 : min);
	}

#ifndef debug
	fclose(stdin);
	fclose(stdout);
#endif
}
