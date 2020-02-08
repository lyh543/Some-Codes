#include<cmath>

using namespace std;

struct vec
{
	double x;
	double y;
	vec(const double a = 0, const double b = 0){x=a;y=b;}
	
	double size()const
	{
		return sqrt(x*x+y*y);
	};
	
	vec operator + (const vec & v)const
	{
		return vec(x+v.x, y+v.y);
	}
	vec operator - ()const
	{
		return vec(-x,-y);
	}
	vec operator - (const vec &v)const
	{
		return vec(x-v.x, y-v.y);
	}
	double operator * (const vec &v)const
	{
		return x * v.x + y * v.y;
	}
};
 
bool operator == (const vec &v1, const vec &v2)
{
	return (v1.x == v2.x && v1.y == v2.y);
}

bool parallel(const vec &v1, const vec &v2)//Æ½ÐÐ 
{
	return (v1.x*v2.y == v1.x*v2.y);
}
bool vertical(const vec &v1, const vec &v2)//´¹Ö±
{
	return v1*v2 == 0;
}
double cos(const vec &v1, const vec &v2)
{
	return v1 * v2 / v2.size() / v1.size();
}
