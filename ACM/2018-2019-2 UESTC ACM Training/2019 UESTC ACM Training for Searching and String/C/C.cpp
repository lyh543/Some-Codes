#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e6+5;

char p[maxn], s[maxn];
int ans[maxn] = { 0 }, fail[maxn] = { -1 }, anslen = 0, pl, sl;

/*
fail[i]：前i位的最长border（不包含自己）
字符串从1计数!!!!
aabcaabaabcaa
0100123123456
*/

void KmpGetFail()
{
	for (int i = 1; i < pl; i++)
	{
		int j = i-1;
		while (j > 0 && p[fail[j]+1] != p[i]) j = fail[j];
		fail[i] = j ? fail[j] + 1 : 0;
	}
	return;
}


/*testdata:

*/
void kmp()
{
	KmpGetFail();
	for (int  i = 1, j = 1; i < sl;)
	{
		if (j == 0)
		{
			i++;
			j++;
			continue;
		}
		if (s[i] == p[j])
		{
			j++;
			if (j == pl)
			{
				ans[anslen++] = i - j + 2 ;
				j = fail[j-1] + 1;
			}
			i++;
		}
		else
		{
			j = fail[j - 1] + 1;
		}
			
	}
	return;
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	s[0] = p[0] = '$';
	cin >> s+1 >> p+1;
	pl = strlen(p), sl = strlen(s);
	kmp();
	
	for (int i = 0; ans[i] != 0; i++)
	{
		cout << ans[i] << " ";
	}
}
