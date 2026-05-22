> 题目难度: 中等

> [原题链接](https://leetcode.cn/problems/bLyHh0/)

## 题目描述

有 n 个城市，其中一些彼此相连，另一些没有相连。如果城市 a 与城市 b 直接相连，且城市 b 与城市 c 直接相连，那么城市 a 与城市 c 间接相连。

省份 是一组直接或间接相连的城市，组内不含其他没有相连的城市。

给你一个 n x n 的矩阵 isConnected ，其中 isConnected[i][j] = 1 表示第 i 个城市和第 j 个城市直接相连，而 isConnected[i][j] = 0 表示二者不直接相连。

- 返回矩阵中 省份 的数量。

### 示例 1：

- 输入：isConnected = [[1,1,0],[1,1,0],[0,0,1]]
- 输出：2

![](https://assets.leetcode.com/uploads/2020/12/24/graph1.jpg)

### 示例 2：

- 输入：isConnected = [[1,0,0],[0,1,0],[0,0,1]]
- 输出：3

![](https://assets.leetcode.com/uploads/2020/12/24/graph2.jpg)

### 提示：

- 1 <= n <= 200
- n == isConnected.length
- n == isConnected[i].length
- isConnected[i][j] 为 1 或 0
- isConnected[i][i] == 1
- isConnected[i][j] == isConnected[j][i]

## 题目思考

1. 需要使用什么算法和数据结构?

## 解决方案

- 分析题目, 不难发现省份数就是整个图的连通分量数, 连通分量内的节点都直接或间接相连, 连通分量间的节点不相连, 所以我们可以采用经典的 BFS 算法:
  - 首先维护一个 v 集合, 用于记录哪些城市已经被访问过
  - 然后开始遍历所有城市, 如果当前城市 i 尚未访问, 则说明找到了一个新省份(连通分量), 最终结果加 1
  - 接下来从该城市 i 开始 BFS, 查找所有与之相连且尚未访问的城市
  - BFS 时, 初始化一个队列 q 包含当前城市 i, 然后将 i 加入 v 集合中, 开始遍历 q 队列
  - 对于当前处理的城市 cur, 遍历所有城市 nex, 如果 cur 和 nex 直接相连, 且 nex 尚未被访问, 则将 nex 加入 v 集合和 q 队列, 等到后续处理
  - 等到队列变成空时, 说明当前省份(连通分量)的所有城市都已经被找到, 继续遍历后续城市找新的省份(连通分量)
- 最终结果就是省份(连通分量)的个数
- 下面的代码对必要步骤有详细的解释, 方便大家理解

#### 复杂度

- 时间复杂度 `O(N^2)`: 外层循环每个节点只会被处理一次 (`O(N)`), 内层循环需要遍历所有节点查看连通性(`O(N)`)
- 空间复杂度 `O(N)`: visit 集合需要存 N 个节点

#### 代码

```python
class Solution:
    def findCircleNum(self, isConnected: List[List[int]]) -> int:
        ### BFS求连通分量
        n = len(isConnected)
        res = 0
        v = set()
        for i in range(n):
            if i not in v:
                # 城市i尚未被遍历, 说明是一个新的省份(连通分量), 开始BFS查找其所有连通的城市
                res += 1
                v.add(i)
                q = [i]
                for cur in q:
                    for nex in range(n):
                        if isConnected[cur][nex] and nex not in v:
                            # nex和cur连通, 且nex尚未被遍历, 将其加入v集合和q队列, 等待后续处理
                            v.add(nex)
                            q.append(nex)
        return res
```
