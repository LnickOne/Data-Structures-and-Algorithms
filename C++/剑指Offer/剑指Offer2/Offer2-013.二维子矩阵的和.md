> 题目难度: 中等

> [原题链接](https://leetcode.cn/problems/O4NDxx)

## 题目描述

给定一个二维矩阵 matrix，以下类型的多个请求：

计算其子矩形范围内元素的总和，该子矩阵的左上角为 (row1, col1) ，右下角为 (row2, col2) 。
实现 NumMatrix 类：

NumMatrix(int[][] matrix)  给定整数矩阵 matrix 进行初始化
int sumRegion(int row1, int col1, int row2, int col2)  返回左上角 (row1, col1) 、右下角  (row2, col2)  的子矩阵的元素总和。

### 示例 1：

![](https://pic.leetcode-cn.com/1626332422-wUpUHT-image.png)

- 输入:
  - ["NumMatrix","sumRegion","sumRegion","sumRegion"]
  - [[[[3,0,1,4,2],[5,6,3,2,1],[1,2,0,1,5],[4,1,0,1,7],[1,0,3,0,5]]],[2,1,4,3],[1,1,2,2],[1,2,2,4]]
- 输出:
  - [null, 8, 11, 12]
- 解释:
  - NumMatrix numMatrix = new NumMatrix([[3,0,1,4,2],[5,6,3,2,1],[1,2,0,1,5],[4,1,0,1,7],[1,0,3,0,5]]]);
  - numMatrix.sumRegion(2, 1, 4, 3); // return 8 (红色矩形框的元素总和)
  - numMatrix.sumRegion(1, 1, 2, 2); // return 11 (绿色矩形框的元素总和)
  - numMatrix.sumRegion(1, 2, 2, 4); // return 12 (蓝色矩形框的元素总和)

### 提示：

- m == matrix.length
- n == matrix[i].length
- 1 <= m, n <= 200
- -10^5 <= matrix[i][j] <= 10^5
- 0 <= row1 <= row2 < m
- 0 <= col1 <= col2 < n
- 最多调用 10^4 次  sumRegion 方法

## 题目思考

1. 如何优化时间复杂度?

## 解决方案

#### 思路

- 分析题目, 最容易想到的做法就是暴力计算: 每次累加所需子矩阵的所有元素
- 但这种做法时间效率太低 (`O(MNK)`, K 是  sumRegion 的调用次数), 如何优化呢?
- 重新分析题目, 这个问题是不是跟一维数组的子数组和很类似? 这里只是把一维的数组换成了二维的矩阵而已
- 定义前缀和二维数组 sums, sums[r+1][c+1]存左上角(0,0)到右下角(r,c)的矩阵和
- 这里之所以用(r+1,c+1)而不是(r,c)作为下标, 是为了处理空子矩阵的情况, 这样 sums 不管哪一维下标是 0 时, 都表示空矩阵, 对应的前缀和就是初始值 0, 无需加上额外的 if 判断
- 我们可以利用该前缀和, 求出任意一个子矩阵[(sr,sc),(er,ec)]的和
- 大家可以画个图来理解, 子矩阵[(sr,sc),(er,ec)]是子矩阵[(0,0),(er,ec)]的右下角的矩阵, 想要求出它, 我们只需要根据[(0,0),(er,ec)]的和, 减去上半部分的矩阵[(0,0),(sr-1,ec)]和, 再减去左半部分的矩阵[(0,0),(er,sc-1)]和, 最后加上左上角被重复减了两次的矩阵[(0,0),(sr-1,sc-1)]和即可
- 具体就是`sumRegion((sr,sc),(er,ec)) = sums[er+1][ec+1]-sums[sr][ec+1]-sums[er+1][sc]+sums[sr,sc]`
- 至于如何求前缀和二维数组 sums 本身, 也可以利用同样的思路, 只是需要减去被重复加了两次的子矩阵[(0,0),(r-1,c-1)]: `sums[r+1][c+1] = matrix[r][c]+sums[r][c+1]+sums[r+1][c]-sums[r][c]`

#### 复杂度

- 时间复杂度 `O(MN)`: 需要额外的前缀和数组
- 空间复杂度 `O(MN+K)`: 初始化前缀和数组需要 `O(MN)` 时间, 之后每次调用  sumRegion 都只需要 `O(1)`, 总共调用 K 次, 所以是 `O(K)`

#### 代码

```python
class NumMatrix:
    def __init__(self, matrix: List[List[int]]):
        rows, cols = len(matrix), len(matrix[0])
        # 前缀和数组的行列数各自加1, 这样下标0就代表空矩阵的情况, 对应前缀和也是初始值0
        self.sums = [[0] * (cols + 1) for _ in range(rows + 1)]
        for r in range(rows):
            for c in range(cols):
                # 当前格子值+左侧子矩阵+上侧子矩阵-左上侧子矩阵
                self.sums[r + 1][c + 1] = matrix[r][c] + self.sums[r][c + 1] + self.sums[r + 1][c] - self.sums[r][c]

    def sumRegion(self, row1: int, col1: int, row2: int, col2: int) -> int:
        # 右下侧子矩阵-左侧子矩阵-上侧子矩阵+左上侧子矩阵
        return self.sums[row2 + 1][col2 + 1] - self.sums[row1][col2 + 1] - self.sums[row2 + 1][col1] + self.sums[row1][col1]
```
