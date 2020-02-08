#include<cstdio>
#include<queue>
#include<vector>

using namespace std;

const int lineSize = 200005, pointSize = 100005;
int lineN, pointN;
long long sum = 0, minT = 0;
int root[pointSize]; //union-find set

struct lineStruct{
	int a;
	int b;
	int t;
}line[lineSize];

struct pointStruct{
	int end;
	long long t;
};

priority_queue<lineStruct> q;
vector<pointStruct> nearPoint[pointSize]; // the graph after simplified

bool operator < (const lineStruct & la, const lineStruct & lb)
{
	return la.t > lb.t;
}
int findrt(int a)
{
	int rt = root[a];
	while (root[rt] != rt)
		rt = root[rt];
	
	int next;
	while (root[a] != rt)
	{
		next = root[a];
		root[a] = rt;
		a = next;
	}
	return rt;
}
void join(int a, int b)
{
	int ra = findrt(a), rb = findrt(b);
	root[ra] = rb;
}
bool isConnected(int a, int b)
{
	return (findrt(a) == findrt(b));
}

void convert(lineStruct l)
{
	pointStruct t;
	t.end = l.a; t.t = l.t;
	nearPoint[l.b].push_back(t);
	t.end = l.b;
	nearPoint[l.a].push_back(t);
}


pointStruct dfs(int cur, int last)
{
	pointStruct ans; ans.t = 0; ans.end = cur;
	for (vector<pointStruct>::iterator iter = nearPoint[cur].begin(); iter < nearPoint[cur].end(); iter++) 
	{
		if (iter->end == last) continue;
		pointStruct temp = dfs(iter->end, cur);
		if (temp.t + iter->t > ans.t)
		{
			ans.t = temp.t + iter->t;
			ans.end = temp.end;
		}
	}
	return ans;
}

long long longest()
{
	int t = dfs(1,-1).end;
	return dfs(t,-1).t;
}

int main()
{
	scanf("%d%d", &pointN, &lineN);
	
	// initialization for union-find set
	for (int i = 1; i <= pointN; i++)
		root[i] = i;
	
	for (int i = 0; i < lineN; i++)
	{
		lineStruct temp;
		scanf("%d%d%d", &temp.a, &temp.b, &temp.t);
		q.push(temp);
	}
	
	int nowLineN = 1;
	while (nowLineN < pointN) //The graph with N points havs N-1 lines 
	{
		lineStruct temp = q.top();
		q.pop();
		if (!isConnected(temp.a, temp.b))
		{
			convert(temp);
			join(temp.a,temp.b);
			sum += temp.t;
			nowLineN++;
		}
	} 
		
	printf("%lld %lld", sum, 2 * sum - longest());
	// ans2 = longest + 2 * (sum - longest) = 2 * sum - longest

}
