#
# @lc app=leetcode.cn id=5 lang=python3
#
# [5] 最长回文子串
#


# @lc code=start
class Solution:
    def longestPalindrome(self, s: str) -> str:
        if not s:
            return ""
        result = ""
        dp = [[False] * len(s) for _ in range(len(s))]
        for i in range(len(s) - 1, -1, -1):
            for j in range(i, len(s)):
                if s[i] != s[j]:
                    dp[i][j] = False
                if s[i] == s[j]:
                    if j - i == 0:
                        dp[i][j] = True
                    if j - i == 1:
                        dp[i][j] = True
                    if j - i > 1:
                        dp[i][j] = dp[i + 1][j - 1]
                if dp[i][j] == True:
                    if j - i + 1 > len(result):
                        result = s[i : j + 1]
        return result


print(Solution().longestPalindrome("babad"))  # Output: "bab"
print(Solution().longestPalindrome("cbbd"))  # Output: "bb"
print(Solution().longestPalindrome("a"))  # Output: "a"
print(Solution().longestPalindrome("ac"))  # Output: "a"
print(Solution().longestPalindrome("aacabdkacaa"))  # Output: "aca"


# @lc code=end
