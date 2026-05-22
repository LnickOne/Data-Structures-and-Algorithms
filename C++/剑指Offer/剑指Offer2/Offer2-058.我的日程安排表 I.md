> 题目难度: 中等

> [原题链接](https://leetcode.cn/problems/fi9suh/)

## 题目描述

- 请实现一个 MyCalendar 类来存放你的日程安排。如果要添加的时间内没有其他安排，则可以存储这个新的日程安排。

- MyCalendar 有一个 book(int start, int end)方法。它意味着在 start 到 end 时间内增加一个日程安排，注意，这里的时间是半开区间，即 [start, end), 实数 x 的范围为， start <= x < end。

- 当两个日程安排有一些时间上的交叉时（例如两个日程安排都在同一时间内），就会产生重复预订。

- 每次调用 MyCalendar.book 方法时，如果可以将日程安排成功添加到日历中而不会导致重复预订，返回 true。否则，返回 false 并且不要将该日程安排添加到日历中。

- 请按照以下步骤调用 MyCalendar 类: MyCalendar cal = new MyCalendar(); MyCalendar.book(start, end)

### 示例:

- 输入:
  - ["MyCalendar","book","book","book"]
  - [[],[10,20],[15,25],[20,30]]
- 输出:
  - [null,true,false,true]
- 解释:
  - MyCalendar myCalendar = new MyCalendar();
  - MyCalendar.book(10, 20); // returns true
  - MyCalendar.book(15, 25); // returns false ，第二个日程安排不能添加到日历中，因为时间 15 已经被第一个日程安排预定了
  - MyCalendar.book(20, 30); // returns true ，第三个日程安排可以添加到日历中，因为第一个日程安排并不包含时间 20

### 提示：

- 每个测试用例，调用 MyCalendar.book 函数最多不超过 1000 次。
- 0 <= start < end <= 10^9

## 题目思考

1. 如何优化时间复杂度?

## 解决方案

#### 思路

- 分析题目, 一个很容易想到的思路就是暴力法: 记录当前所有区间, 然后 book 新区间时依次遍历它们, 如果和新区间有重叠, 则返回 false, 否则遍历结束后插入新区间, 并返回 true
- 不过这种做法的时间复杂度达到了 O(N^2), 有没有办法优化呢?
- 其实在插入新区间时, 我们并不需要判断已有的所有区间, 而是只需要判断按顺序紧挨着新区间的左右两个区间即可: 如果它们任何一个有重叠, 则不能插入; 否则就一定可以插入, 因为其他已有区间离新区间更远, 更不可能和新区间有重叠
- 这就引入了一个新思路: 用一个有序数组来存储当前已有区间, 这样就可以根据起点进行二分查找, 快速找到新区间的左右邻居了
- 假设当前有序数组是 calendars, 新区间为 cur, 而二分查找找到的插入下标为 i, 那么其顺序一定是 `[calendars[i-1], cur, calendars[i]]`, 也即新区间的左右邻居就是下标 i-1 和 i
- 而插入新区间时也要保证有序性, 这样后续才可以继续二分查找
- 对于 Python3, 我们可以使用 sortedcontainers 库的 SortedList 做到这一点, 它提供了二分查找方法, 且它的 add 方法能保证插入后仍保证有序
- 下面代码中有详细的注释, 方便大家理解

#### 复杂度

- 时间复杂度 O(NlogN): 每次 book 操作时的二分查找和有序数组插入都是 O(logN), 共有 N 次 book 操作, 所以总共是 O(NlogN)
- 空间复杂度 O(N): 额外有序数组存储所有区间

#### 代码

```python
from sortedcontainers import SortedList

class MyCalendar:
    def __init__(self):
        self.calendars = SortedList()

    def hasIntersect(self, range1, range2):
        # 判断两个区间是否有重叠
        s1, e1 = range1
        s2, e2 = range2
        return not (s2 >= e1 or s1 >= e2)

    def book(self, start: int, end: int) -> bool:
        # 二分查找当前区间应该插入的位置
        i = self.calendars.bisect_left([start, end])
        for j in (i - 1, i):
            # 只需要判断当前区间cur的左右两个相邻区间, 即[calendars[i-1], cur, calendars[i]]
            if 0 <= j < len(self.calendars) and self.hasIntersect(self.calendars[j], [start, end]):
                return False
        self.calendars.add([start, end])
        return True
```
