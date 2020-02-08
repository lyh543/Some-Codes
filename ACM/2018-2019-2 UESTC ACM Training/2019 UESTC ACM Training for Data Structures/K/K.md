# K题

## 思路

这个题，一开始以为是线段树。后来因为 H 题学到了前缀和的思想，就把这个题用前缀和并在了一起，即告诉你 a~b 的数之和，就是告诉你 presum[b] 和 presum[a-1] 之间有奇偶关系：a~b 之和为奇数，则 presum[b] 和 presum[a] 的奇偶性相异，反之则相同。于是就想要用并查集实现了。判断出现差错的条件是将要关联的两个数本来就是被关联的，而且他们的关联性和即将添加的不一样。

## 代码


```c++
#include<bits/stdc++.h>
#define LL long long
using namespace std;

const int maxn = 10000001;

struct ufset{
    int father;
    int change_with_father; //通过递归可以找到他和祖先的关系
}presum[maxn]; //presum[i]:1~i

int m, n;

ufset findrt(int a) //寻找祖先的函数，顺便得到他和祖先的关系，还要剪枝
{
    if (presum[a].father == a)
    {
        return { a, 0 };
    }
    else
    {
        ufset rt = findrt(presum[a].father);
        presum[a].father = rt.father;
        presum[a].change_with_father = presum[a].change_with_father xor rt.change_with_father;
        //剪枝的时候要顺便求所有父亲和共同祖先的关系
        return presum[a];
    }
}

int merge(int a, int b, int c)
{
    int ra = findrt(a).father, rb = findrt(b).father;
    //由于剪枝，a的祖先 ra 现在一定是 a 的父亲
    if (ra == rb)
    {
        return (presum[a].change_with_father xor presum[b].change_with_father xor c)xor 1;
        //返回他们的奇偶性是否和已知的 ra&a, rb&b, a&b 的奇偶性矛盾

    }
    else
    {
        presum[ra].father = rb;
        presum[ra].change_with_father = c^presum[a].change_with_father^presum[b].change_with_father;
        // ra 和 rb 的关系由 ra&a, rb&b, a&b 的关系决定
        return 1;
    }
}

int main()
{
    cin.sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;
    for (int i = 0; i <= n; i++)
    {
        presum[i].father = i;
        presum[i].change_with_father = 0;
    }
    for (int i = 0; i < m; i++)
    {
        int a, b, c;
        string s;
        cin >> a >> b >> s;
        if (a > b) swap(a, b);
        c = (s == "odd");
        if (!merge(a-1,b,c))
        {
            cout << i;
            return 0;
        }
    }
    cout << "ORZQHQH";
    return 0;
}

```