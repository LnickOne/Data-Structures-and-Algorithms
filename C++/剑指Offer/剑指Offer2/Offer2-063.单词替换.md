> 题目难度: 中等

> [原题链接](https://leetcode.cn/problems/UhWRSj/)

## 题目描述

在英语中，有一个叫做 词根(root) 的概念，它可以跟着其他一些词组成另一个较长的单词——我们称这个词为 继承词(successor)。例如，词根 an，跟随着单词 other(其他)，可以形成新的单词 another(另一个)。

现在，给定一个由许多词根组成的词典和一个句子，需要将句子中的所有继承词用词根替换掉。如果继承词有许多可以形成它的词根，则用最短的词根替换它。

需要输出替换之后的句子。

### 示例 1：

- 输入：dictionary = ["cat","bat","rat"], sentence = "the cattle was rattled by the battery"
- 输出："the cat was rat by the bat"

### 示例 2：

- 输入：dictionary = ["a","b","c"], sentence = "aadsfasf absbs bbab cadsfafs"
- 输出："a a b c"

### 示例 3：

- 输入：dictionary = ["a", "aa", "aaa", "aaaa"], sentence = "a aa a aaaa aaa aaa aaa aaaaaa bbb baba ababa"
- 输出："a a a a a a a a bbb baba a"

### 示例 4：

- 输入：dictionary = ["catt","cat","bat","rat"], sentence = "the cattle was rattled by the battery"
- 输出："the cat was rat by the bat"

### 示例 5：

- 输入：dictionary = ["ac","ab"], sentence = "it is abnormal that this solution is accepted"
- 输出："it is ab that this solution is ac"

### 提示：

- 1 <= dictionary.length <= 1000
- 1 <= dictionary[i].length <= 100
- dictionary[i] 仅由小写字母组成。
- 1 <= sentence.length <= 10^6
- sentence 仅由小写字母和空格组成。
- sentence 中单词的总量在范围 [1, 1000] 内。
- sentence 中每个单词的长度在范围 [1, 1000] 内。
- sentence 中单词之间由一个空格隔开。
- sentence 没有前导或尾随空格。

## 题目思考

1. 需要使用什么数据结构?

## 解决方案

#### 思路

- 分析题目, 一个很容易想到的思路就是: 针对句子的每个原始单词, 遍历整个词典, 利用双指针判断词典单词是否是其前缀. 遍历结束时, 如果没有前缀, 则仍用原始单词自身; 否则就用最小长度的前缀作为其词根, 并替换原始单词.
- 不过上述方法需要两重循环, 每个字符都要处理多遍, 效率太低, 有没有更优的方法呢?
- 回顾题目本身, 我们需要找出句子单词的最短前缀, 而对于前缀问题, 我们都可以先尝试上一道题目([Leetcode 剑指 Offer II 062. 实现 Trie (前缀树)](https://mp.weixin.qq.com/s?__biz=MzA5MDk1MjI5MA==&mid=2247484734&idx=1&sn=c8f9ff3725bd6a41647bf1dba47d9dce&token=1922837604&lang=zh_CN#rd))的思路, 然后根据具体问题进行一些改动
- 首先, 插入单词的逻辑保持不变, 仍然是遍历整个词典插入所有单词
- 其次, 这道题目不需要搜索完整单词或者前缀, 而是需要进行替换, 所以我们移除之前的 search 和 startsWith 方法, 创建额外的 replace 方法:
  - 维护当前节点, 初始化为根
  - 然后遍历句子单词的每个字符, 如果当前节点不存在一个对应字符的子节点时, 说明词典中没有该单词的词根, 返回单词本身
  - 否则将当前节点指向对应的子节点, 然后判断该节点的 isWord 标记, 如果它是 true, 则说明找到了最短的前缀, 直接返回该前缀即可
  - 否则继续上述过程直到遍历结束
  - 此时同样说明词典中没有该单词的词根, 返回单词本身
- 实现好 Trie 之后, 我们只需要把词典的单词加入 Trie 中
- 然后对句子按照空格分隔成单词, 针对每个单词调用 replace 操作, 最终再 join 成句子即可
- 下面代码中有详细的注释, 方便大家理解

#### 复杂度

- 时间复杂度 O(C1+C2): 假设词典的字符总数是 C1, 句子的字符总数是 C2, 插入时需要遍历词典的每个字符, 复杂度是 O(C1), 替换时需要遍历句子的每个字符, 复杂度是 O(C2), 所以总体时间复杂度就是 O(C1+C2)
- 空间复杂度 O(C1): Trie 中需要存储整个词典, 最差情况下没有重复使用的节点, 需要保存所有字符, 空间复杂度就是 O(C1)

#### 代码

```python
class Node:
    def __init__(self):
        self.children = {}
        self.isWord = False

class Trie:
    def __init__(self):
        self.root = Node()

    def insert(self, w):
        # 初始化为根节点
        cur = self.root
        for c in w:
            if c not in cur.children:
                # 子节点不存在时创建它
                cur.children[c] = Node()
            cur = cur.children[c]
        # 根节点->最终节点的路径形成了完整的词根
        cur.isWord = True

    def replace(self, w):
        # 初始化为根节点
        cur = self.root
        for i, c in enumerate(w):
            if c not in cur.children:
                # 词典中没有给定单词的词根, 返回单词本身
                break
            cur = cur.children[c]
            if cur.isWord:
                # 找到了一个词根, 它一定是最短的, 直接返回该词根
                return w[: i + 1]
        # 没找到词根, 返回单词本身
        return w

class Solution:
    def replaceWords(self, dictionary: List[str], sentence: str) -> str:
        trie = Trie()
        for w in dictionary:
            # 将词典中的词根添加到trie中
            trie.insert(w)
        arr = sentence.split()
        res = []
        for s in arr:
            # 对于sentence的每个单词, 尝试用最短词根替换它
            res.append(trie.replace(s))
        return " ".join(res)
```
