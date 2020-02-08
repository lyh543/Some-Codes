#include<iostream>
#include<cmath>

//只需修改下面三排 
#define function x*x-2 //必须以C/C++语言格式输入 
#define function_text "x*x-2" //可以以普通格式输入 
#define accuracy 10

using namespace std;
double a=0,b=0,middle,f0,fa,fb,fm;

double f(double x)
{
    return function;
}

void because(double x1,double x2)
{
	cout << "\n∵\tf(" << x1 << ")=" << f(x1);
	if (f(x1)<0)
	{
		cout << "<0" << endl;
	}
	else
	{
		cout << ">0" << endl;
	}
	cout << "\tf(" << x2 << ")=" << f(x2);
	if (f(x2)<0)
	{
		cout << "<0" << endl;
	}
	else
	{
		cout << ">0" << endl;
	}
	cout << "\tf(" << x1 << ")f(" << x2 << ")<0" << endl; 
	cout << "\n∴\tx0∈(" << x1 << "," << x2 << ")" << endl;
}

void equal(double x)
{
	cout << "\n\tf(" << x << ")=0" << endl;
	cout << "∴\t" << x << "是方程的解" << endl << "\t请按回车以退出…" ;
	cin.get();
}
int main()
{
	cout << "\t令f(x)="  << function_text << endl;
	fb=f0=f(0);
	int plus;
	if ((f(10000)*f(0))<0)
	{
		plus=1;
	}
	else if ((f(-10000)*f(0))<0)
	{
		plus=-1;
	}
	else
	{
		cout << "\t根的范围不在-10000~10000间，无法进行计算" << endl
			 << "\t请按回车以退出…" ;
		cin.get();
		return 0; 
	}
	while(f0*fb>0)
	{
		b=b+plus;
		fb=f(b);
	}
	a=b-1;
	
	if (fb==0)
	{
		equal(b);
		return 0;
	}
	else
	{
		because(a,b);
	}
	while(abs(a-b)>accuracy)
	{
		middle=(a+b)/2;
		fm=f(middle);
		cout << "\t取(" << a << "," << b << ")中点" << middle <<endl; 
		if (fm==0)
		{
			equal(middle);
			return 0;
		}
		if ((fm*fb)<0)
		{
			a=middle;
		}
		else
		{
			b=middle;
		}
		because(a,b);
	}
	cout << "\n∵\t|" << a << "-" << b << "|<" << accuracy << endl;
	cout << "∴\tx0=" << a << "\n\n\t请按回车以退出…" ;
	cin.get();
	return 0;
}