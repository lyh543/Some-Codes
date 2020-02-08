#include<bits/stdc++.h>
#define ld long double 
#define ll long long 
//#define int ll
#define eps 1e-11
#define fastio ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
typedef pair<int, int> P;

const ll maxn = 2e5+5, mod = 1e9 + 7;

ll arr[maxn], presum[maxn] = {0};


int main()
{
	fastio;
	cout << fixed << setprecision(10);
	ld x1, y1, r1, x2, y2, r2;
	cin >> x1 >> y1 >> r1 >> x2 >> y2 >> r2;
	ld d = sqrt((x1 - x2)*(x1 - x2) + (y1 - y2)*(y1 - y2));
	ld r = (r1 + r2 - d) / 2;
	ld x = x1 + (r1 - r)*(x2 - x1) / d;
	ld y = y1 + (r1 - r)*(y2 - y1) / d;
	cout << x << " "<< y << " "<< r;
}
