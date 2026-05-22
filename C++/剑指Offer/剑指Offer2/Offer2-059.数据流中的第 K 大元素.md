> 题目难度: 简单

> [原题链接](https://leetcode.cn/problems/jBjn9C/)

## 题目描述

设计一个找到数据流中第 k 大元素的类（class）。注意是排序后的第 k 大元素，不是第 k 个不同的元素。

请实现 KthLargest 类：

- KthLargest(int k, int[] nums) 使用整数 k 和整数流 nums 初始化对象。
- int add(int val) 将 val 插入数据流 nums 后，返回当前数据流中第 k 大的元素。

### 示例：

- 输入：
  - ["KthLargest", "add", "add", "add", "add", "add"]
  - [[3, [4, 5, 8, 2]], [3], [5], [10], [9], [4]]
- 输出：
  - [null, 4, 5, 5, 8, 8]
- 解释：
  - KthLargest kthLargest = new KthLargest(3, [4, 5, 8, 2]);
  - kthLargest.add(3); // return 4
  - kthLargest.add(5); // return 5
  - kthLargest.add(10); // return 5
  - kthLargest.add(9); // return 8
  - kthLargest.add(4); // return 8

### 提示：

- 1 <= k <= 10^4
- 0 <= nums.length <= 10^4
- -10^4 <= nums[i] <= 10^4
- -10^4 <= val <= 10^4
- 最多调用 add 方法 10^4 次
- 题目数据保证，在查找第 k 大元素时，数组中至少有 k 个元素

## 题目思考

1. 可以使用什么数据结构?

## 解决方案

#### 思路

- 分析题目, 一个很容易想到的思路就是使用一个有序数组, 添加新数字时仍保证有序性, 这样倒数第 k 个元素即为所求
- 不过这种方法需要维护所有数字, 题目只要求第 k 大的, 有没有更优的方法呢?
- 第 k 问题通常都可以尝试用堆/优先队列来解决, 这道题也不例外
- 如果我们只存最大的 k 个数字到一个最小堆中, 那么只需返回堆顶即可, 无需存储所有数字
- 这就引出了下面的思路:
  - 维护一个最小堆, 添加新数字时直接加入堆中, 加入后如果堆中元素超过了 k, 就把堆顶弹出
  - 由于是最小堆, 上述操作保证了堆中元素正是当前最大的 k 个数字, 更小的都被弹出去了
  - 此时堆顶就是第 k 大的元素, 直接返回堆顶即可
- 下面代码中有详细的注释, 方便大家理解

#### 复杂度

- 时间复杂度 O(logk): 每次 add 操作都是操作最多 k 个元素的最小堆, 所以是 O(logk)
- 空间复杂度 O(k): 最小堆存储最多 k 个元素

#### 代码

```python
class KthLargest:
    def __init__(self, k: int, nums: List[int]):
        # 最小堆
        self.q = []
        self.k = k
        for x in nums:
            # 这里直接利用实现好的add方法就行
            self.add(x)

    def add(self, val: int) -> int:
        # 将当前值加入最小堆
        heapq.heappush(self.q, val)
        if len(self.q) > self.k:
            # 最小堆的元素数目超过了k, 弹出堆顶最小值
            heapq.heappop(self.q)
        # 此时堆中存储的就是数据流的最大k个数, 而堆顶就是第k大的
        return self.q[0]
```
