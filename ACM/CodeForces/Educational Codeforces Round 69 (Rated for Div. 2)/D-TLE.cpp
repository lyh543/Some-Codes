#include<bits/stdc++.h>
//#define _CRT_SECURE_NO_WARNINGS
#define ld long double 
#define ll long long 
//#define int ll
#define eps 1e-11
#define fastio ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
typedef pair<int, int> P;
 
const int maxn = 3e5 + 5;
 
ll arr[maxn];
 
deque<int> q[maxn / 2];
 
void push_back(int j, int i)
{
	while (!q[j].empty() && arr[i] > arr[q[j].back()])
		q[j].pop_back();
	q[j].push_back(i);
}
void pop_front(int j, int i)
{
	while (!q[j].empty() && q[j].front() <= i)
		q[j].pop_front();
}
int max_index(int j)
{
	return q[j].front();
}
 
inline int d (int a, int b)
{
	return (a / b + (a%b != 0));
}
 
int main()
{
	fastio;
	int n, m, k; 
	ll ans = 0;
	cin >> n >> m >> k;
	if (m == 1)
	{
		ll x = 0, maxx = 0;
		for (int i = 1; i <= n; i++)
		{
			ll a;
			cin >> a;
			x += a - k;
			maxx = max(maxx, x);
			if (x < 0)
				x = 0;
		}
		cout << maxx;
		return 0;
	}
 
	for (int i = 1; i <= n; i++)
	{
		ll a;
		cin >> a;
		arr[i] = arr[i - 1] + a;
		push_back(d(i,m),i);
	}
	int sn = n / m + (n%m != 0);
	for (int i = 0; i < n; i++)
	{
		for (int j = 1; j <= sn; j++)
		{
			if (!q[j].empty())
				ans = max(ans, arr[max_index(j)] - arr[i] - j * k);
			else
				sn--;
			pop_front(j,i + 1 + (j - 1)*m);
			if (i + 1 + j * m <= n)
				push_back(j, i + 1 + j * m);
		}
	}
	cout << ans;
}

