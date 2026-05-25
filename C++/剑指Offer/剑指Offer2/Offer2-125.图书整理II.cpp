/* 题目难度: 简单
[原题链接](https://leetcode.cn/problems/yong-liang-ge-zhan-shi-xian-dui-lie-lcof/)
题目描述
用两个栈实现队列: push(bookID) 尾部入队, pop() 头部出队 (返回最早归还的书, 若空返回 -1)。
题目样例
示例1
- 输入: ["BookQueue","push","push","pop"] / [[],[1],[2],[]]
- 输出: [null,null,null,1]
题目思考
1. 如何利用两个栈模拟队列?
解决方案
思路
- stackIn 负责入队, stackOut 负责出队
- 出队时若 stackOut 为空, 将 stackIn 全部倒入 stackOut; 两者均空则返回 -1
复杂度
- 时间复杂度: push O(1), pop 均摊 O(1)
- 空间复杂度 O(N): 两个栈
 */
#include <iostream>
#include <stack>
using namespace std;

class BookQueue
{
    stack<int> stackIn, stackOut;
public:
    void push(int value) { stackIn.push(value); }
    int pop()
    {
        if (stackOut.empty())
        {
            if (stackIn.empty()) return -1;
            while (!stackIn.empty()) { stackOut.push(stackIn.top()); stackIn.pop(); }
        }
        int val = stackOut.top(); stackOut.pop();
        return val;
    }
};

int main()
{
    BookQueue q;
    q.push(1);
    q.push(2);
    cout << q.pop() << endl; // 1
    cout << q.pop() << endl; // 2
    cout << q.pop() << endl; // -1
    return 0;
}
