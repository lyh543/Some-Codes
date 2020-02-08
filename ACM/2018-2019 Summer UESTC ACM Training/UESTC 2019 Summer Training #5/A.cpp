#include<bits/stdc++.h>
#include<unordered_map>
#define ll long long
#define ld long double
#define fastio ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);

using namespace std;

struct Prob
{
	ld r;
	ld s;
	ld p;
	Prob operator + (Prob a)
	{
		return { r + a.r, s + a.s, p + a.p };
	}
};

Prob operator * (ld pr, Prob a)
{
	return {pr*a.r, pr*a.s, pr*a.p};
}

const int maxn = 105;

Prob ans[maxn][maxn][maxn] = { {{0}} };

int main()
{
	int R, S, P;
	scanf("%d%d%d", &R, &S, &P);

	for (int r = 0; r <= R; r++)
	{
		for (int s = 0; s <= S; s++)
		{
			for (int p = 0; p <= P; p++)
			{
				Prob & cur = ans[r][s][p];
				if (r == 0) cur = { 0,1,0 };
				else if (s == 0) cur = { 0,0,1 };
				else if (p == 0) cur = { 1,0,0 };
				else
				{
					ld all = p * r + r * s + s * p;
					cur = p * r / all * ans[r - 1][s][p]
						+ r * s / all * ans[r][s - 1][p]
						+ s * p / all * ans[r][s][p - 1];
				}
			}
		}
	}
	printf("%.10Lf %.10Lf %.10Lf",ans[R][S][P].r, ans[R][S][P].s, ans[R][S][P].p);
}