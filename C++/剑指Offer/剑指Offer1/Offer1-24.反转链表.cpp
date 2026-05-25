/* > 题目难度: 简单

> [原题链接](https://leetcode-cn.com/problems/fan-zhuan-lian-biao-lcof/)
题目描述
定义一个函数，输入一个链表的头节点，反转该链表并输出反转后链表的头节点。
0 <= 节点个数 <= 5000
题目样例
示例
输入
1->2->3->4->5->NULL
输出
5->4->3->2->1->NULL
题目思考

1. 如果限制只能用递归或者迭代, 如何解决?

解决方案

方案 1

思路

- 首先考虑迭代做法, 要反转链表, 我们至少需要两个指针才能做到, 否则反转的时候不知道应该指向哪里
- 所以保存前一个节点 pre 和当前节点 cur, 并记录 cur 的下一个节点 nex, 每次都将当前节点指向前一个节点, 然后 pre 和 cur 都往后移动一位即可 (即 pre = cur, cur = nex)
- 注意边界条件: 没有节点的情况, 以及对 head 的 next 的处理

复杂度

- 时间复杂度 `O(N)`
  - 只需要遍历一遍链表
- 空间复杂度 `O(1)`
  - 只需要常数个变量

方案 2

思路

- 接下来我们考虑如何用递归来做这道题
- 如果我们能够得到当前节点之后的节点反转后的链表, 那么只需要将新链表的尾指向当前节点, 同时将当前节点指向空, 就完成了对当前节点的反转
- 所以额外定义一个方法, 传入当前节点, 返回一个二元组: (反转后的链表头, 反转后的链表尾), 然后按照上述操作即可

复杂度

- 时间复杂度 `O(N)`
  - 每个节点只需要访问一次
- 空间复杂度 `O(N)`
  - 递归的栈的消耗

方案 3

思路

- 回顾递归方案 2, 我们不仅需要返回反转后的链表头, 也需要返回链表尾. 如果可以只返回头, 就不需要额外定义新方法了
- 注意反转的过程, 当前节点的 next 在之后节点反转结束后对应的就是反转链表的结尾, 也即方案 2 的 nextTail, 这样我们就可以利用这一性质去掉链表尾这一返回值了
- 该方案是基于方案 2 优化推导得来的, 没有方案 2 直观, 理解起来也有一些难度, 但胜在代码更简洁

复杂度

- 时间复杂度 `O(N)`
  - 每个节点只需要访问一次
- 空间复杂度 `O(N)`
  - 递归的栈的消耗
*/
#include "ListNode.h"

class Solution
{
public:
  ListNode *reverseList(ListNode *head)
  {
    // 方法 1: 迭代, 双指针
    if (!head)
      return head;
    ListNode *pre = head;
    ListNode *cur = head->next;
    // head 变成了翻转后的末尾, 所以其 next 要置为空
    head->next = nullptr;
    while (cur)
    {
      // 先存下 cur 的下一个节点
      ListNode *nex = cur->next;
      // cur 的下一个节点指向 pre, 完成当前节点指向的反转
      cur->next = pre;
      // 更新 pre 和 cur, 分别按照原链表顺序往后移动一位
      pre = cur;
      cur = nex;
    }
    // 最终 cur 就是空, 而 pre 则是反转后的开头节点
    return pre;
  }
};

int main()
{
  Solution s;

  // 示例: 1->2->3->4->5->NULL, 期望输出 5->4->3->2->1->NULL
  ListNode *head1 = createListNode({1, 2, 3, 4, 5});
  ListNode *res1 = s.reverseList(head1);
  printListNode(res1); // 5 -> 4 -> 3 -> 2 -> 1

  // 空链表
  ListNode *res2 = s.reverseList(nullptr);
  printListNode(res2); // (empty)

  // 单节点
  ListNode *head3 = createListNode({1});
  ListNode *res3 = s.reverseList(head3);
  printListNode(res3); // 1

  return 0;
}
