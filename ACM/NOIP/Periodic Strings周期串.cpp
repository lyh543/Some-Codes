//紫书P57
#include<iostream>
#include<cstring>

using namespace std;

char s[80];

int main()
{
	cin >> s;
	
	for (int i = 1; i < strlen(s); i++)
	{
		if (s[0] == s[i]) //周期可能为i,即s[x]与s[x+i]相同 
		{
			bool p = true;
			for (int j = 1; j < strlen(s) - i; j++)
			{
				if (s[j] != s[j + i])
				{
					p = false;
					break;
				}
			}
			if (p)
			{
				cout << i;
				return 0;
			}
		}
	}
	cout <<  strlen(s);
	return 0;
} 
