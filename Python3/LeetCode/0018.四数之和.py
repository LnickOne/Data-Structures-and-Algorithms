#
# @lc app=leetcode.cn id=18 lang=python3
#
# [18] 四数之和
#

# @lc code=start
from typing import List


class Solution:
    def fourSum(self, nums: List[int], target: int) -> List[List[int]]:
        nums.sort()
        result = []
        for i in range(len(nums)):
            if i > 0 and nums[i] == nums[i - 1]:
                continue
            for j in range(i + 1, len(nums)):
                if j > i + 1 and nums[j] == nums[j - 1]:
                    continue
                left, right = j + 1, len(nums) - 1
                while left < right:
                    sum = nums[i] + nums[j] + nums[left] + nums[right]
                    if sum == target:
                        result.append([nums[i], nums[j], nums[left], nums[right]])
                        while left < right and nums[left] == nums[left + 1]:
                            left += 1
                        while left < right and nums[right] == nums[right - 1]:
                            right -= 1
                        left += 1
                        right -= 1
                    if sum > target:
                        right -= 1
                    else:
                        left += 1
        return result


print(Solution().fourSum([1, 0, -1, 0, -2, 2], 0))
print(Solution().fourSum([2, 2, 2, 2, 2], 8))
print(Solution().fourSum([-3, -2, -1, 0, 0, 1, 2, 3], 0))
# @lc code=end
