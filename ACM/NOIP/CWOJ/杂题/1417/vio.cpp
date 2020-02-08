#include<iostream>

using namespace std;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	long long  max = 0, a[100];
	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> a[i];
	}
	
	for (int i = 0; i < n; i++)
	{
		for (int j = i+1; j < n; j++)
		{
			if ((a[i] & a[j]) > max) max = (a[i] & a[j]);
		}
	}
	
	cout << max;
}
