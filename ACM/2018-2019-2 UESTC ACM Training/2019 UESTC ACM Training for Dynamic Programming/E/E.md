# E题

E 题乍一看是一个水题，不就是先求每段里的字符串种数之和，然后删去每两段有没有一样的字母（是我太弱了

然后发现好像有点问题：当字符串 1 和 2 有 a 和 b 相同，那我们是应该把 a 放在中间还是把 b 放在中间呢？这个还会影响后面，比如要是字符串 2 和 3 有一个 a 相邻，那应该用 b；可是如果 2 和 3 后面又有 a 和 b，那怎么办呢？

所以用到了dp（但我写的是记忆化搜索）。状态表示：

> //dp[l][j]: if line l remove j due to upper lines  
> //the longest combo the lower line l have.  
> //j==26 if line l don't remove anything`

本层状态只由下一层决定，只决定上一层

状态转移就是下一层的的什么都没被取走时的值，和两层之间的重复量取走以后（下一层的这个值被取走之后），看看下面还能取多少 +1。

注意如果一行只有 1 种字母，他就可以做到开头结尾的字母一样，就不能去掉。  
~~当时这里写炸了，因为感觉考虑 `mov==26`，导致后面判的时候不该过的 `if` 给过了~~

```c++
	//if the cur line has the mov and other alphas, move th mov
	//It's for those who has only one letter, that can be choosed both at beginning and end
	if (matrix[line] ^ (1 << mov) &&mov != 26)
		temp &= ~(1 << mov);

```