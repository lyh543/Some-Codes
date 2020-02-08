#include<bits/stdc++.h>
//#define DEBUG
#define ll long long
using namespace std;

const int maxn = 1e5 + 5;

struct numbers {
	int index;
	int C;
};

bool operator < (numbers a, numbers b)
{
	return a.C < b.C;
}

struct cmp
{
	bool operator ()(int a, int b)
	{
		return a > b;
	}
};

priority_queue<numbers> q;
priority_queue<int,vector<int>,cmp> A;

int B[maxn];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n, m, a, b, c;
	cin >> n >> m;
	for (int i = 0; i < n; i++)
	{
		cin >> a;
		A.push(a);
	}
	for (int i = 0; i < m; i++)
	{
		cin >> b >> c;
		q.push({ i,c });
		B[i] = b;
	}

	ll ans = 0;
	while (n > 0 && !q.empty() && !A.empty())
	{
		if (q.top().C > A.top())
		{
			ans += q.top().C;
#ifdef DEBUG
			cout << q.top().C << "+";
#endif // DEBUG
			A.pop();
			if ((--B[q.top().index]) == 0)
				q.pop();
		}
		else
		{
			break;
		}
		n--;
	}
	while (n != 0)
	{
		ans += A.top();
#ifdef DEBUG
cout << A.top() << "+";
#endif // DEBUG

		A.pop();
		n--;
	}
	cout << ans;
}

