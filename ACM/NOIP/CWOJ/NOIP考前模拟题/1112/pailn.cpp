#include<iostream>

using namespace std;

int main()
{
	int cnt[256] = {0};
	ios::sync_with_stdio(0);
	char c, maxc, maxn;
	
	while (cin >> c)
	{
		if (c > maxc)
		{
			maxc = c;
			maxn = 1;
		}
		else if (c == maxc)
		{
			maxn++;
		}
	}
	
	for (int i = 0; i < maxn; i++)
	{
		cout << maxc;
	}
}
