//http://codevs.cn/problem/1031/
#include<iostream>
#include<cmath>
#include<fstream>
using namespace std;

const int prime[] = { 3, 5, 7, 11, 13, 17, 19, 23, 29, 31};
bool isPrime[34] = { false };
//只会用到34之内的质数 

int array[18] = { 0 , 1}; //假定的字符链 
bool isUsed[18] = { false, true , false}; //n个待填数中那些被用了 

int main()
{
	
	for (int i = 0; i < sizeof(prime) / sizeof(int); i++)
		isPrime[ prime[i] ] = true;
	int n, point = 2;
	cin >> n;
	if (n % 2 == 1) return 0; //质数链中必然奇偶两两相连 
		for (int i = 2; i <= n; i++)
	{
		array[i] = i % 2 + 2;
	}
	while(point > 1)
	{
		if (array[point] > n) // 如果该数超过了 n ，point就会向前移动1格，同时删去该数 
		{
			isUsed[ array[point - 1] ] = false;
			point--;
			array[point] += 2;
			//isUsed[ array[point] ] = true;
			continue; 
		}
		if (isUsed[ array[point] ]) // 如果该数重复，则 +2 后进入下一次 while 
		{
			//isUsed[ array[point] ] = false;
			array[point] += 2;
			//isUsed[ array[point] ] = true; 
			continue;
		}
		if (!isPrime[ array[point] + array[point-1] ]) //如果该数与前一数之和不是质数，则 +2 后进入下一次 while 
		{
			//isUsed[ array[point] ] = false;
			array[point] += 2;
			//isUsed[ array[point] ] = true; 
			continue;
		}
		
		if (point == n)
		{
			if (isPrime[ array[n] + array[1] ]) // 如果到了最后一个点也满足，则输出 
			{
				cout << array[1];
				for (int i = 2; i <= n; i++)
					cout << " " << array[i];
				cout << endl;
			}
			isUsed[ array[point - 1] ] = false;
			point--;
			array[point] += 2;
			continue;
		}
		isUsed[ array[point] ] = true;
		point++; //point向后移动一格，并初始化它所指向的数
		//for (int i = point % 2 + 2; isUsed[i]; i += 2)
			array[point] = point % 2 + 2;
		//isUsed[ array[point] ] = true; 
	}
}

