#include<bits/stdc++.h>
#define ll long long
using namespace std;



int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	ll r, d, x;
	cin >> r >> d >> x;
	for (int i = 1; i <= 10; i++)
		cout << (x = r * x - d) << endl;
}

