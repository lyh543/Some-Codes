#include<bits/stdc++.h>
using namespace std;

int j[100];

int n;

int getAns(int k, int sum, priority_queue<int, vector<int>, greater<int> > q)
{
	while (k > 0 && q.size() > 0 && q.top() < 0)
	{
		sum -= q.top();
		q.pop();
		k--;
	}
	return sum;
}

int moveRight(int k, int sum, priority_queue<int, vector<int>, greater<int> > q)
{
	int i = n - 1, ans = getAns(k, sum, q);
	while (q.size() < n && k > 0)
	{
		q.push(j[i]);
		sum += j[i];
		i--;
		k--;
		ans = max(ans, getAns(k, sum, q));
	}
	return ans;
}


int main()
{
	int k;
	priority_queue<int, vector<int>, greater<int> > q;
	int sum = 0;
	cin >> n >> k;
	for (int i = 0; i < n; i++)
		cin >> j[i];
	int ans = moveRight(k, sum, q);
	for (int l = 0; l < min(n, k); l++)
	{
		q.push(j[l]);
		sum += j[l];
		ans = max(ans, moveRight(k - l - 1, sum,q));
	}
	cout << ans;
}

