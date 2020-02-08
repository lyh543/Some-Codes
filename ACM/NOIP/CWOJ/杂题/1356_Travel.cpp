#include<iostream>
#include<algorithm>

using namespace std;

const int size=100000;

struct routeStruct{
	int a;
	int b;
	int dis;
}route[size];

struct askStruct{
	int time;
	int i;
	long long ans;
}ask[size];

struct joinStruct{
	int rt;
	long long frien; //the number of people under this one and himself 
}join[size];

bool operator < (routeStruct & a, routeStruct & b)
{
	return (a.dis < b.dis);
}

bool cmp1 (askStruct & a, askStruct & b)
{
	return (a.time < b.time);
}

bool cmp2 (askStruct & a, askStruct & b)
{
	return (a.i < b.i);
}

int findrt(int a)
{
	int rt = a;
	while (join[rt].rt != rt) rt = join[rt].rt;
	while (join[a].rt != rt)
	{
		int next = join[a].rt;
		join[a].rt = rt;
		a = next;
	}
	return rt;
}

void joinIn(int a, int b)
{
	int ra = findrt(a);
	int rb = findrt(b);
	
	if (ra == rb) return; 
	join[rb].rt = join[ra].rt;
	join[ra].frien += join[rb].frien;
	join[rb].frien = 0;
}

int cityN,routeN,askN;

int main()
{
	cin.sync_with_stdio(false);
	cout.sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	//input
	cin >> cityN >> routeN >> askN;
	for (int i = 0; i < routeN; i++)
	{
		cin >> route[i].a >> route[i].b >> route[i].dis;
		route[i].a--;
		route[i].b--;
	}
	sort(&route[0],&route[0]+routeN);
	for (int i = 0; i < askN; i++)
	{
		cin >> ask[i].time;
		ask[i].i = i;
		ask[i].ans = 0;
	}
	sort(&ask[0],&ask[0]+askN,cmp1);
	
	//initialization of join[]
	for (int i = 0 ; i < cityN; i++)
	{
		join[i].rt = i;
		join[i].frien = 1;
	}
	
	int i = 0;
	for (int a = 0; a < askN; a++) // for each ask
	{
		while (ask[a].time >= route[i].dis && i < routeN)
		{
			joinIn(route[i].a, route[i].b);
			i++;
		}

		for (int i = 0; i < cityN; i++)
		{
			ask[a].ans += join[i].frien * (join[i].frien - 1);
		}
	}

	sort(&ask[0],&ask[0]+askN,cmp2);
	
	for (int i = 0; i < askN; i++)
	{
		cout << ask[i].ans << endl;
	}

}

