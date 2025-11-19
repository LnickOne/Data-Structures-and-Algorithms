#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
/*
给你一个整数数组 nums ，请你找出数组中乘积最大的非空连续子数组
（该子数组中至少包含一个数字），并返回该子数组所对应的乘积。
*/
class Solution
{
public:
    /*
    动态规划五部曲
    1. 确定dp数组以及下标的含义
    dp[i]:表示以i结尾的最大乘积
    2. 确定递推关系
    dp[i] = max(dp[i-1]*nums[i],nums[i])
    3. 确定初始值
    4. 确定遍历顺序
    5. 举例推导dp数组
    */
    int maxProduct(vector<int> &nums)
    {
        if (nums.size() == 0)
            return 0;
        if (nums.size() == 1)
            return nums[0];
        vector<int> dp_max(nums.size());
        vector<int> dp_min(nums.size());
        dp_max[0] = nums[0];
        dp_min[0] = nums[0];
        int result = nums[0];
        for (int i = 1; i < nums.size(); i++)
        {
            dp_max[i] = max(dp_max[i - 1] * nums[i], max(dp_min[i - 1] * nums[i], nums[i]));
            dp_min[i] = min(dp_max[i - 1] * nums[i], min(dp_min[i - 1] * nums[i], nums[i]));
            result = max(result, dp_max[i]);
        }
        return result;
    }
};

int main()
{
    vector<int> nums_1 = {2, 3, -2, 4};
    Solution s;
    cout << s.maxProduct(nums_1) << endl;
    return 0;
}