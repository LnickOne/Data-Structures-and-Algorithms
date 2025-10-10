#include <iostream>
#include <vector>
#include <algorithm>
#include <limits.h>
using namespace std;

/*
给你一个整数数组 nums ，请你找出一个具有最大和的连续子数组（子数组最少包含一个元素），返回其最大和。
子数组是数组中的一个连续部分。
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
class Solution
{
public:
    int maxSubArray(vector<int> &nums)
    {
        int result = INT_MIN;
        int count = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            count += nums[i];
            if (count > result)
                result = count; // 取区间累计的最大值（相当于不断确定最大子序终止位置）
            if (count <= 0)
                count = 0; // 连续和变成负数或者为0的时候重置最大子序起始位置（贪心贪在这里），因为遇到负数一定是拉低总和
        }
        return result;
    }
};
int main()
{
    Solution s;
    vector<int> nums = {-2, 1, -3, 4, -1, 2, 1, -5, 4};
    vector<int> nums1 = {5, 4, -1, 7, 8};
    vector<int> nums2 = {-1};
    int result = s.maxSubArray(nums);
    int result1 = s.maxSubArray(nums1);
    int result2 = s.maxSubArray(nums2);
    cout << result << endl;
    cout << result1 << endl;
    cout << result2 << endl;
}
