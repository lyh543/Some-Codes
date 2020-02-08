#include<cstdio>
#include<cstring>
#include<cmath>
#include<vector>
#include<iostream>

using namespace std;

bool isPrime(long long n, vector<long long> * prime)
{
	if (n == 1) return false;
	for (vector<long long>::iterator i = prime->begin(); i < prime->end(); i++)
		if (n == *i)
		{
			return true;
		}
		else
		{
			if (n % *i == 0)
			return false;
		}
	return true;
}


int main()
{
	vector<long long> prime;
	prime.push_back(2);
	for (long long i = 3; i <= 100000; i += 2)
	{
		bool isPrime = true;
		for (vector<long long>::iterator iter=prime.begin(); iter < prime.end(); iter++)
		{
			if (i % *iter == 0) 
			{
				isPrime = false;
				break;
			}
		}
		
		if (isPrime) prime.push_back(i);
	}
	
	int n;
	long long ask;
	scanf("%d",&n);
	for (int i = 0; i < n; i++)
	{
		scanf("%I64d",&ask);
		long long sq = sqrt(ask); 
		if (i) printf("\n");
		//cout << sq*sq;
		if (sq*sq == ask && isPrime(sq,&prime))
			printf("YES");
		else
			printf("NO");
	}
} 
