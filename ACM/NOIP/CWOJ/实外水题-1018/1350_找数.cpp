#include<iostream>

using namespace std;

long long a,b,c,n,ans;

long long gcd(long long a, long long b)
{
	//return (b==0) ? a : gcd(b,a%b);
	if (b == 0)
		return a;
	else
		return gcd(b,a%b);
}
 
long long lcm(long long a, long long b)
{
	return a/gcd(a,b)*b;
}


int main()
{
	cin >> n >> a >> b >> c;
	//cout << n/a <<' '<< n/b <<' '<< n/c <<' '<< n/lcm(a,b) <<' '<< n/lcm(b,c) <<' '<< n/lcm(a,c) <<' '<< n/lcm(lcm(a,b),c) << endl;
	cout << n - (n/a + n/b + n/c - n/lcm(a,b) - n/lcm(b,c) - n/lcm(a,c) + n/lcm(lcm(a,b),c));

}
