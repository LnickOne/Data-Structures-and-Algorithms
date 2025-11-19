/*
给定一个单链表 L 的头节点 head ，单链表 L 表示为：
L0 → L1 → … → Ln - 1 → Ln
请将其重新排列后变为：
L0 → Ln → L1 → Ln - 1 → L2 → Ln - 2 → …
不能只是单纯的改变节点内部的值，而是需要实际的进行节点交换。
示例 1：
输入：head = [1,2,3,4]
输出：[1,4,2,3]
示例 2：
输入：head = [1,2,3,4,5]
输出：[1,5,2,4,3]
*/
#include "ListNode.h"
class Solution
{
public:
    void reorderList(ListNode *head)
    {
        // 快慢指针，链表分割成两个链表，然后把第二个链表反转，之后在通过两个链表相互错开拼接成新的链表。
        // 比如{1,2,3,4,5} 分割成{1,2,3}和{4,5} 然后把{4,5}反转成{5,4}
        // 然后在通过两个链表相互错开拼接成新的链表{1,5,2,4,3}
        if (!head || !head->next)
            return;
        ListNode *slow = head;
        ListNode *fast = head;
        while (fast && fast->next)
        {
            slow = slow->next;
            fast = fast->next->next;
        }
        ListNode *l1 = head;
        ListNode *l2 = reverseList(slow->next);
        slow->next = nullptr;
        AlternatelyMergeList(l1, l2);
        return;
    }

    ListNode *reverseList(ListNode *head)
    {
        ListNode *pre = nullptr;
        ListNode *cur = head;
        while (cur)
        {
            ListNode *next = cur->next;
            cur->next = pre;
            pre = cur;
            cur = next;
        }
        return pre;
    }
    void AlternatelyMergeList(ListNode *l1, ListNode *l2)
    {
        // l1_tmp 在每次循环中被赋值为 l1 的下一个节点，l2_tmp 在每次循环中被赋值为 l2 的下一个节点。
        // 接着 l1 被更新为 l1_tmp， l2 被更新为 l2_tmp, 这样就完成了一次循环中的节点交换。
        while (l1 && l2)
        {
            ListNode *l1_node = l1->next;
            ListNode *l2_node = l2->next;
            l1->next = l2;
            l1 = l1_node;
            l2->next = l1;
            l2 = l2_node;
        }
    }
};

int main()
{
    //ListNode *head = createListNode({1, 2, 3, 4, 5});
     ListNode *head = createListNode({1, 2, 3, 4});
    Solution().reorderList(head);
    printListNode(head);
    return 0;
}