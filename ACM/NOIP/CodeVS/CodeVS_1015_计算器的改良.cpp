//http://codevs.cn/problem/1015/
#include<iostream>
#include<cstring>
#include<cctype>
#include<iomanip>
using namespace std;

int xishu = 0, x = 0, constant = 0, xadd = 1, cadd = -1, positive = 1;

int main()
{
	const int size = 105;
	char equation[size] = {0}, weizhishu;
	cin >> equation;

	int p = 0, l = strlen(equation);
	while (p < l)
	{
		if (equation[p] == ' ')
		{
			constant += cadd * positive * xishu; 
			p++;
		}
		else if (isdigit(equation[p])) //如果是数字，则获取整个字符串
		{
			xishu = 0;
			while (isdigit(equation[p]))
			{
				xishu = xishu * 10 + equation[p] - '0';
				p++;
			}
		}
		else if (isalpha(equation[p])) //如果是字母，则加入系数 
		{
		    weizhishu = equation[p];
			if (xishu == 0) xishu = 1;
			x += xadd * positive * xishu;
			xishu = 0;
			p++;
		}
		else if (equation[p] == '+') //前面有一个数
		{
			constant += cadd * positive * xishu;
			xishu = 0;
			p++;
			positive = 1;
		}
		else if (equation[p] == '-') //前面有一个数
		{
			constant += cadd * positive * xishu;
			xishu = 0;
			p++;
			positive = -1;
		}
		else if (equation[p] == '=')
		{
			constant += cadd * positive * xishu;
			xishu = 0;
			cadd = -cadd;
			xadd = -xadd;
			p++;
			positive = 1;
		}
		if (p == l)
		{
			constant += cadd * positive * xishu;
			xishu = 0;
		}
	}
	cout << setiosflags(ios::fixed) << setprecision(3);
	cout << weizhishu << "=";
	double ans = constant * 1.0 / x;
	if (ans < 0.01 && ans > -0.01)cout << 0.0; else cout << ans;
} 
