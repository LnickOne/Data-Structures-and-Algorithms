/* 题目难度: 中等
[原题链接](https://leetcode.cn/problems/lMSNwu)
题目描述
给定两个非空链表 l1 和 l2 来代表两个非负整数, 数字最高位在链表头部, 每个节点存储一位数字。
将两数相加并以相同形式返回一个链表 (不包含前导零, 零本身除外)。
题目样例
示例1
- 输入: l1 = [7,2,4,3], l2 = [5,6,4]
- 输出: [7,8,0,7]
示例2
- 输入: l1 = [2,4,3], l2 = [5,6,4]
- 输出: [8,0,7]
示例3
- 输入: l1 = [0], l2 = [0]
- 输出: [0]
题目思考
1. 若不能翻转链表, 如何处理?
解决方案
思路
- 数字最高位在链表头, 需要从最低位 (链表尾) 开始相加, 类似二进制加法 (Offer2-002)
- 用两个栈分别存储 l1 和 l2 的所有节点值, 栈顶即为最低位
- 每次从两个栈顶取值相加并维护进位, 创建新节点头插到结果链表
- 循环直到两栈都空且进位为 0
复杂度
- 时间复杂度 O(M+N): M 和 N 分别是两个链表的长度
- 空间复杂度 O(M+N): 两个栈各自存储对应链表的所有值
 */
#include "../剑指Offer1/ListNode.h"
#include <stack>

class Solution
{
public:
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2)
    {
        stack<int> s1, s2;
        for (ListNode *p = l1; p; p = p->next) s1.push(p->val);
        for (ListNode *p = l2; p; p = p->next) s2.push(p->val);
        ListNode *res = nullptr;
        int carry = 0;
        while (!s1.empty() || !s2.empty() || carry)
        {
            int left = 0, right = 0;
            if (!s1.empty()) { left = s1.top(); s1.pop(); }
            if (!s2.empty()) { right = s2.top(); s2.pop(); }
            int sm = left + right + carry;
            carry = sm / 10;
            ListNode *node = new ListNode(sm % 10, res);
            res = node;
        }
        return res;
    }
};

int main()
{
    Solution s;
    auto r1 = s.addTwoNumbers(createListNode({7, 2, 4, 3}), createListNode({5, 6, 4}));
    printListNode(r1); // 7 8 0 7
    deleteList(r1);
    auto r2 = s.addTwoNumbers(createListNode({2, 4, 3}), createListNode({5, 6, 4}));
    printListNode(r2); // 8 0 7
    deleteList(r2);
    auto r3 = s.addTwoNumbers(createListNode({0}), createListNode({0}));
    printListNode(r3); // 0
    deleteList(r3);
    return 0;
}
