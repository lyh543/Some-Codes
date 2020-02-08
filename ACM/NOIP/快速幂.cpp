#include<iostream>

using namespace std;

int quick_power(int base, int index, int mod)
{
	int b = base % mod, ans = 1;
	for (int i = index; i != 0; i = i >> 1)
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
	int base, index, mod;
	cin >> base >> index >> mod;
	
	cout << quick_power(base, index, mod);
} 
