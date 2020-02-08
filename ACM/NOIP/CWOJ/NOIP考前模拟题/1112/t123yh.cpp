#include <iostream>
#include <string>
#include <vector>
#include <list>
#include <cstdio>

using namespace std;

struct {
    long long up, down, sum;
} arr[51];

const long long inf = 0x2FFFFFFFFFFFFFFF;

int main()
{
    int n, m;
    scanf("%d%d", &n, &m);
    long long ans = 0;
    for (int i = 0; i < n; i++)
    {
        int len;
        scanf("%d", &len);
        long long up = 0, down = 0, tmpup = 0,
             cursum = 0, curans = 0;
        for (int j = 0; j < len; j++)
        {
            int x;
            scanf("%d", &x);
            cursum += x;
            
            if (cursum < down)
            {
                down = cursum;
                tmpup = -inf;
            }
            tmpup = max(cursum, tmpup);
            curans = max(tmpup - down, curans);
            ans = max(ans, curans);
            up = max(cursum, up);
        }
        arr[i].up = up;
        arr[i].down = down;
        arr[i].sum = cursum;
    }
    long long sum0 = 0;
    long long curdown = 0, curup = 0;
    for (int i = 0; i < m; i++)
    {
        int x;
        scanf("%d", &x);
        x--;
        curup = max(curup, sum0 + arr[x].up);
        ans = max(ans, curup - curdown);
        if (sum0 + arr[x].down < curdown)
        {
            curdown = sum0 + arr[x].down;
            curup = sum0 + arr[x].down;
        }
        sum0 += arr[x].sum;
    }
    cout << ans;
}
