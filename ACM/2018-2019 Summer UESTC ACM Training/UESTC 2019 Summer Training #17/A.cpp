#include<iostream>
#include<iomanip>
#include<string>
#include<map>
#include<algorithm>
#define ld long double 
#define ll long long
#define lll __int128 
//#define int ll
#define eps 1e-11
#define fastio ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
typedef pair<int, int> P;

const int maxn = 1e3 + 5;

string ans[maxn][maxn];

map<char, int> m;

signed main()
{
	for (int i = 0; i <= 9; i++)
		m[i+'0'] = i;
	for (int i = 0; i < 26; i++)
		m[i + 'A'] = i + 10;
	fastio;
	char c;
	int maxc = 0, sumc = 0;
	while ((c = getchar()) != EOF)
	{
		maxc = max(maxc, m[c]);
		sumc += m[c];
	}
	for (int i = max(2,maxc + 1); i <= 36; i++)
	{
		if (sumc % (i - 1) == 0)
		{
			cout << i;
			return 0;
		}
	}
	cout << "No solution.";
}
