#include <bits/stdc++.h>
#define ll long long 
#define ld long double
using namespace std;

const int maxn = 1 << 9;

bool in[maxn] = { 0 };
int num = 0;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	char s[10000];
	int n;
	while (cin >> n)
	{
		memset(in, 0, sizeof(in));
		num = 0;
		for (int i = 0; i < n; i++)
		{
			int t = 0;
			cin >> s;
			int len = strlen(s);
			for (int i = 0; i < len; i++)
			{
				t |= 1 << (s[i] - '1');
			}
			if (!in[t])
			{
				in[t] = true;
				num++;
			}
		}
		cout << num << endl;
	}
}
