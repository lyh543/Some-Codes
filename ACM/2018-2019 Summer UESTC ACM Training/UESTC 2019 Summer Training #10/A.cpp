//I
#include<bits/stdc++.h>
//#define _CRT_SECURE_NO_WARNINGS
#define ld long double 
#define ll long long 
#define int ll
#define eps 1e-11
#define fastio ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
typedef pair<int, int> P;

const int maxn = 2e5 + 5;

vector<int> arr;

signed main()
{
	fastio;
	int T;
	cin >> T;
	while (T--)
	{
		arr.clear();
		int n;
		int temp = 0;
		cin >> n;
		for (int i = 0; i < n; i++)
		{
			char c;
			cin >> c;
			if (c == '1')
			{
				arr.push_back(temp);
				temp = 0;
			}
			else
			{
				temp++;
			}
		}
		arr.push_back(temp);

		int arrlen = arr.size();
		int sum[2] = { 0 }, sum3 = 0;
		for (int i = 0; i < arrlen; i++)
		{
			sum[i % 2] += arr[i] + 1;
			if (i != arrlen - 1)
				sum3 += arr[i] + arr[i + 1] + 1;
		}
		cout << sum[1] * sum[0] - sum3 << endl;
	}
}
