# J题

这个题可以用贪心做，很神奇。本来想用dp做，但是感觉会爆炸。

很有趣的操作是，取了 a 以后， a.l 和 a.r 就不能取了，但是可以用 a.l+a.r 换 a，后果是多取了一个数，而且 a.l.l 和 a.r.r 就不能取了。

解决的思路是，取了 a 以后，不删 a，而是把左右两个删掉，然后把 a 的值变为 a.l+a.r-a，然后push进优先队列里。这样，下次想取新的a时，实际上是将 a.l 和 a.r 取了出来。

按照此法就可以愉快的贪心了。

至于环，使用链表的形式，维护 l[maxn] 和 r[maxn] 即可。

下面是代码：

一堆初始化：

```c++
int v[maxn], visited[maxn] = {0}, l[maxn], r[maxn];

struct cmp
{
    bool operator ()(const int & a, const int & b)
    {
        return v[a] < v[b];
    }
};

priority_queue<int,vector<int>,cmp> id;
```

输入以及对直接结束的情况的排除（m>n/2）：

```c++
    int n, m, ans = 0;
    cin >> n >> m;

    if (m * 2 > n)
    {
        cout << "Error!";
        return 0;
    }
```

初始化链表，将所有数 push 进优先队列：

```c++
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
        id.push(i);
        l[i] = i - 1;
        r[i] = i + 1;
    }
    l[0] = n - 1;
    r[n - 1] = 0;
```

核心部分及输出

```c++
    for (int i = 0; i < m; i++)
    {
        int temp;
        do
        {
            temp = id.top();
            id.pop();
        }while(visited[temp]);
        //找到最大的没有被访问过的点

        ans += v[temp];//ans增加
        visited[l[temp]] = 1;//把左右设为访问
        visited[r[temp]] = 1;
        v[temp] = v[l[temp]] + v[r[temp]] - v[temp];//改一下中间的v值
        id.push(temp);

        l[temp] = l[l[temp]];
        r[temp] = r[r[temp]];
        l[r[temp]] = r[l[temp]] = temp;
        //去掉temp左边、右边的值
    }
    cout << ans;
```