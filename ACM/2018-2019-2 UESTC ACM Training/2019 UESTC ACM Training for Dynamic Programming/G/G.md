# G题

这个题乍一看挺唬人的，别的题都是数据范围不超过 1e9，这个题，整一个数字长度不超过 1e9。

但这个题，暴力是 O(n^2)，本来想可以从中间二分做，类似于线段树的,但是合并起来太麻烦，每个数在边界才能被合并（如区间 1-8 里的，2-4 就不能和其他的简单合并）。

后来发现其实 O(n) 扫一遍就行了，用滚动数组记录以当前位结尾的数取模后结果相同的数量。从前一位到后一位的状态转移就是`前面的余数`*10+`后面的这一位`再取模得到新的余数，而 ans 就是扫的过程中余数为 0 的数量的和。