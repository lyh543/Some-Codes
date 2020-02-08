#include<iostream>
#include<algorithm>

using namespace std;

const int length=500;
int r,c,ans=0;
int distance1[length][length];
int height[length][length];//行数在前面   列数在后面 

int maxAround(int,int);
int getMaxNum(int,int,int,int);

int main()
{
	cin.tie(0);
	ios_base::sync_with_stdio(false);
	
	cin >> r >> c;  //行数 R   列数 C
	for (int i=0;i<r;i++)
		for (int j=0;j<c;j++)
		{
			cin >> height[i][j];
			distance1[i][j]=0;
		}
	for (int i=0;i<r;i++)
	{
		for (int j=0;j<c;j++)
		{
			//distance=maxAround(i,j);
			ans=max(ans,maxAround(i,j));
		} 
	}
	cout << ans+1;
}

int maxAround(int row,int column)
{
	if (distance1[row][column]!=0)
		return distance1[row][column];
	distance1[row][column]=max(getMaxNum(row,column,1,0),getMaxNum(row,column,-1,0));
	distance1[row][column]=max(getMaxNum(row,column,0,1),distance1[row][column]);
	distance1[row][column]=max(getMaxNum(row,column,0,-1),distance1[row][column]);
	return distance1[row][column];
}

int getMaxNum(int row,int column,int rowChange,int columnChange)
{
	int rowFinal=rowChange+row;
	int columnFinal=columnChange+column;
	if (rowFinal<r&&
		rowFinal>=0&&
		columnFinal<c&&
		columnFinal>=0&&
		height[row][column]>height[rowFinal][columnFinal])
		return maxAround(rowFinal,columnFinal)+1;
	return 0;
}
