#include<bits/stdc++.h>
#define long double ld
#define long long ll
 
using namespace std;
 
const int maxn = 100;
char str[maxn];
 
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
 
	int n, t = 0;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> str[i];
		if (str[i] == '0')
			t++;
		else
			t--;
	}
	if (t == 0)
	{
		cout << 2 << endl << str[0] << " ";
		for (int i = 1; i < n; i++)
			cout << str[i];
	}
	else
	{
		cout << 1 << endl;
		for (int i = 0; i < n; i++)
			cout << str[i];
	}
}
