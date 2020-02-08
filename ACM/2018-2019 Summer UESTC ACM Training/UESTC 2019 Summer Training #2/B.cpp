#include<bits/stdc++.h>

#define ll long long
#define ld  long double
#define eps 1e-8

using namespace std;

const int maxn = 2e5 + 4;

//sv=(sum(x^2)n-sum(x)^2/n)/n;

struct P {
	ld value;
	ld del = 1;
	bool operator < (const P a) const 
	{
		return value*value/(del*(del+1)) < a.value*a.value/(a.del*(a.del+1));
	}
};


int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int T = 1;
	scanf("%d", &T);
	for (int cas = 1; cas <= T; cas++)
	{
		priority_queue<P> s;
		int n, m;
		scanf("%d%d", &n, &m);
		
		ld a, sum = 0, sum2 = 0;
		for (int i = 0;i < n; i++)
		{
			scanf("%Lf", &a);
			sum += a;
			s.push({a,1});
			sum2 += a * a;
		}
		ld ans = (sum2 - sum * sum / m) / m;
		for (int i = n; i < m; i++)
		{
			n++;
			P temp = s.top();
			sum2 -= pow(temp.value,2)/(temp.del * (1 + temp.del));
			s.pop();
			temp.del++;
			s.push(temp);
			ans = min(ans,(sum2 - sum * sum / m) / m);
		}
		printf("Case #%d: %.9Lf\n", cas,ans);
	}
}
