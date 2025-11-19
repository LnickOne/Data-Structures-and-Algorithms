/*
给你两个 非空 的链表，表示两个非负的整数。
它们每位数字都是按照 逆序 的方式存储的，并且每个节点只能存储 一位 数字。
请你将两个数相加，并以相同形式返回一个表示和的链表。
你可以假设除了数字 0 之外，这两个数都不会以 0 开头。
输入：l1 = [2,4,3], l2 = [5,6,4]
输出：[7,0,8]
解释：342 + 465 = 807.
示例 2：
输入：l1 = [0], l2 = [0]
输出：[0]
示例 3：
输入：l1 = [9,9,9,9,9,9,9], l2 = [9,9,9,9]
输出：[8,9,9,9,0,0,0,1]
 */
#include "ListNode.h"

class Solution
{
public:
  ListNode *addTwoNumbers(ListNode *l1, ListNode *l2)
  {
    ListNode *dummy = new ListNode(0);
    ListNode *cur = dummy;
    int sum;       // 两数之和
    int quotient;  // 商数
    int remainder; // 余数
    int carry = 0; // 进位
    while (l1 && l2)
    {
      sum = l1->val + l2->val + carry;
      quotient = sum / 10;                      // 商数
      remainder = sum % 10;                     // 余数
      ListNode *node = new ListNode(remainder); // 余数作为新节点的值
      carry = quotient;                         // 商数作为进位
      cur->next = node;
      cur = cur->next;
      l1 = l1->next;
      l2 = l2->next;
    }
    while (l1)
    {
      sum = l1->val + carry;
      quotient = sum / 10;
      remainder = sum % 10;
      ListNode *node = new ListNode(remainder); // 余数作为新节点的值
      carry = quotient;                         // 商数作为进位
      cur->next = node;
      cur = cur->next;
      l1 = l1->next;
    }
    while (l2)
    {
      sum = l2->val + carry;
      quotient = sum / 10;
      remainder = sum % 10;
      ListNode *node = new ListNode(remainder); // 余数作为新节点的值
      carry = quotient;                         // 商数作为进位
      cur->next = node;
      cur = cur->next;
      l2 = l2->next;
    }
    if (carry != 0)
    {
      ListNode *node = new ListNode(carry); // carry不为0则说明还有进位,将carry作为新节点的值
      cur->next = node;
      cur = cur->next;
    }
    return dummy->next;
  }
};
int main()
{
  Solution s;
  ListNode *l1 = createListNode({2, 4, 3});
  ListNode *l2 = createListNode({5, 6, 4});
  ListNode *l3 = createListNode({9, 9, 9, 9, 9, 9, 9});
  ListNode *l4 = createListNode({9, 9, 9, 9});
  ListNode *res = s.addTwoNumbers(l1, l2);
  ListNode *res1 = s.addTwoNumbers(l3, l4);
  printListNode(res);
  printListNode(res1);
  return 0;
}
