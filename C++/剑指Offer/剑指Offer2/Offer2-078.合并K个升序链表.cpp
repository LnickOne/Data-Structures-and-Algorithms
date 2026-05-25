/* 题目难度: 困难
[原题链接](https://leetcode.cn/problems/vvXgSW/)
题目描述
给定链表数组, 每个链表已按升序排列。将所有链表合并到一个升序链表中并返回。
题目样例
示例1
- 输入: lists = [[1,4,5],[1,3,4],[2,6]]
- 输出: [1,1,2,3,4,4,5,6]
示例2
- 输入: lists = []
- 输出: []
题目思考
1. 如何尽可能优化时间复杂度?
解决方案
思路
- 分治归并: 递归将链表数组 [s, e] 二分, 分别归并左右两半后再将结果合并
- 两个有序链表归并: 哨兵节点 + 双指针
复杂度
- 时间复杂度 O(NKlogK): K 个链表, 每个平均 N 个节点, logK 次归并
- 空间复杂度 O(logK): 递归栈
 */
#include "../剑指Offer1/ListNode.h"
#include <vector>

class Solution
{
    ListNode *mergeTwo(ListNode *h1, ListNode *h2)
    {
        ListNode dummy(0);
        ListNode *cur = &dummy;
        while (h1 || h2)
        {
            if (!h2 || (h1 && h1->val <= h2->val))
            {
                cur->next = h1;
                h1 = h1->next;
            }
            else
            {
                cur->next = h2;
                h2 = h2->next;
            }
            cur = cur->next;
        }
        return dummy.next;
    }
    ListNode *merge(vector<ListNode *> &lists, int s, int e)
    {
        if (s > e)
            return nullptr;
        if (s == e)
            return lists[s];
        int m = (s + e) / 2;
        return mergeTwo(merge(lists, s, m), merge(lists, m + 1, e));
    }

public:
    ListNode *mergeKLists(vector<ListNode *> &lists)
    {
        return merge(lists, 0, (int)lists.size() - 1);
    }
};

int main()
{
    Solution sol;
    auto l1 = createListNode({1, 4, 5});
    auto l2 = createListNode({1, 3, 4});
    auto l3 = createListNode({2, 6});
    vector<ListNode *> lists = {l1, l2, l3};
    printListNode(sol.mergeKLists(lists)); // 1 1 2 3 4 4 5 6
    vector<ListNode *> empty = {};
    cout << (sol.mergeKLists(empty) == nullptr ? "null" : "non-null") << endl; // null
    return 0;
}
