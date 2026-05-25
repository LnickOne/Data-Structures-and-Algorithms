from collections import deque
from typing import List
# 可以用队列这个数据结构生成链表


class LinkedListTest:
    def LinkedList(self) -> None:
        # 创建一个链表
        LinkedList = deque()

        # 添加元素
        # 时间复杂度为O(1)
        LinkedList.append(1)
        LinkedList.append(2)
        LinkedList.append(3)
        # [1,2,3]
        print(LinkedList)

        # 插入元素
        # 时间复杂度为:O(N)
        LinkedList.insert(2, 99)
        # [1,2,99,3]
        print(LinkedList)

        # 访问元素
        # 时间复杂度为O(N)
        element = LinkedList[2]
        # 99
        print(element)

        # 寻找元素
        # 时间复杂度为O(N)
        index = LinkedList.index(99)
        # 2
        print(LinkedList)

        # 删除元素
        # 时间复杂度为O(1)
        length = len(LinkedList)
        # 3
        print(length)


class ListNode(object):
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next


def CreateLinkedList(nums: List[int]) -> ListNode:
    # 生成头节点
    head = ListNode(nums[0])
    # 生成虚拟节点
    VirNode = ListNode
    # 虚拟节点指向头节点
    VirNode = head
    for i in range(1, len(nums)):
        # 生成新节点
        Node = ListNode(nums[i])
        # dummy.next指向新节点
        VirNode.next = Node
        # dummy指向dummy.next
        VirNode = VirNode.next
    # for循环结束dummy 指向head
    VirNode = head
    return VirNode


if __name__ == '__main__':
    linkedlist = LinkedListTest()
    linkedlist.LinkedList()
