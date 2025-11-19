> 题目难度: 中等

> [原题链接](https://leetcode-cn.com/problems/cong-shang-dao-xia-da-yin-er-cha-shu-lcof/)

## 题目描述

从上到下打印出二叉树的每个节点，同一层的节点按照从左到右的顺序打印。

- 节点总数 <= 1000

## 题目样例

### 示例

#### 输入

给定二叉树: [3,9,20,null,null,15,7],

```
    3
   / \
  9  20
    /  \
   15   7
```

#### 输出

[3,9,20,15,7]

## 题目思考

1. 哪些数据结构可以做到按层输出?

## 解决方案

### 思路

- 经典的 BFS 思路, 将当前节点的左右非空子节点追加到队列结尾, 然后继续往后遍历队列, 最终整个队列就是最后的结果
- 由于这里是树, 所以每个节点只可能被加入队列访问一次, 无需额外的 visit 集合
- 另外这道题不需要分开保存每一层的节点, 所以这里不需要记录当前层的长度之类的情况, 可以直接一次循环搞定
- 数据结构方面, 可以采用列表 + 动态的 for 循环(python 3 适用, 其他语言可能不支持遍历过程中更改容器)或者双端队列 + while 循环(所有语言通用, 每次 pop 最左边的元素作为当前节点)
- 下面的代码是个人觉得比较通用的 BFS 模板, 包括列表和双端队列两种方式的实现, 适用于不需要单独处理每一层节点的情况, 供大家参考

### 复杂度

- 时间复杂度 `O(N)`
  - 每个节点只需要遍历一次
- 空间复杂度 `O(N)`
  - 额外需要一个列表/双端队列

### 代码

#### 方案 1 - 列表 + for 循环

```python
class Solution:
    def levelOrder(self, root: TreeNode) -> List[int]:
        # 方案1: 列表+for循环
        if not root:
            return []
        q = [root]
        for node in q:
            # 只将非空子节点追加到队列
            if node.left:
                q.append(node.left)
            if node.right:
                q.append(node.right)
        return [x.val for x in q]
```

#### 方案 2 - 双端队列 + while 循环

```python
import collections

class Solution:
    def levelOrder(self, root: TreeNode) -> List[int]:
        # 方案2: 双端队列+while循环
        if not root:
            return []
        q = collections.deque([root])
        res = []
        while q:
            node = q.popleft()
            res.append(node.val)
            if node.left:
                q.append(node.left)
            if node.right:
                q.append(node.right)
        return res
```

