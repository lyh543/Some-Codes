#include<bits/stdc++.h>
#define ld long double 
#define ll long long 

using namespace std;

inline bool ask(int a, int b, int c)
{
	char ret[10];
	cout << "? "<<a << " " << b << " " << c << "\n";
	cout.flush();
	cin >> ret;
	return (strcmp(ret, "Yes") == 0);
}

int main()
{
	srand(5436);
	int n, k, d;
	cin >> n >> k;
	d = log(n*(k - 1) + 1) / log(k) + 0.01;
	int la, lb;
	multiset<int> ab;
	while (ab.size() != 2 * d - 3)
	{
		ab.clear();
		la = rand() % n + 1;
		lb = rand() % n + 1;
		for (int i = 1; i <= n; i++)
		{
			if (i == la || i == lb)
				continue;
			if (ask(la, i, lb))
			{
				ab.insert(i);
			}
		}
	}
	ab.insert(la);
	ab.insert(lb);
	int value[1505] = { 0 };
	for (int a : ab)
		for (int b : ab)
			for (int c : ab)
				value[b] += ask(a, b, c);
	int ans, ansval = 0;
	for (int a : ab)
		if (ansval < value[a])
		{
			ansval = value[a];
			ans = a;
		}
	cout << "! " << ans;
	return 0;
}
