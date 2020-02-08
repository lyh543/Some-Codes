# H题

乍一眼看上去是 DP。啊不好意思走错专题了。

这个题暴力是 O(n^2*m)。

这个题，需要离线求连续子串长度。而前缀和就能把求和的过程从 O(n) 变为 O(1)。  
问题转化为求每个求每个前缀和减去它前面 m 个前缀和的最小值，然后求这些差的最大值。  
而使用单调队列的技巧，能把求 m 的最小值从 O(m) 变为 O(1)，因为单调递增序列的队列首一定是原数组的最小值，类似于滑动窗口。这个题就变成了O (n)。

下面是实现。

先是一堆初始化。presum[i] 指的是第 1~i 个数的和。注意 presum[0] = 0，因为求 1~3 的和的时候需要 presum[3] - presum[0]。

```c++
#include<bits/stdc++.h>
#define LL long long
using namespace std;

const long long maxn = 100005;

long long n, ans = LLONG_MIN, maxlength;
long long value[maxn], presum[maxn] = { 0 };//presum[i]=sum(1,...,i)
long long head = 1, endp = 1;

deque<long long> q; // to get min of presum, the deque is ascend
```

核心部分：单调队列和求最值

```c++
    for (endp = 1; endp <= n; endp++)
    //when finding max(presum[n] - presum[i])
    //i are m numbers before n (exclusive)
    // i is n-m ~ n-1
    {
        //pop the id of numbers that is bigger than the current number
        //because the current number will remain till the bigger numbers are popped
        // in other words, whenever the current number is pushed, the bigger numbers have no affect on the mininum
        while (!q.empty() && presum[q.back()] >= presum[endp - 1])
        {
            q.pop_back();
        }

        //push the id (n-1)
        q.push_back(endp - 1);

        //when the real queue (not the deque) is longer than m
        //we should pop the first number 
        if (endp - head > maxlength)
        {
            //check if the number going to be popped is in the deque
            if (q.front() == 0)
            {
                q.pop_front();
            }
            if (q.front() == head)
                q.pop_front();
            head++;
        }

        ans = max(ans, presum[endp] - presum[q.front()]);
    }
```
