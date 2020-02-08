#include<bits/stdc++.h>
#define ld long double 
#define ll long long 
//#define int ll
#define eps 1e-11
#define fastio ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
typedef pair<ll, int> P;
 
const int maxn = 1000;
 
int main()
{
	fastio;
	int T;
	cin >> T;
	while (T--)
	{
		ll a[3];
		cin >> a[0] >> a[1] >> a[2];
		cout << (a[0] + a[1] + a[2]) / 2 <<endl;
	}
	
}
