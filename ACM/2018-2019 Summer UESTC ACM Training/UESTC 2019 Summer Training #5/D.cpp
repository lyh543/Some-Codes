#include<bits/stdc++.h>
#include<unordered_map>
#define ll long long
#define ld long double
#define fastio ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);

using namespace std;
typedef pair<ll, int> P;

const int maxn = 2e5 + 5;
const int infty = 1e9;
int a[maxn];

int main()
{
	fastio;
	int n,k;
	cin >> n >> k;
	
	for (int i = 0; i < n; i++)
	{
		cin >> a[i];
	}

	sort(a,a+n);
	if (k == 0)
	{
		if (a[0] == 1)
			cout << -1;
		else
			cout << 1;
	}
	else if (k == n)
	{
		cout << infty;
	}
	else if (a[k] == a[k - 1])
		cout << -1;
	else
		cout << a[k - 1];
}
