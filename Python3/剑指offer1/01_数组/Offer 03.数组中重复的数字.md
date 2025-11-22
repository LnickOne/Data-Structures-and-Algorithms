> 题目难度: 简单

> [题目链接](https://leetcode-cn.com/problems/shu-zu-zhong-zhong-fu-de-shu-zi-lcof/)
## 题目描述

找出数组中重复的数字。

在一个长度为 n 的数组 nums 里的所有数字都在 0 ～ n-1 的范围内。数组中某些数字是重复的，但不知道有几个数字重复了，也不知道每个数字重复了几次。请找出数组中任意一个重复的数字。

2 <= n <= 100000

## 题目样例

### 示例

#### 输入

[2, 3, 1, 0, 2, 5, 3]

#### 输出

2 或 3

## 题目思考

   题目中给出了每个数的取值范围, 有什么启发?

## 解决方案

### 思路

- **分析**
  - 如果使用集合存储已有数字的办法, 就是遍历的过程中如果发现数字已在集合就说明该数字重复, 就将数字加入集合.
  - 但是需要 O(N)空间, 并且完全利用不到每个数的取值范围为 `0~n-1` 这一条件, 肯定不是面试官心里的最优答案
  - 时间复杂度 O(N)应该是没法降低了, 因为最差情况就是最后两个数字是重复的, 我们至少需要扫描整个数组一遍
  - 所以我们只能在空间复杂度上做文章, 看能否降低到 O(1) 空间
- **实现**
  - 注意数字范围在`0~n-1`之间, 这说明每个数都可以放到等同于其自身值的下标中
  - 所以做法很简单, 我们遇到一个值 `nums[i]` 不等于自身下标 `i` 的数时, 我们就将 `nums[i]` 作为下标的值(也即`nums[nums[i]]`)与当前值进行交换, 这样就保证`nums[i] = nums[nums[i]]`; 然后对于新的 `nums[i]`, 我们继续这一过程, 直到 `nums[i]` 也等于 `i` 为止, 这样就保证了下标和值相等. 继续往下遍历 `i`, 重复这一过程直到发现重复数字为止
  - 至于如何发现重复也很简单, 如果本身就有`nums[i] == nums[nums[i]]`的话, 自然说明 `nums[i]` 就是重复项 (因为`i!=nums[i]`是前提条件), 直接返回`nums[i]`即可
  - 注意题目保证了一定有重复, 所以最后外层循环之外一定不可达 (否则就没重复了), 不需要 return; 如果题目改成不存在重复就返回-1, 那直接在外层循环结束后加上`return -1`即可
  - 下面代码中对每一步都有详细注释, 方便大家理解

### 复杂度

- 时间复杂度 `O(N)`
  - 每个数字最多被访问两次(判断值和下标是否相等, 以及交换使得值和下标相等), 所以这里虽然看上去有两重循环(外层 for, 内层 while), 时间复杂度却为 O(N)
- 空间复杂度 `O(1)`
    - 原地更改数组, 只使用了几个变量

### Python 代码
```python{cmd= "python3"}
from typing import List
class Solution:
    def findRepeatDocument(self, documents: List[int]) -> int:
        for i in range(len(documents)):# 从头开始遍历数组
            while i != documents[i]:
                j = documents[i]# 当前下标i和值documents[i]不相等, 进入/继续内层循环
                if documents[i] == documents[j]:# 前提条件: i!=j, 所以documents[i]和documents[j]是数组的两个数字, 它们值相等, 即为重复数字
                    return documents[i]  
                documents[i], documents[j] = documents[j], documents[i]#交换两个值, 使得nums[j] == j, 这样可以继续循环判断i和新的nums[i]
        return -1
# 测试用例
print(Solution().findRepeatDocument([2, 3, 1, 0, 2, 5, 3]))
print(Solution().findRepeatDocument([2, 3, 1, 0, 4, 5]))
print(Solution().findRepeatDocument([2, 3, 1, 0, 4, 5, 6, 5, 5]))

```

