/*
你是一个专业的小偷，计划偷窃沿街的房屋，每间房内都藏有一定的现金。
这个地方所有的房屋都 围成一圈 ，这意味着第一个房屋和最后一个房屋是紧挨着的。
同时，相邻的房屋装有相互连通的防盗系统，如果两间相邻的房屋在同一晚上被小偷闯入，系统会自动报警 。
给定一个代表每个房屋存放金额的非负整数数组，计算你 在不触动警报装置的情况下 ，今晚能够偷窃到的最高金额。
示例 1：
输入：nums = [2,3,2]
输出：3
解释：你不能先偷窃 1 号房屋（金额 = 2），然后偷窃 3 号房屋（金额 = 2）,因为他们是相邻的。
示例 2：
输入：nums = [1,2,3,1]
输出：4
解释：你可以先偷窃 1 号房屋（金额 = 1），然后偷窃 3 号房屋（金额 = 3）。偷窃到的最高金额 = 1 + 3 = 4 。
示例 3：
输入：nums = [1,2,3]
输出：3
*/
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
class Solution
{
public:
    /*
    动态规划五部曲
    1. 确定dp数组以及下标的含义
    dp[i]表示在不触动警报装置的情况下 ，考虑能够在下标[0,i-1]的范围内偷窃到的最高金额
    2. 确定递推关系 整体递推关系是这样
    dp[i]的最大金额的状态是由 dp[i-1]不偷nums[i]的金额，
    和dp[i-2]+nums[i]偷nums[i]的金额互相比较出最大值推导出来。
    dp[i] = max(dp[i-2]+nums[i],dp[i-1])
    有三种情况
    不考虑首尾元素，考虑首元素不考虑尾元素，考虑尾元素不考虑首元素三种，最后求三种情况分别得到的值中的最大值
    3. 确定初始值
    dp[0] = nums[0]
    dp[1] = max(nums[0],nums[1])
    4. 确定遍历顺序
    for(int i=2;i<nums.size();i++)
        dp[i] = max(dp[i-2]+nums[i],dp[i-1])
    5. 举例推导dp数组
    */
    int rob(vector<int> &nums)
    {
        if (nums.empty())
            return 0;
        vector<int> nums_1(nums.begin() + 1, nums.end() - 1); // 不考虑首尾元素
        vector<int> nums_2(nums.begin() + 0, nums.end() - 1); // 考虑首元素不考虑尾元素
        vector<int> nums_3(nums.begin() + 1, nums.end());     // 考虑尾元素不考虑首元素
        return max(rob_condition(nums_1), max(rob_condition(nums_2), rob_condition(nums_3)));
    }
    int rob_condition(vector<int> &nums)
    {
        if (nums.size() == 0)
            return 0;
        if (nums.size() == 1)
            return nums[0];
        vector<int> dp(nums.size(), 0);
        dp[0] = nums[0];
        dp[1] = max(nums[0], nums[1]);
        for (int i = 2; i < nums.size(); i++)
        {
            dp[i] = max(dp[i - 2] + nums[i], dp[i - 1]);
        }
        return dp[nums.size() - 1];
    }
};
int main()
{
    Solution s;
    vector<int> nums{1, 2, 3, 1};
    vector<int> nums1{2, 3, 2};
    vector<int> nums2{1, 2, 3};
    cout << s.rob(nums) << endl;
    cout << s.rob(nums1) << endl;
    cout << s.rob(nums2) << endl;
    return 0;
}