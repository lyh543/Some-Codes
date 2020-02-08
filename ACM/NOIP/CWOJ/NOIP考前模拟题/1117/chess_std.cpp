#include <iostream>
#include <algorithm>
#include <cstdio>
using namespace std;
char map[100][100];
char debugmap[100][100];
int y_line[10];
int k;//k为车数
int n;//n是棋盘的尺寸 
long long count_fuck=0;
void search(int x,int curk)//搜x 第k层搜索
{
 //  cout<<"calling at "<<x<<" "<<curk<<endl;
   if(x>n) return;
   if(curk==k)
    {
      for(int y=1;y<=n;y++)
       {
           if(map[x][y]!='.'&&y_line[y]!=1)
           {
              // cout<<"++"<<endl;
                     count_fuck++;
           }
       }
        return;
    }
    for(int y=1;y<=n;y++)
    {
        if(map[x][y]=='.'||y_line[y]==1) continue;
        y_line[y]=1;
        for(int tempx=x+1;tempx<=n;tempx++)
        {
            search(tempx,curk+1);
        }
        y_line[y]=0;
    }
}
int main()
{
    freopen("chess.in","r",stdin);
      freopen("chess.out","w",stdout);
    cin>>n>>k;
    for(int x=1;x<=n;x++)
    {
        for(int y=1;y<=n;y++)
        {
            cin>>map[x][y];
        }
    }
   for(int x=1;x<=n;x++)
   {
       search(x,1);
   }
    cout<<count_fuck;
}
