> 题目难度: 困难

> [原题链接](https://leetcode.cn/problems/om3reC/)

## 题目描述

在字典（单词列表） wordList 中，从单词 beginWord 和 endWord 的 转换序列 是一个按下述规格形成的序列：

- 序列中第一个单词是 beginWord 。
- 序列中最后一个单词是 endWord 。
- 每次转换只能改变一个字母。
- 转换过程中的中间单词必须是字典 wordList 中的单词。

给定两个长度相同但内容不同的单词 beginWord 和 endWord 和一个字典 wordList ，找到从 beginWord 到 endWord 的 最短转换序列 中的 单词数目 。如果不存在这样的转换序列，返回 0。

### 示例 1：

- 输入：beginWord = "hit", endWord = "cog", wordList = ["hot","dot","dog","lot","log","cog"]
- 输出：5
- 解释：一个最短转换序列是 "hit" -> "hot" -> "dot" -> "dog" -> "cog", 返回它的长度 5。

### 示例 2：

- 输入：beginWord = "hit", endWord = "cog", wordList = ["hot","dot","dog","lot","log"]
- 输出：0
- 解释：endWord "cog" 不在字典中，所以无法进行转换。

### 提示：

- 1 <= beginWord.length <= 10
- endWord.length == beginWord.length
- 1 <= wordList.length <= 5000
- wordList[i].length == beginWord.length
- beginWord、endWord 和 wordList[i] 由小写英文字母组成
- beginWord != endWord
- wordList 中的所有字符串 互不相同

## 题目思考

1. 如何尽可能优化时间复杂度?

## 解决方案

- 分析题目, 要求最短转换序列, 也就是 beginWord 到 endWord 的最少单词数目, 我们可以尝试 BFS:
  - 我们可以维护一个队列 q 记录当前需要遍历的单词, 并使用一个集合 v 记录已经遍历过的单词, 且初始化单词数目 cnt 为 1
  - 然后从 beginWord 出发, 将其加入队列 q 和集合 v 中
  - 接下来开始 BFS 的每轮遍历: 初始化一个新队列 nq, 对于当前队列 q 的单词, 遍历整个字典 wordList, 如果某个单词不在已遍历集合 v 中, 且和当前单词恰好只差一个字母, 则将其加入新队列 nq 和集合 v 中, 等待下次遍历
  - 等到当前队列 q 遍历结束后, 单词数目 cnt 加 1, 并将新队列 nq 赋值给当前队列 q, 开始新一轮的遍历, 直到 q 没有单词为止
  - 在遍历过程中, 如果 q 的单词恰好等于 endWord, 则说明找到了最短转换序列, 直接返回当前单词数目 cnt 即可
  - 如果直到遍历结束都没得到 endWord, 则说明不存在这样的转换序列, 返回 0
- 拿题目的示例 1 来说, 上述过程如下:
  - `beginWord = "hit", endWord = "cog", wordList = ["hot","dot","dog","lot","log","cog"]`
  - 第一轮开始时 q 和 v 包含`[hit]`, cnt 是 1; 结束时只有 hot 满足要求, 将其加入 nq 和 v 中, 同时 cnt 加到 2
  - 第二轮开始时 q 包含`[hot]`, v 包含`[hit, hot]`, cnt 是 2; 结束时 dot 和 lot 都满足要求, 将其加入 nq 和 v 中, 同时 cnt 加到 3
  - 第三轮开始时 q 包含`[dot, lot]`, v 包含`[hit, hot, dot, lot]`, cnt 是 3; 结束时 dog 和 log 都满足要求, 将其加入 nq 和 v 中, 同时 cnt 加到 4
  - 第四轮开始时 q 包含`[dog, log]`, v 包含`[hit, hot, dot, lot, dog, log]`, cnt 是 4; 而结束时只有 cog 都满足要求, 将其加入 nq 和 v 中, 同时 cnt 加到 5
  - 第五轮开始时 q 包含`[cog]`, v 包含`[hit, hot, dot, lot, dog, log, cog]`, cnt 是 5, 遍历时发现 cog 恰好等于 endWord, 所以就返回当前 cnt 5
- 以上就是最基本的 BFS 思路, 它的时间复杂度是`O(C*N^2)` (C 是单词平均长度, N 是单词字典的单词个数), 因为最差情况下每个单词需要被遍历一遍 (`O(N)`), 然后遍历时需要查找所有单词字典的单词 (`O(N)`), 并判断它是否已经被遍历 (`O(C)`), 如何优化呢?
- 回顾题目规模, 我们可以发现单词长度最大只有 10, 且只由 26 个小写英文字母组成
- 所以我们可以换个方式, 遍历单词的每个位置, 将其替换成其他 25 个小写字母, 从而组成新的可转换单词
- 然后判断该单词是否存在于单词字典且不存在于集合中, 是的话就可以遍历, 这里需要先额外将单词字典从列表转成集合, 从而加速查询
- 这样就把第二个`O(N)`优化到了`O(C*25)`, N 最大是 5000, 而 `C*25` 最大也只有 250, 优化了一个数量级, 最终时间复杂度也就变成了`O(C^2*25*N)`
- 另外, 在上面的优化之后, 我们需要判断该单词是否存在于单词字典且不存在于集合中, 而这两步完全可以合二为一: 我们不再需要已遍历集合, 而是如果该单词存在于单词字典集合中时, 就直接将其从该集合中移除, 这样可以节省不必要的空间消耗
- 下面的代码对必要步骤有详细的解释, 方便大家理解

#### 复杂度

- 时间复杂度 `O(C^2*25*N)`: 最差情况下每个单词需要被遍历一遍 (`O(N)`), 然后遍历时需要查找所有可转换单词 (`O(C*25)`), 并判断它是否已经被遍历 (`O(C)`)
- 空间复杂度 `O(C*N)`: 队列和集合占用的空间

#### 代码

```python
class Solution:
    def ladderLength(self, beginWord: str, endWord: str, wordList: List[str]) -> int:
        # 先将单词字典列表转成集合
        wordSet = set(wordList)
        q = [beginWord]

        def getNext(w):
            # 找出w可以转换的所有单词
            for i, c in enumerate(w):
                for o in range(26):
                    cc = chr(ord("a") + o)
                    if cc != c:
                        # 将第i位的c替换成cc, 形成新的单词
                        yield w[:i] + cc + w[i + 1 :]

        # 初始化序列单词数目为1, 即beginWord
        cnt = 1
        while q:
            nq = []
            for w in q:
                if w == endWord:
                    # 转换成endWord, 此时的cnt就是最短序列的单词数目
                    return cnt
                for nex in getNext(w):
                    if nex in wordSet:
                        # 该单词存在于字典中, 可以使用它
                        # 使用后将其移出字典, 因为后续有序列再使用它的话, 一定不是最短序列
                        wordSet.remove(nex)
                        # 将其加入新的队列中, 等待后续处理
                        nq.append(nex)
            q = nq
            cnt += 1
        # 没有找到有效的转换序列, 返回0
        return 0
```
