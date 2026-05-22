> 题目难度: 困难

> [原题链接](https://leetcode.cn/problems/PLYXKQ/)

## 题目描述

给定一个由 0 和 1 组成的矩阵 matrix ，找出只包含 1 的最大矩形，并返回其面积。

注意：此题 matrix 输入格式为一维 01 字符串数组。

### 示例 1：

![](https://assets.leetcode.com/uploads/2020/09/14/maximal.jpg)

- 输入：matrix = ["10100","10111","11111","10010"]
- 输出：6
- 解释：最大矩形如上图所示。

### 示例 2：

- 输入：matrix = []
- 输出：0

### 示例 3：

- 输入：matrix = ["0"]
- 输出：0

### 示例 4：

- 输入：matrix = ["1"]
- 输出：1

### 示例 5：

- 输入：matrix = ["00"]
- 输出：0

### 提示：

- rows == matrix.length
- cols == matrix[0].length
- 0 <= row, cols <= 200
- matrix[i][j] 为 '0' 或 '1'

## 题目思考

1. 如何优化时间复杂度?

## 解决方案

#### 思路

- 分析题目, 比较容易想到的思路是动态规划, 具体做法如下:
  - `dp[sr][sc][er][ec]`表示左上角是(sr,sc), 右下角是(er,ec)的全 1 矩形的面积
  - 这些矩形里面如果有任意一个 0, 则其面积为 0
  - 那么如果 `matrix[er][ec]` 或 `dp[sr][sc][er-1][ec]` 或 `dp[sr][sc][er][ec-1]` 是 0 时, `dp[sr][sc][er][ec]=0`
  - 否则`dp[sr][sc][er][ec]=dp[sr][sc][er-1][ec-1]+er-sr+ec-sc+1`
  - 最终结果就是最大的 dp 值
- 但上述做法的复杂度是 O(RCRC), 可能会超时, 如何优化呢?
- 回想前面刚做过的题目[剑指 Offer II 039. 直方图最大矩形面积](https://mp.weixin.qq.com/s?__biz=MzA5MDk1MjI5MA==&mid=2247484657&idx=1&sn=059b4b5dc9a6d7535d6ddf6dec44a5ba&token=1012189368&lang=zh_CN#rd), 不难发现这道题和它很类似, 都是求最大矩形面积
- 只是这道题是矩阵, 而那道题是直方图, 有没有办法利用那道题的思路呢?
- 我们可以维护一个高度数组, 然后遍历每一行并累加高度, 这样就把矩阵转换成了若干个直方图, 即 0~r 行矩阵形成的直方图 (`0<=r<R`)
- 然后利用那道题的单调栈思路求当前直方图的最大矩形面积, 所有面积的最大值就是最终结果
- 这里就不再赘述单调栈求最大矩形面积的过程了, 大家如果不记得的话可以参考[剑指 Offer II 039. 直方图最大矩形面积](https://mp.weixin.qq.com/s?__biz=MzA5MDk1MjI5MA==&mid=2247484657&idx=1&sn=059b4b5dc9a6d7535d6ddf6dec44a5ba&token=1012189368&lang=zh_CN#rd)
- 下面的代码就对应了上面的整个过程, 并且有详细的注释, 方便大家理解

#### 复杂度

- 时间复杂度 O(RC): R 是行数, C 是列数, 矩阵每个元素最多处理 2 遍 (压入和弹出栈)
- 空间复杂度 O(C): 高度数组存 C 个元素, 单调栈最多也存 C 个元素

#### 代码

```python
class Solution:
    def maximalRectangle(self, matrix: List[str]) -> int:
        def largestRectangleArea(heights):
            # stack存储柱子的下标, 且其高度满足从栈顶到栈底递减
            stack = []
            res = 0
            for r, h in enumerate(heights):
                while stack and heights[stack[-1]] > h:
                    # 栈顶高度大于当前高度, 可以计算栈顶柱子对应的矩形面积了
                    # 栈顶柱子的右边界r就是当前下标, 左边界l是上一个栈顶或-1(上一个栈顶不存在时)
                    ch = heights[stack.pop()]
                    l = -1 if not stack else stack[-1]
                    # 宽*高
                    res = max(res, (r - l - 1) * ch)
                stack.append(r)
            # 如果遍历结束后栈中仍有元素, 则说明这些柱子右边没有比它更低的柱子了, 需要计算它们对应的矩形面积
            while stack:
                ch = heights[stack.pop()]
                # 栈顶柱子的右边界r就是数组长度, 左边界l是上一个栈顶或-1(上一个栈顶不存在时)
                r = len(heights)
                l = -1 if not stack else stack[-1]
                # 宽*高
                res = max(res, (r - l - 1) * ch)
            return res

        if not matrix:
            return 0
        rows, cols = len(matrix), len(matrix[0])
        heights = [0] * cols
        res = 0
        for r in range(rows):
            # 将0~r行矩阵看作以第r行为底的直方图, 求其最大矩形面积
            for c in range(cols):
                # 注意如果第r行的某个元素是0, 则其对应直方图的该列高度也是0, 而不是继续累加上一个高度
                heights[c] = heights[c] + 1 if matrix[r][c] != "0" else 0
            res = max(res, largestRectangleArea(heights))
        return res
```
