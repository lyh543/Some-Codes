#include<bits/stdc++.h>
#define LL long long
using namespace std;

const int maxn = 200001;

int v[maxn], visited[maxn] = {0}, l[maxn], r[maxn];

struct cmp
{
	bool operator ()(const int & a, const int & b)
	{
		return v[a] < v[b];
	}
};

priority_queue<int,vector<int>,cmp> id;

int main()
{
	cin.sync_with_stdio(0);
	cin.tie(0);

	int n, m, ans = 0;
	cin >> n >> m;

	if (m * 2 > n)
	{
		cout << "Error!";
		return 0;
	}

	for (int i = 0; i < n; i++)
	{
		cin >> v[i];
		id.push(i);
		l[i] = i - 1;
		r[i] = i + 1;
	}
	l[0] = n - 1;
	r[n - 1] = 0;

	for (int i = 0; i < m; i++)
	{
		int temp;
		do
		{
			temp = id.top();
			id.pop();
		}while(visited[temp]);
        //找到最大的没有被访问过的点

		ans += v[temp];//ans增加
		visited[l[temp]] = 1;//把左右设为访问
		visited[r[temp]] = 1;
		v[temp] = v[l[temp]] + v[r[temp]] - v[temp];//改一下中间的v值
		id.push(temp);

		l[temp] = l[l[temp]];
		r[temp] = r[r[temp]];
		l[r[temp]] = r[l[temp]] = temp;
        //去掉temp左边、右边的值
	}
	cout << ans;
}