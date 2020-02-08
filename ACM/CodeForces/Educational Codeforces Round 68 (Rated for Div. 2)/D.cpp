#include<bits/stdc++.h>
#define ld long double 
#define ll long long
#define fastio ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
 
const int maxn = 105;
 
char s[maxn], t[maxn], p[maxn];
 
int main()
{
	fastio;
	int T;
	cin >> T;
	for (int i = 0; i < T; i++)
	{
		int n, k, winner; //winner == 0:ÏÈÊÖ±Ø°Ü
		cin >> n >> k;
		if (n == 0)
			winner = 0;
		else if (n <= 2)
			winner = 1;
		else if (k == 3)
			winner = (n % 4 != 0);
		else if (k % 3 != 0)
			winner = (n % 3 != 0);
		else
		{
			int t = n % (k + 1);
			if (t != k && t % 3 == 0)
				winner = 0;
			else
				winner = 1;
		}
			cout << (winner ? "Alice" : "Bob") << endl;
	}
}
