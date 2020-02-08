#include<bits/stdc++.h>
//#define _CRT_SECURE_NO_WARNINGS
#define ld long double 
#define ll long long 
#define int ll
#define eps 1e-11
#define fastio ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
typedef pair<int, int> P;
 
const int maxn = 105;
 
map<int,vector<int> > a;
 
int arr[maxn], arrlen = 0;
 
signed main()
{
	fastio;
	int n, sum = 0, sum2 = 0, a0;
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		int t;
		cin >> t;
		sum += t;
		
		if (i == 1)
			a0 = t;
		else if (t <= a0/2)
		{
			sum2 += t;
			arr[arrlen++] = i;
		}
	}
	if (sum2 + a0 > sum/2)
	{
		cout << arrlen + 1 << endl << 1 << " ";
		for (int i = 0; i < arrlen; i++)
		{
			cout << arr[i] << " ";
		}
	}
	else
	{
		cout << 0;
	}
 
}
