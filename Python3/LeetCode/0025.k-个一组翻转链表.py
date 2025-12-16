#
# @lc app=leetcode.cn id=25 lang=python3
#
# [25] K 个一组翻转链表
#
# https://leetcode.cn/problems/reverse-nodes-in-k-group/description/
#
# algorithms
# Hard (69.91%)
# Likes:    2707
# Dislikes: 0
# Total Accepted:    955.1K
# Total Submissions: 1.4M
# Testcase Example:  '[1,2,3,4,5]\n2'
#
# 给你链表的头节点 head ，每 k 个节点一组进行翻转，请你返回修改后的链表。
#
# k 是一个正整数，它的值小于或等于链表的长度。如果节点总数不是 k 的整数倍，那么请将最后剩余的节点保持原有顺序。
#
# 你不能只是单纯的改变节点内部的值，而是需要实际进行节点交换。
#
#
#
# 示例 1：
#
#
# 输入：head = [1,2,3,4,5], k = 2
# 输出：[2,1,4,3,5]
#
#
# 示例 2：
#
#
#
#
# 输入：head = [1,2,3,4,5], k = 3
# 输出：[3,2,1,4,5]
#
#
#
# 提示：
#
#
# 链表中的节点数目为 n
# 1 <= k <= n <= 5000
# 0 <= Node.val <= 1000
#
#
#
#
# 进阶：你可以设计一个只用 O(1) 额外内存空间的算法解决此问题吗？
#
#
#
#
#

# @lc code=start
# Definition for singly-linked list.
from typing import Optional


def printListNode(head):
    temp = head
    while temp:
        print(temp.val, end=" ")
        temp = temp.next
    print()


class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next


class Solution:
    def reverseKGroup(self, head: Optional[ListNode], k: int) -> Optional[ListNode]:
        # 迭代方法实现，空间复杂度O(1)
        # 创建虚拟头节点，简化边界条件处理
        dummy = ListNode(0)
        dummy.next = head
        pre_group = dummy
        while True:
            # 检查剩余节点是否足够k个
            kth = pre_group
            for _ in range(k):
                kth = kth.next
                if not kth:
                    return dummy.next  # 不足k个，直接返回结果
            # 记录下一组的头部
            next_group_head = kth.next
            # 翻转当前k个节点
            pre, cur = kth.next, pre_group.next
            while cur != next_group_head:
                next_node = cur.next
                cur.next = pre
                pre = cur
                cur = next_node
            # 将翻转后的组与前一组连接
            # 先记录当前组翻转后的尾部（即原头部）
            cur_group_tail = pre_group.next
            # 连接前一组与当前组翻转后的头部
            pre_group.next = pre
            # 移动pre_group到当前组的尾部，为下一次循环做准备
            pre_group = cur_group_tail
        return dummy.next


printListNode(
    Solution().reverseKGroup(
        ListNode(1, ListNode(2, ListNode(3, ListNode(4, ListNode(5))))), 2
    )
)
printListNode(
    Solution().reverseKGroup(
        ListNode(1, ListNode(2, ListNode(3, ListNode(4, ListNode(5))))), 3
    )
)


# @lc code=end
