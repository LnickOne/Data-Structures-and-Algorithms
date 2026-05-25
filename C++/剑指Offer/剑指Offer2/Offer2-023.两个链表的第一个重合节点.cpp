/* 题目难度: 简单
[原题链接](https://leetcode.cn/problems/3u1WK4)
题目描述
输入两个链表的头节点, 找出它们的第一个公共节点并返回。如果没有公共节点则返回 null。
链表中均无环, 不能修改链表。
题目样例
示例1
- 输入: listA = [4,1,8,4,5], listB = [5,0,1,8,4,5], 交叉于 val=8 的节点
- 输出: 返回 val = 8 的节点
示例2
- 输入: listA = [2,6,4], listB = [1,5], 无交叉
- 输出: null
题目思考
1. 如何设计 O(N) 时间 O(1) 空间的解法?
解决方案
思路
- 利用路径等长的对称性: 指针 a 走完 A 后走 B, 指针 b 走完 B 后走 A
- 两者路径总长都是 lenA + lenB, 若有公共节点则必在该节点相遇
- 若无公共节点, 两者同时到达各自的 null 相遇 (均为 null 则 a==b 退出循环)
- 关键: 走到末尾后要先进入 null 再切换, 即 a = (a ? a->next : headB)
复杂度
- 时间复杂度 O(M+N): 各自最多遍历两次
- 空间复杂度 O(1): 只使用了几个常数空间的变量
 */
#include "../剑指Offer1/ListNode.h"

class Solution
{
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB)
    {
        ListNode *a = headA, *b = headB;
        while (a != b)
        {
            a = a ? a->next : headB;
            b = b ? b->next : headA;
        }
        return a;
    }
};

int main()
{
    Solution s;
    // 示例1: A=[4,1]+common, B=[5,0,1]+common, common=[8,4,5]
    ListNode *common = createListNode({8, 4, 5});
    ListNode *a1 = new ListNode(4);
    ListNode *a2 = new ListNode(1);
    a1->next = a2; a2->next = common;
    ListNode *b1 = new ListNode(5);
    ListNode *b2 = new ListNode(0);
    ListNode *b3 = new ListNode(1);
    b1->next = b2; b2->next = b3; b3->next = common;
    ListNode *res = s.getIntersectionNode(a1, b1);
    cout << (res ? res->val : -1) << endl; // 8
    // 释放
    a2->next = nullptr; delete a1; delete a2;
    b3->next = nullptr; delete b1; delete b2; delete b3;
    deleteList(common);
    // 示例2: 无交叉
    ListNode *la = createListNode({2, 6, 4});
    ListNode *lb = createListNode({1, 5});
    cout << (s.getIntersectionNode(la, lb) ? "有" : "null") << endl; // null
    deleteList(la); deleteList(lb);
    return 0;
}
