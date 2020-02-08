//http://codevs.cn/problem/1009/
#include<iostream>
#include<cstring>
using namespace std;

bool changeInto[10][10] = {{false}};
int posibility[10] = {0}; //i可变换的种数 
char s[50];
int k;

int main()
{
	for (int i = 0; i < 10; i++)
		changeInto[i][i] = true;
		
	cin >> s >> k;
	
	for (int i = 0; i < k; i++)
	{
		int a, b;
		cin >> a >> b;
		
		for (int j = 0; j < 10; j++)
		{
			changeInto[a][j] = changeInto[a][j] || changeInto[b][j];//已知a->b，那么如果b->j，必有a->j
			changeInto[j][b] = changeInto[j][a] || changeInto[j][b];//已知a->b，那么如果j->a，必有j->b 
		}
	}
	
	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j < 10; j++)
			if (changeInto[i][j])
				posibility[i]++;
	}
	
	int l = strlen(s);
	long long ans = 1;
	for (int i = 0; i < l; i++)
	{
		ans *= posibility[ s[i] - '0' ];
	}
	
	cout << ans;

}
