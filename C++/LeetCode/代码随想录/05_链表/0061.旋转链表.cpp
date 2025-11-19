/*
给你一个链表的头节点 head ，旋转链表，将链表每个节点向右移动 k 个位置。
示例 1：
输入：head = [1,2,3,4,5], k = 2
输出：[4,5,1,2,3]
示例 2：
输入：head = [0,1,2], k = 4
输出：[2,0,1]
*/
#include "ListNode.h"
class Solution
{
public:
    ListNode *rotateRight(ListNode *head, int k)
    {
        if (!head)
            return head;
        int length = getListLength(head);
        k = k % length;
        head = reverseListNode(head);           // 整体反转
        head = reverseBetween(head, 0, k);      // 前k个反转
        head = reverseBetween(head, k, length); // 后k个反转
        return head;
    }
    ListNode *reverseListNode(ListNode *head)
    {
        ListNode *pre = nullptr;
        ListNode *cur = head;
        while (cur)
        {
            ListNode *node = cur->next;
            cur->next = pre;
            pre = cur;
            cur = node;
        }
        return pre;
    }
    ListNode *reverseBetween(ListNode *head, int left, int right)
    {
        ListNode *dummy = new ListNode(0);
        ListNode *pre = dummy;
        ListNode *cur = head;
        dummy->next = head;
        for (int i = 0; i < left; i++)
        {
            pre = cur;
            cur = cur->next;
        }
        for (int i = left + 1; i < right; i++)
        {
            ListNode *node = cur->next;
            cur->next = node->next; // 1指向3
            node->next = pre->next; // 2指向1
            pre->next = node;       // 0指向2
        }
        return dummy->next;
    }
    int getListLength(ListNode *head)
    {
        if (head == nullptr)
            return 0;
        int length = 0;
        ListNode *cur = head;
        while (cur)
        {
            cur = cur->next;
            length++;
        }
        return length;
    }
};

int main()
{
    ListNode *head = createListNode({1, 2, 3, 4, 5});
    Solution s;
    head = s.rotateRight(head, 2);
    printListNode(head);
    return 0;
}