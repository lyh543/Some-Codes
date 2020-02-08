#include<bits/stdc++.h>
#include<unordered_set>
#define ld long double 
#define ll long long
#define infty 0x3fffffffll
#define fastio ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
typedef pair<int, int> P;
 
const int maxn = 1005;
 
int a[maxn] = { 0 };
 
int main()
{
	
	fastio;
	//euler(100001);
	ll n, k;
	cin >> n >> k;
	cout <<n-(ll)((-3 + sqrt(9 + 8ll * (n+k))) / 2);
}
