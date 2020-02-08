//http://codevs.cn/problem/1008
#include<iostream>
#include<cstring> 
using namespace std;

const int size = 20000;

int n, k, x[20], tot;

int getSum(int,int,int);
bool isPrime(int);
bool prime[size];

int main()
{
	memset(prime,1,sizeof(prime));
	for (int i = 2; i < size; i++)
		if (prime[i])
			for (int j = i * i; j < size; j+= i)
				prime[j] = false;
	cin >> n >> k;
	for (int i = 0; i < n; i++) cin >> x[i];
	getSum(0,0,0);
	cout << tot;
}

int getSum(int sum, int point, int get)
{
	if (get == k)
	{
		if (isPrime(sum))
		{
			//cout << sum << " ";
			tot++;
		}
		return 0;
	}
	if (point == n) return 0;
	getSum(sum+x[point],point+1,get+1);
	getSum(sum,point+1,get);
}

bool isPrime(int num)
{
	if (num < size)
	{
		return prime[num];
	}
	else
	{
		for (int i = 2; i < size; i++)
			if (prime[i] == true && num % i == 0) return false;
		return true; 
	}
}
