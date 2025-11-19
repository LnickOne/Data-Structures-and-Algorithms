#include <iostream>
#include <vector>
#include <algorithm>
#include "ListNode.h"
using namespace std;
/*
描述
给定一个单链表，请设定一个函数，将链表的奇数位节点和偶数位节点分别放在一起，重排后输出。
注意是节点的编号而非节点的数值。
示例1
输入：
{1,2,3,4,5,6}
返回值：
{1,3,5,2,4,6}
示例2
输入：
{1,4,6,3,7}
返回值：
{1,6,7,4,3}
*/
class Solution
{
public:
    ListNode *oddEvenList(ListNode *head)
    {
        if (head == nullptr)
            return nullptr;
        ListNode *odd = head; // 奇数位头节点
        ListNode *even = head->next;
        ListNode *evenHead = even; // 偶数位头节点
        while (even != nullptr && even->next != nullptr)
        {
            odd->next = even->next;        // 1指向3
            odd = odd->next;               // 奇数位节点跳跃移到3
            even->next = even->next->next; // 2指向4
            even = even->next;             // 偶数位节点后移到4
        }
        odd->next = evenHead; // 奇数位尾节点指向偶数位头节点
        return head;
    }
};

int main()
{
    ListNode *head = createListNode({1, 2, 3, 4, 5, 6});
    Solution().oddEvenList(head);
    return 0;
}