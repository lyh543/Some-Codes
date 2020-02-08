#include<bits/stdc++.h>
#define ld long double 
#define ll long long 
#define fastio ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
 
const int maxn = 1005;
 
map<int, int> m;
 
int main()
{
	fastio;
	int n, a;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> a;
		m[a]++;
	}
	int temp = 0;
	if (m.size() == 3)
	{
		for (pair<int,int> i : m)
		{
			temp ^= i.first;
			if (i.second * 3 != n)
			{
				cout << "No";
				return 0;
			}
		}
		if (temp == 0)
			cout << "Yes";
		else
			cout << "No";
		return 0;
	}
	else if (m.size() == 2)
	{
		if (m.find(0) != m.end() && (abs(m[0] * 2 - n) <= 1 || m[0]*3==n*2 || m[0] * 3 == n))
			cout << "Yes";
		else
			cout << "No";
		return 0;
	}
	else if (m.size() == 1)
	{
		if (m.begin()->first == 0)
			cout << "Yes";
		else
			cout << "No";
	}
	else
		cout << "No";
	return 0;
}
