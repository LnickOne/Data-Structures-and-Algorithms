#include <iostream>
#include <vector>
#include <algorithm>
#include "ListNode.h"
using namespace std;
/*
描述
给出一个升序排序的链表，删除链表中的所有重复出现的元素，只保留原链表中只出现一次的元素。
示例1
输入：
{1,2,2}
返回值：
{1}
示例2
输入：
{}
返回值：
{}
*/
class Solution
{
public:
    ListNode *deleteDuplicates(ListNode *head)
    {
        ListNode *dummy = new ListNode(-1);
        dummy->next = head;
        ListNode *pre = dummy;
        ListNode *cur = head;
        while (cur)
        {
            while (cur->next && cur->val == cur->next->val)
            {
                ListNode *tmp = cur;
                cur = cur->next;
                delete tmp;
            }
            if (pre->next == cur)
                pre = pre->next;
            if (pre->next != cur)
                pre->next = cur->next;
            cur = cur->next;
        }
        return dummy->next;
    }
};

int main()
{
    ListNode *head = createListNode({1, 2, 2});
    Solution().deleteDuplicates(head);
    printListNode(head);
    return 0;
}