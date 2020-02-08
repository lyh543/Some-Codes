//D
#include<bits/stdc++.h>
#define ld long double 
#define ll long long 
//#define int ll
#define eps 1e-11
#define fastio ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
typedef pair<ll, int> P;

const int maxn = 2e5 + 5, infty = 100000;

int arr[maxn];

int main()
{
	fastio;
	int n, y = 0;
	cin >> n;
	cin >> arr[0];
	for (int i = 1; i < n; i++)
	{
		cin >> arr[i];
		if (arr[i] == arr[i - 1])
		{
			cout << "NO";
			return 0;
		}
		if (abs(arr[i] - arr[i - 1]) != 1)
		{
			if (y == 0)
			{
				y = abs(arr[i] - arr[i - 1]);
			}
			else if (y != abs(arr[i] - arr[i - 1]))
			{
				cout << "NO";
				return 0;
			}
		}
	}
	if (y == 0)
		y = 1;
	else for (int i = 1; i < n; i++)
		{
			if ((arr[i - 1] % y == 0 && arr[i] % y == 1 && arr[i]-arr[i-1] == 1) || (arr[i - 1] % y == 1 && arr[i] % y == 0 && arr[i - 1] - arr[i] == 1))
			{
				cout << "NO";
				return 0;
			}
		}
	cout << "YES\n" << 1000000000 << " " << y;

}
