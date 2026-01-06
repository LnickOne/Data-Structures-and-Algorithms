/*
给你一个单链表的头节点 head ，请你判断该链表是否为回文链表
如果是，返回 true ；否则，返回 false 。
示例 1：
输入：head = [1,2,2,1]
输出：true
示例 2：
输入：head = [1,2]
输出：false
*/
#include "ListNode.h"
class Solution
{
public:
    bool isPalindrome(ListNode *head)
    {
        ListNode *slow = head;
        ListNode *fast = head;
        while (fast && fast->next)
        {
            slow = slow->next;
            fast = fast->next->next;
        }
        ListNode *right = reverseList(slow);
        while (right && head)
        {
            if (right->val != head->val)
                return false;
            right = right->next;
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
            ListNode *cur_next = cur->next;
            cur->next = pre;
            pre = cur;
            cur = cur_next;
        }
        return pre;
    }
};

int main()
{
    ListNode *head = createListNode({1, 2});
    ListNode *head1 = createListNode({1, 2, 2, 1, 3, 3, 4, 1, 2, 2, 1});
    ListNode *head2 = createListNode({1, 1, 2, 1});
    bool result = Solution().isPalindrome(head2);
    std::cout << result << std::endl;
    return 0;
}