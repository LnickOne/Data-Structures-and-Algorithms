#
# @lc app=leetcode.cn id=2841 lang=python3
#
# [2841] 几乎唯一子数组的最大和
#

# @lc code=start
from typing import List
from collections import Counter


class Solution:
    def maxSum(self, nums: List[int], m: int, k: int) -> int:
        if len(nums) < k:
            return 0
        result = 0
        total = 0
        numsMap = Counter(nums[:k])  # 处理第一个窗口
        total = sum(nums[:k])
        if len(numsMap) >= m:
            result = total
        for i in range(k, len(nums)):  # 处理后续窗口
            total += nums[i]
            total -= nums[i - k]
            numsMap[nums[i]] = numsMap.get(nums[i], 0) + 1
            numsMap[nums[i - k]] = numsMap.get(nums[i - k], 0) - 1
            if numsMap[nums[i - k]] == 0:
                del numsMap[nums[i - k]]
            if len(numsMap) >= m:
                result = max(result, total)
        return result


print(Solution().maxSum([1, 2, 1, 2, 1, 2, 1], 3, 3))
print(Solution().maxSum([2, 6, 7, 3, 1, 7], 3, 4))
print(Solution().maxSum([2, 1, 8, 1, 2, 2, 1, 7, 1, 5], 2, 3))


# @lc code=end
