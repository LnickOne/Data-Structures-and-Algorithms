> 题目难度: 中等

> [原题链接](https://leetcode.cn/problems/sfvd7V/)

## 题目描述

某种外星语也使用英文小写字母，但可能顺序 order 不同。字母表的顺序（order）是一些小写字母的排列。

给定一组用外星语书写的单词 words，以及其字母表的顺序 order，只有当给定的单词在这种外星语中按字典序排列时，返回 true；否则，返回 false。

### 示例 1：

- 输入：words = ["hello","leetcode"], order = "hlabcdefgijkmnopqrstuvwxyz"
- 输出：true
- 解释：在该语言的字母表中，'h' 位于 'l' 之前，所以单词序列是按字典序排列的。

### 示例 2：

- 输入：words = ["word","world","row"], order = "worldabcefghijkmnpqstuvxyz"
- 输出：false
- 解释：在该语言的字母表中，'d' 位于 'l' 之后，那么 words[0] > words[1]，因此单词序列不是按字典序排列的。

### 示例 3：

- 输入：words = ["apple","app"], order = "abcdefghijklmnopqrstuvwxyz"
- 输出：false
- 解释：当前三个字符 "app" 匹配时，第二个字符串相对短一些，然后根据词典编纂规则 "apple" > "app"，因为 'l' > '∅'，其中 '∅' 是空白字符，定义为比任何其他字符都小（更多信息）。

### 提示：

- 1 <= words.length <= 100
- 1 <= words[i].length <= 20
- order.length == 26
- 在 words[i] 和 order 中的所有字符都是英文小写字母。

## 题目思考

1. 如何给定字母表来判断顺序?
2. 如何判断单词列表是否有序?

## 解决方案

#### 思路

- 根据题目描述, 我们需要做两件事:
  1. 根据给定字母表判断两个单词的字典序
  2. 判断给定单词是否按照该字典序排列
- 针对第一个需求:
  - 我们可以根据给定字母表定义一个下标映射字典, 字符对应下标越大, 则其自身越大, 这样就把字符的比较转换成其字母表下标的比较
  - 然后自定义一个 le(小于等于) 方法, 参数为两个字符串
  - 在该方法中, 依次遍历相同位置的两个字符
  - 如果两字符对应的下标不相等, 则可以直接返回 True(前者更小)或 False(后者更小)
  - 否则继续遍历, 直到较短的一个字符串遍历完毕
  - 此时说明两字符串前缀相同, 则只有当前者长度不超过后者时, 才说明前者字符串小于等于后者
- 针对第二个需求:
  - 我们可以从下标 1 的单词开始遍历
  - 然后利用先前定义好的 le 方法, 传入前一个单词和当前单词
  - 如果返回 False, 则说明前一个单词更大, 不是有序的
  - 否则继续遍历, 如果遍历结束仍未返回, 则说明全部单词都有序, 返回 True
- 下面的代码就对应了上面的整个过程, 并且有详细的注释, 方便大家理解

#### 复杂度

- 时间复杂度 `O(NM)`: N 是字符串数目, M 是字符串长度, 需要遍历每个字符串的每个字符最多两遍
- 空间复杂度 `O(C)`: C 是字符种类数, 额外使用了一个下标映射字典

#### 代码

```python
class Solution:
    def isAlienSorted(self, words: List[str], order: str) -> bool:
        # 下标映射字典+自定义比较相邻单词+特殊处理前缀相等
        # 构造字符->下标映射字典
        maps = {}
        for i, c in enumerate(order):
            maps[c] = i

        def le(s1, s2):
            # 判断字符串s1是否小于等于s2
            for i in range(min(len(s1), len(s2))):
                if maps[s1[i]] < maps[s2[i]]:
                    # 当前s1字符映射下标小于s2的, 说明s1小于s2, 直接返回
                    return True
                if maps[s1[i]] > maps[s2[i]]:
                    # 当前s1字符映射下标大于s2的, 说明s1大于s2, 直接返回
                    return False
            # 此时说明s1和s2的前缀相等, 只有当s1长度不超过s2时, s1才小于等于s2
            return len(s1) <= len(s2)

        for i in range(1, len(words)):
            if not le(words[i - 1], words[i]):
                # 前一个单词大于当前单词, 说明不是有序
                return False
        return True
```
