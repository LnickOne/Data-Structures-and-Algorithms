#
# @lc app=leetcode.cn id=1343 lang=python3
#
# [1343] 大小为 K 且平均值大于等于阈值的子数组数目
#

# @lc code=start
from typing import List


class Solution:
    def numOfSubarrays(self, arr: List[int], k: int, threshold: int) -> int:
        result = 0
        total = sum(arr[0:k])
        if total / k >= threshold:
            result += 1
        for i in range(k, len(arr)):
            total += arr[i]
            total -= arr[i - k]
            if total / k >= threshold:
                result += 1
        return result


print(Solution().numOfSubarrays([2, 2, 2, 2, 5, 5, 5, 8], 3, 4))
print(Solution().numOfSubarrays([11, 13, 17, 23, 29, 31, 7, 5, 2, 3], 3, 5))
print(Solution().numOfSubarrays([1, 2, 3, 4, 5, 6, 7, 8, 9, 10], 5, 5))


# @lc code=end
