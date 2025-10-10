/*
给你一个整数数组 nums ，请你找出一个具有最大和的连续子数组（子数组最少包含一个元素），返回其最大和。
子数组
是数组中的一个连续部分。
示例 1：
输入：nums = [-2,1,-3,4,-1,2,1,-5,4]
输出：6
解释：连续子数组 [4,-1,2,1] 的和最大，为 6 。
示例 2：
输入：nums = [1]
输出：1
示例 3：
输入：nums = [5,4,-1,7,8]
输出：23
*/
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
class Solution
{
public:
    /*
    动态规划五部曲
    1.确定DP数组的含义
    dp[i]：包括下标i（以nums[i]为结尾）的最大连续子序列和为dp[i]
    2.确定递推公式
    dp[i]=max(dp[i-1]+nums[i],nums[i]))
    3.初始化DP数组
    dp[0] = nums[0];
    4.确定遍历顺序
    5.举例推导DP数组
    */
    int maxSubArray(vector<int> &nums)
    {
        if (nums.empty())
            return 0;
        if (nums.size() == 1)
            return nums[0];
        vector<int> dp(nums.size());
        dp[0] = nums[0];
        dp[1] = max(nums[0], nums[1]);
        for (int i = 1; i < nums.size(); i++)
        {
            dp[i] = max(dp[i - 1] + nums[i], nums[i]);
        }
        return *max_element(dp.begin(), dp.end());
    }
};

int main()
{
    vector<int> nums_1 = {-2, 1, -3, 4, -1, 2, 1, -5, 4};
    vector<int> nums_2 = {1};
    vector<int> nums_3 = {5, 4, -1, 7, 8};
    Solution s;
    s.maxSubArray(nums_1);
    s.maxSubArray(nums_2);
    s.maxSubArray(nums_3);
    return 0;
}