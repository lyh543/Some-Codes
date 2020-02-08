#include<bits/stdc++.h>
#include<unordered_set>
//#define _CRT_SECURE_NO_WARNINGS
#define ld long double 
#define ll long long 
#define int ll
#define eps 1e-11
#define fastio ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
typedef pair<int, int> P;
 
const int maxn = 5005, mod = 998244353;
 
bool vis[maxn] = { 0 };
int prime[maxn], cnt = 0;
void euler(int n = maxn)
{
	for (int i = 2; i < n; i++)
	{
		if (!vis[i]) prime[cnt++] = i, vis[i] = 1;
		for (int j = 0; j < cnt && i * prime[j] < n; j++)
		{
			vis[i*prime[j]] = 1;
			if (i%prime[j] == 0)
				break;
		}
	}
}
 
int degree[maxn];
 
signed main()
{
	fastio;
	euler();
	int n, p,t3,t5;
	cin >> n;
	if (n == 3)
	{
		cout << "3\n1 2\n2 3\n3 1";
		return 0;
	}
	if (n == 4)
	{
		cout << "5\n1 2\n1 3\n2 3\n2 4\n3 4";
		return 0;
	}
	else if(n ==5)
	{
		cout << "5\n1 2\n2 3\n3 4\n4 5\n5 1";
		return 0;
	}
	if (n % 2)
	{
		degree[1] = 2;
 		p = *lower_bound(prime, prime + cnt, 3 * n/2+1);
		t5 = (2 * p - 2- 3 * (n - 1)) / 2;
		t3 = n - 1 - t5;
		int t = 2;
		while (t3)
			t3--, degree[t++] = 3;
		while (t5)
			t5--, degree[t++] = 5;
	}
	else
	{
		p = *lower_bound(prime, prime + cnt, 3 * n/2+1);
		t5 = (2 * p - 3 * n) / 2;
		t3 = n - t5;
		int t = 1;
		while (t3)
			t3--, degree[t++] = 3;
		while (t5)
			t5--, degree[t++] = 5;
	}
	//cout << "3*" << t3 << "+5*" << t5 << (degree[0]?"+2":"") << "=2*" << p;
	cout << p << endl;
	int i = n, j = n-1;
 
	set<P> s;
	while (i > 0)
	{
		if (degree[i] == 0)
		{
			i--;
			continue;
		}
		if (degree[j] == 0 || i == j)
		{
			j--;
			if (j == 0)
				j = n;
			continue;
		}
		
		int ti = max(i,j), tj = min(i,j);
		if(s.find({ ti,tj })==s.end())
		{
			s.insert({ ti,tj });
			cout << i << " " << j << endl;
			degree[i]--;
			degree[j]--;
			
		}
		j--;
		if (j == 0)
		j = n;
	}
}
