/*
给你一个链表，删除链表的倒数第 n 个结点，并且返回链表的头结点。
示例 1：
输入：head = [1,2,3,4,5], n = 2
输出：[1,2,3,5]
示例 2：
输入：head = [1], n = 1
输出：[]
示例 3：
输入：head = [1,2], n = 1
输出：[1]
*/
#include "ListNode.h"
class Solution
{
public:
    ListNode *removeNthFromEnd(ListNode *head, int n)
    {
        // 双指针的经典应用，快指针先走n+1步，然后快慢指针一起走，
        // 当快指针走到末尾时，慢指针指向的节点就是要删除的节点
        if (!head)
            return nullptr;
        ListNode *dummy = new ListNode(0);
        dummy->next = head;
        ListNode *slow = dummy;
        ListNode *fast = dummy;
        n += 1;
        while (fast && n > 0)
        {
            fast = fast->next;
            n -= 1;
        }
        // 添加 n 有效性检查
        if (n > 0)
        {
            delete dummy;
            return head;
        }
        while (fast)
        {
            fast = fast->next;
            slow = slow->next;
        }
        if (slow->next)
        {
            ListNode *node = slow->next;
            slow->next = slow->next->next;
            delete node;
            node = nullptr;
        }
        // 释放 dummy 节点
        ListNode *result = dummy->next;
        delete dummy; 
        return result;
    }

    // ListNode *removeNthFromEnd2(ListNode *head, int n)
    // {
    //     ListNode *dummy = new ListNode(0);
    //     dummy->next = head;
    //     ListNode *cur = dummy;
    //     int length = getLength(head);
    //     for (int i = 1; i < length - n + 1; ++i)
    //     {
    //         cur = cur->next;
    //     }
    //     ListNode *del_node = cur->next;
    //     cur->next = cur->next->next;
    //     delete del_node;
    //     del_node = nullptr;
    //     return dummy->next;
    // }
    // int getLength(ListNode *head)
    // {
    //     ListNode *cur = head;
    //     int length = 0;
    //     while (cur)
    //     {
    //         cur = cur->next;
    //         length++;
    //     }
    //     return length;
    // }
};

int main()
{
    Solution s;
    vector<int> nums{1, 2, 3, 4, 5};
    ListNode *head = createListNode(nums);
    int n = 2;
    printListNode(head);
    head = s.removeNthFromEnd(head, n);
    printListNode(head);
    return 0;
}