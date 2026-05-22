> 题目难度: 中等

> [原题链接](https://leetcode.cn/problems/pOCWxh)

## 题目描述

给定一个二叉树 根节点 root ，树的每个节点的值要么是 0，要么是 1。请剪除该二叉树中所有节点的值为 0 的子树。

节点 node 的子树为 node 本身，以及所有 node 的后代。

### 示例 1:

- 输入: [1,null,0,0,1]
- 输出: [1,null,0,null,1]
- 解释:
  只有红色节点满足条件“所有不包含 1 的子树”。
  右图为返回的答案。

  ![](https://s3-lc-upload.s3.amazonaws.com/uploads/2018/04/06/1028_2.png)

### 示例 2:

- 输入: [1,0,1,0,0,0,1]
- 输出: [1,null,1,null,1]
- 解释:
  ![](https://s3-lc-upload.s3.amazonaws.com/uploads/2018/04/06/1028_1.png)

### 示例 3:

- 输入: [1,1,0,1,1,0,1,0]
- 输出: [1,1,0,1,1,null,1]
- 解释:
  ![](https://s3-lc-upload.s3.amazonaws.com/uploads/2018/04/05/1028.png)

### 提示:

- 二叉树的节点个数的范围是 [1,200]
- 二叉树节点的值只会是 0 或 1

## 题目思考

1. 如何在得到子树所有节点值的同时, 进行剪除操作?

## 解决方案

#### 思路

- 分析题目, 如果某个子树的所有节点都是 0, 则其根节点的值为 0, 且左右子树的所有节点也都是 0
- 我们可以根据这一点, 使用 DFS 来判断, 具体做法如下:
  1. dfs 函数传入节点 node 作为参数, 返回以该节点为根的子树的所有节点是否全为 0
  2. 如果传入是空节点, 则返回 true, 作为递归出口
  3. 否则先递归调用 dfs 函数, 传入其左右子节点, 从而得到左右子树是否全为 0 的两个布尔值: leftAllZero 和 rightAllZero
  4. 那么当前子树要想全为 0, 就需要 `node.val==0 && leftAllZero && rightAllZero`, 返回它即可
- 上述步骤只是得出了每个子树的所有节点是否全 0, 题目还要求剪除全 0 子树, 如何操作呢?
- 我们可以在上面的第三步和第四步之间加入剪除操作:
  - 如果左子树全 0, 就断开当前节点和其左子节点的连接
  - 如果右子树全 0, 就断开当前节点和其右子节点的连接
- 这样就在得到子树所有节点值的同时, 进行了剪除操作
- 需要注意有可能整棵树的所有节点全为 0, 此时剪除后需要返回空节点
- 我们可以引入一个哨兵节点, 将其左子节点指向整棵树的根节点
- 然后从哨兵节点开始判断, 最终返回哨兵的左子节点, 这样就无需针对根节点做特殊处理了
- 下面的代码就对应了上面的整个过程, 并且有详细的注释, 方便大家理解

#### 复杂度

- 时间复杂度 O(N): 需要遍历每个节点一遍
- 空间复杂度 O(H): H 是树的高度, 也是递归栈的空间消耗

#### 代码

```python
class Solution:
    def pruneTree(self, root: TreeNode) -> TreeNode:
        # 使用哨兵节点, 将其左子节点指向root, 并从哨兵开始判断
        # 因为有可能整个树都是0, 此时需要返回空节点, 如果不用哨兵从root开始判断, 就需要额外的逻辑特殊处理root
        dummy = TreeNode(0, root)

        def allZero(node):
            if not node:
                # 递归出口, 空节点的值不是1, 所以返回True
                return True
            leftAllZero = allZero(node.left)
            rightAllZero = allZero(node.right)
            if leftAllZero:
                # 左子树全为0, 断开当前节点与其的连接
                node.left = None
            if rightAllZero:
                # 右子树全为0, 断开当前节点与其的连接
                node.right = None
            # 当前子树全为0需要满足: 当前节点值为0 && 左子树全为0 && 右子树全为0
            return node.val == 0 and leftAllZero and rightAllZero

        allZero(dummy)
        # 最终哨兵节点的左子节点即为删除全0子树后的根节点 (可能为空)
        return dummy.left
```
