#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e7+5;

/*char str[maxn], m[maxn * 2];
int p[maxn * 2] = { 0 };

int n;

int manacher(char*str)
{
	int ans = 1;
	m[0] = '$';
	m[2 * n+1] = '\0';
	for (int i = 0; i < n; i++)
	{
		m[2 * i + 1] = str[i];
		m[2 * i + 2] = '#';
	}
	cout << m+1 << endl;
	int n2 = 2 * n , mx = 1, id = 1;
	for (int i = 1; i <= n2 ; i++)
	{
		p[i] = mx > i ? min(p[id * 2 - i], mx - i) : 1;
		while (m[ i - p[i]] == m[i + p[i]]) p[i]++;
		if (i+p[i] > mx)
		{
			mx = i + p[i];
			id = i;
		}
		cout << p[i];
		ans = max(ans, p[i]);
	}
	return ans/2;
}*/

int n;
char str[maxn], m[maxn << 1];
int p[maxn] = { 0 };

int manacher(char * str)
{
	int len = 2;
	//m[len] = '\0';
	m[0] = '$', m[1] = '#';
	for (int i = 0; i < n; i++)
	{
		m[len++] = str[i];
		m[len++] = '#';
	}
	int ans = 1, id = 0, mx = 0;

	for (int i = 0; i < len; i++)
	{
		p[i] = mx > i ? min(p[2 * id - i], mx - i) : 1;
		while (m[i - p[i]] == m[i + p[i]]) p[i]++;
		if (i + p[i] > mx)
		{
			mx = i + p[i];
			id = i;
		}
		//cout << p[i];
		if (p[i]&1)
			ans = max(ans, p[i]);
	}
	//cout <<endl << m;
	//cout << endl;
	return ans - 1;
}


int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n;
	cin >> str;
	cout << manacher(str);
}