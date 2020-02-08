#include<iostream>
#include<iomanip>
#include<string>
#include<vector>
#include<queue>
#include<set>
#define ld long double 
#define ll long long
#define lll __int128 
//#define int ll
#define eps 1e-11
#define fastio ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
typedef pair<int, int> P;

const int maxn = 1e5 + 5;

set<int> t;
int arr[maxn];

signed main()
{
	fastio;
	int n, m;
	cin >> n >> m;
	for (int i = 0; i < n; i++)
	{
		cin >> arr[i];
	}
	for (int i = n - 1; i >= 0; i--)
	{
		if (m == 0)
			break;
		if (!t.insert(arr[i]).second)
			continue;
		cout << arr[i] << endl;
		m--;
	}
}
