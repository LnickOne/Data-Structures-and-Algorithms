/* 题目难度: 简单
[原题链接](https://leetcode.cn/problems/N6YdxV/)
题目描述
给定排序的整数数组 nums 和整数目标值 target, 在数组中找到 target 并返回其下标。
若目标值不存在则返回它将被按顺序插入的位置。要求 O(logN) 算法。
题目样例
示例1
- 输入: nums=[1,3,5,6], target=5
- 输出: 2
示例2
- 输入: nums=[1,3,5,6], target=2
- 输出: 1
示例3
- 输入: nums=[1,3,5,6], target=7
- 输出: 4
题目思考
1. 如何利用数组的有序性?
解决方案
思路
- 标准 lower_bound 二分: 找第一个 >= target 的位置
- 使用 STL lower_bound 直接返回
复杂度
- 时间复杂度 O(logN): 二分查找
- 空间复杂度 O(1): 只使用了几个常数空间的变量
 */
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution
{
public:
    int searchInsert(vector<int> &nums, int target)
    {
        return (int)(lower_bound(nums.begin(), nums.end(), target) - nums.begin());
    }
};

int main()
{
    Solution sol;
    vector<int> n1 = {1, 3, 5, 6};
    cout << sol.searchInsert(n1, 5) << endl; // 2
    cout << sol.searchInsert(n1, 2) << endl; // 1
    cout << sol.searchInsert(n1, 7) << endl; // 4
    cout << sol.searchInsert(n1, 0) << endl; // 0
    return 0;
}
