#include<bits/stdc++.h>
#define ld long double 
#define ll long long 
 
using namespace std;
 
const int maxn = 1e5 + 5;
 
ll a[maxn], b[maxn] = {0}, del = 0;
 
void endgame(int a)
{
	cout << ((a == 1) ? "sjfnb": "cslnb");
}
 
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
 
	int n;
	cin >> n;
 
	for (int i = 0; i < n; i++)
		cin >> a[i];
 
	if (n == 1)
	{
		endgame(a[0] % 2);
		return 0;
	}
	sort(a, a + n);
	del += a[0];
 
	if (a[0] == 0 && a[1] == 0)
	{
		endgame(0);
		return 0;
	}
 
	int cnt = 0;
	for (int i = 1; i < n; i++)
	{
		if (a[i] == a[i - 1])
		{
			cnt++;
			if (cnt == 2 || (i > 1 && a[i-1] - a[i-2] <= 1) )
			{
				endgame(0);
				return 0;
			}
		}
		b[i] = b[i - 1] + 1;
		del += a[i] - b[i];
	}
 
	endgame(del % 2);
}
