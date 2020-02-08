#include<iostream>
#include<stack>
#include<queue>
using namespace std;

const int point_size = 10;
int point_n, line_n;

struct point_s{
	char name;
	bool isVisited;
}point[point_size];


int line[point_size][point_size];

void createPoint(int n, char label)
{
	point[n].isVisited = false;
	point[n].name = label;
} 

void drawLine(char ca, char cb)
{
	int ia, ib;
	for (int i = 0; i < point_n; i++)
	{
		if (point[i].name == ca) ia = i;
		if (point[i].name == cb) ib = i;
	}
	line[ia][ib] = true;
	line[ib][ia] = true;
}



void dfs()
{
	stack<int> stk;
	stk.push(0);
	cout << point[0].name;
	point[0].isVisited = true;
	
	while (!stk.empty())
	{
		int oper = stk.top();
		int adj = -1;
		for (int i = 0; i < point_n; i++)
		{
			if (line[oper][i] == true && point[i].isVisited == false)
				adj = i;
		}
		if (adj == -1)
		{
			stk.pop();
		}
		else
		{
			stk.push(adj);
			cout << " " << point[adj].name;
			point[adj].isVisited = true;
		}
	}
	
	for (int i = 0; i < point_n; i++)
		point[i].isVisited = false;
}

void bfs()
{
	queue<int> q;
	q.push(0);
	cout << point[0].name;
	point[0].isVisited = true;
	
	while (!q.empty())
	{
		int t = q.front();
		q.pop();
		
		for (int i = 0; i < point_n; i++)
		{
			if (line[t][i] == true && point[i].isVisited == false)
			{
				cout << " " << point[i].name;
				q.push(i);
				point[i].isVisited = true;
			}
		}
	}
}

int main()
{
	cin >> point_n >> line_n;
	
	for (int i = 0; i < point_n; i++)
	{
		char label;
		cin >> label;
		createPoint(i,label);
	}
	
	for (int i = 0; i < line_n; i++)
	{
		char a, b;
		cin >> a >> b;
		drawLine(a, b);
	}
	
	cout << endl; 
	cout << "DFS Answer: ";
	dfs();
	cout << endl;
	
	cout << endl;
	cout << "BFS Answer: ";
	bfs();
	cout << endl;
}

/*
input data:

5 6
D A B C E
A D
B D
C D
A E
B E
C E

	D
   /|\
   ABC
   \|/
    E


DFS Answer: D C E B A

BFS Answer: D A B C E

*/
