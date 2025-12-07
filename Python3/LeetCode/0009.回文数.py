#
# @lc app=leetcode.cn id=9 lang=python3
#
# [9] 回文数
#
# 思路：将数字转换为字符串，然后判断字符串是否为回文
# 1. 将数字转换为字符串
# 2. 判断字符串是否为回文
# 3. 返回结果


# @lc code=start
class Solution:
    def isPalindrome(self, x: int) -> bool:
        if x < 0:
            return False
        return str(x) == str(x)[::-1]


print(Solution().isPalindrome(121))
print(Solution().isPalindrome(-121))
print(Solution().isPalindrome(10))
print(Solution().isPalindrome(-101))
print(Solution().isPalindrome(1000021))


# @lc code=end
