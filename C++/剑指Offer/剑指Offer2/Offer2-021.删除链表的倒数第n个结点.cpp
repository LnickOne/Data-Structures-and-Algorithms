/* 题目难度: 中等
[原题链接](https://leetcode.cn/problems/SLwz0R)
题目描述
给定一个链表, 删除链表的倒数第 n 个结点, 并返回链表的头结点。
题目样例
示例1
- 输入: head = [1,2,3,4,5], n = 2
- 输出: [1,2,3,5]
示例2
- 输入: head = [1], n = 1
- 输出: []
示例3
- 输入: head = [1,2], n = 1
- 输出: [1]
题目思考
1. 如何使用一趟扫描实现?
解决方案
思路
- 朴素做法: 先统计链表总长度, 算出待删节点的正数下标, 再找到其前驱节点删除; 需要两趟扫描
- 优化: 快慢指针保证两者距离始终为 n
  1. 快指针先正向遍历 n 步
  2. 慢指针初始化为哨兵节点 (dummy -> head)
  3. 快慢指针同时右移直到快指针为空
  4. 此时慢指针指向待删节点的前驱, 将其 next 指向 next->next
- 哨兵节点可以统一处理删除头节点的边界情况
复杂度
- 时间复杂度 O(N): 只需一趟扫描
- 空间复杂度 O(1): 只使用了几个常数空间的变量
 */
#include "../剑指Offer1/ListNode.h"

class Solution
{
public:
    ListNode *removeNthFromEnd(ListNode *head, int n)
    {
        ListNode dummy(0, head);
        ListNode *fast = head, *slow = &dummy;
        for (int i = 0; i < n; i++) fast = fast->next;
        while (fast)
        {
            fast = fast->next;
            slow = slow->next;
        }
        ListNode *del = slow->next;
        slow->next = del->next;
        del->next = nullptr;
        delete del;
        return dummy.next;
    }
};

int main()
{
    Solution s;
    auto r1 = s.removeNthFromEnd(createListNode({1, 2, 3, 4, 5}), 2);
    printListNode(r1); // 1 2 3 5
    deleteList(r1);
    auto r2 = s.removeNthFromEnd(createListNode({1}), 1);
    printListNode(r2); // (empty)
    auto r3 = s.removeNthFromEnd(createListNode({1, 2}), 1);
    printListNode(r3); // 1
    deleteList(r3);
    return 0;
}
