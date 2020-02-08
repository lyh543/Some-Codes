# O题

## 思路

数字有个很好的性质，高位的优先级始终比低位的高。在这个题来说，异或的时候，高位能产生 1，一定优于高位不产生 1 的数。因此，我们应该从高位开始，逐位寻找是否有能使该位变为 1 的数。也就是贪心吧。从第一位逐位到最后一位，这就是字典树的思路。  
于是就拿字典树写吧。  
注意一下，求最大值是和输入的数的高位尽量不一样；求最小值是和输入的数的高位尽量相同就行了。  
剩下的就是建字典树。

## 代码

```c++
#include<bits/stdc++.h>
#define LL long long
using namespace std;

const long long maxlength = 32;//30就WA，32就AC。有点迷
const long long maxTrieNode = 600000*maxlength; //最多给每个加入的数加入 maxlength 个结点

struct trieStruct {
    int nextNode[2] = { 0 };
    int cnt = 0;
    //不用 tag 标记了，因为长度是一定的（30位），只需要统数量，方便判断有没有这边还有没有数
}trie[maxTrieNode]; //没有用指针实现
int UsedTrieNode = 1;

int n;

int getMaxAns(int person)
{
    int curNode = 0, maxp = 0;
    for (int j = maxlength - 1; j > 0; j--) //get the (i+1)th bit
    {
        int next = 1 xor ((person >> (j - 1)) & 1);
        if (trie[curNode].nextNode[next] == 0 || trie[trie[curNode].nextNode[next]].cnt == 0)
        //node[next]==0 和 next node.cnt==0 都是判定没有子节点的条件
        //前者是因为字典树的根是 0！
        {
            next = 1 xor next;
        }
        maxp = (maxp << 1) + next;
        curNode = trie[curNode].nextNode[next];
    }
    return maxp;
}

int getMinAns(int person)
{
    int curNode = 0, minp = 0;
    for (int j = maxlength - 1; j > 0; j--) //get the (i+1)th bit
    {
        int next = ((person >> (j - 1)) & 1);
        if (trie[curNode].nextNode[next] == 0 || trie[trie[curNode].nextNode[next]].cnt == 0)
        {
            next = 1 xor next;
        }
        minp = (minp << 1) + next;
        curNode = trie[curNode].nextNode[next];
    }
    return minp;
}

int dfs(int curNode, int curNum, int length)
//供调试用，输出所有存了的数
{
    if (length == 0)
    {
        for (int i = 0; i <trie[curNode].cnt; i++)
            cout << curNum << " ";
        return 0;
    }
    if (trie[curNode].nextNode[0])
        dfs(trie[curNode].nextNode[0], curNum << 1, length - 1);
    if (trie[curNode].nextNode[1])
        dfs(trie[curNode].nextNode[1], (curNum << 1)+1, length - 1);
    return 0;
}

int main()
{
    cin.sync_with_stdio(false);
    cin.tie(0);
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int c, person;
        cin >> c;
        //OJ只有 1, 2, 3 的输入，4,5是供调试
        //4：输出字典树里的所有数
        //5：输出使答案 max 和 min 的原始值
        if (c == 1)
        {
            cin >> person;
            int curNode = 0;
            for (int j = maxlength-1; j > 0; j--) //get the (i+1)th bit
            {
                trie[curNode].cnt++;
                int next = (person >> (j - 1)) & 1;
                if (trie[curNode].nextNode[next] == 0)
                {
                    //分配内存，因为内存是按询问全为增加数的情况给够了的
                    //可以浪费一点，删了就不要了，直接从美没有分配的 node 里分配
                    trie[curNode].nextNode[next] = UsedTrieNode;
                    UsedTrieNode++;
                }
                curNode = trie[curNode].nextNode[next];
            }
            trie[curNode].cnt++;
        }
        else if (c == 2)
        {
            cin >> person;
            int curNode = 0, lastNode = 0;
            for (int j = maxlength-1; j > 0; j--) //get the (j+1)th bit
            {
                trie[curNode].cnt--;
                int next = (person >> (j - 1)) & 1;//一步一步在每个子节点 cnt - 1
                lastNode = curNode;
                curNode = trie[curNode].nextNode[next];
            }
            trie[curNode].cnt--;
        }
        else if (c == 3)
        {
            cin >> person;
            cout << (getMinAns(person) xor person) << " " << (getMaxAns(person) xor person) << "\n";
        }
        else if (c == 4)
        {
            cout << "d ";
            dfs(0, 0, maxlength - 1);
            cout << endl;
        }
        else if (c == 5)
        {
            cin >> person;
            cout << "p " << getMinAns(person) <<" "<< getMaxAns(person) << "\n";
            cout << "a " << (getMinAns(person) xor person) << " " << (getMaxAns(person) xor person) << "\n";

        }
    }
    return 0;
}
```
