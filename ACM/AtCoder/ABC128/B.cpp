#include<bits/stdc++.h>
using namespace std;

struct rest
{
	char name[10];
	int score;
	int index;
}r[200];

bool operator < (rest a, rest b)
{
	int s = strcmp(a.name, b.name);
	if (s == 0)
		return a.score > b.score;
	else
	{
		return s < 0;
	}

}

int main()
{
	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> r[i].name >> r[i].score;
		r[i].index = i;
	}
	
	sort(r, r + n);

	for (int i = 0; i < n; i++)
	{
		cout << r[i].index + 1 <<endl;
	}
	

}

