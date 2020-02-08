#include<bits/stdc++.h>
#define ld long double 
#define ll long long
#define fastio ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
 
const int maxn = 5e4 + 4;
 
char curRow[maxn], maxRow[maxn];
int maxRowN, R, C, columnN[maxn];
 
int main()
{
	fastio;
	int t;
	cin >> t;
	for (int i = 0; i < t; i++)
	{
		//memset(xOnMaxRow, 0, sizeof(xOnMaxRow));
		memset(columnN, 0, sizeof(columnN));
		memset(maxRow, 0, sizeof(maxRow));
		maxRowN = -1;
		cin >> R >> C;
		for (int i = 0; i < R; i++)
		{
			cin >> curRow;
			int temp = 0;
			for (int j = 0; j < C; j++)
			{
				if (curRow[j] == '*')
				{
					temp++;
					columnN[j]++;
				}
			}
			if (temp == maxRowN)
			{
				for (int i = 0; i < C; i++)
				{
					if (curRow[i] == '.')
					{
						maxRow[i] = '.';
					}
				}
			}
			else if (temp > maxRowN)
			{
				maxRowN = temp;
				strcpy(maxRow, curRow);
			}
		}
		int ans = 0;
		for (int i = 0; i < C; i++)
		{
			ans = max(ans, columnN[i] + (maxRow[i] != '*'));//+-1???
		}
		cout << R + C - maxRowN - ans << endl;
		
	}
}
