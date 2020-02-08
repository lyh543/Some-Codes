# I题

## 思路

这个题，以两个数据为排序还是比较好实现的——定义一个结构体就行了。  

那么，如何把所有队伍存起来呢？我们需要的操作有：

1. 增加一个数
1. 查询一个数
1. 删去一个数

果使用简单的数组，增删操作会很困难；如果使用方便增删的链表，搜索又变成了 O(n) 复杂度的低效操作。  
其实还想使用优先队列，但是优先队列不能删、也不能查询任意一个数。  
然后学到了 multiset。它的底层实现是红黑树。要是手写的话，这个题的难度会上升几个级别，还好 C++ 自带。

于是，我们维护一个只装强于1队的队伍信息的 multiset，其他队 A 题了，我们看他原来是不是比1强，如果在就删掉，然后把新的成绩 insert 进 multiset；如果1队 A 题了，就按降序顺序 pop 出所有比1队弱的队伍。最后统计一下 multiset 的大小就好啦。

## 代码

一堆定义：

```c++
struct teamS {
    int s; //solved
    int p; //penalty
    teamS() {};
    teamS(int _s, int _p):s(_s), p(_p){}
};
bool operator > (teamS a, teamS b)
{
    return a.s > b.s ||
        (a.s == b.s && a.p < b.p);
}
bool operator < (teamS a, teamS b)
{
    return a.s < b.s ||
        (a.s == b.s && a.p > b.p);
}
bool operator <= (teamS a, teamS b)
{
    return a.s < b.s ||
        (a.s == b.s && a.p >= b.p);
}
//it seems that some comparing operators are not necessary...
multiset<teamS> dalao; //include team stronger than team 1
teamS a[maxn]; //include every team's info
```

```c++
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int m, n, team, p1;
    teamS tmp;
    multiset<teamS>::iterator iter, iter2;
    cin >> n >> m;
    for (int i = 0; i < m; i++)
    {
        cin >> team >> p1;
        tmp = a[team];
        a[team].s++;
        a[team].p += p1;

        if (team == 1)
        {
            iter = dalao.begin();
            //delete all teams lower than team1
            while (iter != dalao.end() && (*iter) <= a[1])
            {
                iter2 = iter;
                iter++;
                //remember to ++ before erase
                dalao.erase(iter2);
            }
        }
        else
        {
            if (a[team] > a[1])
            {
                if (tmp > a[1]) //if it was lower than team1
                {
                    dalao.erase(dalao.find(tmp));
                }
                dalao.insert(a[team]);
            }
        }
        cout << dalao.size() + 1 << endl;
    }
}
```