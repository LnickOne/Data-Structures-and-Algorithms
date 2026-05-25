/* > 题目难度: 简单

> [原题链接](https://leetcode-cn.com/problems/he-bing-liang-ge-pai-xu-de-lian-biao-lcof/)

题目描述

输入两个递增排序的链表，合并这两个链表并使新链表中的节点仍然是递增排序的。

- 0 <= 链表长度 <= 1000

题目样例

示例

输入

1->2->4, 1->3->4

输出

1->1->2->3->4->4

题目思考

1. 如果限制只能用递归或者迭代, 如何解决?

解决方案

方案 1

思路

- 一个很自然的思路就是采用类似归并排序的做法, 只是把原算法中数组下标转换成这里的链表指针即可
- 循环结束条件是两个指针都指向空, 只要有一个不为空, 那就继续循环, 追加到当前节点中即可
- 这里额外引入一个哨兵节点 prehead, 用于统一各种边界条件, 例如 l1 和 l2 都不存在的情况, 从而简化代码

复杂度

- 时间复杂度 `O(M+N)`
  - 两个链表的每个节点都只需要访问一次
- 空间复杂度 `O(1)`
  - 只使用了常数个变量

方案 2

思路

- 接下来我们考虑如何用递归来做这道题
- 我们先尝试能否直接使用题目给的方法作为递归方法本身, 也即传入两个节点, 返回它们合并后的链表的头
- 首先定义递归出口
  - 自然就是 l1 或者 l2 不存在的情况, 这时候就返回另一个指针即可, 因为任何链表和空链表合并都是它自身
- 然后写递归内部调用逻辑
  - 当 l1 和 l2 都存在的时候, 就要判断其头节点的大小关系了
  - 小的那个节点(这里记为 small)可以进行递归调用, 传入其下个节点 (small.next) 和另一个节点(这里记为 big), 从而得到两者合并后的链表头
  - 根据递归方法本身定义, 这里合并后的链表就是有序的, 那么 small 只需要指向该链表头即可, 这样整个链表仍然有序
  - 最终 small 也正好就是递归的返回值, 也即 small 和 big 合并后的链表头

复杂度
- 时间复杂度 `O(M+N)`
  - 两个链表的每个节点都只需要访问一次
- 空间复杂度 `O(M+N)`
  - 递归的栈的消耗
*/
#include "ListNode.h"

class Solution
{
public:
  ListNode *mergeTwoLists(ListNode *l1, ListNode *l2)
  {
    // 方法 1: 迭代, 哨兵节点, 归并排序思路
    ListNode prehead(0);
    ListNode *cur = &prehead;
    while (l1 || l2)
    {
      if (!l1 || (l2 && l2->val <= l1->val))
      {
        // 该情况要么是只有 l2 节点, 要么 l2 节点值更小
        cur->next = l2;
        l2 = l2->next;
      }
      else
      {
        // 否则的话当前的下个节点只能是 l1
        cur->next = l1;
        l1 = l1->next;
      }
      cur = cur->next;
    }
    // 哨兵节点的 next 就是合并后的链表头
    return prehead.next;
  }
};

int main()
{
  Solution s;

  // 示例: 1->2->4 与 1->3->4, 期望输出 1->1->2->3->4->4
  ListNode *l1 = createListNode({1, 2, 4});
  ListNode *l2 = createListNode({1, 3, 4});
  ListNode *res1 = s.mergeTwoLists(l1, l2);
  printListNode(res1); // 1 -> 1 -> 2 -> 3 -> 4 -> 4

  // 其中一个为空
  ListNode *l3 = createListNode({1, 3, 5});
  ListNode *res2 = s.mergeTwoLists(l3, nullptr);
  printListNode(res2); // 1 -> 3 -> 5

  // 两个都为空
  ListNode *res3 = s.mergeTwoLists(nullptr, nullptr);
  printListNode(res3); // (empty)

  return 0;
}
