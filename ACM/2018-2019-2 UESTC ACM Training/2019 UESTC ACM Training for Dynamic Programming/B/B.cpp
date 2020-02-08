#define debug
#include<bits/stdc++.h>

using namespace std;
const int maxn = 600;

struct mine {
	int up;
	int left;
}m[maxn][maxn] = {0};

mine & operator +=(mine & t, mine & a)
{
	t.up = t.up + a.up;
	t.left = t.left + a.left;
	return t;
}

int main()
{
	cin.sync_with_stdio(0);
	cin.tie(0);

	int C, R;
	cin >> R >> C;
	for (int i = 1; i <= R; i++)
		for (int j = 1; j <= C; j++)
			cin >> m[i][j].left;
	for (int i = 1; i <= R; i++)
		for (int j = 1; j <= C; j++)
			cin >> m[i][j].up;

	for (int i = R; i > 0; i--)
	{
		for (int j = C; j > 0; j--)
		{
			if (m[i][j].up > m[i][j].left)
				m[i - 1][j] += m[i][j];
			else
				m[i][j - 1] += m[i][j];
		}
	}
	int ans = 0;
	for (int i = 1; i <= R; i++)
		ans += m[i][0].left;
	for (int i = 1; i <= C; i++)
		ans += m[0][i].up;
	
	cout << ans;
}