#include<iostream>
#include<cstdlib>
#include<ctime>
#include<cmath>
#include<algorithm>

using namespace std;

const int size = 100;

int c1[size][size] = {0};
long long Combination1(int n, int m) //从n个人中选m个人，用Pascal's Formula实现 
{
	if (m == n) return 1;
	if (m == 1) return n;
	
	if (c1[n][m] != 0) return c1[n][m];
	return (c1[n][m] = Combination1(n-1, m-1) + Combination1(n-1, m));
}

long long Combination2(int n, int m) // 用阶乘实现 
{
	long double ans = 1;
	if (m * 2 > n) m = n - m;
	
	for (int i = 1; i <= m; i++)
	{
		ans *= (n - i + 1) / i; 
	}
	return ans;
}

int main()
{
	srand(time(NULL));
	for (int i = 0; i < 10; i++)
	{
		int m = rand() % 50, n = m + rand() % 50;
		cout << "----------------------------" << endl
			 << "For m = " << m << " & n = " << n << endl
			 << "C1 = " << Combination1(n,m) << endl
			 << "C2 = " << Combination2(n,m) << endl << endl;
	}
}
