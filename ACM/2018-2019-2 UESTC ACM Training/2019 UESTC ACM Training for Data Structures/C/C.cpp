#include<bits/stdc++.h>
#define LL long long
using namespace std;

const int maxn = 100001;

struct edge {
	int l;
	int r;
};

bool operator <(edge a, edge b)
{
	return a.r < b.l;
}
set<edge> s;

set<edge>::iterator iter;

int merge(edge & temp)
{
	if ((iter = s.find(temp)) != s.end())
	//如果存在和temp相等的线段
	{
		temp.l = min(temp.l, iter->l);
		temp.r = max(temp.r, iter->r);
		//造新线段，再删除原线段，再插入新线段，不然删了就找不到了
		s.erase(iter);
		merge(temp);//把这条线段插入的过程交到下一层递归了
		return 1;
	}
	else
	{
		s.insert(temp);
		return 0;
	}
}

int main()
{
	cin.sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		edge temp;
		cin >> temp.l >> temp.r;

		merge(temp);

		cout << (i?" ":"") << s.size();
	}
}
