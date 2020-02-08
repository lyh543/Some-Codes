#include<bits/stdc++.h>
 
using namespace std;
 
int main()
{
	char s[4][100] = {"AMBIGUOUS","YYMM","MMYY","NA"};
	int a, ans = 0;
	cin >> a;
	if (a/100>12 || a/100 ==0)
		ans += 1;
	if(a%100>12 || a%100 == 0)
		ans += 2; 
	cout << s[ans];
}

