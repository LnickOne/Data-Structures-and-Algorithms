/* 题目难度: 简单
[原题链接](https://leetcode.cn/problems/aMhZSa)
题目描述
给定一个链表的头节点 head, 请判断其是否为回文链表。
题目样例
示例1
- 输入: head = [1,2,3,3,2,1]
- 输出: true
示例2
- 输入: head = [1,2]
- 输出: false
题目思考
1. 能否用 O(N) 时间 O(1) 空间实现?
解决方案
思路
- 朴素做法: 将链表值存入数组再用双指针判断, O(N) 时间 O(N) 空间
- O(1) 空间优化:
  1. 快慢指针找中点 (奇数长度慢指针停在正中, 偶数长度停在左中)
  2. 反转后半链表
  3. 从头和后半各一指针向中间对比, 有不等则非回文
  4. (可选) 再次反转后半恢复链表
复杂度
- 时间复杂度 O(N): 三次遍历
- 空间复杂度 O(1): 只使用了几个常数空间的变量
 */
#include "../剑指Offer1/ListNode.h"

class Solution
{
    ListNode *reverse(ListNode *head)
    {
        ListNode *pre = nullptr, *cur = head;
        while (cur)
        {
            ListNode *nex = cur->next;
            cur->next = pre;
            pre = cur;
            cur = nex;
        }
        return pre;
    }
public:
    bool isPalindrome(ListNode *head)
    {
        // 找中点
        ListNode *fast = head, *slow = head;
        while (fast && fast->next)
        {
            fast = fast->next->next;
            slow = slow->next;
        }
        // 反转后半
        ListNode *right = reverse(slow);
        ListNode *rightHead = right;
        ListNode *left = head;
        bool res = true;
        while (right)
        {
            if (left->val != right->val) { res = false; break; }
            left = left->next;
            right = right->next;
        }
        reverse(rightHead); // 恢复
        return res;
    }
};

int main()
{
    Solution s;
    cout << boolalpha;
    auto r1 = createListNode({1, 2, 3, 3, 2, 1});
    cout << s.isPalindrome(r1) << endl; // true
    deleteList(r1);
    auto r2 = createListNode({1, 2});
    cout << s.isPalindrome(r2) << endl; // false
    deleteList(r2);
    auto r3 = createListNode({1});
    cout << s.isPalindrome(r3) << endl; // true
    deleteList(r3);
    return 0;
}
