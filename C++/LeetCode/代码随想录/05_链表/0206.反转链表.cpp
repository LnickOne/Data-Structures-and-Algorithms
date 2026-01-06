/*
给你单链表的头节点 head ，请你反转链表，并返回反转后的链表。
示例 1：
输入：head = [1,2,3,4,5]
输出：[5,4,3,2,1]
示例 2：
输入：head = [1,2]
输出：[2,1]
示例 3：
输入：head = []
输出：[]
*/
#include "ListNode.h"
class Solution
{
public:
    ListNode *reverseList(ListNode *head)
    {
        ListNode *pre = nullptr;
        ListNode *cur = head;
        while (cur)
        {
            ListNode *node = cur->next;
            cur->next = pre; // 1节点指向空节点
            pre = cur;       // 空节点移动到1节点
            cur = node;      // 1节点移动到2节点
        }
        return pre;
    }
};

int main()
{
    ListNode *head_1 = createListNode({1, 2, 3, 4, 5});
    ListNode *result = Solution().reverseList(head_1);
    printListNode(result);
    return 0;
}