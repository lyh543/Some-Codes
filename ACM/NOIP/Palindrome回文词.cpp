//×ÏÊéP48 
#include<iostream>
#include<cctype>
#include<cstring>

using namespace std;

char reverseNumber[] = "1SE Z  8 ";
char reverseAlphabet[] = "A   3  HIL JM O   2TUVWXY5";
char s[100];
bool mirror = true, palindrome = true;

int reserve(char);

int main()
{
	cin >> s;
	int half = strlen(s) / 2;
	for (int i = 0; i < half; i++)
	{
		if (s[i] != reserve(s[strlen(s) - i - 1]))
			mirror = false;
		if (s[i] != s[strlen(s) - i - 1])
			palindrome = false;
	}
	
	cout << s;
	if (mirror)
	{
		if (palindrome)
			cout << " -- is a mirrored palindrome.";
		else
			cout << " -- is a mirrored string.";
	}
	else
	{
		if (palindrome)
			cout << " -- is a regular palindrome.";
		else
			cout << " -- is not a palindrome.";
	}
}

int reserve(char ch)
{
	if (ch >= 'A' && ch <= 'Z')
		return reverseAlphabet[ch - 'A'];
	else
		return reverseNumber[ch - '0'];
}
