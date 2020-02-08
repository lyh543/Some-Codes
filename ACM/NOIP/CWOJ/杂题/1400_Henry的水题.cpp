#include<cstdio>
#include<cmath>

using namespace std;

const double PI = 3.14159265358979;


double ans(double a,double b,double c);
double maxR(double a, double b, double c);
double S_Tri(double a, double b);
double S_Tri(double a, double b, double c);
double bevel(double a, double b);
double V(double a, double b, double c);

int main()
{
	double a, b, c;
	scanf("%lf%lf%lf",&a,&b,&c);
	printf("%.2lf",ans(a,b,c));
}

double ans(double a,double b,double c)
{
	return pow(maxR(a,b,c),3) * PI * 4 / 3;
}
double maxR(double a, double b, double c)
{
	return (V(a,b,c) * 3 / (S_Tri(a,b) + S_Tri(b,c) + S_Tri(a,c)
						+S_Tri(bevel(a,b), bevel(b,c), bevel(a,c))));
}
double S_Tri(double a, double b)
{
	return a * b / 2;
}
double S_Tri(double a, double b, double c)
{
	double p = (a + b + c) / 2;
	return sqrt(p * (p - a) * (p - b) * (p - c));
}
double bevel(double a, double b)
{
	
	return sqrt(a*a + b*b);
}
double V(double a, double b, double c)
{
	return a * b * c / 6;
}

