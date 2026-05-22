> 题目难度: 中等

> [原题链接](https://leetcode.cn/problems/US1pGT/)

## 题目描述

设计一个使用单词列表进行初始化的数据结构，单词列表中的单词 互不相同 。 如果给出一个单词，请判定能否只将这个单词中一个字母换成另一个字母，使得所形成的新单词存在于已构建的神奇字典中。

实现 MagicDictionary 类：

- MagicDictionary() 初始化对象
- void buildDict(String[] dictionary) 使用字符串数组 dictionary 设定该数据结构，dictionary 中的字符串互不相同
- bool search(String searchWord) 给定一个字符串 searchWord ，判定能否只将字符串中 一个 字母换成另一个字母，使得所形成的新字符串能够与字典中的任一字符串匹配。如果可以，返回 true ；否则，返回 false 。

### 示例：

- 输入
  - inputs = ["MagicDictionary", "buildDict", "search", "search", "search", "search"]
  - inputs = [[], [["hello", "leetcode"]], ["hello"], ["hhllo"], ["hell"], ["leetcoded"]]
- 输出
  - [null, null, false, true, false, false]
- 解释

```Java
MagicDictionary magicDictionary = new MagicDictionary();
magicDictionary.buildDict(["hello", "leetcode"]);
magicDictionary.search("hello"); // 返回 False
magicDictionary.search("hhllo"); // 将第二个 'h' 替换为 'e' 可以匹配 "hello" ，所以返回 True
magicDictionary.search("hell"); // 返回 False
magicDictionary.search("leetcoded"); // 返回 False
```

### 提示：

- 1 <= dictionary.length <= 100
- 1 <= dictionary[i].length <= 100
- dictionary[i] 仅由小写英文字母组成
- dictionary 中的所有字符串 互不相同
- 1 <= searchWord.length <= 100
- searchWord 仅由小写英文字母组成
- buildDict 仅在 search 之前调用一次
- 最多调用 100 次 search

## 题目思考

1. 需要使用什么数据结构?
2. 如果需要频繁调用 search, 如何优化?

## 解决方案

#### 思路

- 分析题目, 可以发现题目规模很小, 单词数量和长度最多只有 100, 而搜索次数也是如此, 所以我们可以直接使用暴力法来解决
- 我们将原始字符串数组数组保存下来, 然后每次 search 时, 遍历整个词典, 判断当前单词是否可以通过输入单词替换某一个字符来获得
- 是的话就返回 true, 如果遍历结束时还没返回, 则说明输入单词不能通过替换某个字符的方式转换成词典中的单词, 返回 false
- 上面的判断过程具体如下:
  - 首先比较两个单词长度, 长度不相等则一定不行, 返回 false
  - 接下来遍历每个下标, 比较相同下标对应的字符, 并维护一个 flag hasDiff, 代表是否有不同
  - 当某两个字符不同时, 就判断 hasDiff: 如果已经设置为 true, 则说明之前存在另一对字符不同, 所以不能通过只改变一个字符获得, 此时返回 false; 否则将 hasDiff 设为 true, 继续遍历
  - 遍历结束时, 需判断 hasDiff 是否为 true, 是的话才说明可行, 因为题目要求必须替换一个字符, 不能完全相同
- 按照题目的规模, 暴力法完全可以胜任, 那如果 search 方法需要被频繁调用 (比如几十万次), 又该如何解决呢?
- 此时我们需要尽可能优化 search 的复杂度, 暴力法每次都需要遍历整个词典, 显然不是很好
- 注意到 buildDict 方法只需要在开始时调用一次, 我们可以把重量级的操作都放到这里
- 也就是说, 我们可以预先把词典中每个单词更改一个字符后得到的新单词都保存到一个集合里, 这样 search 时只需要判断集合是否存在输入单词即可
- 上面的保存过程具体如下:
  - 外层遍历整个词典
  - 中层遍历当前单词的下标
  - 内层遍历 26 个字母, 注意新单词不能和原单词相同, 所以需要额外判断字母是否和原字母一样
  - 字母不同时, 将当前下标替换成该字母, 从而构建出新的单词, 并加入集合中
- 通过上述过程, 我们成功优化了 search 的复杂度, 这就是典型的预处理的思想
- 下面代码针对两种方法都有详细的注释, 方便大家理解

#### 复杂度

- 暴力法
  - 时间复杂度: 假设 N 是词典单词的数目, C 是每个单词的平均长度, 那么 buildDict 方法是 O(1), 而 search 方法是 O(NC)
  - 空间复杂度 O(NC): 词典需要保存所有字符
- 预处理法
  - 时间复杂度: 假设 N 是词典单词的数目, C 是每个单词的平均长度, 那么 buildDict 方法是 O(NC\*26), 而 search 方法是 O(C)
  - 空间复杂度 O(NC\*25C): 词典需要保存所有单词的所有变种, 长度为 C 的单词有 25\*C 个变种

#### 代码

```python
# 方法1: 数组存原始单词+搜索时遍历数组
class MagicDictionary:
    def __init__(self):
        """
        Initialize your data structure here.
        """
        self.dict = []

    def buildDict(self, dictionary: List[str]) -> None:
        self.dict = dictionary

    def search(self, searchWord: str) -> bool:
        def match(d, w):
            if len(d) != len(w):
                # 长度不相等, 不匹配
                return False
            hasDiff = False
            for c1, c2 in zip(d, w):
                if c1 != c2:
                    if hasDiff:
                        # 超过一个字符不同, 不匹配
                        return False
                    hasDiff = True
            # 注意最终需要保证两单词恰好有一个字符不同
            return hasDiff

        for d in self.dict:
            if match(d, searchWord):
                return True
        return False

# 方法2 (优化search): 集合+buildDict时存所有变种
class MagicDictionary:
    def __init__(self):
        """
        Initialize your data structure here.
        """
        self.dict = set()

    def buildDict(self, dictionary: List[str]) -> None:
        for w in dictionary:
            for i, c in enumerate(w):
                for o in range(26):
                    # 将i位字符替换成其他字符
                    cc = chr(ord("a") + o)
                    if cc != c:
                        # 注意: 不能存储原始单词, 必须替换一个字符
                        cur = w[:i] + cc + w[i + 1 :]
                        self.dict.add(cur)

    def search(self, searchWord: str) -> bool:
        return searchWord in self.dict
```
