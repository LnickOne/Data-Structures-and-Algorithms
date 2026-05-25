/* 题目难度: 中等
[原题链接](https://leetcode.cn/problems/c32eOV)
题目描述
给定一个链表, 返回链表开始入环的第一个节点。若链表无环则返回 null。
不允许修改给定的链表。
题目样例
示例1
- 输入: head = [3,2,0,-4], pos = 1
- 输出: 返回 val = 2 的节点 (环的入口)
示例2
- 输入: head = [1,2], pos = 0
- 输出: 返回 val = 1 的节点
示例3
- 输入: head = [1], pos = -1
- 输出: null (无环)
题目思考
1. 如何用 O(1) 空间解决?
解决方案
思路
- Floyd 判圈算法: 快慢指针, 快指针每次走 2 步, 慢指针每次走 1 步
- 若有环则快慢指针必然相遇; 无环则快指针先到 null
- 相遇后, 将慢指针重置为 head, 快慢指针同时以 1 步走
- 再次相遇点即为环的入口 (数学证明: 设头到入口距离为 x, 入口到相遇点为 y, 环长为 y+z, 则 x = z + k*(y+z))
复杂度
- 时间复杂度 O(N): 常数趟遍历
- 空间复杂度 O(1): 只使用了几个常数空间的变量
 */
#include "../剑指Offer1/ListNode.h"

class Solution
{
public:
    ListNode *detectCycle(ListNode *head)
    {
        ListNode *slow = head, *fast = head;
        while (fast && fast->next)
        {
            slow = slow->next;
            fast = fast->next->next;
            if (slow == fast)
            {
                slow = head;
                while (slow != fast)
                {
                    slow = slow->next;
                    fast = fast->next;
                }
                return slow;
            }
        }
        return nullptr;
    }
};

int main()
{
    Solution s;
    // 示例1: [3,2,0,-4] 尾部连接到 index=1 的节点
    ListNode *n1 = new ListNode(3);
    ListNode *n2 = new ListNode(2);
    ListNode *n3 = new ListNode(0);
    ListNode *n4 = new ListNode(-4);
    n1->next = n2; n2->next = n3; n3->next = n4; n4->next = n2;
    ListNode *res = s.detectCycle(n1);
    cout << (res ? res->val : -1) << endl; // 2
    // 手动释放 (有环不能用 deleteList)
    n4->next = nullptr;
    n1->next = nullptr; delete n1;
    n2->next = nullptr; delete n2;
    delete n3; delete n4;
    // 示例2: 无环
    ListNode *m1 = new ListNode(1);
    ListNode *m2 = new ListNode(2);
    m1->next = m2;
    cout << (s.detectCycle(m1) ? "有环" : "null") << endl; // null
    delete m2; delete m1;
    return 0;
}
