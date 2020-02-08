#include<bits/stdc++.h>
 
using namespace std;
 
int main()
{
	cin.sync_with_stdio(0);
	cin.tie(0);
 
	long long t[4];
	cin >> t[0] >> t[1] >> t[2] >> t[3];
	for (int i = 0; i < 3; i++)
	{
		if ((t[1] + t[2] + t[3]) == 2 * t[0])
		{
			cout << t[0] - t[1] << " "
				<< t[0] - t[2] << " "
				<< t[0] - t[3];
			return 0;
		}
		swap(t[0], t[i + 1]);
	}
	cout << t[0] - t[1] << " "
		<< t[0] - t[2] << " "
		<< t[0] - t[3];
}
