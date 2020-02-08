//http://codevs.cn/problem/3143/
#include<iostream>

using namespace std;

bool first;

struct point{
	int father;
	int left;
	int right;
	point(){father=0;left=0;right=0;}
} p[17];

void forward(int i)//ÏÈÐò£¬¼´¸ù->×ó->ÓÒ 
{
	if (first) first = false; else cout << " ";
	cout << i;
	if (p[i].left != 0) forward(p[i].left);
	if (p[i].right != 0) forward(p[i].right);
}

 
void middle(int i)//ÖÐÐò£¬¼´×ó->¸ù->ÓÒ 
{
	if (p[i].left != 0) middle(p[i].left);
	if (first) first = false; else cout << " ";
	cout << i;
	if (p[i].right != 0) middle(p[i].right);
}

void backward(int i)//ºóÐò£¬¼´×ó->ÓÒ->¸ù 
{
	if (p[i].left != 0) backward(p[i].left);
	if (p[i].right != 0) backward(p[i].right);	
	if (first) first = false; else cout << " ";
	cout << i;
}

int main()
{
	int n, l, r;
	cin >> n;
	p[1].father = 0;
	for (int i = 1; i <= n; i++)
	{
		cin >> l  >> r;
		p[i].left = l;
		p[i].right = r;
		p[l].father = i;
		p[r].father = i;
	}
	first = true;
	forward(1);
	cout << endl;
	
	first = true;
	middle(1);
	cout << endl;
	
	first = true;
	backward(1);
}
