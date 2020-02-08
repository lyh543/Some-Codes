#include<iostream>

using namespace std;

const int size = 30;
long long tot[size+1]; //tot[j]表示j人拿50元的情况数 

long long dp(int m, int n)
{
	for (int j = 0; j <= m; j++) tot[j] = 1;
	for (int i = 1; i <= n; i++)
		for (int j = i+1; j <= m; j++)
			tot[j] += tot[j-1];
			
	return tot[m];
			
}

int main()
{
	cin.sync_with_stdio(false);
	cin.tie(0);
	
	int m,n;
	cin >> m >> n;
	cout << dp(m,n);
}

/* 
动态规划。

显然出现一个100元前，必须出现一个50元。
用一个int tot[i][j]的数组
表示最后i+j个人中出现i个100元和j个50元，有多少种情况
(i=j=0时) tot[i][j] = 1 
(i<j时) tot[i][j] = tot[i][j-1] + tot[i-1][j]
(i=j时) tot[i][j] = tot[i][j-1]
所求量即为tot[n][n]。 
时间复杂度 O(n^2)


接下来进行降维：
显然计算每个tot时只需要左方和上方的格子，所以可以省略i
对于i = 1 ~ n的循环：
对于所有j<i， tot[j] += tot[j-1]（需要正着算）
所求即为最后的tot[n]。

另外，把j降维掉也是可以的。
*/ 
