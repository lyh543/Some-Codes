#include<iostream>
#include<cmath>

using namespace std;

long long quick_power(long long base, long long index, long long mod)
{
	long long ans = 1;
	long long b = base % mod;
	for (long long i = index; i != 0; i >>= 1)
	{
		if (i & 1)
		{
			ans = ans * b % mod;
		}
		b = b * b % mod; 
	}
	return ans;
}

int main()
{
	long long base = 10, mod, x, m, k;
	cin >> mod >> m >> k >> x;
	
	// ans = (10^k * m  + x) % mod
	
	//cout <<  (quick_power(10,k,mod) * (m%mod) + x) % mod;
	cout << ((long long)pow(10,k) * m  + x) % mod;
	
}
