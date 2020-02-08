#include<iostream>
#include<list>

using namespace std;

const int size=100010;

int n;
list<int> connect[size];
bool visited[size] = {false};
long long ans = 0;

long long C(int n, int m)
{
	if (n < m) return 0;
	long long ansC = 1;
	for (int i = 1; i <= m; i++)
	{
		ansC = ansC * (n-i+1) / i;
	}
	return ansC;
}

int dp(int cur, int last, int l)
{
	if (connect[cur].size() == 1 && last != -1)
	{
		if (!visited[cur])
		{
			ans += C(l,3);
		}
		return 0;
	}
	for (list<int>::iterator iter = connect[cur].begin(); iter != connect[cur].end(); iter++)
	{
		if (*iter != last)
			dp(*iter, cur, l+1);
	}
	return 0;
}

int main()
{
	freopen("travel.in","r",stdin);
	//freopen("travel.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> n;
	for (int i = 1; i < n; i++)
	{
		int a, b;
		cin >> a >> b;
		connect[a].push_back(b);
		connect[b].push_back(a);
	}
	
	for (int i = 0; i < n; i++)
	{
		if (connect[i].size() == 1)
		{
			visited[i] = true;
			dp(i, -1, 1);
		}
	}
	
	cout << C(n,3) - ans;
}
