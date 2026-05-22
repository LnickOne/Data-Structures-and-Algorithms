> 题目难度: 简单

> [原题链接](https://leetcode.cn/problems/ti-huan-kong-ge-lcof/)

## 题目描述

假定一段路径记作字符串 path，其中以 "." 作为分隔符。现需将路径加密，加密方法为将 path 中的分隔符替换为空格 " "，请返回加密后的字符串。

### 示例 1：

- 输入：path = "a.aef.qerf.bb"

- 输出："a aef qerf bb"

### 限制：

- 0 <= path.length <= 10000

## 题目思考

1. 如何优化效率?

## 解决方案

- 分析题目, 我们可以直接遍历原始字符串, 然后初始化一个空的字符串, 遇到 `.` 就追加空格, 否则就追加原始字符即可
- 对于 Python3, 由于 `str` 不可变, 如果直接使用 `+=` 操作符, 会导致每次都要重新创建一个新的字符串, 效率较低
- 所以我们可以利用可变的`list` 以及它的 `join` 方法, 每次操作 `append` 新字符, 最后再使用 `join` 方法将列表中的字符连接起来, 这样就无需每次追加都创建新的字符串了
- 类似的, 对于 Java, 可以使用 `StringBuilder` 来提高效率
- 下面的代码对必要步骤有详细的解释, 方便大家理解

#### 复杂度

- 时间复杂度 `O(N)`: 只需要遍历一次原始字符串
- 空间复杂度 `O(N)`: 使用了一个额外的列表来存储最终结果

#### 代码

```python
class Solution:
    def pathEncryption(self, path: str) -> str:
        # 初始化一个空列表, 用于存储最终结果
        res = []
        for c in path:
            if c == '.':
                # 遇到 `.` 就追加空格
                res.append(' ')
            else:
                # 否则就追加原始字符
                res.append(c)
        # 最后使用join方法将列表中的字符连接起来
        return ''.join(res)

```
