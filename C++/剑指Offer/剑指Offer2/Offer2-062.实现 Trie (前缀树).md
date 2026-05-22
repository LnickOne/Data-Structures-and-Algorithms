> 题目难度: 中等

> [原题链接](https://leetcode.cn/problems/QC3q1f/)

## 题目描述

Trie（发音类似 "try"）或者说 前缀树 是一种树形数据结构，用于高效地存储和检索字符串数据集中的键。这一数据结构有相当多的应用情景，例如自动补完和拼写检查。

请你实现 Trie 类：

- Trie() 初始化前缀树对象。
- void insert(String word) 向前缀树中插入字符串 word 。
- boolean search(String word) 如果字符串 word 在前缀树中，返回 true（即，在检索之前已经插入）；否则，返回 false 。
- boolean startsWith(String prefix) 如果之前已经插入的字符串 word 的前缀之一为 prefix ，返回 true ；否则，返回 false 。

### 示例：

- 输入
  - inputs = ["Trie", "insert", "search", "search", "startsWith", "insert", "search"]
  - inputs = [[], ["apple"], ["apple"], ["app"], ["app"], ["app"], ["app"]]
- 输出
  - [null, null, true, false, true, null, true]
- 解释

```java
Trie trie = new Trie();
trie.insert("apple");
trie.search("apple");   // 返回 True
trie.search("app");     // 返回 False
trie.startsWith("app"); // 返回 True
trie.insert("app");
trie.search("app");     // 返回 True
```

### 提示：

- 1 <= word.length, prefix.length <= 2000
- word 和 prefix 仅由小写英文字母组成
- insert、search 和 startsWith 调用次数 总计 不超过 3 \* 10^4 次

## 题目思考

1. 如何定义哪些类, 包含哪些字段?

## 解决方案

#### 思路

- 这道题就是典型的 Trie 的实现, 可以参考下图:
  - ![Trie](https://bkimg.cdn.bcebos.com/pic/8cb1cb1349540923dd5444ffe40ec609b3de9d82e3ae?x-bce-process=image/watermark,image_d2F0ZXIvYmFpa2U4MA==,g_7,xp_5,yp_5/format,f_auto)
- 从图中可以看出, 每个非叶节点指向其子节点的边上都有一个字符
- 另外有的节点标记为红色, 代表从根节点到该节点形成了一个完整的单词, 而不是前缀
- 根据这些信息, 我们可以设计出所需的节点类 Node, 它用于存储每个节点的信息
  - Node 类里面需要包含一个{字符->子节点}的字典, 来模拟图中带字符的边
  - 另外 Node 类还要包含一个 boolean, 用于存储当前节点作为终点时是否构成一个完整单词, 初始化为 false
- 接下来我们在 Trie 类中维护一个根节点, 每次操作都从根节点开始
- 在执行 insert 操作时:
  - 维护当前节点, 初始化为根
  - 然后遍历单词的每个字符, 如果当前节点不存在一个对应字符的子节点时, 就创建它
  - 然后将当前节点指向对应的子节点, 继续这个过程直到遍历结束
  - 此时我们将当前节点的 boolean 设置为 true, 表示从根节点到当前节点形成了一个完整的单词
- 对于 search 和 startsWith 操作, 它们唯一的区别就是最终节点是否形成单词, 所以我们可以将共享的逻辑提取出来:
  - 维护当前节点, 初始化为根
  - 然后遍历待查询字符串的每个字符, 如果当前节点不存在一个对应字符的子节点时, 就返回空
  - 否则将当前节点指向对应的子节点, 继续这个过程直到遍历结束
  - 此时的当前节点就是最终节点, 返回它
- 在得到最终节点后:
  - search 操作需要它非空且对应的 boolean 是 true 时才返回 true
  - startsWith 操作只需要它非空就返回 true
- 下面代码中有详细的注释, 方便大家理解

#### 复杂度

- 时间复杂度 O(NC): 假设需要操作 N 次, 每次操作的字符串平均长度为 C, 那么每个操作都需要从根开始最多遍历 C 个节点, 时间复杂度都是 O(C), 所以总体时间复杂度就是 O(NC)
- 空间复杂度 O(NC): Trie 中需要存储所有单词的字符, 最差情况下没有重复使用的节点, 空间复杂度就是 O(NC)

#### 代码

```python
class Node:
    def __init__(self):
        # {字符->子节点}字典
        self.children = {}
        # boolean flag判断当前节点结尾时是否构成单词
        self.isWord = False

class Trie:
    def __init__(self):
        """
        Initialize your data structure here.
        """
        # 保存根节点
        self.root = Node()

    def insert(self, word: str) -> None:
        """
        Inserts a word into the trie.
        """
        # 初始化为根节点
        cur = self.root
        for c in word:
            if c not in cur.children:
                # 子节点不存在时创建它
                cur.children[c] = Node()
            cur = cur.children[c]
        # 根节点->最终节点的路径形成了完整的单词
        cur.isWord = True

    def find(self, word: str) -> Node:
        cur = self.root
        for c in word:
            if c not in cur.children:
                # 子节点不存在时返回空
                return None
            cur = cur.children[c]
        # 返回最终节点
        return cur

    def search(self, word: str) -> bool:
        """
        Returns if the word is in the trie.
        """
        last_node = self.find(word)
        # 最终节点不为空且形成单词时才返回true
        return last_node is not None and last_node.isWord

    def startsWith(self, prefix: str) -> bool:
        """
        Returns if there is any word in the trie that starts with the given prefix.
        """
        # 最终节点不为空时返回true
        return self.find(prefix) is not None
```
