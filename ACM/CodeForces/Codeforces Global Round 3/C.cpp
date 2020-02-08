#include <bits/stdc++.h>
#define ll long long
//#define DEBUG
using namespace std;
 
const int  maxn = 1500025;
 
int opers = 0;
int a[maxn], b[maxn];
int arr[maxn / 5];
int loc[maxn / 5];
int n, n2;
 
inline void so(int ta, int tb)
{
	a[opers] = ta;
	b[opers] = tb; 
	swap(loc[arr[ta]], loc[arr[tb]]);
	swap(arr[ta], arr[tb]);
	opers++;
#ifdef DEBUG
	for (int i = 1; i <= n; i++)
	{
		cout << arr[i];
	}
	cout << endl;
#endif // DEBUG
}
 
void s(int ta, int tb)
{
	if (ta > tb)
		swap(ta, tb);
 
	if (abs(ta - tb) >= n2)
		so(ta, tb);
	else if ((ta <= n2) ^ (tb <= n2))
	{
		int ta1 = (ta <= n2) ? ta + n2 : ta - n2;
		int tb1 = (tb <= n2) ? tb + n2 : tb - n2;
		so(ta, ta1);
		so(tb, tb1);
		so(ta1, tb1);
		so(ta, ta1);
		so(tb, tb1);
	}
	else 
	{
		if (ta >= n2)
		{
			so(ta, ta - n2);
			so(tb, ta - n2);
			so(ta, ta - n2);
		}
		else
		{
			so(tb, tb + n2);
			so(ta, tb + n2);
			so(tb, tb + n2);
		}
	}
#ifdef DEBUG
	for (int i = 1; i <= n; i++)
	{
		cout << arr[i];
	}
	cout << endl;
#endif // DEBUG
}
 
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
 
	cin >> n;
	n2 = n / 2;
	for (int i = 1; i <= n; i++)
	{
		cin >> arr[i];
		loc[arr[i]] = i;
	}
 
	for (int i = 1; i <= n; i++)
	{
		if (i == loc[i])
			continue;
		s(i, loc[i]);
	}
 
	cout << opers << endl;
	for (int i = 0; i < opers; i++)
	{
		cout << a[i] << " " << b[i] << "\n";
	}
}
