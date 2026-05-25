/* 题目难度: 中等
[原题链接](https://leetcode.cn/problems/7WHec2/)
题目描述
给定链表头结点 head, 请将其按升序排列并返回排序后的链表。
题目样例
示例1
- 输入: head = [4,2,1,3]
- 输出: [1,2,3,4]
示例2
- 输入: head = [-1,5,3,4,0]
- 输出: [-1,0,3,4,5]
题目思考
1. 如何做到 O(NlogN) 时间和 O(1) 空间?
解决方案
思路
- 迭代归并排序: 从长度 1 开始, 每次将相邻两段 (长度为 cnt) 归并
- 外层循环 cnt 从 1 倍增到 n; 内层循环遍历链表, 依次找到左右两段归并
- 归并时用哨兵节点连接, 注意断开各段末尾与后续的连接
复杂度
- 时间复杂度 O(NlogN): logN 次归并, 每次 O(N)
- 空间复杂度 O(1): 不使用递归栈
 */
#include "ListNode.h"

class Solution
{
    pair<ListNode *, ListNode *> mergeTwoLists(ListNode *h1, ListNode *h2)
    {
        ListNode dummy(0);
        ListNode *cur = &dummy;
        while (h1 || h2)
        {
            if (!h2 || (h1 && h1->val <= h2->val))
            {
                cur->next = h1; h1 = h1->next;
            }
            else
            {
                cur->next = h2; h2 = h2->next;
            }
            cur = cur->next;
        }
        return {dummy.next, cur};
    }
public:
    ListNode *sortList(ListNode *head)
    {
        int n = 0;
        for (ListNode *p = head; p; p = p->next) n++;
        ListNode dummy(0, head);
        for (int cnt = 1; cnt < n; cnt *= 2)
        {
            ListNode *ptail = &dummy;
            ListNode *cur = dummy.next;
            while (cur)
            {
                ListNode *lhead = cur;
                ListNode *ltail = cur;
                for (int i = 0; i < cnt - 1 && ltail->next; i++) ltail = ltail->next;
                cur = ltail->next;
                ltail->next = nullptr;
                ListNode *rhead = cur;
                ListNode *rtail = cur;
                if (rtail)
                {
                    for (int i = 0; i < cnt - 1 && rtail->next; i++) rtail = rtail->next;
                    cur = rtail->next;
                    rtail->next = nullptr;
                }
                auto [nh, nt] = mergeTwoLists(lhead, rhead);
                ptail->next = nh;
                ptail = nt;
            }
        }
        return dummy.next;
    }
};

int main()
{
    Solution sol;
    auto r1 = createListNode({4, 2, 1, 3});
    printListNode(sol.sortList(r1)); // 1 2 3 4
    auto r2 = createListNode({-1, 5, 3, 4, 0});
    printListNode(sol.sortList(r2)); // -1 0 3 4 5
    return 0;
}
