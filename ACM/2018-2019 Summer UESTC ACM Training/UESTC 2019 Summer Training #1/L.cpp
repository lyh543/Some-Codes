#include <bits/stdc++.h>
#define ll long long 
#define ld long double
using namespace std;

char code[26][10] = {
	".-",
	"-...",
	"-.-.",
	"-..",
	".",
	"..-.",
	"--.",
	"....",
	"..",
	".---",
	"-.-",
	".-..",
	"--",
	"-.",
	"---",
	".--.",
	"--.-",
	".-.",
	"...",
	"-",
	"..-",
	"...-",
	".--",
	"-..-",
	"-.--",
	"--..",
};

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	char s[10], i = 0;
	while ((s[i] = getchar()) != EOF)
	{
		if (s[i] == '/' || s[i] == '\n')
		{
			if (i == 0)
			{
				cout << " ";
				continue;
			}
			char t = s[i];
			s[i] = '\0';
			i = 0;
			for (int i = 0; i < 26; i++)
			{
				if (strcmp(s, code[i]) == 0)
				{
					cout << char(i + 'A');
					if (t == '\n') cout << t;
					break;
				}
			}
		}
		else
			i++;
	}
	
	if (i == 0)
	{
		cout << " ";
	}
	else
	{
		s[i] = '\0';
		i = 0;
		for (int i = 0; i < 26; i++)
		{
			if (strcmp(s, code[i]) == 0)
			{
				cout << char(i + 'A');
				break;
			}
		}
	}
}
