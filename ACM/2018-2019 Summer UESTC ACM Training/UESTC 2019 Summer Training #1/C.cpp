#include <bits/stdc++.h>
#define ll long long 
#define ld long double
using namespace std;


const int maxn = 2e5 + 5;
char p[maxn], s[maxn];
int ans[maxn] = { 0 }, fail[maxn] = { -1 }, anslen = 0, pl, sl ,ppl;
/*
fail[i]：前i位的最长border（不包含自己）
字符串从1计数!!!!
aabcaabaabcaa
0100123123456
*/
void kmp()
{
	//KmpGetFail
	for (int i = 1; i <= pl; i++)
	{
		int j = i - 1;
		while (j > 0 && p[fail[j] + 1] != p[i]) j = fail[j];
		fail[i] = j > 0 ? fail[j] + 1 : 0;
	}

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
				j = fail[j-1] + 1;
			}
			i++;
		}
		else
		{
			ans[j - 1]++;
			j = fail[j - 1] + 1;
		}
	}
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	s[0] = '#', p[0] = '$';
	cin.getline(s + 1, maxn);
	cin.getline(p + 1,maxn);
	ppl = pl = strlen(p + 1), sl = strlen(s + 1);
	for (int i = 0; i < pl; i++)
	{
		s[++sl] = '#';
	}
	while(pl < sl)
	{
		p[++pl] = '$';
	}
	//cout << "p" << p << endl;
	kmp();
	//for (int i = 1; i <= pl; i++)
		//cout << ans[i] << " ";
	int t;
	cin >> t;
	while (pl > 0 && t-ans[pl] > 0)
	{
		t -= ans[pl];
		pl--;
	}
	if (pl == 0)
		cout << "IMPOSSIBLE";
	else
	{
		int i = pl;
		for (int i = 1; i <= pl; i++)
			cout << p[i];
	}

}
