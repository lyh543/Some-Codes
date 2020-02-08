#include<cstdio>
#include<cmath>
#include<iostream>
//#define debug 

using namespace std;

const double PI = acos(-1);

double dis(double x1, double y1, double x2, double y2)
{
	return sqrt(pow(x1-x2,2) + pow(y1-y2,2));
}

int main()
{
	int n;
	double r;
	scanf("%d%lf",&n, &r);
	double s = 2 * PI * r;
#ifdef debug
	cout << "s += " << 2 * PI * r << endl;
#endif
	
	
	double x0, y0, x1, y1, x2, y2;
	scanf("%lf%lf", &x0, &y0);
	x2 = x0; y2 = y0;
	
	for (int i = 1; i < n; i++)
	{
		x1 = x2; y1 = y2;
		scanf("%lf%lf", &x2, &y2);
		s += dis(x1,y1,x2,y2);
#ifdef debug
		cout << "s += " << dis(x1,y1,x2,y2) << endl;
#endif
	}
	
	s += dis(x2, y2, x0, y0);
#ifdef debug
		cout << "s += " << dis(x0,y0,x2,y2) << endl;
#endif

	printf("%.2lf",s);
} 
