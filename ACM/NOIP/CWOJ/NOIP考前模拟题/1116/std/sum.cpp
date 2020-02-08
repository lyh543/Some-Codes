#include <iostream>
#include <stdio.h>
#include <string.h>
using namespace std;

typedef long long LL;
const int M=1e6+5;
int nu[M];

int main()
{
	freopen("sum.in","r",stdin);
	freopen("sum.out","w",stdout);
    int n;
    while(scanf("%d",&n)!=EOF)
    {
        for(int i=1;i<=n;i++)
            scanf("%d",&nu[i]);
        int ans=0;
        LL sum=0;
        for(int i=n;i>=1;i--)
        {
            sum+=nu[i];
            if(sum>=0)
            {
                ans++;
                sum=0;
            }
            else
                continue;
        }
        if (sum!=0) printf("fuck\n");
        printf("%d\n",ans);
    }
    return 0;
}
