#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include "ListNode.h"
using namespace std;
/*
输入两个递增的链表，单个链表的长度为n，合并这两个链表并使新链表中的节点仍然是递增排序的。
如输入{1,3,5},{2,4,6}时，合并后的链表为{1,2,3,4,5,6}，所以对应的输出为{1,2,3,4,5,6}，转换过程如下图所示：
输入：
{1,3,5},{2,4,6}
复制
返回值：
{1,2,3,4,5,6}
*/
class Solution
{
public:
    ListNode *Merge(ListNode *pHead1, ListNode *pHead2)
    {
        ListNode *dummy = new ListNode(-1);
        ListNode *cur = dummy;
        while (pHead1 != nullptr && pHead2 != nullptr)
        {
            if (pHead1->val < pHead2->val)
            {
                cur->next = pHead1;
                pHead1 = pHead1->next;
            }
            else
            {
                cur->next = pHead2;
                pHead2 = pHead2->next;
            }
            cur = cur->next;
        }
        if (pHead1 == nullptr)
            cur->next = pHead2;
        if (pHead2 == nullptr)
            cur->next = pHead1;
        return dummy->next;
    }
};

int main()
{
    ListNode *head1 = createListNode({1, 3, 5});
    ListNode *head2 = createListNode({2, 4, 6});
    Solution s;
    ListNode *res = s.Merge(head1, head2);
    printListNode(res);
    return 0;
}