/*
给你两个非空链表来代表两个非负整数。数字最高位位于链表开始位置。
它们的每个节点只存储一位数字。将这两数相加会返回一个新的链表。
你可以假设除了数字 0 之外，这两个数字都不会以零开头。
示例1：
输入：l1 = [7,2,4,3], l2 = [5,6,4]
输出：[7,8,0,7]
示例2：
输入：l1 = [2,4,3], l2 = [5,6,4]
输出：[8,0,7]
示例3：
输入：l1 = [0], l2 = [0]
输出：[0]
*/
#include "ListNode.h"
class Solution
{
public:
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2)
    {
        l1 = reverseListNode(l1);
        l2 = reverseListNode(l2);
        ListNode *dummy = new ListNode(0);
        ListNode *cur = dummy;
        int quotient;
        int remainder;
        int sum;
        int carry = 0;
        while (l1 && l2)
        {
            sum = l1->val + l2->val + carry;
            quotient = sum / 10;
            remainder = sum % 10;
            cur->next = new ListNode(remainder); // 取个位上的数字
            carry = quotient;                    // 取十位上的数字
            l1 = l1->next;
            l2 = l2->next;
            cur = cur->next;
        }
        while (l1)
        {
            sum = l1->val + carry;
            quotient = sum / 10;
            remainder = sum % 10;
            cur->next = new ListNode(remainder); // 取个位上的数字
            carry = quotient;                    // 取十位上的数字
            l1 = l1->next;
            cur = cur->next;
        }
        while (l2)
        {
            sum = l2->val + carry;
            quotient = sum / 10;
            remainder = sum % 10;
            cur->next = new ListNode(remainder); // 取个位上的数字
            carry = quotient;                    // 取十位上的数字
            l2 = l2->next;
            cur = cur->next;
        }
        if (carry != 0)
        {
            ListNode *node = new ListNode(carry);
            cur->next = node;
            cur = cur->next;
        }
        dummy->next = reverseListNode(dummy->next);
        return dummy->next;
    }
    ListNode *reverseListNode(ListNode *head)
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
    ListNode *l1 = createListNode({7, 2, 4, 3});
    ListNode *l2 = createListNode({5, 6, 4});
    Solution s;
    ListNode *res = s.addTwoNumbers(l1, l2);
    printListNode(res);
    return 0;
}