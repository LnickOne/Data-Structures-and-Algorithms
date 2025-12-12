/*
将两个升序链表合并为一个新的 升序 链表并返回。新链表是通过拼接给定的两个链表的所有节点组成的。
示例 1：
输入：l1 = [1,2,4], l2 = [1,3,4]
输出：[1,1,2,3,4,4]
示例 2：
输入：l1 = [], l2 = []
输出：[]
示例 3：
输入：l1 = [], l2 = [0]
输出：[0]
*/
#include "ListNode.h"
class Solution
{
public:
    ListNode *mergeTwoLists(ListNode *list1, ListNode *list2)
    {
        ListNode *dummy = new ListNode(0);
        ListNode *cur = dummy;
        while (list1 && list2)
        {
            if (list1->val <= list2->val)
            {
                cur->next = list1;
                list1 = list1->next;
                cur = cur->next;
            }
            else if (list1->val > list2->val)
            {
                cur->next = list2;
                list2 = list2->next;
                cur = cur->next;
            }
        }
        if (list1)
            cur->next = list1;
        if (list2)
            cur->next = list2;
        return dummy->next;
    }
};

int main()
{
    Solution s;
    ListNode *l1 = createListNode({1, 2, 4});
    ListNode *l2 = createListNode({1, 3, 4});
    ListNode *l3 = s.mergeTwoLists(l1, l2);
    printListNode(l3);
    return 0;
}