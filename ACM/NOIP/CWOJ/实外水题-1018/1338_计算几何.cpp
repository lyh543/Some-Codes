#include<iostream>
#include<algorithm>

using namespace std; 

const int size = 100000;
int n, m;
int x[size], y[size], crossValue[size];

int cross(int m, double xp, double yp)
{
	if (crossValue[m] != 2) return crossValue[m];
	double t =  (xp/x[m] + yp/y[m] - 1);
	if (t > 0.0001) return (crossValue[m]=1);
	else if (t < -0.0001) return (crossValue[m]=-1);
	else return (crossValue[m]=0);
}

int bs(int xp, int yp, int l, int r)
//l可以用，r不能用
{
	int middle;
	
	for (int i = l; i < r; i++)
		crossValue[i] = 2;
		
	while (l < r)
	{
		middle = (l + r) / 2;
		if (cross(middle,xp,yp) == 1)
		{
			if (cross(middle+1,xp,yp) == -1)
			return middle+1;
			l = middle+1;
			
		}
		else if (cross(middle,xp,yp) == -1)
		{
			if (cross(middle-1,xp,yp) == 1)
			return middle;
			r = middle;
		}
		else return middle+1;
	}
	return l;
	
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
#ifdef debug
	freopen("input.txt","r",stdin);
#endif
	
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> x[i];
	for (int i = 0; i < n; i++)
		cin >> y[i];
		
	sort(&x[0],&x[n]);
	sort(&y[0],&y[n]);
	
	cin >> m;
	for (int i = 0; i < m; i++)
	{
		int xp, yp;
		cin >> xp >> yp;
		cout << bs(xp,yp,0,n) << endl;
	}
}
