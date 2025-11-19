/*
给你一个链表的头节点 head 和一个特定值 x ，请你对链表进行分隔，使得所有 小于 x 的节点都出现在 大于或等于 x 的节点之前。
你应当 保留 两个分区中每个节点的初始相对位置。
示例 1：
输入：head = [1,4,3,2,5,2], x = 3
输出：[1,2,2,4,3,5]
示例 2：
输入：head = [2,1], x = 2
输出：[1,2]
*/
#include "ListNode.h"
class Solution
{
public:
    /*
    只需维护两个链表 dummy1 和 dummy2 ，
    dummy1 链表按顺序存储所有小于 x 的节点，
    dummy2 链表按顺序存储所有大于等于 x 的节点。
    遍历完原链表后将 cur1 链表尾节点指向 cur2 链表的头节点即能完成对链表的分隔。
    */
    ListNode *partition(ListNode *head, int x)
    {
        ListNode *dummy1 = new ListNode(0);
        ListNode *dummy2 = new ListNode(0);
        ListNode *cur1 = dummy1;
        ListNode *cur2 = dummy2;
        while (head)
        {
            if (head->val < x)
            {
                cur1->next = head;
                cur1 = cur1->next;
            }
            else if (head->val >= x)
            {
                cur2->next = head;
                cur2 = cur2->next;
            }
            head = head->next;
        }
        cur2->next = nullptr;
        cur1->next = dummy2->next;
        return dummy1->next;
    }
};

int main()
{
    ListNode *head = createListNode({1, 4, 3, 2, 5, 2});
    printListNode(head);
    ListNode *res = Solution().partition(head, 3);
    printListNode(res);
    return 0;
}