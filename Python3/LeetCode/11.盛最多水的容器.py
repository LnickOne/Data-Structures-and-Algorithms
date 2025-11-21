#
# @lc app=leetcode.cn id=11 lang=python3
#
# [11] 盛最多水的容器
#
# @lc code=start
from typing import List


class Solution:
    def maxArea(self, height: List[int]) -> int:
        max_area = 0
        left = 0
        right = len(height) - 1
        while left < right:
            length = right - left
            area = length * min(height[left], height[right])
            max_area = max(max_area, area)
            if height[left] < height[right]:
                left += 1
            else:
                right -= 1
        return max_area


# @lc code=end
