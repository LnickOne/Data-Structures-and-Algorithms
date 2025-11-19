/*
给你链表的头结点 head ，请将其按 升序 排列并返回 排序后的链表 。
示例 1：
输入：head = [4,2,1,3]
输出：[1,2,3,4]
示例 2：
输入：head = [-1,5,3,4,0]
输出：[-1,0,3,4,5]
 */
#include "ListNode.h"
class Solution
{
public:
    ListNode *sortList(ListNode *head)
    {
        if (head == nullptr)
            return nullptr;
        vector<int> arr;
        while (head)
        {
            arr.push_back(head->val);
            head = head->next;
        }
        sort(arr.begin(), arr.end());
        ListNode *newHead = new ListNode(arr[0]);
        ListNode *cur = newHead;
        for (int i = 1; i < arr.size(); i++)
        {
            cur->next = new ListNode(arr[i]);
            cur = cur->next;
        }
        return newHead;
    }
};

int main()
{
    vector<int> arr = {4, 2, 1, 3};
    ListNode *head = createListNode(arr);
    printListNode(head);
    Solution s;
    head = s.sortList(head);
    printListNode(head);
    return 0;
}