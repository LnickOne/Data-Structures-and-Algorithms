#
# @lc app=leetcode.cn id=2461 lang=python3
#
# [2461] 长度为 K 子数组中的最大和
#

# @lc code=start
from typing import List


class Solution:
    def maximumSubarraySum(self, nums: List[int], k: int) -> int:
        result = 0
        total = 0
        numsMap = {}
        for i in range(k):
            numsMap[nums[i]] = numsMap.get(nums[i], 0) + 1
            total += nums[i]
        if len(numsMap) == k:
            result = total
        for i in range(k, len(nums)):
            total += nums[i]
            total -= nums[i - k]
            numsMap[nums[i]] = numsMap.get(nums[i], 0) + 1
            numsMap[nums[i - k]] = numsMap.get(nums[i - k], 0) - 1
            if numsMap.get(nums[i - k]) == 0:
                del numsMap[nums[i - k]]
            if len(numsMap) == k:
                result = max(result, total)
        return result


print(Solution().maximumSubarraySum([1, 5, 4, 2, 9, 9, 9], 3))
print(Solution().maximumSubarraySum([4, 4, 4], 3))
print(Solution().maximumSubarraySum([1, 1, 1, 7, 8, 9], 3))

# @lc code=end
