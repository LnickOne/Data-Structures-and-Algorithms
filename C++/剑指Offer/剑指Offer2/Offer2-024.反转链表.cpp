/* 题目难度: 简单
[原题链接](https://leetcode.cn/problems/3u1WK4)
题目描述
给定单链表的头节点 head, 请反转链表, 并返回反转后的链表。
题目样例
示例1
- 输入: head = [1,2,3,4,5]
- 输出: [5,4,3,2,1]
示例2
- 输入: head = [1,2]
- 输出: [2,1]
示例3
- 输入: head = []
- 输出: []
题目思考
1. 能否只用迭代实现?
2. 能否只用递归实现?
解决方案
方案1
思路
- 迭代: 维护 pre 和 cur 指针, 每次将 cur->next 指向 pre, 然后 pre/cur 各右移一步
- 注意先保存 cur->next 再修改指针
复杂度
- 时间复杂度 O(N): 遍历一次
- 空间复杂度 O(1): 只使用了几个常数空间的变量
方案2
思路
- 递归: 对 head->next 递归反转, 返回新头节点
- 反转完后令 head->next->next = head, head->next = nullptr 即可
复杂度
- 时间复杂度 O(N): 遍历一次
- 空间复杂度 O(N): 递归栈的消耗
 */
#include "../剑指Offer1/ListNode.h"

class Solution
{
public:
    // 方案1: 迭代
    ListNode *reverseList(ListNode *head)
    {
        ListNode *pre = nullptr, *cur = head;
        while (cur)
        {
            ListNode *nex = cur->next;
            cur->next = pre;
            pre = cur;
            cur = nex;
        }
        return pre;
    }
    // 方案2: 递归
    ListNode *reverseList2(ListNode *head)
    {
        if (!head || !head->next) return head;
        ListNode *newHead = reverseList2(head->next);
        head->next->next = head;
        head->next = nullptr;
        return newHead;
    }
};

int main()
{
    Solution s;
    auto r1 = s.reverseList(createListNode({1, 2, 3, 4, 5}));
    printListNode(r1); // 5 4 3 2 1
    deleteList(r1);
    auto r2 = s.reverseList2(createListNode({1, 2}));
    printListNode(r2); // 2 1
    deleteList(r2);
    auto r3 = s.reverseList(nullptr);
    printListNode(r3); // (empty)
    return 0;
}
