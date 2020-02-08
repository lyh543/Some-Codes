#include<bits/stdc++.h>
#include<unordered_map>
#define ll long long
#define ld long double
#define fastio ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);

using namespace std;
typedef pair<int, ll> P;
unordered_map<int,P> m;
//first: father; second: dist

void init(int cur)
{
	if (m.find(cur) == m.end())
	{
		m[cur] = { cur,0 };
	}
}

int findrt(int cur) //return father
{
	init(cur);
	if (m[cur].first == cur)
		return cur;
	else
	{
		int fa = findrt(m[cur].first);
		m[cur].second ^= m[m[cur].first].second;
		m[cur].first = m[fa].first;
		return m[cur].first;
	}
}

void merge(int l, int r, int x)
{
	init(l);
	init(r);
	int rl = findrt(l-1), rr = findrt(r);
	if (rl == rr)
		return;
	m[rl].first = rr;
	m[rl].second  = m[l-1].second  ^ m[r].second ^ x;
}

int query(int l, int r)
{
	if (findrt(l - 1) == findrt(r))
	{
		return m[l - 1].second ^ m[r].second;
	}
	else
		return -1;
}

int main()
{
	fastio;
	int q;
	cin >> q;
	int last = 0;
	for (int i = 0; i < q; i++)
	{
		int t, l, r, x;
		cin >> t;
		if (t == 1)
		{
			cin >> l >> r >> x;
			l ^= last;
			r ^= last;
			x ^= last;
			if (l > r) swap(l, r);
			//cout << "uncode:" << l << " " << r << " " << x << "\n";
			merge(l, r, x);
		}
		else
		{
			cin >> l >> r;
			l ^= last;
			r ^= last;
			if (l > r) swap(l, r);
			//cout << "uncode:" << l << " " << r << "\n";

			last = query(l, r);
			cout << last << endl;
			if (last == -1)
				last = 1;
		}
	}
	return 0;
}
