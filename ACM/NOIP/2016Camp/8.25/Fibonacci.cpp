#include<iostream>

using namespace std;

void Fibonacci(const int n)
{
	int ans[3] = {0, 1, 2};
	cout << "1! = 1" << endl
		 << "2! = 2" << endl;
	for (int i = 3; i <= n; i++)
	{
		cout << i << "! = " << (ans[i%3] = ans[(i+1)%3] + ans[(i-1)%3]) << endl;
	} 
}

int main()
{
	 Fibonacci(10);
}

