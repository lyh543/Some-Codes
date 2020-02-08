#include<iostream>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	int a, b, tot;
	cin >> a >> b;
	tot = a * b;
	for (int i = 0; i < tot; i++)
	{
		char c;
		cin >> c;
		if (c == 'M' || c == 'C' || c == 'Y')
		{
			cout << "#Color";
			return 0;
		}
	}
	
	cout << "#Black&White";
	return 0;
} 
