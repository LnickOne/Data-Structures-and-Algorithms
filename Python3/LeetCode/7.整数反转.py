#
# @lc app=leetcode.cn id=7 lang=python3
#
# [7] 整数反转
#


# @lc code=start
class Solution:
    def reverse(self, x: int) -> int:
        if x < 0:
            return -self.reverse(-x)
        res = 0
        while x:
            res = res * 10 + x % 10
            x //= 10
        return res if res <= 0x7FFFFFFF else 0


print(Solution().reverse(123))  # Output: 321
print(Solution().reverse(-123))  # Output: -321
print(Solution().reverse(120))  # Output: 21
print(Solution().reverse(0))  # Output: 0


# @lc code=end
