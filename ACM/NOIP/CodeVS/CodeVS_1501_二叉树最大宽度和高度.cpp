//http://codevs.cn/problem/1501/
#include<iostream>
#include<cmath>

using namespace std;

int push(int,int,int*,int*);

int main()
{
	const int maxn = 16;
	int n;
	cin >> n;
	int level[maxn+1]={0,1,0};//level[i]表示数i的层数 
	int width[maxn+1] = {0,1,0};//level[i]表示第i层的宽度 
	for (int i = 1; i <= n; i++)
	{
		int a,b;
		cin >> a >> b;
		push(a,i,level,width);
		push(b,i,level,width);
	}
	int highest = 1, widest = 1;
	for (int i = 1; i <= maxn && width[i] != 0;i++)
		widest = max (widest, width[i]);
	for (int i = 1; i <= maxn && level[i] != 0;i++)
		highest = max (highest, level[i]);
	cout << widest << " " << highest;
}

int push(int down, int up, int* level, int* width)
{
	if (down == 0) return 0;
	level[down] = level[up] + 1;
	width[ level[down] ] ++;
}
