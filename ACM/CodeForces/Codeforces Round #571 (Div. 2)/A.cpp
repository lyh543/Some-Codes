#include<bits/stdc++.h>
#define LL long long
#define mod 1000000007ll
#define M(x) (x+mod)%mod
using namespace std;
 
const LL maxn = 200000;
 
LL a[maxn] = { 0 }; //starts with 1
 
int main()
{
	int b, c, d;
	cin >> b >> c >> d;
	if (b <= min(c, d))
		cout << "Yes";
	else
		cout << "No";
	return 0;
}
