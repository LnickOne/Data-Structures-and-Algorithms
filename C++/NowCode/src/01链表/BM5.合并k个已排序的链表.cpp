#include <iostream>
#include <vector>
#include <algorithm>
#include "ListNode.h"
using namespace std;
/*
描述
合并 k 个升序的链表并将结果作为一个升序的链表返回其头节点。
*/
class Solution
{
public:
    ListNode *mergeKLists(vector<ListNode *> &lists)
    {
        if (lists.size() == 0)
            return nullptr;
        ListNode *head = nullptr;
        head = mergeTwoLists(head, lists[0]);
        for (int i = 1; i < lists.size(); i++)
        {
            head = mergeTwoLists(head, lists[i]);
        }
        printListNode(head);
        return head;
    }

    ListNode *mergeTwoLists(ListNode *list1, ListNode *list2)
    {
        ListNode *dummy = new ListNode(-1);
        ListNode *cur = dummy;
        while (list1 && list2)
        {
            if (list1->val < list2->val)
            {
                cur->next = list1;
                list1 = list1->next;
            }
            else
            {
                cur->next = list2;
                list2 = list2->next;
            }
            cur = cur->next;
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
    vector<ListNode *> lists;
    // lists.push_back(createListNode({1, 3, 5}));
    // lists.push_back(createListNode({2, 4, 6}));
    // lists.push_back(createListNode({7, 8, 9}));
    lists.push_back(createListNode({-5}));
    lists.push_back(createListNode({-5, -9, -8, -7, -5, 1, 1, 1, 3}));
    lists.push_back(createListNode({-10, -7, -6, -6, -6, 0, 1, 3, 3}));
    lists.push_back(createListNode({-10, -8, -7, -2, 3, 3}));
    lists.push_back(createListNode({-1, 4}));
    Solution s;
    ListNode *res = s.mergeKLists(lists);
    printListNode(res);
    return 0;
}