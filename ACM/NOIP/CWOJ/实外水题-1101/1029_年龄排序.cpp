#include<iostream>

using namespace std;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	int n, people[101] = {0};
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		int age;
		cin >> age;
		people[age]++;
	}
	
	for (int age = 1; age <= 100; age++)
	{
		for (int i = 0; i < people[age]; i++)
		{
			cout << age << " ";
		}
	}
}
