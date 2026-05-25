/* 题目难度: 简单
[原题链接](https://leetcode.cn/problems/shan-chu-lian-biao-de-jie-dian-lcof/)
题目描述
给定链表头指针和要删除的节点值 val (值互不相同), 删除该节点并返回新头节点。
题目样例
示例1
- 输入: head=[4,5,1,9], val=5
- 输出: [4,1,9]
示例2
- 输入: head=[4,5,1,9], val=1
- 输出: [4,5,9]
题目思考
1. 如何快速找到并删除节点?
解决方案
思路
- 哨兵节点 prehead 指向 head, pre/cur 双指针遍历找到 val 后删除
复杂度
- 时间复杂度 O(N): 最差遍历全链表
- 空间复杂度 O(1): 常数空间
 */
#include <iostream>
#include "ListNode.h"
using namespace std;

class Solution
{
public:
    ListNode *deleteNode(ListNode *head, int val)
    {
        ListNode prehead(0);
        prehead.next = head;
        ListNode *pre = &prehead, *cur = head;
        while (cur)
        {
            if (cur->val == val) { pre->next = cur->next; break; }
            pre = cur; cur = cur->next;
        }
        return prehead.next;
    }
};

int main()
{
    auto make = [](vector<int> v) {
        ListNode *h = nullptr, **p = &h;
        for (int x : v) { *p = new ListNode(x); p = &(*p)->next; }
        return h;
    };
    auto print = [](ListNode *h) {
        bool first = true;
        while (h) { if (!first) cout << "->"; cout << h->val; first = false; h = h->next; }
        cout << endl;
    };
    Solution sol;
    print(sol.deleteNode(make({4,5,1,9}), 5)); // 4->1->9
    print(sol.deleteNode(make({4,5,1,9}), 1)); // 4->5->9
    return 0;
}
