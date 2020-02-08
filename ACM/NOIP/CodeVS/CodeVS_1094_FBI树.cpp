//http://codevs.cn/problem/1094/
#include<iostream>
#include<cstring>
#include<cmath>
using namespace std;

char get_type(char * s, int start, int end)
{
	int i = start;
	char type = 'X';
	while (i <= end && type != 'F')
	{
		if (s[i] == '0')
			type = (type == 'I')?'F':'B';
		if (s[i] == '1')
			type = (type == 'B')?'F':'I';
		i++;
	}
	return type;
}

int build_tree(char * s, char * tree,int point, int start, int end, int go_on)
{
	tree[point] = get_type(s,start,end);
	//if (tree[point] == 'I')
	if (go_on != 0)
	{
		build_tree(s,tree,point*2,start,(start+end-1)/2,end-start); //建左子树，如果start==end，下一层就不能递归了 
		build_tree(s,tree,point*2+1,(start+end+1)/2,end,end-start); //建右子树
	}
}

int backward(char * s, int point, int l)
{
	if (point * 2 < l)
	{
		backward(s, point*2, l); //递归左节点 
		backward(s, point*2+1, l);//递归右节点 
	}
	cout << s[point]; // 输出父节点 
}

int main()
{
	int n;
	cin >> n;
	char s[10000];
	cin >> s;
	char tree[10000];
	build_tree(s,tree,1,0,pow(2,n)-1,1);
	
	backward(tree,1,pow(2,n+1)-1); // tree的节点数等于s的长度*2-1 
} 
