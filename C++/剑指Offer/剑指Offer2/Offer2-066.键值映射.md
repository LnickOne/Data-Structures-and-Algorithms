> 题目难度: 中等

> [原题链接](https://leetcode.cn/problems/z1R5dt/)

## 题目描述

实现一个 MapSum 类，支持两个方法，insert 和 sum：

- MapSum() 初始化 MapSum 对象
- void insert(String key, int val) 插入 key-val 键值对，字符串表示键 key ，整数表示值 val 。如果键 key 已经存在，那么原来的键值对将被替代成新的键值对。
- int sum(string prefix) 返回所有以该前缀 prefix 开头的键 key 的值的总和。

### 示例：

- 输入：
  - inputs = ["MapSum", "insert", "sum", "insert", "sum"]
  - inputs = [[], ["apple", 3], ["ap"], ["app", 2], ["ap"]]
- 输出：
  - [null, null, 3, null, 5]
- 解释：
  - MapSum mapSum = new MapSum();
  - mapSum.insert("apple", 3);
  - mapSum.sum("ap"); // return 3 (apple = 3)
  - mapSum.insert("app", 2);
  - mapSum.sum("ap"); // return 5 (apple + app = 3 + 2 = 5)

### 提示：

- 1 <= key.length, prefix.length <= 50
- key 和 prefix 仅由小写英文字母组成
- 1 <= val <= 1000
- 最多调用 50 次 insert 和 sum

## 题目思考

1. 如何优化时间复杂度?

## 解决方案

#### 思路

- 分析题目, 一个最直接的思路就是, 使用一个字典存储所有 key-val 键值对
- 这样 insert 时直接更新字典即可, 而针对 sum 操作, 遍历字典的所有 key, 如果它的前缀是 prefix 的话, 就累加它的值, 最终返回累加的和
- 不过这样 sum 操作的复杂度有点高, 每次都需要遍历存储的所有 key, 有没有更高效的方法呢?
- 在之前的题目中, 我们已经了解到, 字典树 trie 可以用来解决前缀问题 ([Leetcode 剑指 Offer II 062. 实现 Trie (前缀树)](https://mp.weixin.qq.com/s?__biz=MzA5MDk1MjI5MA==&mid=2247484734&idx=1&sn=c8f9ff3725bd6a41647bf1dba47d9dce&token=1922837604&lang=zh_CN#rd) / [Leetcode 剑指 Offer II 063. 单词替换](https://mp.weixin.qq.com/s?__biz=MzA5MDk1MjI5MA==&mid=2247484739&idx=1&sn=cf8e2e1b720712cfcbe3cd092e10d476&token=1214673232&lang=zh_CN#rd))
- 这道题也不例外, 我们只需要稍作改动, 每个节点额外保存当前的值总和 sum, 同时也不需要 isWord 标记了
- 另外我们还是需要维护 key-val 字典, 用于处理更新已有 key 的情况
- 在执行 insert(key, val) 操作时:
  - 首先计算当前 key 对应的每个节点需要增加的值 diff
    - 如果 key 在字典中, 则 diff 就是新值减去旧值
    - 如果 key 不在字典中, 则 diff 就是 val
  - 然后维护当前节点, 初始化为根
  - 遍历单词的每个字符, 如果当前节点不存在一个对应字符的子节点时, 就创建它
  - 然后将当前节点指向对应的子节点, 同时将节点的 sum 累加之前计算好的 diff, 继续这个过程直到遍历结束
- 在执行 sum(prefix) 操作时:
  - 维护当前节点, 初始化为根
  - 然后遍历待查询字符串的每个字符, 如果当前节点不存在一个对应字符的子节点时, 说明不存在以 prefix 为前缀的 key, 直接返回 0
  - 否则将当前节点指向对应的子节点, 继续这个过程直到遍历结束
  - 此时的当前节点的 sum 就是以该前缀 prefix 开头的键 key 的值的总和, 返回它
- 下面代码中有详细的注释, 方便大家理解

#### 复杂度

- 时间复杂度 O(C): 假设 C 是每个字符串的平均长度, insert 和 sum 操作都只需要对字符串的每个字符操作一次
- 空间复杂度 O(NC): 假设 N 是 insert 操作的次数, 最差情况下, kv 字典需要存所有字符串, trie 需要存每个字符串的所有字符

#### 代码

```python
# trie+kv字典
class Node:
    def __init__(self):
        self.children = {}
        # 记录当前节点的值总和
        self.sum = 0

class MapSum:
    def __init__(self):
        """
        Initialize your data structure here.
        """
        self.root = Node()
        # 额外kv字典记录key:value映射
        self.k2v = {}

    def insert(self, key: str, val: int) -> None:
        # diff存储当前key的路径上各个节点需要增加的值
        # 如果当前key不在字典中, 则各个节点增加的值就是val
        # 否则增加的值是新值和旧值的差
        diff = val if key not in self.k2v else val - self.k2v[key]
        self.k2v[key] = val
        cur = self.root
        for c in key:
            if c not in cur.children:
                cur.children[c] = Node()
            cur = cur.children[c]
            # 当前节点的值总和加上diff
            cur.sum += diff

    def sum(self, prefix: str) -> int:
        cur = self.root
        for c in prefix:
            if c not in cur.children:
                # 当前前缀不存在, 返回0
                return 0
            cur = cur.children[c]
        # 返回当前前缀的值总和
        return cur.sum
```
