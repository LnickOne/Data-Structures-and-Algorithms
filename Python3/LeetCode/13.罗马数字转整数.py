#
# @lc app=leetcode.cn id=13 lang=python3
#
# [13] 罗马数字转整数
#


# @lc code=start
from typing import List


class Solution:
    def romanToInt(self, s: str) -> int:
        if not s or len(s) == 0:
            return 0
        map = {}
        map = {"I": 1, "V": 5, "X": 10, "L": 50, "C": 100, "D": 500, "M": 1000}
        result = 0
        for i in range(len(s)):
            if i + 1 < len(s) and map[s[i]] < map[s[i + 1]]:
                result -= map[s[i]]
            else:
                result += map[s[i]]
        return result


if __name__ == "__main__":
    s = Solution()
    print(s.romanToInt("III"))
    print(s.romanToInt("IV"))
    print(s.romanToInt("IX"))
    print(s.romanToInt("LVIII"))
    print(s.romanToInt("MCMXCIV"))

# @lc code=end
