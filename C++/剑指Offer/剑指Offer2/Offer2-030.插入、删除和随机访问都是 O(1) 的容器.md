> 题目难度: 中等

> [原题链接](https://leetcode.cn/problems/FortPu/)

## 题目描述

设计一个支持在平均 时间复杂度 O(1) 下，执行以下操作的数据结构：

- insert(val)：当元素 val 不存在时返回 true ，并向集合中插入该项，否则返回 false 。
- remove(val)：当元素 val 存在时返回 true ，并从集合中移除该项，否则返回 false 。
- getRandom：随机返回现有集合中的一项。每个元素应该有 相同的概率 被返回。

### 示例 :

- 输入: inputs = ["RandomizedSet", "insert", "remove", "insert", "getRandom", "remove", "insert", "getRandom"]
  [[], [1], [2], [2], [], [1], [2], []]
- 输出: [null, true, false, true, 2, true, false, 2]
- 解释:

```java
RandomizedSet randomSet = new RandomizedSet(); // 初始化一个空的集合
randomSet.insert(1); // 向集合中插入 1 ， 返回 true 表示 1 被成功地插入
randomSet.remove(2); // 返回 false，表示集合中不存在 2
randomSet.insert(2); // 向集合中插入 2 返回 true ，集合现在包含 [1,2]
randomSet.getRandom(); // getRandom 应随机返回 1 或 2
randomSet.remove(1); // 从集合中移除 1 返回 true 。集合现在包含 [2]
randomSet.insert(2); // 2 已在集合中，所以返回 false
randomSet.getRandom(); // 由于 2 是集合中唯一的数字，getRandom 总是返回 2
```

### 提示：

- -2^31 <= val <= 2^31 - 1
- 最多进行 2 \* 10^5 次 insert ， remove 和 getRandom 方法调用
- 当调用 getRandom 方法时，集合中至少有一个元素

## 题目思考

1. 需要用到哪些数据结构?

## 解决方案

#### 思路

- 分析题目, 最容易想到的思路就是利用 set, 这样插入和删除都是 O(1) 时间
- 但 set 的问题是 getRandom 无法做到 O(1), 必须得先转成数组, 然后取其随机下标才行
- 要想 getRandom 操作是 O(1) 时间, 我们必须维护一个数组, 但其删除元素不是 O(1), 如何解决呢?
- 回顾数组的性质, 其删除末尾元素只需要 O(1) 时间, 我们如果可以将删除任意元素转换成删除末尾元素, 就能做到所有操作都是 O(1) 了, 这要如何实现呢?
- 我们如果能够知道任意元素的下标, 那么在删除它时, 可以将它与末尾元素进行交换, 这样就转换成了删除末尾元素
- 不难想到我们可以使用一个元素到下标的映射字典来实现, 然后在插入和删除时增加一些额外的操作来更新该字典
- 插入时, 我们先利用该字典判断元素是否存在 (O(1)), 不存在时只需要将元素插入到数组末尾 (O(1)), 然后在字典中增加一项, 即它到新的末尾下标的映射 (O(1))
- 删除时, 同样先判断元素是否存在于字典中 (O(1)), 存在时拿到元素对应下标 (O(1)), 如果该下标不是末尾, 则将其与末尾元素交换 (O(1)), 同时更新映射字典 ((O(1))), 最后再移除数组的末尾元素 (O(1)), 以及字典中该元素的映射关系即可 ((O(1)))
- 取随机项时, 利用 random 库直接得到一个数组范围内的下标, 并返回数组对应元素即可 (O(1))
- 综上所述, 所有操作都只需要 O(1) 时间
- 下面代码有详细的注释, 方便大家理解

#### 复杂度

- 时间复杂度 O(1): 每种操作都只需要常数时间
- 空间复杂度 O(N): 数组和字典各需要 O(N) 空间

#### 代码

```python
class RandomizedSet:
    def __init__(self):
        """
        Initialize your data structure here.
        """
        # 初始化数组(用于取随机数)和v2i字典(用于维护值和下标的对应关系)
        self.arr = []
        self.v2i = {}

    def insert(self, val: int) -> bool:
        """
        Inserts a value to the set. Returns true if the set did not already contain the specified element.
        """
        if val in self.v2i:
            # 该值已存在, 不进行操作
            return False
        # 追加到数组末尾, 并更新v2i字典
        self.arr.append(val)
        self.v2i[val] = len(self.arr) - 1
        return True

    def remove(self, val: int) -> bool:
        """
        Removes a value from the set. Returns true if the set contained the specified element.
        """
        if val in self.v2i:
            # 该值存在, 找到它的下标
            i = self.v2i[val]
            end = len(self.arr) - 1
            if i != end:
                # 如果待移除下标不是末尾, 则将它和末尾下标交换, 并更新v2i字典
                self.arr[i], self.arr[end] = self.arr[end], self.arr[i]
                self.v2i[self.arr[i]] = i
            # 这样只需要O(1)时间移除数组末尾元素和v2i字典对应项即可
            self.arr.pop()
            del self.v2i[val]
            return True
        return False

    def getRandom(self) -> int:
        """
        Get a random element from the set.
        """
        # 使用randrange获取[0,n)的随机下标
        i = random.randrange(len(self.arr))
        return self.arr[i]
```
