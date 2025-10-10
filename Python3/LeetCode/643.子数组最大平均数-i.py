#
# @lc app=leetcode.cn id=643 lang=python3
#
# [643] 子数组最大平均数 I
#

# @lc code=start
from typing import List


class Solution:
    def findMaxAverage(self, nums: List[int], k: int) -> float:
        result = 0.0
        sum = 0.0
        # 处理第一个窗口
        for i in range(k):
            sum += nums[i]
        result = sum / k
        # 处理后续窗口
        for i in range(k, len(nums)):
            sum += nums[i]
            sum -= nums[i - k]
            result = max(result, sum / k)
        return result


print(Solution().findMaxAverage([1, 12, -5, -6, 50, 3], 4))
print(Solution().findMaxAverage([5], 1))
print(Solution().findMaxAverage([-1], 1))
print(Solution().findMaxAverage([0, 4, 0, 3, 2], 1))
print(Solution().findMaxAverage([0, 1, 1, 3, 3], 4))
print(Solution().findMaxAverage([4, 2, 1, 3, 3], 2))
# @lc code=end
