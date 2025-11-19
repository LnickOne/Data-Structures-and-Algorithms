#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
/**
给你一个整数数组 nums ，找到其中最长严格递增子序列的长度。
子序列 是由数组派生而来的序列，删除（或不删除）数组中的元素而不改变其余元素的顺序。
例如，[3,6,2,7] 是数组 [0,3,1,6,2,2,7] 的子序列
示例 1：
输入：nums = [10,9,2,5,3,7,101,18]
输出：4
解释：最长递增子序列是 [2,3,7,101]，因此长度为 4 。
示例 2：
输入：nums = [0,1,0,3,2,3]
输出：4
示例 3：
输入：nums = [7,7,7,7,7,7,7]
输出：1
 */
class Solution
{
public:
    /*
    动态规划五部曲
    1.确定dp数组以及下标的含义
    dp[i]：表示i之前包括i的以nums[i]结尾的最长递增子序列的长度
    2.确定递推关系
    互相比较才有最长，所以分为dp[i]和dp[j] 并且j的起始位置为0，一直到i-1,dp[i]可以由dp[j]+1得到
    dp[i] = max(dp[j] + 1, dp[i])
    3.确定初始值
    dp数组所有元素都初始化为1，因为数组的每个子序列就是元素本身，长度为1
    4.确定遍历顺序
    5.举例推导dp数组
    */
    int lengthOfLIS(vector<int> &nums)
    {
        if (nums.size() <= 1)
            return nums.size();
        vector<int> dp(nums.size(), 1); // dp[i]：表示i之前包括i的以nums[i]结尾的最长递增子序列的长度
        for (int i = 1; i < nums.size(); i++)
        {
            for (int j = 0; j < i; j++) // 要比较长度，需要有一个辅助dp[j]作为参照物来互相对比,dp[j],dp[i]
            {
                if (nums[j] < nums[i]) // 只要是严格递增的，就进行比较,一直更新dp数组
                {
                    dp[i] = max(dp[i], dp[j] + 1); // dp[i]和dp[j]的关系,dp[i]可以由dp[j]+1得到，因为一个以i结尾最长，一个以j结尾最长。
                }
            }
        }
        return *max_element(dp.begin(), dp.end());
    }
};

int main()
{
    vector<int> nums_1 = {10, 9, 2, 5, 3, 7, 101, 18};
    vector<int> nums_2 = {0, 1, 0, 3, 2, 3};
    vector<int> nums_3 = {7, 7, 7, 7, 7, 7, 7};
    cout << "最长递增子序列的长度是：" << endl;
    cout << Solution().lengthOfLIS(nums_1) << endl;
    cout << Solution().lengthOfLIS(nums_2) << endl;
    cout << Solution().lengthOfLIS(nums_3) << endl;
    return 0;
}
