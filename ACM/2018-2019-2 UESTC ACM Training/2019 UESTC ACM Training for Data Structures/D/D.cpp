#include<bits/stdc++.h>
using namespace std;

int n, k;
char temp;
const int maxn = 100005;
char ans[maxn];
int leng = 0;

int main()
{
	cin.sync_with_stdio(0);
	cin.tie(0);

	while (cin >> n >> k)
	//多组数据局
	{
		if (k == 0)
		{
			for (int i = 0; i < n; i++)
				cin >> temp;
				//即使 k==0 时可以无脑输出空行，但还是得把这 n 个数据吃掉。WA在这里了qwq
			cout << endl;
			continue;
		}

		leng = 0;
		for (int i = 0; i < n; i++)
		{
			cin >> temp;
			while (leng > 0 && ans[leng - 1] < temp && k - leng + 1 <= n - i)
			//栈里还有数，并且比 temp 小，后面还有足够的数，就可以把栈顶的数拿出来
				leng--;
			ans[leng++] = temp;//入栈
		}

		for (int i = 0; i < leng; i++)
			cout << ans[i];
		cout << "\n";
	}
	return 0;
}
