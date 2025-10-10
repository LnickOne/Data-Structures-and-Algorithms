#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include "ListNode.h"
using namespace std;
/*
将一个节点数为 size 链表 m 位置到 n 位置之间的区间反转
示例1
输入：
{1,2,3,4,5},2,4
复制
返回值：
{1,4,3,2,5}
*/
class Solution
{
public:
    ListNode *reverseBetween(ListNode *head, int left, int right)
    {
        ListNode *dummy = new ListNode(0);
        dummy->next = head;
        ListNode *pre = dummy;
        ListNode *cur = head;
        for (int i = 0; i < left - 1; i++)
        {
            pre = cur;
            cur = cur->next;
        }
        for (int i = left; i < right; i++)
        {
            ListNode *cur_next = cur->next;
            cur->next = cur_next->next; // 1指向3
            cur_next->next = pre->next; // 2指向1
            pre->next = cur_next;       // 0指向2
        }
        return dummy->next;
    }
};

int main()
{
    ListNode *head = createListNode({1, 2, 3, 4, 5});
    Solution().reverseBetween(head, 2, 4);
    printListNode(head);
    return 0;
}