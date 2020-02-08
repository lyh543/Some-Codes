# B题

由于这是一棵树，两点之间只有一条线路，所以题目要求就是要找到这条线路，并且得到线路上的最小权重边（在遍历的时候统计一下就行了）。如果把这个树化成一个有根树，两点的路线必经过他们的最近公共祖先（并且在这里转弯）。
寻找LCA的时候，使用倍增法，预处理之后，把一层一层向上的过程变成了向上4层、2层、1层，将O(n)的复杂度降到了O(logn).
每条边用邻接链表存。

```c++
for (int i = 1; i < n ; i++)
{
    int a, b, d;
    cin >> a >> b >> d;
    neigh[a].push_back({ b, d });
    neigh[b].push_back({ a, d });
}
```

在倍增中不想判越界，于是把所有不存在的父节点设为0（后面是若父节点不相同则往上走，所以这样没问题），并把距离设为maxlength+1

```c++
depth[1] = 1;
for (int i = 1; i <= n; i++)
    for (int j = 0; j < maxlog; j++)
        up[i][j].distance = maxans;
```

然后dfs计算深度depth，顺便算一下往上跳2^k层的路径权重最小值

```c++
int dfs(int cur, int father)
{
    int i = 1;
    while ((1<<i) < depth[cur])
    {
        up[cur][i] = {
            up[up[cur][i-1].point][i-1].point,
            min(up[cur][i-1].distance, up[up[cur][i - 1].point][i - 1].distance)
        };
        i++;
    }
    list<edgeS>::iterator iter;
    for (iter = neigh[cur].begin(); iter != neigh[cur].end(); iter++)
    {
        if (iter->point != father)
        {
            depth[iter->point] = depth[cur] + 1;
            up[iter->point][0] = { cur, iter->distance };
            dfs(iter->point, cur);
        }
    }
    return 0;
}
```

然后开始处理每个询问。  
第一步是让他们跳到同一层：算出深度差（diff），然后深的往上跳。

```c++
    for (int i = 0; i < q; i++)
    {
        int a, b, ans = maxans;
        cin >> a >> b;

        if (depth[a] > depth[b]) swap(a, b); // make sure b is deeper than a
        int diff = depth[b] - depth[a];
        int  j = 0;
        while (diff != 0)
        {
            if (diff & (1<<j))
            {
                ans = min(ans, up[b][j].distance);
                b = up[b][j].point;
                diff ^= (1 << j);
            }
            j++;
        }
```

然后检查一下他们在同一层的时候就相等了（说明原来的a和b是父子关系），相等就可以直接输出答案了，然后下一组gogogo。
```c++
        if (a == b)
        {
            cout << ans << endl;
            continue;
        }
```

如果不是的，接下来是就一起往上跳。因为看到他们相等的时候不知道这是不是他们**最近的**祖先，所以只能跳到他们跳到LCA的前一个点。  
相同就不能跳，所以可以把不能跳的高度的点的值设为0（两边的up
都是0，相等，就不能跳）

```
        for (int i = maxlog-1; i >= 0; i--)
        {
            if (up[a][i].point != up[b][i].point) // excluding overflow that are both 0
            {
                ans = min(min(ans, up[a][i].distance), up[b][i].distance);
                a = up[a][i].point;
                b = up[b][i].point;
            }
        }
```

最后记得往上再跳一下，然后输出，完事。

```c++
        ans = min(min(ans, up[a][0].distance), up[b][0].distance);

        cout << ans << "\n";
```