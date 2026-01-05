/*
给你一个链表，两两交换其中相邻的节点，并返回交换后链表的头节点。
你必须在不修改节点内部的值的情况下完成本题（即，只能进行节点交换）。
示例 1：
输入：head = [1,2,3,4]
输出：[2,1,4,3]
示例 2：
输入：head = []
输出：[]
示例 3：
输入：head = [1]
输出：[1]
*/
#include "ListNode.h"
class Solution
{
public:
    ListNode *swapPairs(ListNode *head)
    {
        if (!head)
        {
            return nullptr;
        }
        ListNode *dummy = new ListNode(0);
        ListNode *cur = dummy;
        dummy->next = head;
        while (cur->next && cur->next->next)
        {
            ListNode *node_1 = cur->next;
            ListNode *node_3 = cur->next->next->next;
            cur->next = cur->next->next; // 0->2
            cur->next->next = node_1;    // 2->1
            node_1->next = node_3;       // 1->3
            cur = cur->next->next;       // cur移动到原来2的位置 然后对原来的34进行操作
        }
        return dummy->next;
    }
};

int main()
{
    ListNode *l1 = createListNode({1, 2, 3, 4});
    Solution s;
    ListNode *result = s.swapPairs(l1);
    printListNode(result);
    return 0;
}