#include<iostream>
#include<vector>
#include<queue>

using namespace std;

typedef struct {
	int e; 
	int d;
}Line;

const int space=30000;
int distance1[space];
vector<Line> matrix[space]; //condition
queue<int> q;
bool isInQueue[space];

int main ()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n,m,a,b,d;
	for(int t=0;t<space;t++)
		distance1[t]=0x7fffffff; 
	cin >> n >> m;
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
	//finish input
	
	cin >> a >> b;
	a--;
	b--;
	distance1[a]=0;
	q.push(a);
	isInQueue[a]=true; //push point a into queue
	 
	while (!q.empty())
	{
		n=q.front();//pop the front element
		q.pop();
		isInQueue[n]=false;
		
		for(vector<Line>::iterator iter=matrix[n].begin();iter<matrix[n].end();iter ++)
		//n是起始点,*iter.e是条件中的结束点，*iter.d是条件中的距离 
		{
			int tempDistance = (*iter).d+distance1[n];  
			if (tempDistance < distance1[(*iter).e] && !isInQueue[iter->e]) //if the new distance is shorter than before 
			{
				distance1[(*iter).e]=tempDistance;  //push the updating end point into queue to prepare to process
				q.push((*iter).e);
				isInQueue[(*iter).e]=true;
			}
		}
	}
	cout << distance1[b];
} 
