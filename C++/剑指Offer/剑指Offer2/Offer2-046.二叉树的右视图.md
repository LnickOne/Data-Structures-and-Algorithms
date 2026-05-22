> 题目难度: 中等

> [原题链接](https://leetcode.cn/problems/WNC0Lk/)

## 题目描述

给定一个二叉树的 根节点 root，请找出该二叉树的 最底层 最左边 节点的值。

假设二叉树中至少有一个节点。

### 示例 1:

![](https://assets.leetcode.com/uploads/2020/12/14/tree1.jpg)

- 输入: root = [2,1,3]
- 输出: 1

### 示例 2:

![](https://assets.leetcode.com/uploads/2020/12/14/tree2.jpg)

- 输入: [1,2,3,4,null,5,6,null,null,7]
- 输出: 7

### 提示:

- 二叉树的节点个数的范围是 [1,10^4]
- -2^31 <= Node.val <= 2^31 - 1

## 题目思考

1. 如何找出最底层?

## 解决方案

#### 思路

- 分析题目, 不难发现这道题和上一道题[Leetcode 剑指 Offer II 045. 找树左下角的值](https://mp.weixin.qq.com/s?__biz=MzA5MDk1MjI5MA==&mid=2247484672&idx=1&sn=1989e39111fbcdc7af05801c68dff758&token=1616441487&lang=zh_CN#rd)非常类似, 只是把要求的最底层的最左节点换成了每一层的最右节点
- 所以我们同样可以使用经典的按层 BFS 来解决, 具体思路如下:
  - 记录下当前层的节点边界, 并将当前层最后一个节点的值加入最终结果
  - 然后当前层的子节点都加入队列后, 将队列更新为从下一层节点起点开始
  - 这样队列变空后的最终结果就是整个二叉树的右视图
- 具体实现细节如下:
  - 使用一个队列存储节点
  - 接下来开始循环, 记录当前队列长度 curlen
  - 然后遍历前 curlen 个节点, 并将它们的左右非空子节点追加到队列结尾
  - 另外当前层最后一个遍历到的节点就是其最右节点, 将它的值追加到 res 中
  - 当前层遍历结束时, 下层的起点下标自然就是 curlen, 所以只需要将队列切片成 curlen 及以后的部分即可
  - 最终当队列没有元素时则说明所有节点都遍历过了, 退出循环
  - 此时 res 保存的正是每一层最右节点的值
- 由于这里是树, 所以每个节点只可能被加入队列访问一次, 无需额外的 visit 集合
- 下面的代码就对应了上面的整个过程, 并且有详细的注释, 方便大家理解

#### 复杂度

- 时间复杂度 O(N): 需要遍历每个节点一遍
- 空间复杂度 O(N): 需要存储所有节点到对应的层

#### 代码

```python
class Solution:
    def rightSideView(self, root: TreeNode) -> List[int]:
        # 按层BFS
        res = []
        if not root:
            # 根节点为空, 返回空列表
            return res
        # 队列初始化为第一层, 即根节点
        q = [root]
        while q:
            # 记录当前层的节点个数curlen
            curlen = len(q)
            # 将当前层最右侧的值加入最终结果中
            res.append(q[-1].val)
            # 只遍历当前层的节点, 即前curlen个
            for node in q[:curlen]:
                # 左右子节点非空时, 将其追加到队列中
                if node.left:
                    q.append(node.left)
                if node.right:
                    q.append(node.right)
            # 将队列更新成下一层的节点
            q = q[curlen:]
        # 最终res就是整个二叉树的右视图
        return res
```
