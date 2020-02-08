//暴力枚举，一楼献给学长 
#include<iostream>

using namespace std;

//int main()
//{
//	int l, r;
//	cin >> l >> r;
//	int ans = 0;
//	for (int i = 10; i < r * 10; i *= 10)
//	{
//		int t = r/i - l/i;
//		if (l % i / (i/10) < 2) t--;
//		if (r % i / (i/10) >= 2) t++;
//		ans += t;
//		cout << t << " ";
//	}
//	//cout << ans;
//}

int main() //暴力枚举 
{
	int l, r, ans = 0;
	cin >> l >> r; 
	for (int i = l; i <= r; i++)
	{
		for (int j = 1; j < i; j *= 10)
		{
			if (i % (10*j) / j == 2) ans++;
		}
	}
	cout << ans;
}
