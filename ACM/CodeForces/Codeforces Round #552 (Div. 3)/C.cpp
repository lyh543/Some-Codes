#include<bits/stdc++.h>
 
using namespace std;
 
int Go(int first, int f, int r, int c)
{
	int t = 0, day = first;
	while (true)
	{
		if (day == 1 || day == 4 || day == 7)
		{
			if (f == 0)
				return t;
			f--;
		}
		else if (day == 2 || day == 6)
		{
			if (r == 0)
				return t;
			r--;
		}
		else
		{
			if (c == 0)
				return t;
			c--;
		}
		day++;
		if (day == 8)
			day = 1;
		t++;
	}
}
 
 
int main()
{
	cin.sync_with_stdio(0);
	cin.tie(0);
 
	// f r c  f c r f
	int f = 0, r = 0, c = 0;
	cin >> f >> r >> c;
	int ans = min(min(f / 3, r / 2), c / 2);
	f -= 3 * ans;
	r -= 2 * ans;
	c -= 2 * ans;
	ans *= 7;
 
	int t = 0;
	for (int i = 1; i <= 7; i++)
	{
		t = max(t,Go(i,f,r,c));
	}
	cout << ans + t;
}
