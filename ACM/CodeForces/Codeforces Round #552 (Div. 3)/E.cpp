#include<bits/stdc++.h>
 
using namespace std;
 
struct NodeStruct{
	int position;
	int left;
	int right;
}node[200005];
 
int team[200005] = { 0 };
 
int main()
{
	cin.sync_with_stdio(0);
	cin.tie(0);
 
	int n, k;
	cin >> n >> k;
	int last, cur;
	for (int i = 1; i <= n; i++)
	{
		cin >> cur;
		node[cur].position = i;
		if (i != 1)
		{
			node[cur].left = last;
			node[last].right = cur;
		}
		else
		{
			node[cur].left = -1;
		}
		if (i == n)
			node[cur].right = -1;
		last = cur;
	}
 
	int coach = 1, remaining = n, maxn = n;
	while (remaining)
	{
		while (node[maxn].position < 0)
			maxn--;
		int cur = node[maxn].left, next, leftmost, rightmost;
		team[node[maxn].position] = coach;
		node[maxn].position = -coach;
		remaining--;
		for (int i = 0; i < k; i++)
		{
			if (cur < 0 || node[cur].position < 0)
				break;
			next = node[cur].left; 
			team[node[cur].position] = coach;
			node[cur].position = -coach;
			cur = next;
			remaining--;
		}
		if (node[cur].position < 0)
			leftmost = -1;
		else
			leftmost = cur;
 
		cur = node[maxn].right;
		for (int i = 0; i < k; i++)
		{
			if (cur < 0 || node[cur].position < 0)
				break;
			next = node[cur].right;
			team[node[cur].position] = coach;
			node[cur].position = -coach;
			cur = next;
			remaining--;
		}
		if (node[cur].position < 0)
			rightmost = -1;
		else
			rightmost = cur;
 
		if (leftmost >= 0)
			node[leftmost].right = rightmost;
		if (rightmost >= 0)
			node[rightmost].left = leftmost;
 
		coach = (coach == 2) ? 1 : 2;
	}
	for (int i = 1; i <= n; i++)
	{
		cout << team[i];
	}
	return 0;
}
