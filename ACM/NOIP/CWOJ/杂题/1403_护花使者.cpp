#include<iostream>
#include<algorithm>
//Ì°ÐÄ£¿ 
using namespace std;

struct personStruct
{
	int time;
	int steal;
	double r;
}person[100000];

bool cmp(personStruct a, personStruct b)
{
	return a.r > b.r;
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0); 
	
	int n;
	long long v = 0, ans = 0;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> person[i].time >> person[i].steal;
		person[i].r = double(person[i].steal) / person[i].time;
		v += person[i].steal;
	}
	
	sort(person, &person[n], cmp);
	
	//for (int i = 0; i < n; i++) cout << person[i].r << " ";
	for (int i = 0; i < n; i++)
	{
		v -= person[i].steal;
		ans += v * person[i].time;
	}
	
	cout <<  2 * ans;
}
