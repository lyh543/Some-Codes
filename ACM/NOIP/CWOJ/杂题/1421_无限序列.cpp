#include<iostream>
#include<cstring>

using namespace std;

char s[100];
long long L, R, n, nB=0, nB1;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> s >> L >> R;
	n = strlen(s);
	L--;R--;
	
	long long l = L % n;
	long long r = (R+1) % n;
	long long i = l;
	do
	{
		if (i == r) nB1 = nB;
		if (s[i] == 'B') nB++;
		i = (i+1) % n;
	}
	while(i != l);
	
	cout << (R-L+1) / n * nB + nB1;
} 
