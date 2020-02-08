#include<iostream>
#include<list>

using namespace std;

const int size = 100002;

int n, maxLength;
struct pointStruct{
	int maxL;
	int max2L;
	list<int> connect;
}point[size];

int dfs(int i, int last)
{
	point[i].maxL = point[i].max2L = 0;
	for (list<int>::iterator iter = point[i].connect.begin(); iter != point[i].connect.end(); iter++)
	{
		if (*iter == last) continue;
		//cout << *iter << " ";
		int t = dfs(*iter, i) + 1;
		if (t > point[i].max2L)
		{
			point[i].max2L = t;
			if (point[i].max2L > point[i].maxL)
			{
				t = point[i].maxL;
				point[i].maxL = point[i].max2L;
				point[i].max2L = t;
			}
			if (point[i].max2L + point[i].maxL > maxLength)
				maxLength = point[i].max2L + point[i].maxL;
		}
	}
	return point[i].maxL;
}

int main()
{
	cin >> n;
	
	for (int i = 1; i < n; i++)
	{
		int a, b;
		cin >> a >> b;
		point[a].connect.push_back(b);
		point[b].connect.push_back(a);
	}
	
	dfs(1,0);
	
	cout << (maxLength + 1) / 2;
} 
