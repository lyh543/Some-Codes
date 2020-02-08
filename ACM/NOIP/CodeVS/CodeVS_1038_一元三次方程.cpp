// http://codevs.cn/problem/1038/
#include<iostream>
#include<iomanip>

double a,b,c,d;
bool first = true;

bool f(double x)
{
	return (a*x*x*x+b*x*x+c*x+d > 0);
}

double binary(double l, double r);

using namespace std;

int main()
{
	cin >> a >> b >> c >> d;
	cout << setiosflags(ios::fixed) << setprecision(2);
	bool lastPositive = f(-100);
	for (int i = -99; i <= 100; i++)
	{
		bool temp = f(i);
		if (temp xor lastPositive) binary (i-1, i);
		lastPositive = temp;
	}
}

double binary(double l, double r)
{
	if (r - l < 0.001)
	{
		if (first) first=false; else cout << " ";
		cout << l;
		return 0;
	}
	else
	{
		double m = (l + r) / 2;
		if ( f(m) xor f(l)) return binary(l,m);
		else return binary(m,r);
	}
}
