/*
给你一个链表数组，每个链表都已经按升序排列。
请你将所有链表合并到一个升序链表中，返回合并后的链表。

示例 1：
输入：lists = [[1,4,5],[1,3,4],[2,6]]
输出：[1,1,2,3,4,4,5,6]
解释：链表数组如下：
[
  1->4->5,
  1->3->4,
  2->6
]
将它们合并到一个有序链表中得到。
1->1->2->3->4->4->5->6

示例 2：
输入：lists = []
输出：[]

示例 3：
输入：lists = [[]]
输出：[]
*/
#include "ListNode.h"
class Solution
{
public:
    ListNode *mergeKLists(vector<ListNode *> &lists)
    {
        if (lists.empty())
            return nullptr;
        ListNode *result = lists[0];
        for (int i = 1; i < lists.size(); i += 1)
        {
            result = mergeTwoLists(result, lists[i]);
        }
        return result;
    }
    ListNode *mergeTwoLists(ListNode *list1, ListNode *list2)
    {
        if (list1 == nullptr)
        {
            return list2;
        }
        else if (list2 == nullptr)
        {
            return list1;
        }
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
        else if (list2)
            cur->next = list2;
        ListNode *result = dummy->next;
        delete dummy; // 删除dummy节点
        return result;
    }
};
int main()
{
    Solution s;
    vector<ListNode *> lists = {createListNode({1, 4, 5}), createListNode({1, 3, 4}), createListNode({2, 6})};
    ListNode *l3 = s.mergeKLists(lists);
    printListNode(l3);
    // 释放合并后的链表内存
    deleteList(l3);

    return 0;
}