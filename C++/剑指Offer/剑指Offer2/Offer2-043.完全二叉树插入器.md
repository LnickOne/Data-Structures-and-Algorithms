> 题目难度: 中等

> [原题链接](https://leetcode.cn/problems/NaqhDT/)

## 题目描述

完全二叉树是每一层（除最后一层外）都是完全填充（即，节点数达到最大，第 n 层有 2n-1 个节点）的，并且所有的节点都尽可能地集中在左侧。

设计一个用完全二叉树初始化的数据结构 CBTInserter，它支持以下几种操作：

- CBTInserter(TreeNode root) 使用根节点为 root 的给定树初始化该数据结构；
- CBTInserter.insert(int v) 向树中插入一个新节点，节点类型为 TreeNode，值为 v 。使树保持完全二叉树的状态，并返回插入的新节点的父节点的值；
- CBTInserter.get_root() 将返回树的根节点。

### 示例 1：

- 输入：inputs = `["CBTInserter","insert","get_root"]`, inputs = `[[[1]],[2],[]]`
- 输出：`[null,1,[1,2]]`

### 示例 2：

- 输入：inputs = `["CBTInserter","insert","insert","get_root"]`, inputs = `[[[1,2,3,4,5,6]],[7],[8],[]]`
- 输出：`[null,3,4,[1,2,3,4,5,6,7,8]]`

### 提示：

- 最初给定的树是完全二叉树，且包含 1 到 1000 个节点。
- 每个测试用例最多调用 CBTInserter.insert 操作 10000 次。
- 给定节点或插入节点的每个值都在 0 到 5000 之间。

## 题目思考

1. 如何利用完全二叉树的性质?

## 解决方案

#### 思路

- 分析题目, 为了保证插入新节点后仍保持完全二叉树的状态, 我们需要知道当前待插入的节点位置
- 根据完全二叉树的性质, 这里有两种可能:
  1. 当前最底层还有空位, 则插入位置就是上个插入节点的相邻右侧
  2. 当前最底层没有空位了, 则需要往下新开辟一层, 并插入该层最左侧
- 那如何判断当前最底层还有没有空位呢?
  - 我们可以利用按层 BFS, 记录最初给定的树的每一层节点信息, 这样就可以得到树高度, 以及最底层的节点个数
  - 然后根据完全二叉树的性质, 如果某层高度是 h(从 0 开始), 那么当其节点个数达到 2^h 就表示这一层满了, 否则就还有空位
  - 最后再按照上面的判断, 就可以知道当前待插入节点位置了
- 接下来我们需要得到待插入节点的父节点, 这里同样可以利用完全二叉树的性质: 某一层第 i 个节点的父节点一定是上一层第 i/2 个节点 (i 下标从 0 开始)
- 举两个例子:
  1. 某一层第 0 个节点的左子节点是下一层第 0 个节点, 右子节点是下一层第 1 个节点
  2. 某一层第 2 个节点的左子节点是下一层第 4 个节点, 右子节点是下一层第 5 个节点
- 得到父节点之后, 我们判断其左子节点是否为空, 是的话就说明待插入节点是其左子节点, 否则就是其右子节点
- 下面的代码就对应了上面的整个过程, 并且有详细的注释, 方便大家理解

#### 复杂度

- 时间复杂度 O(1): 每次 insert 只需要几个常数时间的操作
- 空间复杂度 O(N): 需要存储所有节点到对应的层

#### 代码

```python
class CBTInserter:
    def __init__(self, root: TreeNode):
        self.root = root
        self.levels = []
        q = [root]
        while q:
            curlen = len(q)
            for node in q[:curlen]:
                if node.left:
                    q.append(node.left)
                if node.right:
                    q.append(node.right)
            # 将当前层加入levels列表
            self.levels.append(q[:curlen])
            q = q[curlen:]

    def insert(self, v: int) -> int:
        h = len(self.levels) - 1
        if len(self.levels[-1]) == 1 << h:
            # 最底层满了, 需要新建一层
            self.levels.append([])
        # 父节点下标是当前待插入下标除以2
        pi = len(self.levels[-1]) // 2
        # 父节点在倒数第二层, 根据其下标得到父节点
        parent = self.levels[-2][pi]
        # 追加父子连接
        node = TreeNode(v)
        if not parent.left:
            # 父节点的左子节点还不存在, 将其指定为node
            parent.left = node
        else:
            # 父节点的左子节点已存在, 将右子节点指定为node
            parent.right = node
        # 将node添加到最底层
        self.levels[-1].append(node)
        return parent.val

    def get_root(self) -> TreeNode:
        return self.root
```
