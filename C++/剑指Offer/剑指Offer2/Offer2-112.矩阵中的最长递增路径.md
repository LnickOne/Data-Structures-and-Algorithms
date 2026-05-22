> 题目难度: 困难

> [原题链接](https://leetcode.cn/problems/fpTFWP/)

## 题目描述

给定一个 m x n 整数矩阵 matrix ，找出其中 最长递增路径 的长度。

对于每个单元格，你可以往上，下，左，右四个方向移动。 不能 在 对角线 方向上移动或移动到 边界外（即不允许环绕）。

### 示例 1：

![](https://assets.leetcode.com/uploads/2021/01/05/grid1.jpg)

- 输入：matrix = [[9,9,4],[6,6,8],[2,1,1]]
- 输出：4
- 解释：最长递增路径为 [1, 2, 6, 9]。

### 示例 2：

![](https://assets.leetcode.com/uploads/2021/01/27/tmp-grid.jpg)

- 输入：matrix = [[3,4,5],[3,2,6],[2,2,1]]
- 输出：4
- 解释：最长递增路径是 [3, 4, 5, 6]。注意不允许在对角线方向上移动。

### 示例 3：

- 输入：matrix = [[1]]
- 输出：1

### 提示：

- m == matrix.length
- n == matrix[i].length
- 1 <= m, n <= 200
- 0 <= matrix[i][j] <= 231 - 1

## 题目思考

1. 如何优化时间复杂度?

## 解决方案

- 观察题目, 一个很容易想到的思路就是从每个格子出发, 使用 DFS 或者 BFS 遍历相邻的值更大的邻居格子, 以此类推直到无法继续扩展为止, 此时得到的最长长度就是以该格子为起点的最长递增路径长度, 最终结果就是所有这些最长长度的最大值
- 不过这种方法会有大量的重复计算, 矩阵共有 M\*N 个格子, 每个格子在求最长长度时都可能需要遍历整个矩阵, 所以时间复杂度是`O(MNMN)`, 如何优化呢?
- 如果我们计算出来某个格子的最长递增路径长度后, 将其保存下来, 这样再遍历到它时就不需要重复计算了, 这就是记忆化搜索的思路, 用空间换时间, 从而优化时间复杂度
- 具体实现时, 我们可以定义一个 getLongestPathLength 函数, 传入行列下标, 计算以它为起点的最长递增路径长度, 并利用 Python3 的@functools.cache 将计算结果保存下来 (其他语言可以自行定义一个字典, key 是行列下标, value 是对应最长长度)
- 在计算以当前格子为起点的最长递增路径长度时, 首先初始化长度为 1, 即只使用起点本身, 然后遍历起点的四个邻居, 如果邻居的值更大, 则找到一个有效递增路径, 其长度就是邻居最长长度加 1, 起点的最长长度就是所有这些有效路径长度的最大值, 而所有这些起点的最长递增路径长度的最大值就是最终结果
- 下面的代码对必要步骤有详细的解释, 方便大家理解

#### 复杂度

- 时间复杂度 `O(MN)`: 每个格子都只会被处理一次
- 空间复杂度 `O(MN)`: 需要保存以每个格子为起点的最长递增路径长度

#### 代码

```python
class Solution:
    def longestIncreasingPath(self, matrix: List[List[int]]) -> int:
        rows, cols = len(matrix), len(matrix[0])

        @functools.cache
        def getLongestPathLength(r, c):
            # 计算从当前节点出发的最长递增路径长度
            # 因为路径需要递增, 所以一定是单向, 不会出现循环
            # 初始化为只使用当前格子的路径, 长度为1
            res = 1
            for rr, cc in ((r + 1, c), (r - 1, c), (r, c + 1), (r, c - 1)):
                if 0 <= rr < rows and 0 <= cc < cols and matrix[rr][cc] > matrix[r][c]:
                    # 找到一个大于当前格子的邻居格子, 更新最长递增路径长度
                    res = max(res, getLongestPathLength(rr, cc) + 1)
            return res

        res = 0
        for r in range(rows):
            for c in range(cols):
                res = max(res, getLongestPathLength(r, c))
        return res
```
