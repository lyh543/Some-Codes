#include<iostream>
#include<cstdio>
// Author: lyh 
using namespace std;

const int people_size = 20000;
const int relation_size = 1000000;
const int ask_size = 1000000;

int people_n, relation_n;
int root[people_size+1];

int findrt(int people)
{
	int temp = people;
	while (root[temp] != temp)
		temp = root[temp];
	
	int root2 = temp;
	temp = people; 
	
	while (root[temp] != temp)
	{
		int next = root[temp];
		root[temp] = root2;
		temp = next;
	}
	
	return root2;
}

void join(int a, int b)
{
	int ra = findrt(a);
	int rb = findrt(b);
	
	root[rb] = ra;
	
	return;
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	int ask_n;
	
	cin >> people_n >> relation_n >> ask_n;
	for (int i = 1; i <= people_n; i++)
	{
		root[i] = i;
	}
	
	for (int i = 1; i <= relation_n; i++)
	{
		int a, b;
		cin >> a >> b;
		join(a, b);
	}
	
	for (int i = 0; i < ask_n; i++)
	{
		int a, b;
		cin >> a >> b;
		
		if (i != 0) cout << endl;
		
		if (findrt(a) == findrt(b))
		{
			cout << "Yes";
		}
		else
		{
			cout << "No";
		}
	}
} 
