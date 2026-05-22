> 题目难度: 中等

> [原题链接](https://leetcode.cn/problems/c32eOV)

## 题目描述

给定一个链表，返回链表开始入环的第一个节点。 从链表的头节点开始沿着 next 指针进入环的第一个节点为环的入口节点。如果链表无环，则返回  null。

为了表示给定链表中的环，我们使用整数 pos 来表示链表尾连接到链表中的位置（索引从 0 开始）。 如果 pos 是 -1，则在该链表中没有环。注意，pos 仅仅是用于标识环的情况，并不会作为参数传递到函数中。

说明：不允许修改给定的链表。

### 示例 1：

![](https://assets.leetcode-cn.com/aliyun-lc-upload/uploads/2018/12/07/circularlinkedlist.png)

- 输入：head = [3,2,0,-4], pos = 1
- 输出：tail connects to node index 1
- 解释：链表中有一个环，其尾部连接到第二个节点。

### 示例 2：

![](https://assets.leetcode-cn.com/aliyun-lc-upload/uploads/2018/12/07/circularlinkedlist_test2.png)

- 输入：head = [1,2], pos = 0
- 输出：tail connects to node index 0
- 解释：链表中有一个环，其尾部连接到第一个节点。

### 示例 3：

![](https://assets.leetcode-cn.com/aliyun-lc-upload/uploads/2018/12/07/circularlinkedlist_test3.png)

- 输入：head = [1], pos = -1
- 输出：no cycle
- 解释：链表中没有环。

### 提示：

- 链表中节点的数目范围在范围 [0, 10^4] 内
- -10^5 <= Node.val <= 10^5
- pos 的值为 -1 或者链表中的一个有效索引

## 题目思考

1. 如何使用 O(1) 空间解决此题?

## 解决方案

#### 思路

- 一个比较容易想到的思路将节点存到集合里面, 然后如果遍历到已经在集合的节点, 就说明存在环, 但这样使用了额外空间, 如何做到不使用额外空间呢?
- 将链表想象成一个跑道, 其中属于环的部分是圆形跑道, 不属于环的部分是直线跑道. 假设有两个人同时从跑道起点出发且速度不同, 什么情况下两人会再次相遇呢?
- 如果跑道没有环, 那么慢的那个人永远追不上快的, 自然不会再次相遇; 但如果有环, 那么总有一个时刻两个人会在环的某个点相遇, 此时快的那个人领先若干圈
- 所以我们可以采用快慢指针的方法, **快指针每次走两步, 慢指针每次走一步, 如果两个指针能相遇, 则说明存在环; 否则如果快指针先到达终点(即空节点), 则说明无环**
- 接下来考虑如何求环的起点:
  - 找到交点后, 设 head 到环的起点的距离为 x, 环的起点到两个指针交点的距离为 y, 交点继续往后走到环的起点的距离为 z, 慢指针达到交点时走了 m 圈完整的环, 快指针达到交点时走了 n 圈完整的环
  - 显然有 `2(x+y+m(y+z)) = x+y+n(y+z)`, 进而得到`x=(n-2m-1)(y+z) + z`, 也就是说, x 相当于 z 加上若干圈完整的环的距离.
  - 所以我们可以将指针 a 重新指向链表头, 指针 b 保持在交点不变, 然后两指针每次往前走一步, 那么当 a 走了 x 步到达环路起点时, b 必定走了 z 加若干圈完整的环的距离, 恰好也到了环的起点, 也就是两指针重新出发后第一次相遇的位置, 这样就得到了题目答案

#### 复杂度

- 时间复杂度 O(N): 只需要遍历每个节点常数遍
- 空间复杂度 O(1): 只使用了几个常数空间的变量

#### 代码

```python
class Solution:
    def detectCycle(self, head: ListNode) -> ListNode:
        # 经典快慢指针
        # 注意环路起点的求法:
        #   找到相等的节点后
        #   其中一个指针重新变成head
        #   然后和另一个指针每次+1
        #   直到再次相交, 该点即为环路起点
        # 证明:
        #   设head到起点为x, 起点到第一次交点为y, 第一次交点到环起点为z
        #   那么2(x+y+m(y+z)) = x+y+n(y+z) (n和m是快慢指针经过环的次数)
        #   那么x+y = (n-2m)(y+z) (n-2m>0)
        #   那么x = (n-2m-1)(y+z) + z (n-2m-1>=0)
        #   即新的头指针经过x步和原来在第一个交点的指针经过x步(可能又走了n-2m-1个环, 加上交点到起点的距离z)所处的位置一定都是环路起点
        slow, fast = head, head
        while fast:
            slow = slow.next
            fast = fast.next
            if fast:
                fast = fast.next
            if not fast:
                # 没有环
                return None
            if fast == slow:
                break
        slow = head
        while slow != fast:
            slow = slow.next
            fast = fast.next
        return slow
```
