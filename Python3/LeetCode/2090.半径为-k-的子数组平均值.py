#
# @lc app=leetcode.cn id=2090 lang=python3
#
# [2090] 半径为 k 的子数组平均值
#

# @lc code=start
from typing import List


class Solution:
    def getAverages(self, nums: List[int], k: int) -> List[int]:
        if 2 * k + 1 > len(nums):
            return [-1] * len(nums)
        result = [-1] * len(nums)
        total = sum(nums[: 2 * k + 1])
        result[k] = total // (2 * k + 1)
        for i in range(2 * k + 1, len(nums)):
            total += nums[i]
            total -= nums[i - (2 * k + 1)]
            result[i - k] = total // (2 * k + 1)
        return result


print(Solution().getAverages([7, 4, 3, 9, 1, 8, 5, 2, 6], 3))
print(Solution().getAverages([100000], 0))
print(Solution().getAverages([8], 100000))
print(Solution().getAverages([1, 2, 3, 4, 5, 6, 7, 8, 9, 10], 5))

# @lc code=end
