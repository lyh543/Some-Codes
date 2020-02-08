//I
#include<bits/stdc++.h>
//#define _CRT_SECURE_NO_WARNINGS
#define ld long double 
#define ll long long 
#define int ll
#define eps 1e-11
#define fastio ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
typedef pair<int, int> P;

const char pstr[] = { 'A', 'H', 'I', 'M', 'O', 'T', 'U', 'V', 'W', 'X', 'Y' };

int pok[26] = { 0 };

const int maxn = 1e7 + 5;
int n;
char str[maxn];
char m[maxn << 1];
int p[maxn] = { 0 };

int manacher(char * str)
{
	memset(m, 0, sizeof(m));
	m[0] = '$', m[1] = '#';
	int len = 2;
	for (int i = 0; i < n; i++)
	{
		m[len++] = str[i];
		m[len++] = '#';
	}
	int ans = 0, id = 0, mx = 0;

	for (int i = 0; i < len; i++)
	{
		if (m[i] != '#' && pok[m[i] - 'A'] == 0)
		{
			p[i] = 0;
			continue;
		}
		p[i] = mx > i ? min(p[2 * id - i], mx - i) : 1;
		while ((m[i-p[i]] == '#' || pok[m[i - p[i]] - 'A']) && m[i - p[i]] == m[i + p[i]]) p[i]++;
		if (i + p[i] > mx)
		{
			mx = i + p[i];
			id = i;
		}
		//cout << p[i];
		ans = max(ans, p[i]);
	}
	//cout <<endl << m;
	//cout << endl;
	return ans - 1;

}


signed main()
{
	fastio;
	for (int i = 0; i < 11; i++)
		pok[pstr[i] - 'A'] = 1;
	int T;
	cin >> T;
	while (T--)
	{
		cin >> str;
		n = strlen(str);
		cout << manacher(str) << endl;
	}
}
