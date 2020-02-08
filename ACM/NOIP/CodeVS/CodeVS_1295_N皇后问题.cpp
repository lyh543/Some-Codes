#include<iostream>

using namespace std;

const int size = 14; 

int position[size] = {0};
int n;
int used1[2*size] = {false};//x+y=?是否被用过 
int used2[2*size] = {false};//x+13-y=?是否被用过 
//int used3[size] = {false}; //x=?是否被用过 
int used4[size] = {false}; //y=?是否被用过 

bool push(int x, int y)
{
	if (used1[x+y] || used2[x+n-y] || used4[y]) return false;
	used1[x+y] = used2[x+n-y] = used4[y] = true;
	position[x] = y;
	return true;
}

void pop(int x)
{
	used1[x+position[x]] = false;
	used2[x+n-position[x]] = false;
	//used3[x] = false;
	used4[position[x]] = false;
	position[x] = 0;
}

int dfs(int x)
{
	//cout << x;
	if (x == n){
		return 1;
	}
	int ans = 0;
	for (int y = 0; y < n; y++)
	{
		if (push(x,y))
			ans += dfs(x+1);
	}
	pop(x);
	return ans;
}

int main()
{
	//cin >> n;
	n = 4;
	cout << dfs(0);
}
