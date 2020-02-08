#include<iostream>

using namespace std;

int main()
{
	double x, base = 0, differ = 0, n = 0; //base¼´»ùÊý, differ¼´ÊÇ²î, 
	while (cin >> x)
	{
		n++;
		differ += x - base;
		if (differ > 2 * base || differ * 2 < base)
		{
			base += differ / n;
			differ = 0;
		}
	}
	cout /* << "Average=" */ << base + differ / n;
}
