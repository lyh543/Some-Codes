#include <algorithm>
#include <iostream>
#include <cstring>
#include <cstdio>
#include <cmath>
using namespace std;

const int MaxN = 5001;
const int MaxM = 12600000;
const int M = 4194303;
const int R = 1000000;

int n, a[MaxN];
int m, next[MaxM], value[MaxM];
int adj[M + 1];

inline void add(const int &w)
{
	value[++m] = w, next[m] = adj[w & M];
	adj[w & M] = m;
}
inline bool query(const int &w)
{
	for (int p = adj[w & M]; p; p = next[p])
		if (value[p] == w)
			return true;
	return false;
}

inline int solve1()
{
	static bool book[R * 4 + 10];

	int res = 0;
	for (int i = 1; i <= n; ++i)
	{
		for (int j = 1; j < i; ++j)
			if (book[a[i] - a[j] + R + R])
			{
				++res;
				break;
			}
		for (int j = 1; j <= i; ++j)
			book[a[i] + a[j] + R + R] = true;
	}
	return res;
}

inline int solve2()
{
	int res = 0;
	for (int i = 1; i <= n; ++i)
	{
		for (int j = 1; j < i; ++j)
			if (query(a[i] - a[j]))
			{
				++res;
				break;
			}
		for (int j = 1; j <= i; ++j)
			add(a[i] + a[j]);
	}
	return res;
}

int main()
{
	freopen("good.in", "r", stdin);
	freopen("good.out", "w", stdout);

	cin >> n;
	for (int i = 1; i <= n; ++i)
		scanf("%d", &a[i]);

	int foo = *min_element(a + 1, a + n + 1);
	int bar = *max_element(a + 1, a + n + 1);
	int res = foo >= -R && bar <= R ? solve1() : solve2();
	cout << res << endl;

	fclose(stdin);
	fclose(stdout);
	return 0;
}