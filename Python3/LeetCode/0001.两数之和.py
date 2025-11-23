#
# @lc app=leetcode.cn id=1 lang=python3
#
# [1] 两数之和
#

# @lc code=start
from typing import List


class Solution:
    def twoSum(self, nums: List[int], target: int) -> List[int]:
        map = {}
        for key, value in enumerate(nums):
            if target - value in map:
                return [map[target - value], key]
            map[value] = key
        return []


print(Solution().twoSum([2, 7, 11, 15], 9))
print(Solution().twoSum([3, 2, 4], 6))
print(Solution().twoSum([3, 3], 6))
print(Solution().twoSum([2, 5, 5, 11], 10))
print(Solution().twoSum([2, 5, 5, 11], 16))
print(Solution().twoSum([2, 5, 5, 11], 13))
# @lc code=end
