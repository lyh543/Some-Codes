#include<bits/stdc++.h>
#define ld long double 
#define ll long long 
 
using namespace std;
 
 
int ans1[] = { 1,0,1,2 };
 
char ans2[] = { 'A','A','B','A' };
 
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
 
	int a;
	cin >> a;
	cout << ans1[a % 4] << " " << ans2[a % 4];
}
