#include<bits/stdc++.h>
 
using namespace std;
 
int main()
{
	cin.sync_with_stdio(0);
	cin.tie(0);
 
	//r:current definite )
	//rmore: from right ) more
	int r = 0, len, rmore = 0;
	char str[300001];
	cin >> len;
	for (int i = 0; i < len; i++)
	{
		cin >> str[i];
		if (str[i] == ')')r++;
	}
	str[len] = '\0';
	if (str[len - 1] == '(' || str[0] == ')' || (len & 1) || (r << 1 > len))
	{
		cout << ":(";
		return 0;
	}
	str[0] = '(';
	if (str[len - 1] != ')')
	{
		str[len - 1] = ')';
		r++;
	}
	rmore++;
	int cur;
	for (cur = len - 2; cur > 0; cur--)
	{
		if (r << 1 > len)
		{
			cout << ":(";
			return 0;
		}
		if (str[cur] == '?')
		{
 
			if (r == len >> 1)
			{
				str[cur] = '(';
			}
			else
			{
				r++;
				str[cur] = ')';
			}
		}
		if (str[cur] == '(')
		{
			rmore--;
			if (rmore <= 0)
			{
				cout << ":(";
				return 0;
			}
		}
		else if (str[cur] == ')')
		{
			rmore++;
		}
	}
	cout << str;
	return 0;
}

