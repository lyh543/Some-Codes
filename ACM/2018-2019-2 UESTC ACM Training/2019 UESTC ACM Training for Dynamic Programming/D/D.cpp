#include<bits/stdc++.h>

using namespace std;

const int maxn = 1e6 + 5;

int a[maxn], b[maxn], n, len1[maxn], len2[maxn];
int LIS1[maxn] = { 0 }, LIS2[maxn] = { 0 };
//leng[i]: max lis length from a[0] to a[i]
//lis[i]: least last number of a i-length lis


void getLIS(int a[], int lis[], int leng[])
{
	lis[1] = a[0];
	int len = 1; // length of lis
	leng[0] = 1;
	for (int i = 0; i < n; i++)
	{
		if (a[i] > lis[len])
		{
			lis[++len] = a[i];
			leng[i] = len;
		}
		else
		{
			leng[i] = lower_bound(lis+1, lis + len+1, a[i]) - lis;
			lis[leng[i]] = a[i];
		}
	}
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> a[i];
		b[n - i - 1] = a[i];
	}

	getLIS(a, LIS1, len1);
	getLIS(b, LIS2, len2);

	int ans = 0;
	for (int i = 0; i < n; i++)
	{
		ans = max(ans, min(len1[i], len2[n - i - 1]));
	}
	cout << ans * 2 - 1;
	return 0;
}

