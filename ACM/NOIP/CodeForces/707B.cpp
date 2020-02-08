#include<iostream>
#include<cmath>
#include<queue>
#include<Windows.h>

using namespace std;

struct r{
	int a;
	int b;
	int d;	
}road[100000];

int n, m, k; // n:城市数; m:路数; k:有货的城市数
bool storage[100000] = {false}; //true表示此城市有存货 

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	int min = -1;
	cin >> n >> m >> k;
	if (k == 0) {cout << "-1"; return 0;}
	for (int i = 1; i <= m; i++)
	{
		int ta, tb, td; // temp (a,b,d)
		cin >> ta >> tb >> td;
		road[i].a = ta;
		road[i].b = tb;
		road[i].d = td; 
	}
	
	for (int i = 1; i <= k; i++)
	{
		cin >> i;
		storage[i] = true;
	} 
	
	for (int i = 1; i <= n; i++)
	{
		if (storage[road[i].a] != storage[road[i].b])
		if (min > road[i].d || min == -1)
			min = road[i].d;
	}
	
	cout << min;
	system("pause");
}
