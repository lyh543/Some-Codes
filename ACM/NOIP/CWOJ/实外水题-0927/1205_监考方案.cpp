//   https://cwoj.org/problempage.php?contest_id=1006&prob=1
#include<iostream>
#include<list>
#include<stack>

using namespace std; 

struct pointSturct{
	int y; //该点设老师时的最小值 
	int n; //该点不设老师时的最小值
}value[100001];

int min(pointSturct value)
{
	return value.n > value.y ? value.y : value.n;
}

int n;
list<int> near[100001];
//stack<int> visit;

void dfs(int head, int i)
{
	value[i].y = 1;
	value[i].n = 0; 
	for (list<int>::iterator iter = near[i].begin(); iter != near[i].end(); iter++)
	{
		if (*iter == head) continue;
		dfs(i,*iter);
		
		value[i].y += min(value[*iter]);
		value[i].n += value[*iter].y;
	}
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;
	int a, b;
	for (int i = 1; i < n; i++)
	{
		cin >> a >> b;
		near[a].push_back(b);
		near[b].push_back(a);
	}
	
	dfs(0,1);
//	visit.push(1);
//	while(!visit.empty())
//	{
//		
//	}
	
	cout << min(value[1]);
}
