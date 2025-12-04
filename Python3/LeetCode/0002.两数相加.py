#
# @lc app=leetcode.cn id=2 lang=python3
#
# [2] 两数相加
#

# @lc code=start
# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
from typing import Optional


class ListNode:
    def __init__(self, val, next=None):
        self.val = val
        self.next = next


def printListNode(head):
    temp = head
    while temp:
        print(temp.val, end=" ")
        temp = temp.next
    print()


class Solution:
    def addTwoNumbers(
        self, l1: Optional[ListNode], l2: Optional[ListNode]
    ) -> Optional[ListNode]:
        dummy = ListNode(0, None)
        cur = dummy
        sum = 0
        quotient = 0
        remainder = 0
        carry = 0
        while l1 and l2:
            sum = l1.val + l2.val + carry
            quotient = sum // 10
            remainder = sum % 10
            carry = quotient
            cur.next = ListNode(remainder, None)
            cur = cur.next
            l1 = l1.next
            l2 = l2.next
        while l1:
            sum = l1.val + carry
            quotient = sum // 10
            remainder = sum % 10
            carry = quotient
            cur.next = ListNode(remainder, None)
            cur = cur.next
            l1 = l1.next
        while l2:
            sum = l2.val + carry
            quotient = sum // 10
            remainder = sum % 10
            carry = quotient
            cur.next = ListNode(remainder, None)
            cur = cur.next
            l2 = l2.next
        if carry != 0:
            cur.next = ListNode(carry, None)
        return dummy.next


l1 = ListNode(2, ListNode(4, ListNode(3, None)))
l2 = ListNode(5, ListNode(6, ListNode(4, None)))
result = Solution().addTwoNumbers(l1, l2)
printListNode(result)
# @lc code=end
