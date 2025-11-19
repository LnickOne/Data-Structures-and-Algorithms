#
# @lc app=leetcode.cn id=6 lang=python3
#
# [6] Z 字形变换
#


# @lc code=start
class Solution:
    def convert(self, s: str, numRows: int) -> str:
        if numRows == 1:
            return s
        result = [[] for i in range(numRows)]
        for i in range(len(s)):
            index = i % (2 * numRows - 2)
            if index < numRows:
                result[index].append(s[i])
            else:
                result[2 * numRows - 2 - index].append(s[i])
        return "".join(["".join(i) for i in result])


print(Solution().convert("PAYPALISHIRING", 3))  # Output: "PAHNAPLSIIGYIR"
print(Solution().convert("PAYPALISHIRING", 4))  # Output: "PINALSIGYAHRPI"
print(Solution().convert("A", 1))  # Output: "A"


# @lc code=end
