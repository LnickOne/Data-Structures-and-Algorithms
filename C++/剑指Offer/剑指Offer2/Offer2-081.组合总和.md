> 题目难度: 中等

> [原题链接](https://leetcode.cn/problems/Ygoe9J/)

## 题目描述

给定一个无重复元素的正整数数组 candidates 和一个正整数 target ，找出 candidates 中所有可以使数字和为目标数 target 的唯一组合。

candidates 中的数字可以无限制重复被选取。如果至少一个所选数字数量不同，则两种组合是不同的。

对于给定的输入，保证和为 target 的唯一组合数少于 150 个。

### 示例 1：

- 输入: candidates = [2,3,6,7], target = 7
- 输出: [[7],[2,2,3]]

### 示例 2：

- 输入: candidates = [2,3,5], target = 8
- 输出: [[2,2,2,2],[2,3,3],[3,5]]

### 示例 3：

- 输入: candidates = [2], target = 1
- 输出: []

### 示例 4：

- 输入: candidates = [1], target = 1
- 输出: [[1]]

### 示例 5：

- 输入: candidates = [1], target = 2
- 输出: [[1,1]]

### 提示：

- 1 <= candidates.length <= 30
- 1 <= candidates[i] <= 200
- candidate 中的每个元素都是独一无二的。
- 1 <= target <= 500

## 题目思考

1. 如果限制只能用递归或者迭代, 如何解决?

## 解决方案

### 方案 1

#### 思路

- 首先我们可以尝试用递归的思路来解决
- 分析题目, 我们可以发现针对 candidates 的每个数字, 都可以细分成两种情况: (1) 将该数字添加到组合中, 继续处理当前数字; (2) 不再添加当前数字, 开始处理下一个数字
- 我们可以基于上述分析进行递归求解, 具体做法如下:
  - 传入当前下标, 当前组合, 以及当前组合的数字之和
  - 如果当前数字和恰好等于 target, 则将当前组合加入最终结果, 并返回
  - 如果当前数字和已经大于 target, 或者当前下标超出数组范围, 则没必要继续递归了, 直接返回
  - 如果不是上述两种情况, 则说明可以继续递归: 此时要么继续使用当前数字, 将其添加到当前组合中, 同时保持当前下标不变; 要么不再使用当前数字, 当前组合保持不变, 同时将当前下标加 1
- 由于每条递归路径添加的数字个数都不一样, 所以每个递归出口形成的有效组合也各不相同, 无需手动去重

#### 复杂度

- 时间复杂度 O(2^M): 假设 sum(ceil(target/candidate))是 M (candidate 是 candidates 中的每个数字), 意味着最多进行 M 次判断, 每次判断都有两种可能性, 所以总时间是 2^M
- 空间复杂度 O(M): 递归栈的消耗, 最差情况下长度是 M

#### 代码

##### Python 3

```python
class Solution:
    def combinationSum(self, candidates: List[int], target: int) -> List[List[int]]:
        # 方法1: 两分支递归
        n = len(candidates)
        res = []

        # 递归传入当前下标, 当前组合以及当前组合的数字之和
        def dfs(i, path, sm):
            if sm == target:
                # 递归出口#1, 找到一个有效组合, 将其加入最终结果集
                res.append(path)
                return
            if i >= n or sm > target:
                # 递归出口#2, 当前组合已经不可能满足要求了, 直接返回
                return
            # 情况1: 将该数字添加到组合中, 继续处理当前数字
            dfs(i, path + [candidates[i]], sm + candidates[i])
            # 情况2: 不再添加当前数字, 开始处理下一个数字
            dfs(i + 1, path, sm)

        dfs(0, [], 0)
        return res
```

### 方案 2

#### 思路

- 接下来我们尝试用迭代的思路来解决
- 我们可以将递归函数的三个参数作为一个三元组存储起来
- 然后遍历这个三元组列表, 同样利用递归方案的分析来进行相应处理
- 只是需要将递归出口的 return 改成 continue, 以及将递归调用改成追加新的三元组到列表中
- 下面代码中有详细的注释, 方便大家理解

#### 复杂度

- 时间复杂度 O(2^M): 分析同方案 1
- 空间复杂度 O(2^M): 需要保存所有可能的三元组

#### 代码

##### Python 3

```python
class Solution:
    def combinationSum(self, candidates: List[int], target: int) -> List[List[int]]:
        # 方法2: 三元组迭代
        n = len(candidates)
        res = []
        # (当前下标,当前组合,当前组合的数字之和)
        tuples = [(0, [], 0)]
        for i, path, sm in tuples:
            if sm == target:
                # 找到一个有效组合, 将其加入最终结果集, 继续循环
                res.append(path)
                continue
            if i >= n or sm > target:
                # 当前组合已经不可能满足要求了, 不再继续处理它, 继续循环
                continue
            # 情况1: 将该数字添加到组合中, 继续处理当前数字
            tuples.append((i, path + [candidates[i]], sm + candidates[i]))
            # 情况2: 不再添加当前数字, 开始处理下一个数字
            tuples.append((i + 1, path, sm))
        return res
```
