> 题目难度: 简单

> [原题链接](https://leetcode-cn.com/problems/er-cha-shu-de-shen-du-lcof/)

## 题目描述

输入一棵二叉树的根节点，求该树的深度。从根节点到叶节点依次经过的节点（含根、叶节点）形成树的一条路径，最长路径的长度为树的深度。

- 节点总数 <= 10000

## 题目样例

### 示例

```
给定二叉树 [3,9,20,null,null,15,7]，

    3
   / \
  9  20
    /  \
   15   7
返回它的最大深度 3 。
```

## 题目思考

1. 如果限制只能用递归或者迭代, 如何解决?

## 解决方案

### 方案 1

#### 思路

- 先考虑递归做法, 尝试 DFS
- 我们可以这样构造递归方法: 传入节点, 返回当前节点的深度, 该深度是左右子树的最大深度+1
- 假设叶子节点的深度为 1, 显然根节点的深度就是整个树的最大深度了
- 递归出口即节点为空的情况, 此时深度为 0

#### 复杂度

- 时间复杂度 O(N): 需要遍历整个树
- 空间复杂度 O(H): H 表示树的高度, 也即递归的栈的消耗

#### 代码

```python
class Solution:
    def maxDepth(self, root: TreeNode) -> int:
        if not root:
            # 递归出口, 空节点的情况
            return 0
        # 当前节点深度是左右子树的最大深度+1
        return 1 + max(self.maxDepth(root.left), self.maxDepth(root.right))
        # 也可以进一步简化为只需要一行代码..
        # return 0 if not root else 1 + max(self.maxDepth(root.left), self.maxDepth(root.right))
```

### 方案 2

#### 思路

- 如果要求必须用迭代方式实现, 那方案 1 就不行了
- 迭代一般可以先尝试 BFS, 这道题也不例外
- 通过分析题目, 显然这里的深度就是指 BFS 的层数, 所以完全可以利用[剑指 Offer 32 - II. 从上到下打印二叉树 II - leetcode 剑指 offer 系列](https://mp.weixin.qq.com/s?__biz=MzA5MDk1MjI5MA==&mid=2247484055&idx=1&sn=eb46c80176a468ea276ea3746978b501&chksm=9002859aa7750c8c0a010b5df67f411b538d791d5600946773fae1dcecefe3a96e46c115c4f4&token=44591176&lang=zh_CN#rd)的做法得出层数, 只是不需要打印出每一层的节点, 只需要统计层数即可. 不清楚的同学可以先看看那道题的思路~
- 下面代码对必要的步骤有详细的解释, 方便大家理解

#### 复杂度

- 时间复杂度 O(N): 需要遍历整个树
- 空间复杂度 O(N): 队列的空间消耗

#### 代码

```python
class Solution:
    def maxDepth(self, root: TreeNode) -> int:
        if not root:
            return 0
        q = [root]
        res = 0
        while q:
            # 当前层节点数目
            curlen = len(q)
            for node in q[:curlen]:
                # 只追加非空子节点
                if node.left:
                    q.append(node.left)
                if node.right:
                    q.append(node.right)
            # 队列切片, 开始处理下一层
            q = q[curlen:]
            # 当前层遍历完毕, 深度+1
            res += 1
        return res
```
