/* 题目难度: 中等
[原题链接](https://leetcode.cn/problems/LGjMqU)
题目描述
给定链表 L0→L1→…→Ln-1→Ln, 将其重排为 L0→Ln→L1→Ln-1→L2→Ln-2→…
不能只改节点值, 必须实际修改节点连接。
题目样例
示例1
- 输入: head = [1,2,3,4]
- 输出: [1,4,2,3]
示例2
- 输入: head = [1,2,3,4,5]
- 输出: [1,5,2,4,3]
题目思考
1. 如何做到 O(1) 空间复杂度?
解决方案
思路
- 分三步:
  1. 快慢指针找中点, 将链表分为左右两半 (奇数长度中点归左半)
  2. 反转右半链表
  3. 交替合并左右两半: 每次取左一个→右一个→左一个→...
- 每步都是 O(N) 时间 O(1) 空间, 整体 O(N)/O(1)
复杂度
- 时间复杂度 O(N): 三次 O(N) 操作
- 空间复杂度 O(1): 只使用了几个常数空间的变量
 */
#include "ListNode.h"

class Solution
{
    ListNode *reverse(ListNode *head)
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
public:
    void reorderList(ListNode *head)
    {
        if (!head || !head->next) return;
        // 找中点: 偶数长度取左中点
        ListNode *fast = head->next, *slow = head;
        while (fast && fast->next)
        {
            slow = slow->next;
            fast = fast->next->next;
        }
        ListNode *right = reverse(slow->next);
        slow->next = nullptr;
        ListNode *left = head;
        while (left && right)
        {
            ListNode *nl = left->next, *nr = right->next;
            left->next = right;
            right->next = nl;
            left = nl;
            right = nr;
        }
    }
};

int main()
{
    Solution s;
    auto r1 = createListNode({1, 2, 3, 4});
    s.reorderList(r1);
    printListNode(r1); // 1 4 2 3
    deleteList(r1);
    auto r2 = createListNode({1, 2, 3, 4, 5});
    s.reorderList(r2);
    printListNode(r2); // 1 5 2 4 3
    deleteList(r2);
    return 0;
}
