#include<bits/stdc++.h>
#define ll long long
using namespace std;

const int maxn = 2e5 + 5;

struct work
{
	int t;
	int e;
}w[maxn];

bool operator < (work t, work e)
{
	return t.e < e.e;
}

int main()
{
	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> w[i].t >> w[i].e;
	sort(w, w + n);
	int  t = 0;
	for (int i = 0; i < n; i++)
	{
		t += w[i].t;
		if (t > w[i].e)
		{
			cout << "No";
			return 0;
		}
	}
	cout << "Yes";
	return 0;
}

