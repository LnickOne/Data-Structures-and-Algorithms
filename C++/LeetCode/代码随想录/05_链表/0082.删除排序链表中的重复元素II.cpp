/*
给定一个已排序的链表的头 head ，删除原始链表中所有重复数字的节点，只留下不同的数字 。返回 已排序的链表 。
示例 1：
输入：head = [1,2,3,3,4,4,5]
输出：[1,2,5]
示例 2：
输入：head = [1,1,1,2,3]
输出：[2,3]
*/
#include "ListNode.h"
class Solution
{
public:
    ListNode *deleteDuplicates(ListNode *head)
    {
        // 方法一：使用一个新的链表存储不重复的节点
        ListNode *dummy = new ListNode(0);
        ListNode *cur = dummy;
        dummy->next = head;
        while (cur->next && cur->next->next)
        {
            if (cur->next->val == cur->next->next->val)
            {
                ListNode *node = cur->next;
                int value = node->val;
                while (node && node->val == value)
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
        return dummy->next;

        // 方法二： 使用双指针
        // ListNode *dummy = new ListNode(0);
        // dummy->next = head;
        // ListNode *pre = dummy;
        // ListNode *cur = head;
        // while (cur)
        // {
        //     while (cur->next && cur->val == cur->next->val)
        //     {
        //         ListNode *del_node = cur;
        //         cur = cur->next;
        //         delete del_node;
        //     }
        //     if (pre->next == cur)
        //         pre = pre->next;
        //     if (pre->next != cur)
        //         pre->next = cur->next;
        //     cur = cur->next;
        // }
        // return dummy->next;
    }
};

int main()
{
    Solution s;
    vector<int> arr = {1, 1, 1, 2, 3, 3, 4, 4, 5};
    vector<int> arr1 = {1, 1, 1, 2, 3};
    // vector<int> arr2 = {1, 1};
    vector<int> arr3 = {1, 2, 3, 3};
    ListNode *head = createListNode(arr);
    ListNode *test = s.deleteDuplicates(head);
    printListNode(test);
    ListNode *head1 = createListNode(arr1);
    ListNode *test1 = s.deleteDuplicates(head1);
    printListNode(test1);
    return 0;
}