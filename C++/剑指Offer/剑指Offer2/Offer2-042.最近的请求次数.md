> 题目难度: 简单

> [原题链接](https://leetcode.cn/problems/H8086Q/)

## 题目描述

写一个 RecentCounter 类来计算特定时间范围内最近的请求。

请实现 RecentCounter 类：

- RecentCounter() 初始化计数器，请求数为 0 。
- int ping(int t) 在时间 t 添加一个新请求，其中 t 表示以毫秒为单位的某个时间，并返回过去 3000 毫秒内发生的所有请求数（包括新请求）。确切地说，返回在 [t-3000, t] 内发生的请求数。

保证 每次对 ping 的调用都使用比之前更大的 t 值。

### 示例：

- 输入：
  - inputs = ["RecentCounter", "ping", "ping", "ping", "ping"]
  - inputs = [[], [1], [100], [3001], [3002]]
- 输出：
  - [null, 1, 2, 3, 3]
- 解释：
  - RecentCounter recentCounter = new RecentCounter();
  - recentCounter.ping(1); // requests = [1]，范围是 [-2999,1]，返回 1
  - recentCounter.ping(100); // requests = [1, 100]，范围是 [-2900,100]，返回 2
  - recentCounter.ping(3001); // requests = [1, 100, 3001]，范围是 [1,3001]，返回 3
  - recentCounter.ping(3002); // requests = [1, 100, 3001, 3002]，范围是 [2,3002]，返回 3

### 提示：

- 1 <= t <= 10^9
- 保证每次对 ping 调用所使用的 t 值都 严格递增
- 至多调用 ping 方法 10^4 次

## 题目思考

1. 可以使用什么数据结构模拟整个过程?

## 解决方案

#### 思路

- 分析题目, 要想动态维护过去 3000 毫秒内发生的所有请求数, 需要支持一端添加新元素, 另一端移除老元素, 显然可以使用双端队列来模拟这个过程
- 每次调用 ping 函数时:
  - 先将新请求添加到队列末尾
  - 然后循环判断队列开头请求是否不在时间窗口内, 不在的话移除它并继续循环
  - 循环结束时, 队列里存储的就是时间窗口内的所有请求, 返回队列长度即可
- 下面的代码就对应了上面的整个过程, 并且有详细的注释, 方便大家理解

#### 复杂度

- 时间复杂度 O(1): 每个请求最多入队和出队各一次, 所以每次操作的均摊时间复杂度为 O(1)
- 空间复杂度 O(N): 双端队列最多存储全部 N 个元素

#### 代码

```python
class RecentCounter:
    def __init__(self):
        # 初始化一个双端队列
        self.q = collections.deque()

    def ping(self, t: int) -> int:
        # 将当前元素加入队尾
        self.q.append(t)
        # 这里由于刚入队一个元素, 且其一定不满足循环条件
        # 所以可以保证队列至少有一个元素(t), 无需判断q是否为空
        while self.q[0] < t - 3000:
            # 队头元素不在时间窗口[t-3000,t]内了, 将其出队
            self.q.popleft()
        # 最终队列剩余的元素个数即为时间窗口内的总请求数
        return len(self.q)
```
