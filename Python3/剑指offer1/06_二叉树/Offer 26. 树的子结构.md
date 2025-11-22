> 题目难度: 中等

> [原题链接](https://leetcode-cn.com/problems/shu-de-zi-jie-gou-lcof/)

## 题目描述

输入两棵二叉树 A 和 B，判断 B 是不是 A 的子结构。(约定空树不是任意一个树的子结构)

B 是 A 的子结构， 即 A 中有出现和 B 相同的结构和节点值。

例如:
给定的树 A:

```
     3
    / \
   4   5
  / \
 1   2
```

给定的树 B：

```
   4 
  /
 1
```

返回 true，因为 B 与 A 的一个子树拥有相同的结构和节点值。

0 <= 节点个数 <= 10000

## 题目样例

### 示例 1

#### 输入

A = [1,2,3], B = [3,1]

#### 输出

false

### 示例 2

#### 输入

A = [3,4,5,1,2], B = [4,1]

#### 输出

true

## 题目思考

1. 子结构有哪些性质?

## 解决方案

### 思路

- 分析题目, B 是 A 的子结构的话, 那么 B 的节点结构需要完全是 A 的某一部分, 而且该部分中的一部分子树可以不在 B 中(例如题目中 A 的 2 号节点就不在 B 中)
- 所以我们可以额外定义一个方法, 来递归比较当前 A 和 B 节点是否满足子结构关系
- 然后从 A 和 B 的根节点开始调用该方法, 如果当前满足条件就直接返回 true, 否则就将 A 移动到其左右子节点位置, 重新与 B 的根节点比较即可
- 下面代码中有详细的注释, 方便大家理解

### 复杂度

- 时间复杂度 `O(MN)`
  - 假设 A 和 B 的节点数目分别是 M 和 N, 那么最差情况是对于每个 A 节点, 都要调用一次 match 方法遍历整个 B 树, 所以时间复杂度是 `O(MN)`
- 空间复杂度 `O(M)`
  - isSubStructure 递归调用则最多使用 `O(M)` 递归栈空间, match 递归调用使用 `O(min(M, N))` 递归栈空间, 所以整体空间复杂度为 `O(M)`

### 代码

```python {cmd = "python3"}
class Solution:
    def isSubStructure(self, A: TreeNode, B: TreeNode) -> bool:
        if not A or not B: # 根据题意, B如果是空树一定不满足条件, 而A是空树的话B更不可能是其子结构了
            return False
        mid = self.match(A, B)
        left = self.isSubStructure(A.left, B)
        right = self.isSubStructure(A.right, B)
        return mid or left or right # B是A的子结构的充要条件: 要么当前A和B匹配, 要么A的左右子节点和B匹配
    def match(self,A, B):
        if not B:
            # 因为A的子树部分可以有部分节点是B没有的, 所以如果当前b节点是空的话是满足条件的情况, 直接返回true
            return True
        if not A:
            # 此时b节点还有值, 但a节点是空了, B不可能是A的子结构
            return False
        # 既要当前a和b的值相等, 同时各自左右子树部分也要匹配
        left = self.match(A.left, B.left)
        right = self.match(A.right, B.right)
        return A.val == B.val and left and right
```
