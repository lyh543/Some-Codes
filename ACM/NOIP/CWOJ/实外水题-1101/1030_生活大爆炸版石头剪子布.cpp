#include<iostream>

using namespace std;

const int size = 100000;
int n, na, nb, pa=0, pb=0, pa1, pb1;
int sa[size] = {0}, sb[size] = {0};

int judge[5][5] = {
{0,-1,1,1,-1},
{1,0,-1,1,-1},
{-1,1,0,-1,1},
{-1,-1,1,0,1},
{1,1,-1,-1,0}
};


int gcd(int a, int b)
{
	return b == 0 ? a : gcd(b,a%b);
}

int lcm(int a, int b)
{
	return a/gcd(a,b)*b;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); 
	cin >>  n >> na >> nb;
	for (int i = 0; i < na; i++)
		cin >> sa[i];
	for (int i = 0; i < nb; i++)
		cin >> sb[i];
	
	/*for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < i; j++)
		{
			judge[i][j] = -judge[j][i];
		}
	}*/
	
	int lcmab = lcm(na,nb);
	int t = n % lcmab;
	int i = 0;
	while (i < lcmab)
	{
		switch(judge[sa[i%na]][sb[i%nb]])
		{
			case 1: pa++;break;
			case -1: pb++; break;
		}
		i++;
		if (i == t)
		{
			pa1 = pa; pb1 = pb;
		}
	}
	
	t = n / lcmab;
	cout << pa1 + t * pa << " " << pb1 + t * pb;
}
