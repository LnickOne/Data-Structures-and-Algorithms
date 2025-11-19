#
# @lc app=leetcode.cn id=3 lang=python3
#
# [3] 无重复字符的最长子串
#


# @lc code=start
class Solution:
    def lengthOfLongestSubstring(self, s: str) -> int:
        if not s:
            return 0
        
        return max_len


print(Solution().lengthOfLongestSubstring("abcabcbb"))  # Output: 3
print(Solution().lengthOfLongestSubstring("bbbbb"))  # Output: 1
print(Solution().lengthOfLongestSubstring("pwwkew"))  # Output: 3
print(Solution().lengthOfLongestSubstring(""))  # Output: 0

# @lc code=end
