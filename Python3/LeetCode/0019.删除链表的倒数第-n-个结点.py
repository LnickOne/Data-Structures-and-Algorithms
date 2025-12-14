#
# @lc app=leetcode.cn id=19 lang=python3
#
# [19] 删除链表的倒数第 N 个结点
#

# @lc code=start
# Definition for singly-linked list.
from typing import Optional


class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next


def printListNode(head):
    temp = head
    while temp:
        print(temp.val, end=" ")
        temp = temp.next
    print()


class Solution:
    def removeNthFromEnd(self, head: Optional[ListNode], n: int) -> Optional[ListNode]:
        dummy = ListNode()
        dummy.next = head
        fast = dummy
        slow = dummy
        n += 1
        while n > 0:
            fast = fast.next
            n -= 1
        while fast:
            fast = fast.next
            slow = slow.next
        slow.next = slow.next.next
        return dummy.next


printListNode(
    Solution().removeNthFromEnd(
        ListNode(1, ListNode(2, ListNode(3, ListNode(4, ListNode(5))))), 2
    )
)
printListNode(Solution().removeNthFromEnd(ListNode(1), 1))
printListNode(Solution().removeNthFromEnd(ListNode(1, ListNode(2)), 1))
printListNode(Solution().removeNthFromEnd(ListNode(1, ListNode(2)), 2))
printListNode(Solution().removeNthFromEnd(ListNode(1, ListNode(2, ListNode(3))), 3))

# @lc code=end
