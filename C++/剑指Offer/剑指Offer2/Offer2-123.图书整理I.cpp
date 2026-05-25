/* 题目难度: 简单
[原题链接](https://leetcode.cn/problems/cong-wei-dao-tou-da-yin-lian-biao-lcof/)
题目描述
给定链表头节点, 倒序返回链表各节点的值。
题目样例
示例1
- 输入: head=[3,6,4,1]
- 输出: [1,4,6,3]
题目思考
1. 遍历后翻转, 或递归, 或辅助栈?
解决方案
思路
- 正向遍历链表收集到数组, 然后翻转数组返回
复杂度
- 时间复杂度 O(N): 遍历一次
- 空间复杂度 O(N): 结果数组
 */
#include <iostream>
#include <vector>
#include <algorithm>
#include "ListNode.h"
using namespace std;

class Solution
{
public:
    vector<int> reverseBookList(ListNode *head)
    {
        vector<int> res;
        while (head)
        {
            res.push_back(head->val);
            head = head->next;
        }
        reverse(res.begin(), res.end());
        return res;
    }
};

int main()
{
    ListNode *head = new ListNode(3);
    head->next = new ListNode(6);
    head->next->next = new ListNode(4);
    head->next->next->next = new ListNode(1);
    Solution sol;
    auto r = sol.reverseBookList(head);
    cout << "[";
    for (int i = 0; i < (int)r.size(); ++i)
    {
        if (i)
            cout << ",";
        cout << r[i];
    }
    cout << "]" << endl; // [1,4,6,3]
    return 0;
}
