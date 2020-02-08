#include<bits/stdc++.h>
#define ld long double 
#define ll long long 
//#define int ll
#define eps 1e-11
#define fastio ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
typedef pair<int, int> P;

const ll maxn = 1e7+5, mod = 1e9 + 7;

ll arr[maxn] = { 0 };

ll sta[4] = { 0 };
string a[2];

int main()
{
	fastio;
	cin >> a[0] >> a[1];
	int len = a[0].length();
	for (int i = 0; i < len; i++)
	{
		int temp = 0;
		if (a[0][i] == '#')
			temp += 1;
		if (a[1][i] == '#')
			temp += 2;
		sta[temp]++;
	}
	if (sta[1] && sta[2] && !sta[3])
	{
		cout << "NO";
	}
	else
	{
		cout << "YES\n";
		for (int i = 0; i < sta[0]; i++)
			cout << ".";
		for (int i = 0; i < sta[1] + sta[3]; i++)
			cout << "#";
		for (int i = 0; i < sta[2]; i++)
			cout << ".";
		cout << endl;
		for (int i = 0; i < sta[0] + sta[1]; i++)
			cout << ".";
		for (int i = 0; i < sta[3] + sta[2]; i++)
			cout << "#";
	}
}
