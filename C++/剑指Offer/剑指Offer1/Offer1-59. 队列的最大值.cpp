/* > 题目难度: 中等

> [原题链接](https://leetcode-cn.com/problems/dui-lie-de-zui-da-zhi-lcof/)

题目描述

请定义一个队列并实现函数 max_value 得到队列里的最大值，要求函数 max_value、push_back 和 pop_front 的均摊时间复杂度都是 O(1)。

若队列为空，pop_front 和 max_value  需要返回 -1

- 1 <= push_back,pop_front,max_value 的总操作数 <= 10000
- 1 <= value <= 10^5

题目样例

示例

- 输入:
- ["MaxQueue","push_back","push_back","max_value","pop_front","max_value"]
- [[],[1],[2],[],[],[]]
- 输出: [null,null,null,2,1,2]

- 输入:
- ["MaxQueue","pop_front","max_value"]
- [[],[],[]]
- 输出: [null,-1,-1]

题目思考

1. 要做到均摊时间复杂度为 O(1), 需要哪些数据结构?

解决方案

思路

- 一个比较容易想到的思路是使用一个双端队列模拟, 然后每次利用 max 函数求最大值, 但这样求最大值的时间复杂度为 O(N), 不满足题目要求
- 如果我们能够动态维护当前队列的最大值, 那么求最大值的时候只需要用 O(1)时间返回这个值即可
- 但只使用一个变量来保存最大值并不够用, 因为当它被 pop 的时候必须重新计算新的最大值, 时间复杂度仍为 O(N)
- 所以需要把当前队列的第二大值, 第三大值...也都给保存下来
- 上面的分析是不是和昨天的题目[剑指 Offer 59 - I. 滑动窗口的最大值 - leetcode 剑指 offer 系列](https://mp.weixin.qq.com/s?__biz=MzA5MDk1MjI5MA==&mid=2247484103&idx=1&sn=32e232b428b34d9d6eb7eb10011281a9&chksm=900285caa7750cdc1c95fe09f03dc3d127eafe435e793e8203a97ff155eb91d6d26296097989&token=948739292&lang=zh_CN#rd)很类似?
- 没错, 我们仍然需要把这些值保存在一个单调双端队列中, 一边是最小值, 一边是最大值, 大家可以结合昨天的文章一起阅读
- 这里采用单调队列左侧最小右侧最大的方案, 各个操作具体细节如下:

  - **max_value**: 直接返回单调队列右侧最大值即可, 不存在则返回-1
  - **push_back**: 将新元素加到正常队列左侧, 且从单调队列左侧不断弹出比新元素更小的值, 最后将新元素插入单调队列左侧作为新的最小值, 因为更小的值绝不可能是最大值候选项了(更小且更旧)
  - **pop_front**: 弹出并返回正常队列右侧元素, 不存在则返回-1; 且如果单调队列最大值恰好等于弹出的元素时, 也需要将其从单调队列中弹出

- 下面代码对必要的步骤有详细的解释, 特别是对 push_back 和 pop_front 的一些关键点的解释, 方便大家理解

复杂度

- 时间复杂度 O(1): 显然 max_value 和 pop_front 操作的复杂度都是 O(1). 而对于 push_back 操作, 虽然它使用了 while 循环, 可能弹出多个元素, 但是每个元素只会进入和弹出单调队列各一次, 所以整个操作序列下来的均摊时间复杂度为 O(1)
- 空间复杂度 O(N): 队列需要存所有值

--- */
#include <iostream>
#include <deque>
#include <queue>
using namespace std;

class MaxQueue
{
    queue<int> q;
    deque<int> dq; // monotonic decreasing deque
public:
    MaxQueue() {}

    int max_value() { return dq.empty() ? -1 : dq.front(); }

    void push_back(int value)
    {
        q.push(value);
        while (!dq.empty() && dq.back() < value)
            dq.pop_back();
        dq.push_back(value);
    }

    int pop_front()
    {
        if (q.empty())
            return -1;
        int val = q.front();
        q.pop();
        if (val == dq.front())
            dq.pop_front();
        return val;
    }
};

int main()
{
    MaxQueue mq;
    mq.push_back(1);
    mq.push_back(2);
    cout << mq.max_value() << endl; // 2
    cout << mq.pop_front() << endl; // 1
    cout << mq.max_value() << endl; // 2
    return 0;
}
