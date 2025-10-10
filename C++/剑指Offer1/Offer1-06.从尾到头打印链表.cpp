> 题目难度: 简单

> [原题链接](https://leetcode-cn.com/problems/cong-wei-dao-tou-da-yin-lian-biao-lcof/)

## 题目描述

输入一个链表的头节点，从尾到头反过来返回每个节点的值（用数组返回）。

0 <= 链表长度 <= 10000

## 题目样例

### 示例

#### 输入

head = [1,3,2]

#### 输出

[2,3,1]

## 题目思考

1. 如果限制只能用递归来做, 或者只能用迭代来做, 你能想到哪些方案?

## 解决方案

### 方案 1

#### 思路

- 从尾到头打印, 一个很自然的思路就是先按照头到尾的顺序遍历并保存到数组中, 最后将数组翻转即可

#### 复杂度

- 时间复杂度 `O(N)`
  - 链表中每个节点只需要遍历一遍
- 空间复杂度 `O(1)`
  - 只需要几个变量

#### 代码

```python{cmd="python"}
from typing import List
class ListNode:
    def __init__(self, x):
        self.val = x
        self.next = None
class Solution:
    def reversePrint(self, head: ListNode) -> List[int]:
        # 方法1: 正向遍历, 然后数组翻转
        result = []
        while head:
            result.append(head.val)
            head = head.next
        return result[::-1]
# 测试用例
head = ListNode(1)
head.next = ListNode(3)
head.next.next = ListNode(2)
print(Solution().reversePrint(head))
```

### 方案 2

#### 思路

- 如果此时题目多了个限制, 只能用递归来做, 我们就得利用递归的特性了

1. 先设计递归参数, 这里只需要传入节点本身即可, 因为只需要知道它自己的值
2. 然后定义递归出口, 很显然就是节点不存在时直接返回
3. 然后我们先尽可能向后调用递归函数, 直到到达递归出口
4. 最后再将当前节点加入结果中. 这样就保证尾部节点第一个加入结果中, 按照递归栈的顺序, 接下来是倒数第二个节点, 以此类推, 最终所有的节点都会按照从尾到头的顺序加入结果中

#### 复杂度

- 时间复杂度 `O(N)`
  - 链表中每个节点只需要遍历一遍
- 空间复杂度 `O(N)`
  - 递归的栈的消耗

#### 代码

```python
class Solution:
    def reversePrint(self, head: ListNode) -> List[int]:
        # 方法2: 递归
        res = []

        def addNode(node):
            if not node:
                # 递归出口, 当前node是None
                return
            # 先递归调用下一个节点
            addNode(node.next)
            # 此时后面的节点都已经按照从尾到头的顺序, 依次加入了res, 加入当前节点即可
            # 如果这一句和上一句交换位置, 那就变成了从头到尾的顺序了, 因为先遍历到的节点先加入res中
            res.append(node.val)
        # 初始传入头节点, 开始递归
        addNode(head)
        return res
```

### 方案 3

#### 思路

- 如果此时面试官再来个限制, 只能用迭代, 而且不允许数组翻转, 又该怎么做呢 (内心 OS: 面试官真难伺候 🤣)
- 回顾方案 2, 我们使用了递归来实现, 而递归本质上就是一个递归栈来保存整个调用链, 所以我们可以尝试引入一个栈来解决 (其实很多递归问题都可以通过改成栈来变成等价的迭代)
- 思路也很简单, 就是利用栈先进后出的性质

1. 从头遍历链表, 并将节点值加入栈里
2. 然后再循环 pop 栈里的所有值, 并按顺序加入结果中, 这样第一个加入的就是尾节点的值, 最后才是头节点, 保证从尾到头的顺序

#### 复杂度

- 时间复杂度 `O(N)`
  - 链表中每个节点只需要遍历两遍
- 空间复杂度 `O(N)`
  - 使用了一个长度为 N 的栈

#### 代码

```python
class Solution:
    def reversePrint(self, head: ListNode) -> List[int]:
        # 方法3: 使用辅助栈
        stack = []
        while head:
            # 先按顺序加入栈中
            stack.append(head)
            head = head.next
        res = []
        while stack:
            # 按照栈的pop顺序加入结果中
            res.append(stack.pop().val)
        return res
```

---
