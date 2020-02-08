#include<bits/stdc++.h>
#define ll long long
using namespace std;



int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int a, b;
	cin >> a >> b;
	if (a <= 5)
		b = 0;
	else if (a <= 12)
		b = b / 2;
	cout << b;

}

