#include<bits/stdc++.h>

using namespace std;

int main()
{
	int n, l, total = 0;
	cin >> n >> l;
	total = l * n + n * (n - 1)/2;
	if (l > 0)
		cout << total - l;
	else if (l + n - 1 < 0)
		cout << total - (l + n - 1);
	else
		cout << total;
}

