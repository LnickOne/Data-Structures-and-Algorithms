/*
给你链表的头节点 head ，每 k 个节点一组进行翻转，请你返回修改后的链表。
k 是一个正整数，它的值小于或等于链表的长度。如果节点总数不是 k 的整数倍，那么请将最后剩余的节点保持原有顺序。
你不能只是单纯的改变节点内部的值，而是需要实际进行节点交换。
示例 1：
输入：head = [1,2,3,4,5], k = 2
输出：[2,1,4,3,5]
示例 2：
输入：head = [1,2,3,4,5], k = 3
输出：[3,2,1,4,5]
*/
#include "ListNode.h"
class Solution
{
public:
    ListNode *reverseKGroup(ListNode *head, int k)
    {
        ListNode *cur = head;
        int count = 0;
        while (cur && count != k)
        {
            cur = cur->next;
            count += 1;
        }
        if (count == k)
        {
            cur = reverseKGroup(cur, k);
            while (count > 0)
            {
                ListNode *tmp = head->next;
                head->next = cur;
                cur = head;
                head = tmp;
                count -= 1;
            }
            head = cur;
        }
        else
        {
            return head;
        }
        return head;
    }
};
int main()
{
    ListNode *head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    head->next->next->next->next = new ListNode(5);
    Solution s;
    ListNode *res = s.reverseKGroup(head, 3);
    while (res)
    {
        cout << res->val << " ";
        res = res->next;
    }
    cout << endl;
    return 0;
}