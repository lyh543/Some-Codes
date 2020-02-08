#include<iostream>
#include<algorithm>

using namespace std;

const int point_size = 100, line_size = 100;
int point_n, line_n;
//int dis[point_size+1][point_size+1] = {0};
int used_line_n = 0; // 除去平行线、一个点的环的线段数 
int rt[point_size]; // 用于并查集 

struct line_struct {
	int a;
	int b;
	int d;
	//bool used; //方便调试 
}line[line_size];

int cmp(line_struct a, line_struct b)
{
	return a.d < b.d;
}

void addLine(int i, int a, int b, int d)
{
/*	if (a == b) return;
	if (dis[a][b] != 0 && dis[a][b] < d) return;
	dis[a][b] = d;
	dis[b][a] = d;

*/	line[used_line_n].a = a;
	line[used_line_n].b = b;
	line[used_line_n].d = d;
//	line[used_line_n].used = false;	 
	used_line_n++;
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

bool unionFind(int a, int b)
{
/*	
	if (makefriend)
		return true; 
	else
		return false; 
*/
	int ra = findrt(a), rb = findrt(b);
	if (ra == rb) //两点本来就连接，又把它们连起来，说明是环
	{
		return false; 
	} 
	else
	{
		rt[a] = b;
		return true;
	}
	
}

int calculateMin()
{
	sort(&line[0], &line[used_line_n], cmp);
	
	for (int i = 0; i < point_n; i++) //为并查集做准备 
		rt[i] = i;
		
	int tot = 0;
	
	for (int i = 0; i < used_line_n; i++)
	{
		if (unionFind(line[i].a, line[i].b))
		{
		//	line[i].used = true;
		//	cout << "The line between "<< line[i].a << line[i].b << " whose length is " << line[i].d << " is used" << endl;
			tot += line[i].d;
		}
	}
	
	return tot; 
}

int main()
{
	cin >> point_n >> line_n;
	for (int i = 0 ; i < line_n; i++)
	{
		int a, b, d;
		cin >> a >> b >> d;
		addLine(i, a, b, d);
	}
	
	cout << calculateMin(); 
	
}

/*

input data:

6 11
1 2 6
1 2 9
1 3 3
2 3 4
3 3 1 
4 3 3
2 4 2
5 1 7
5 3 8
6 2 5
6 4 2
		_
	   / \
	  1---2 
	 /|	  |\ 
	5 |   | 6
	 \|   |/
	 _3---4
	/ |
	\_/
answer: 17
*/



