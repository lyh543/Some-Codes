#include <bits/stdc++.h>
#define ll long long
using namespace std;
 
int main()
{
	ll a, b, c;
	cin >> a >> b >> c;
	cout <<  (c + min(a, b)) * 2 + 1-(a==b);
}
