#include<bits/stdc++.h>
using namespace std;

const int maxn = 100002;

struct teamS {
	int s; //solved
	int p; //penalty
	teamS() {};
	teamS(int _s, int _p):s(_s), p(_p){}
};
bool operator > (teamS a, teamS b)
{
	return a.s > b.s ||
		(a.s == b.s && a.p < b.p);
}
bool operator < (teamS a, teamS b)
{
	return a.s < b.s ||
		(a.s == b.s && a.p > b.p);
}
bool operator <= (teamS a, teamS b)
{
	return a.s < b.s ||
		(a.s == b.s && a.p >= b.p);
}

multiset<teamS> dalao; //include team stronger than team 1
teamS a[maxn];//include every team's info

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	int m, n, team, p1;
	teamS tmp;
	multiset<teamS>::iterator iter, iter2;
	cin >> n >> m;
	for (int i = 0; i < m; i++)
	{
		cin >> team >> p1;
		tmp = a[team];
		a[team].s++;
		a[team].p += p1;

		if (team == 1)
		{
			iter = dalao.begin();
			//delete all teams lower than team1
			while (iter != dalao.end() && (*iter) <= a[1])
			{
				iter2 = iter;
				iter++;
				//remember to ++ before erase
				dalao.erase(iter2);
			}
		}
		else
		{
			if (a[team] > a[1])
			{
				if (tmp > a[1]) //if it was lower than team1
				{
					dalao.erase(dalao.find(tmp));
				}
				dalao.insert(a[team]);
			}
		}
		cout << dalao.size() + 1 << endl;
	}
}
