//D
#include<bits/stdc++.h>
#define ld long double 
#define ll long long 
//#define int ll
#define eps 1e-11
#define fastio ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
typedef pair<int, int> P;

const int maxn = 2e5+5, infty = 100000;

int arr[maxn];

map<ld, ld> m;

int main()
{
	fastio;
	int n, T;
	cin >> n >> T;
	for (int i = 0; i < n; i++)
	{
		cin >> arr[i];
	}
	for (int i = 0; i < n; i++)
	{
		int a;
		cin >> a;
		m[a] += arr[i];
	}
	ld ans = 0;
	while (!m.empty())
	{
		auto a = m.lower_bound(T);
		if (a == m.end())
			break;
		if (a->first == T)
		{
			ans += a->second;
			m.erase(a);
			continue;
		}
		if (a == m.begin())
			break;
		auto low = a;
		low--;
		ld ra = (a->first - T) / (T - low->first);
		if (low->second <= a->second * ra)
		{
			ans += low->second*(1 + 1/ra);
			a->second -= low->second / ra;
			m.erase(low);
		}
		else
		{
			ans += a->second * (1 + ra);
			low->second -= a->second * ra;
			m.erase(a);
		}
	}
	cout <<fixed << setprecision(7) << ans;
}
