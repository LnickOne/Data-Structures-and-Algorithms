> 题目难度: 简单

> [原题链接](https://leetcode-cn.com/problems/er-cha-shu-de-zui-jin-gong-gong-zu-xian-lcof/)

## 题目描述

给定一个二叉树, 找到该树中两个指定节点的最近公共祖先。

百度百科中最近公共祖先的定义为：“对于有根树 T 的两个结点 p、q，最近公共祖先表示为一个结点 x，满足 x 是 p、q 的祖先且 x 的深度尽可能大（一个节点也可以是它自己的祖先）。”

例如，给定如下二叉树: root = [3,5,1,6,2,0,8,null,null,7,4]

![二叉树](https://assets.leetcode-cn.com/aliyun-lc-upload/uploads/2018/12/15/binarytree.png)

说明:

- 所有节点的值都是唯一的。
- p、q 为不同节点且均存在于给定的二叉树中。

## 题目样例

### 示例

- **示例 1:**

- 输入: root = [3,5,1,6,2,0,8,null,null,7,4], p = 5, q = 1
- 输出: 3
- 解释: 节点 5 和节点 1 的最近公共祖先是节点 3。

- **示例 2:**

- 输入: root = [3,5,1,6,2,0,8,null,null,7,4], p = 5, q = 4
- 输出: 5
- 解释: 节点 5 和节点 4 的最近公共祖先是节点 5。因为根据定义最近公共祖先节点可以为节点本身。

## 题目思考

1. 还可以利用昨天二叉搜索树的方法吗?
2. 如果限制只能用递归或者迭代, 如何解决?

## 解决方案

### 方案 1

#### 思路

- 这里的树不再是二叉搜索树, 也就意味着不能根据节点值来判断应该往那边遍历, 只能老老实实逐个节点遍历了
- 首先尝试递归的做法, 如果我们能得出左右子树各自的 p/q 节点存在的情况, 再结合当前节点, 就能得出当前节点以及其所有子节点中是否包含 p 和 q
- 那么在**第一次**找到这样一个自身或子节点中同时包含 p 和 q 的节点时, 这个节点就一定是最近公共祖先, 因为其所有子节点都不满足这一性质, 不可能有更近的祖先了
- 接下来考虑如何实现:
  1. **首先定义待求的祖先节点:** 初始化为空, 表示还未找到
  2. **接下来定义递归方法:** 根据上面的分析, 递归方法中需要传入当前节点, 并返回两个 bool, 分别代表当前节点以及其所有子节点中是否包含 p 或 q
  3. **第三步定义递归出口:** 很显然是节点为空或者祖先节点已经找到的情况, 此时直接返回
  4. **最后设计正常情况下的递归逻辑:** 我们依次递归调用左右子节点并得到它们 p/q 节点存在的情况, 并考虑当前节点本身是否为 p/q, 从而得到当前的两个 bool 返回值. 如果它们都是 true**且当前祖先为空**的话, 就把祖先设为当前节点, 即找到了最近祖先. (因为最近祖先的更高层的父节点的两个 bool 肯定也是 true, 所以必须判断当前祖先为空才赋值, 保证祖先是最近的)
- 下面代码对必要步骤有详细解释, 方便大家参考

#### 复杂度

- 时间复杂度 O(N): 最多需要遍历每个节点一遍
- 空间复杂度 O(H): 递归栈中要存树的高度个节点

#### 代码

```python
class Solution:
    def lowestCommonAncestor(self, root: TreeNode, p: TreeNode,
                             q: TreeNode) -> TreeNode:
        # 方法1: 递归dfs, 返回是否找到p或q
        # 注意ancestor只能赋值一次, 即为最近的祖先
        ancestor = None

        def find(cur):
            nonlocal ancestor
            if not cur or ancestor:
                # 递归出口, 返回全false
                return (False, False)
            # 先得出左右子树上的p/q节点存在情况
            lp, pq = find(cur.left)
            rp, rq = find(cur.right)
            # 然后计算加上当前节点后的p/q节点存在情况
            findp = lp or rp or cur == p
            findq = pq or rq or cur == q
            # 如果两者都存在, 且祖先还为空, 则表示找到最近祖先了, 即当前节点
            if findp and findq and not ancestor:
                ancestor = cur
            # 返回当前节点以及其所有子节点中的p/q节点存在情况
            return (findp, findq)

        find(root)
        return ancestor
```

### 方案 2

#### 思路

- 假如此时要求只能利用迭代来实现, 又该如何做呢?
- 一个很自然的思路是我们从两个节点出发, 往上走, 并把路上的节点都加入集合中
- 然后某个节点如果在加入前已经在集合里了, 就说明这个节点一定也存在于另一条路径中, 也即这个节点是个祖先, 而且显然**第一次遇到的这种节点就是最近祖先**
- 如何实现向上走呢? 我们可以定义一个 parent 字典, key 是当前节点, value 是其父节点, 然后通过将当前节点置为其父节点的方式一直向上走了, 直到到根节点
- 那如何求 parent 字典呢? DFS 和 BFS 都很好实现, 因为它们都有当前节点和子节点的信息, 这里要求迭代, 那就直接用 BFS 好了
- 下面代码对必要步骤有详细解释, 方便大家参考

#### 复杂度

- 时间复杂度 O(N): 最多需要遍历每个节点一遍
- 空间复杂度 O(N): 需要存每个节点的父节点信息, 以及一个集合存当前遍历过的节点

#### 代码

```python
class Solution:
    def lowestCommonAncestor(self, root: TreeNode, p: TreeNode,
                             q: TreeNode) -> TreeNode:
        # 方法2: 迭代BFS, 记录每个节点父节点, p/q依次向上找并加入集合中, 直到找到第一个父节点已在集合的节点, 这个父节点就是最近公共祖先
        if not root:
            return None
        # 初始化根节点的父节点为空
        parent = {root: None}
        # BFS部分, 记录每个节点父节点
        queue = [root]
        for node in queue:
            if node.left:
                parent[node.left] = node
                queue.append(node.left)
            if node.right:
                parent[node.right] = node
                queue.append(node.right)
        # 注意集合需要初始化加上p/q, 因为它们可能自身就是祖先
        v = {p, q}
        while p or q:
            # 这里循环条件为or, 因为有可能p/q高度可能不同, 有可能某个节点先遍历到了根节点, 这时候另外的节点需要继续往上走来找祖先
            if p:
                p = parent[p]
                if p and p in v:
                    # 当前父节点不是空且已经在集合中, 说明它就是最近祖先
                    return p
                v.add(p)
            if q:
                q = parent[q]
                if q and q in v:
                    # 当前父节点不是空且已经在集合中, 说明它就是最近祖先
                    return q
                v.add(q)
        # 最终一定会在循环内部返回的, 所以循环外不需要return, 因为保底祖先是根节点, 一定在集合中
```
