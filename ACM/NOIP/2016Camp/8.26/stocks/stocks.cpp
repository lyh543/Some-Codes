#include<iostream>
#include<cstdlib>
#include<queue> 

using namespace std;

const int size = 100000;

int main()
{
	double f[size+1] = {0}, price[size+1];
	double g;
	// f[i]表示i天的理想收入，g表示i天的理想收入全换成股票的数量
	
	int n;
	cin >> n;
  	for (int i = 1; i <= n; i++)
		cin >> price[i];
	
	f[1] = 1;
	g = 1 / price[1];
	
	for (int i = 2; i <= n; i++) //开始计算i天的理想收入 
	{
		//如果i天操作，就应该是max(g[j]) * price[i] 
		f[i] = max( f[i-1], g * price[i] );
		g = max (g , f[i] / price[i]);
	}
	
	cout.setf(ios_base::fixed, ios_base::floatfield);
	cout.precision(4);
	cout << f[n];
}
