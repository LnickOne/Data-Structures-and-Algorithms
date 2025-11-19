#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
/*
给定一个未排序的整数数组 nums ， 返回最长递增子序列的个数 。
注意 这个数列必须是 严格 递增的。
示例 1:
输入: [1,3,5,4,7]
输出: 2
解释: 有两个最长递增子序列，分别是 [1, 3, 4, 7] 和[1, 3, 5, 7]。
示例 2:
输入: [2,2,2,2,2]
输出: 5
解释: 最长递增子序列的长度是1，并且存在5个子序列的长度为1，因此输出5。
*/
class Solution
{
public:
    /*
    动态规划五部曲
    1. 确定dp数组以及下标的含义
    dp[i]：表示i之前（包括i）最长递增子序列的长度为dp[i]
    count[i]：表示以nums[i]为结尾的字符串，最长递增子序列的个数为count[i]
    2. 确定递推关系
    if (nums[i] > nums[j])
        dp[i] = max(dp[j] + 1, dp[i])
    3. 确定初始值
    4. 确定遍历顺序
    5. 举例推导dp数组
    */
    int findNumberOfLIS(vector<int> &nums)
    {
        vector<int> dp(nums.size(), 1);
        vector<int> count(nums.size(), 1);
        for (int i = 0; i < nums.size(); i++)
        {
            for (int j = 0; j < i; j++)
            {
                if (nums[j] < nums[i])     // 只要是严格递增的，就进行比较,一直更新dp数组
                {                          // dp[i]=max(dp[i],dp[j]+1); 将两种情况分开统计count[i]
                                           // dp[i]和dp[j]的关系,dp[i]可以由dp[j]+1得到，因为一个以i结尾最长，一个以j结尾最长。
                    if (dp[j] + 1 > dp[i]) // 如果在[0, i-1]的范围内，找到了j，使得dp[j] + 1 > dp[i]，说明找到了一个更长的递增子序列。
                    {
                        dp[i] = dp[j] + 1;
                        count[i] = count[j]; // 那么以j为结尾的子串的最长递增子序列的个数，就是最新的以i为结尾的子串的最长递增子序列的个数，即：count[i] = count[j]
                    }
                    if (dp[j] + 1 == dp[i]) // 如果在[0, i-1]的范围内，找到了j，使得dp[j] + 1 == dp[i]，说明找到了两个相同长度的递增子序列。                                           // 那么以i为结尾的子串的最长递增子序列的个数 就应该加上以j为结尾的子串的最长递增子序列的个数，即：count[i] += count[j];
                    {
                        count[i] += count[j];
                    }
                    dp[i] = max(dp[i], dp[j] + 1);
                }
            }
        }
        int maxLen = *max_element(dp.begin(), dp.end());
        int result = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            if (dp[i] == maxLen)
                result += count[i];
        }
        return result;
    }
};

int main()
{
    return 0;
}