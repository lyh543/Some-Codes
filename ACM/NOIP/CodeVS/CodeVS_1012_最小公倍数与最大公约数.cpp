//http://codevs.cn/problem/1012/ 
#include <iostream>

using namespace std;

int main()
{
	int x, y, a, i = 2, count = 0;
	cin >> x >> y;
	a = y / x;
	while (a != 1)
	{
		if (a % i == 0)
		{
			count++;
			while (a % i == 0)
				a = a / i;
		}
		i++;
	}
	cout << (1<<count);
}
