# I题

## 原来的思路(I-Old.cpp)

显然这是一个背包题。但是很难受的是，他有一个量，相当于是用钱对一部分妹子（要求魅力值高的）产生影响。

一个暴力的想法是，我们按每一个魅力值跑一遍背包，O(n^2*m)，可以试着搞一下。（主要是我dg说他暴力过了）

然后 WA1。并不知道为啥。自闭。

## 新的思路(I-New.cpp)

在讲座上 cjj 说道跑一遍其实就可以了，先按魅力值排个序，然后就相当于从低魅力值妹子到高魅力值妹子的时候，选之前先要减一次钱，或者加一次价格。

本来还写了平移数组的，后来发现没有必要，直接就当背包容量变小了算就行，之前大背包容量算出来的结果按道理就是不能用了的，所以可以这么写。

```c++
        if (mz[i].d > curd) 
        {
            //for (int j = (mz[i].d - curd)*x; j <= curm; j++)
            //    bp[j - (mz[i].d - curd)*x] = bp[j];
                //minus money, that is to move the array left
#ifdef debug
            for (int j = curm - (mz[i].d - curd)*x + 1; j <= m && j >= 0; j++)
                bp[j] = 0;
#endif
            curm -= (mz[i].d - curd)*x;
            curd = mz[i].d;
        }
        for (int j = curm; j >= y * mz[i].weight; j--)
        {
            bp[j] = max(bp[j], bp[j - y * mz[i].weight] + mz[i].value);
            ans = max(ans, bp[j]);
            //if i < needed money, we can't get the i-th meizi
            //and we just don't need to move the array
            // and we don't even need to start the for(j) from 0
        }
```

## 细节注意

写题的时候，结构里面用过的函数名，外面尽量不要用相同的变量名，不然手贱写错了，还不报错。

```c++
struct meizi {
    int weight;
    int value;
    int d;
}mz[maxn];

int d;
//然后把 mz[i].d 写成了 d, 还调了一年
//awsl
```

## 结局

上面两个代码还是 WA1。awsl。后来看到群里有人讨论 I 题，可能是爆 int 了。但是题上说的保证**所有数**在 int 范围内。结果还是改了一下，然后过了。  
然后过了。  
然后过了。  
而且，把之前的暴力代码交了一发，  
也过了。  
也过了。

出题人出来挨打.jpg

就当长个教训吧。保证所有数 int ≈ 保证所有输入 int