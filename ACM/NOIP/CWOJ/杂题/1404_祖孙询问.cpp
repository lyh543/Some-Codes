#include<iostream>
#include<list>
#include<vector>

using namespace std;

const int size = 40010; 

int nodeN, head, askN;

struct nodeStruct{
	list<int> connect;
	//vector<int> connect;
	int height;
	int father;
}node[size];

void markHeight(int i, int h)
{
	node[i].height = h;
	for (list<int>::iterator iter = node[i].connect.begin();
	//for (vector<int>::iterator iter = node[i].connect.begin();
		 iter != node[i].connect.end(); iter++)
	{
			if (*iter == node[i].father) continue;
		 	node[*iter].father = i;
		 	markHeight(*iter, h+1);
	}
}

int relation(int a, int b)
{
	if (node[a].height == node[b].height) return a == b; 
	if (node[a].height < node[b].height) //只可能a是b的祖先 
	{
		return relation(a, node[b].father);
	}
	else //只可能b是a的祖先
	{
		return relation(node[a].father, b) ? 2 : 0;
	}
}

int main()
{
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	cin >> nodeN;
	int a, b;
	for (int i = 0; i < nodeN; i++)
	{
		cin >> a >> b;
		if (b == -1)
		{
			head = a;
			node[a].height = 0;
			node[a].father = -1; 
		}
		else
		{
			node[a].connect.push_back(b);
			node[b].connect.push_back(a);
		}
	}
	
	markHeight(head,0);
	
	cin >> askN;
	for (int i = 0; i < askN; i++)
	{
		cin >> a >> b;
		cout << relation(a,b) << endl;
	}
}
