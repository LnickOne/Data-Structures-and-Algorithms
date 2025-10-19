/*
给定一个已排序的链表的头head，删除所有重复的元素，使每个元素只出现一次 。
返回 已排序的链表 。
示例 1：
输入：head = [1,1,2]
输出：[1,2]
示例 2：
输入：head = [1,1,2,3,3]
输出：[1,2,3]
*/
#include "ListNode.h"
class Solution
{
public:
    ListNode *deleteDuplicates(ListNode *head)
    {
        if (head == nullptr)
            return nullptr;
        ListNode *dummy = new ListNode(0);
        dummy->next = head;
        ListNode *cur = dummy;
        while (cur->next && cur->next->next)
        {
            if (cur->next->val == cur->next->next->val)
            {
                int value = cur->next->val; // 将value获取移至此处，更清晰
                ListNode *node = cur->next;
                while (node->next && node->next->val == value)
                {
                    ListNode *del_node = node;
                    node = node->next;
                    delete del_node;
                    del_node = nullptr;
                }
                cur->next = node;
            }
            else
                cur = cur->next;
        }
        ListNode *result = dummy->next; // 保存结果指针
        delete dummy;                   // 释放dummy节点，防止内存泄漏
        return result;
    }
};
int main()
{
    Solution s;
    ListNode *head = createListNode({1, 1, 2});
    ListNode *head1 = createListNode({1, 1, 2, 3, 3});
    ListNode *head2 = createListNode({1, 1});
    ListNode *head3 = createListNode({1, 2, 3, 3});
    ListNode *result = s.deleteDuplicates(head);
    ListNode *result1 = s.deleteDuplicates(head1);
    ListNode *result2 = s.deleteDuplicates(head2);
    ListNode *result3 = s.deleteDuplicates(head3);
    printListNode(result);
    printListNode(result1);
    printListNode(result2);
    printListNode(result3);
    return 0;
}