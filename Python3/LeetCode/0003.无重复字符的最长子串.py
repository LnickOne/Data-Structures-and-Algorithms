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
        max_len = 0
        start = 0
        char_map = {}

        for end in range(len(s)):
            if s[end] in char_map:
                start = max(start, char_map[s[end]] + 1)
            char_map[s[end]] = end
            max_len = max(max_len, end - start + 1)

        return max_len


print(Solution().lengthOfLongestSubstring("abcabcbb"))  # Output: 3
print(Solution().lengthOfLongestSubstring("bbbbb"))  # Output: 1
print(Solution().lengthOfLongestSubstring("pwwkew"))  # Output: 3
print(Solution().lengthOfLongestSubstring(""))  # Output: 0

# @lc code=end
