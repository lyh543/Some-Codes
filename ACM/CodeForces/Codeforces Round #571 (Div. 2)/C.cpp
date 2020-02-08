#include<bits/stdc++.h>
#define ll long long
using namespace std;
 
const int maxn = 1e6 + 5;
 
char a[maxn], b[maxn];
 
int main()
{
	cin >> a >> b;
	int la, lb, va = 0, vb = 0, ans = 0;
	la = strlen(a), lb = strlen(b);
	for (int i = 0; i < lb; i++)
	{
		va ^= a[i] - '0';
		vb ^= b[i] - '0';
	}
	ans += (va == vb);
	for (int i = lb; i < la; i++)
	{
		va = va ^ (a[i] - '0') ^ (a[i - lb] - '0');
		if (va == vb)
			ans++;
	}
	cout << ans;
}
