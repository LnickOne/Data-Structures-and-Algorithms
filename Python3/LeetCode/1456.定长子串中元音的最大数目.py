# [1456] 定长子串中元音的最大数目


class Solution:
    def maxVowels(self, s: str, k: int) -> int:
        result = 0
        count = 0
        vowels = {"a", "e", "i", "o", "u"}
        # 处理第一个窗口
        for i in range(0, k):
            if s[i] in vowels:
                count += 1
        result = max(result, count)
        # 处理后续窗口
        for i in range(k, len(s)):
            if s[i] in vowels:  
                count += 1
            if s[i - k] in vowels: 
                count -= 1
            result = max(result, count)
        return result


print(Solution().maxVowels("abciiidef", 3))
print(Solution().maxVowels("aeiou", 2))
print(Solution().maxVowels("leetcode", 3))
print(Solution().maxVowels("rhythms", 4))
