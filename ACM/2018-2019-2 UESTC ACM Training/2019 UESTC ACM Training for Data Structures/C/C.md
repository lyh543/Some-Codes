# C题

想抄潇神的PPT（逃

题目要求的是求有多少个不联通的线段。本来是想用线段树做的，但是不知道咋做  
其实是当时还不会线段树（逃

潇神用了一个东西就很强，就是重定义了<符号，并且利用了set的特性。  
两线段a, b不相交一定会有a.r < b.l or a.l < b.r。如果把<定义为a.r < b.l，那么相交就化为 !(a<b) && !(b<a)，这就是set中的等于。  
所以就可以拿set来做，找和a相交线段用find(a)就好。注意一条边可能和两条边相交，所以加入每一条边的时候要跑两次。

代码部分：  

先是线段的定义、<的重载。

```c++
struct edge {
    int l;
    int r;
};

bool operator <(edge a, edge b)
{
    return a.r < b.l;
}
set<edge> s;
```

然后是main()函数。因为合并的/插入线段操作写在一个单的函数，所以main()函数不是很长。

```c++
int main()
{
    cin.sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        edge temp;
        cin >> temp.l >> temp.r;

        merge(temp);

        cout << (i?" ":"") << s.size();
        //用(i?" ":"")在每两数之间加一个空格
    }
}
```

最后是merge()函数。  
这个函数可以用递归写，因为最多只会合并两次，只会往下递归两层。也可以写非递归写，用while()写，或者在main()函数里调用多次。  

```c++

int merge(edge & temp)
{
    if ((iter = s.find(temp)) != s.end())
    //如果存在和temp相等的线段
    {
        temp.l = min(temp.l, iter->l);
        temp.r = max(temp.r, iter->r);
        //造新线段，再删除原线段，再插入新线段，不然删了就找不到了
        s.erase(iter);//先删再插，有一次WA在这里，因为set的相异性和刚才定义的==，新线段是插不进去的
        merge(temp);//把这条线段插入的过程交到下一层递归了
        return 1;
    }
    else
    {
        s.insert(temp);
        return 0;
    }
}
```

这题代码还是挺简短的。主要是set比较好用。