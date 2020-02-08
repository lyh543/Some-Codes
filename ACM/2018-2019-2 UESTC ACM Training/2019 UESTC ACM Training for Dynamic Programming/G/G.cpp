#define _CRT_SECURE_NO_WARNINGS
#include<iostream>

const int maxn = 2e7+5;

using namespace std;

long long ans = 0, p[maxn][2] = { 0 };
long long n, mod;
char c;
int cur, i = 0;


int main()
{
	scanf("%lld%lld", &n, &mod);

	while(i < n)
	{
		c = getchar();
		if (c > '9' || c < '0')
			continue;
		c -= '0';
		for (int j = 0; j < mod; j++)
			p[j][!(i & 1)] = 0;
		for (int j = 0; j < mod; j++)
		{
			cur = (j * 10 + c)%mod;
			p[cur][!(i & 1)] += p[j][i & 1];
		}
		p[c%mod][!(i & 1)]++;
		ans += p[0][!(i & 1)];
		i++;
	}

	printf("%lld", ans);
}