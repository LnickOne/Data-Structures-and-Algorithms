#
# @lc app=leetcode.cn id=13 lang=python3
#
# [13] 罗马数字转整数
#
# 思路：
# 1. 罗马数字的规则是：如果一个小的数字在大的数字的左边，那么就用大的数字减去小的数字；如果一个小的数字在大的数字的右边，那么就用大的数字加上小的数字。
# 2. 所以我们可以从左到右遍历罗马数字，每次判断当前数字是否比下一个数字小，如果是，就用下一个数字减去当前数字，否则就用下一个数字加上当前数字。
# 3. 最后返回结果即可。

# @lc code=start
from typing import List


class Solution:
    def romanToInt(self, s: str) -> int:
        if not s or len(s) == 0:
            return 0
        map = {"I": 1, "V": 5, "X": 10, "L": 50, "C": 100, "D": 500, "M": 1000}
        result = 0
        for i in range(len(s)):
            if i + 1 < len(s) and map[s[i]] < map[s[i + 1]]:
                result -= map[s[i]]
            else:
                result += map[s[i]]
        return result


print(Solution().romanToInt("III"))
print(Solution().romanToInt("IV"))
print(Solution().romanToInt("IX"))
print(Solution().romanToInt("LVIII"))
print(Solution().romanToInt("MCMXCIV"))

# @lc code=end
