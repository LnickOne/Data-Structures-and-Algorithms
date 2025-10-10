#include <iostream>
#include <vector>
#include <algorithm>
#include "ListNode.h"
using namespace std;
/*
描述
给定一个链表，请判断该链表是否为回文结构。
回文是指该字符串正序逆序完全一致。
*/
class Solution
{
public:
    bool isPail(ListNode *head)
    {
        ListNode *slow = head;
        ListNode *fast = head;
        while (fast->next && fast->next->next)
        {
            slow = slow->next;
            fast = fast->next->next;
        }
        ListNode *mid = slow->next;
        ListNode *left = reverseList(mid);
        printListNode(left);
        printListNode(head);
        while (left && head)
        {
            if (left->val != head->val)
                return false;
            left = left->next;
            head = head->next;
        }
        return true;
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
};

int main()
{
    ListNode *head = new ListNode(1);
    ListNode *node1 = new ListNode(2);
    ListNode *node2 = new ListNode(3);
    ListNode *node3 = new ListNode(2);
    ListNode *node4 = new ListNode(1);
    head->next = node1;
    node1->next = node2;
    node2->next = node3;
    node3->next = node4;
    Solution s;
    bool res = s.isPail(head);
    cout << res << endl;
    return 0;
}