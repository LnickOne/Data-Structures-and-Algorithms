/*
> 题目难度: 简单
> [原题链接](https://leetcode-cn.com/problems/bao-han-minhan-shu-de-zhan-lcof/)
题目描述
定义栈的数据结构，请在该类型中实现一个能够得到栈的最小元素的 min 函数在该栈中，调用 min、push 及 pop 的时间复杂度都是 O(1)。
各函数的调用总次数不超过 20000 次
题目样例
示例
```
MinStack minStack = new MinStack();
minStack.push(-2);
minStack.push(0);
minStack.push(-3);
minStack.min();   --> 返回 -3.
minStack.pop();
minStack.top();      --> 返回 0.
minStack.min();   --> 返回 -2.
```
题目思考
1. 内部需要什么数据结构来满足所有操作都是 O(1), 一个栈够吗?
解决方案
思路
- 要使得 push 和 pop 的复杂度为 O(1), 传统的栈就可以搞定, 难点在于如何使得 min 函数也为 O(1)
- 如果我们能一直维护当前所有元素的最小值, 那么 min 函数直接返回它就可以, 但问题是在 pop 的时候有可能会正好 pop 这个最小值, pop 之后的最小值(也即原来的次小值)如何得到呢?
- 要存储多个最小值, 显然一个变量不够用. 而根据上一步的分析, 这里我们可以考虑额外引入一个**单调递减栈**, 栈顶存当前最小值, 下面依次是次小, 第三小...
- 这样如果 pop 了最小值的话, 这个单调栈的栈顶仍会保存 pop 后的最小值, 每次 min 只需要取这个栈的栈顶即可
- 而 push 的时候也需要额外的操作, 由于是单调栈, 只需要在新的值**小于等于**栈顶的时候才 push 到单调栈中.特别注意在等于栈顶的时候也要 push 到单调栈中, 这是因为如果对于重复的最小值 x 不 push, 那么在后续的 pop 其中一个 x 之后, 栈顶(不再是 x)就和实际最小值(仍为 x)不一致了
复杂度
- 时间复杂度 `O(1)`
  - 各种操作都是常数复杂度
- 空间复杂度 `O(N)`
  - 使用了两个栈
*/

#include <iostream>
#include <stack>
using namespace std;

class MinStack
{
public:
    stack<int> st;
    stack<int> minSt;

    MinStack()
    {
    }

    void push(int x)
    {
        st.push(x);
        if (minSt.empty() || x <= minSt.top())
        {
            minSt.push(x);
        }
    }

    void pop()
    {
        if (st.empty())
        {
            return;
        }
        int x = st.top();
        st.pop();
        if (x == minSt.top())
        {
            minSt.pop();
        }
    }

    int top()
    {
        return st.top();
    }

    int min()
    {
        return minSt.top();
    }
};

int main()
{
    MinStack minStack;
    minStack.push(-2);
    minStack.push(0);
    minStack.push(-3);
    cout << minStack.min() << endl; // -3
    minStack.pop();
    cout << minStack.top() << endl; // 0
    cout << minStack.min() << endl; // -2

    return 0;
}
