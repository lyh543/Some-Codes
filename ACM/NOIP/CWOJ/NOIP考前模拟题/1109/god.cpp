//一楼献给hwj大佬 
#include<iostream>
#include<algorithm>

using namespace std;

const int size = 300010;
int circleN, ans = 1;

struct circleStruct{
	int x;
	int r;
	int left;
	int right;
}circle[size];

bool operator < (const circleStruct a, const circleStruct b)
{
	if (a.left != b.left) return a.left < b.left;
	return a.r > b.r;
}

int i = 0;
int area(int c) //计算圆c及其子圆的空间 
{
	
	int space = 1, continuum = circle[c].left;
	
	i++;
	if (circle[i].left >= circle[c].right) return space;
	 while ( i < circleN && circle[i].right <= circle[c].right)
	 {
	 	if (continuum == circle[i].left) //如果圆c内部被完全分开，那么再+1 
	 		continuum = circle[i].right;
	 	space += area(i);
	 }
	 
	 if (continuum == circle[c].right) space++;
	 return space;
}


int main()
{
	//freopen("god.i","r",stdin);
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> circleN;
	for (int t = 0; t < circleN; t++)
	{
		cin >> circle[t].x >> circle[t].r;
		circle[t].left = circle[t].x - circle[t].r;
		circle[t].right = circle[t].x + circle[t].r;
	}
	
	sort(circle, circle + circleN);
	
	while (i < circleN)
	{
		ans += area(i);
	}
	
	cout << ans;
}
