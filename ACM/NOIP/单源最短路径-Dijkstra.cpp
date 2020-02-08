#include<iostream>
#include<vector>
#include<queue>

using namespace std;

typedef struct {
	int e;//endpoint
	int d;//diatance
} Line;
bool operator < (const Line& a,const Line& b){
	return a.d>b.d;
}

const int space=30000;
int distance1[space];
vector<Line> matrix[space]; //已知条件
priority_queue<Line> q;
bool isDone[space];

int main ()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n,m,a,b,d;
	cin >> n >> m;
	for(int t=0;t<n;t++)
	{
		distance1[t]=0x7fffffff;
		isDone[t]=false;
	}
	for (int i=0;i<m;i++)
	{
		cin >> a >> b >> d;
		a--;
		b--;
		Line input={b,d};
		matrix[a].push_back(input);
		input.e=a;
		matrix[b].push_back(input);
	}
	//完成对条件的输入 
	cin >> a >> b;
	a--;
	b--;
	distance1[a]=0;
	q.push({a,0});
	
//	for (int i=0;i<n;i++)
	while (!q.empty())
	{
		int oper=q.top().e; //oper_ 
		q.pop();
		if (!isDone[oper])
		{
			for(vector<Line>::iterator iter=matrix[oper].begin();iter<matrix[oper].end();iter ++)//oper是起始点,*iter.e是条件中的结束点，*iter.d是条件中的距离
			{
				int tempDistance=(*iter).d+distance1[oper];  
				if (tempDistance<distance1[(*iter).e])
				{
					distance1[(*iter).e]=tempDistance;
					q.push({(*iter).e,distance1[(*iter).e]});
				}
			}
			isDone[oper]=true;
			cout << endl;
			}
		else
			{
//				i--;
			}
		
	}
	cout << distance1[b];
} 
