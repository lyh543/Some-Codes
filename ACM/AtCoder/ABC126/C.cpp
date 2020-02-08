#include<bits/stdc++.h>

using namespace std;

int main()
{
	long double N,K, ans = 0;
	cin >> N >> K;
	
	for (int i = 1; i < K & i <= N; i++)
	{
		int cur = i;
		long double p = 1;
		while (cur < K)
		{
			cur *= 2;
			p /= 2;
		}
		ans += p;
		
	}
	ans /= N;
	if ((N-K+1)/N > 0)
		ans += (N-K+1)/N;
	printf("%.12Lf", ans);
}

