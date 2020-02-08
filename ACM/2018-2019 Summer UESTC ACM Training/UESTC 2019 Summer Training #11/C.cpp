#include<bits/stdc++.h>
#include<unordered_set>
//#define _CRT_SECURE_NO_WARNINGS
#define ld long double 
#define ll long long 
//#define int ll
#define eps 1e-11
#define fastio ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
typedef pair<ll, ll> P;

const ll maxn = 3005, mod = 998244353;
const ll infty = LLONG_MAX / 2;

int m[maxn];

int arr[maxn], arr2[maxn], posi[maxn];

signed main()
{
	fastio;
	int n;
	cin >> n;
	while (n)
	{
		for (int i = 1; i <= n; i++)
		{
			cin >> arr[i];
			m[arr[i]] = i;
		}
		for (int i = 1; i <= n; i++)
		{
			int a;
			cin >> a;
			arr2[i] = m[a];
			posi[m[a]] = i;
		}
		ll ans = 0;
		for (int i = 1; i <= n; i++)
		{
			int l = posi[i], r = posi[i], up = i;
			while (true)
			{
				if ((l == 1 || arr2[l - 1] < i) && (r == n || arr2[r + 1] < i))
					break;
				if ((r == n || arr2[r + 1] < i) || ((l != 1 && arr2[l-1] > i) && arr2[l - 1] < arr2[r + 1])) //move left
				{
					l--;
					up = max(up, arr2[l]);
					if (up != i && up - i == r - l)
						ans++;
				}
				else
				{
					r++;
					up = max(up, arr2[r]);
					if (up != i && up - i == r - l)
						ans++;
				}
			}
		}
		cout << ans << endl;
		cin >> n;
	}
}
