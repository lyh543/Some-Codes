#include<iostream>

using namespace std;
const int size = 45;

int n, k;
int num[size];
long long ans[size][size];

int main()
{
	cin >> n >> k;
	char c;
	for (int i = 0; i < n; i++)
	{
		cin >> c;
		num[i] = c - '0';
		cout << num[i];
	}
}
