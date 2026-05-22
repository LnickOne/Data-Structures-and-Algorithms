> 题目难度: 中等

> [原题链接](https://leetcode.cn/problems/4sjJUc/)

## 题目描述

给定一个可能有重复数字的整数数组 candidates 和一个目标数 target ，找出 candidates 中所有可以使数字和为 target 的组合。

candidates 中的每个数字在每个组合中只能使用一次，解集不能包含重复的组合。

### 示例 1:

- 输入: candidates = [10,1,2,7,6,1,5], target = 8,
- 输出:

```
[
    [1,1,6],
    [1,2,5],
    [1,7],
    [2,6]
]
```

### 示例 2:

- 输入: candidates = [2,5,2,1,2], target = 5,
- 输出:

```
[
    [1,2,2],
    [5]
]
```

### 提示:

- 1 <= candidates.length <= 100
- 1 <= candidates[i] <= 50
- 1 <= target <= 30

## 题目思考

1. 如何做到不添加重复组合?
2. 如果限制只能用递归或者迭代, 如何解决?

## 解决方案

### 方案 1

#### 思路

- 分析题目, 不难发现这道题和上一道题([剑指 Offer II 081.组合总和](https://mp.weixin.qq.com/s?__biz=MzA5MDk1MjI5MA==&mid=2247484806&idx=1&sn=e01a4e324691d7205b59eed221bdde02&token=1003373131&lang=zh_CN#rd))非常类似, 区别只是数字存在重复, 且只能取一次
- 但如果我们仍采用之前的两分支的做法, 即选取当前数字和不选当前数字, 则会出现重复组合
- 举个例子, 假设 candidates 是`[1,2,1]`, 而 target 是 3, 那么只选第一个 1 对应的组合是`[1,2]`, 而只选第二个 1 对应的组合是`[2,1]`, 这就导致重复了, 如何解决呢?
- 既然在不同位置选择相同的数字会导致重复, 那么我们可以将相同数字聚合起来, 对应的就是计数字典`{key:cnt}`
- 然后针对字典的每个 key, 我们都可以有 0,1,...,cnt 种选择, 对应就是组合里不添加该数字, 添加一个,...,添加 cnt 个
- 然后其余部分就和上一道题非常类似了, 本质上来说, 就是相当于将上一道题的无限制添加某个数字改成最多添加 cnt 次
- 我们可以基于上述分析进行递归求解, 具体做法如下:
  - 首先将原始数组转换成计数字典, 并得到 key 的列表
  - 传入当前下标, 当前组合, 以及当前组合的数字之和
  - 如果当前数字和恰好等于 target, 则将当前组合加入最终结果, 并返回
  - 如果当前数字和已经大于 target, 或者当前下标超出 key 列表的范围, 则没必要继续递归了, 直接返回
  - 如果不是上述两种情况, 则说明可以继续递归, 此时可以使用 0~cnt 个数字, 共有 cnt+1 种情况
  - 对于每种情况, 将对应数目的当前数字添加到当前组合并更新数字和, 然后下标加 1
- 由于每条递归路径添加的数字个数都不一样, 所以每个递归出口形成的有效组合也各不相同, 无需手动去重

#### 复杂度

- 时间复杂度 O(2^N): 假设原始数组共有 N 个数字, 每个数字都要么添加到组合, 要么不添加, 所以最多判断 2^N 种组合, 总时间是 2^N
- 空间复杂度 O(N): 计数字典和 key 列表需要存储最多 N 个元素, 而递归栈在最差情况下长度同样是 N

#### 代码

##### Python 3

```python
class Solution:
    def combinationSum2(self, candidates: List[int], target: int) -> List[List[int]]:
        # 方法1: 转计数字典+多分支递归
        res = []
        # 将原始数组转成计数字典, 并记录key列表
        cnts = collections.Counter(candidates)
        keys = list(cnts.keys())

        # 递归传入当前下标, 当前组合以及当前组合的数字之和
        def dfs(i, path, sm):
            if sm == target:
                # 递归出口#1, 找到一个有效组合, 将其加入最终结果集
                res.append(path)
                return
            if i >= len(keys) or sm > target:
                # 递归出口#2, 当前组合已经不可能满足要求了, 直接返回
                return
            for cnt in range(cnts[keys[i]] + 1):
                # 针对0~cnt, 将对应次数的数字加入组合并更新数字和, 然后继续处理下一个key
                dfs(i + 1, path + [keys[i]] * cnt, sm + cnt * keys[i])

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

- 时间复杂度 O(2^N): 分析同方案 1
- 空间复杂度 O(2^N): 需要保存所有可能的三元组

#### 代码

##### Python 3

```python
class Solution:
    def combinationSum2(self, candidates: List[int], target: int) -> List[List[int]]:
        # 方法2: 转计数字典+三元组迭代
        res = []
        # 将原始数组转成计数字典, 并记录key列表
        cnts = collections.Counter(candidates)
        keys = list(cnts.keys())
        # (当前下标,当前组合,当前组合的数字之和)
        tuples = [(0, [], 0)]
        for i, path, sm in tuples:
            if sm == target:
                # 找到一个有效组合, 将其加入最终结果集, 继续循环
                res.append(path)
                continue
            if i >= len(keys) or sm > target:
                # 当前组合已经不可能满足要求了, 不再继续处理它, 继续循环
                continue
            for cnt in range(cnts[keys[i]] + 1):
                # 针对0~cnt, 将对应次数的数字加入组合并更新数字和, 然后继续处理下一个key
                tuples.append((i + 1, path + [keys[i]] * cnt, sm + cnt * keys[i]))
        return res
```
