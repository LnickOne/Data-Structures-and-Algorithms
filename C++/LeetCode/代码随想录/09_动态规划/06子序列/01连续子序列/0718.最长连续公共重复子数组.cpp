#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
/*
给两个整数数组 nums1 和 nums2 ，返回 两个数组中 公共的 、长度最长的子数组的长度 。
示例 1：
输入：nums1 = [1,2,3,2,1], nums2 = [3,2,1,4,7]
输出：3
解释：长度最长的公共子数组是 [3,2,1] 。
示例 2：
输入：nums1 = [0,0,0,0,0], nums2 = [0,0,0,0,0]
输出：5
*/
class Solution
{
public:
    /*
    动态规划五部曲
    1. 确定dp数组以及下标的含义
    dp[i][j]表示：两个数组nums1和nums2以下标i-1和下标j-1结尾,两个数组中公共的长度最长的子数组的长度。
    如果定义 dp[i][j]为 以下标i为结尾的A，和以下标j 为结尾的B，那么 第一行和第一列毕竟要进行初始化，
    如果nums1[i] 与 nums2[0] 相同的话，对应的 dp[i][0]就要初始为1， 因为此时最长重复子数组为1。
    nums2[j] 与 nums1[0]相同的话，同理。所以定义以i-1和j-1为结尾的子数组的长度
    2. 确定递推关系
    如果nums[i-1]和nums[j-1]相等的话dp[i][j]则由dp[i-1][j-1]的长度+1得到
    需要两个数组一起回退才能做比较。
    if(nums[i-1]==nums[j-1])
        dp[i][j] =dp[i-1][j-1]+1
    3. 确定初始值
    全初始化为0,因为会被前面的覆盖
    dp[i][j] = 0;
    4. 确定遍历顺序
    5. 举例推导dp数组
    */
    int findLength(vector<int> &nums1, vector<int> &nums2)
    {
        vector<vector<int>> dp(nums1.size() + 1, vector<int>(nums2.size() + 1, 0));
        int result = 0;
        for (int i = 1; i <= nums1.size(); i++) // i-1和j-1要抵达到最后，所以需要等号等于nums.size()
        {
            for (int j = 1; j <= nums2.size(); j++)
            {
                if (nums1[i - 1] == nums2[j - 1])
                    dp[i][j] = max(dp[i][j], dp[i - 1][j - 1] + 1);
                if (nums1[i - 1] != nums2[j - 1])
                    dp[i][j] = 0;
                result = max(result, dp[i][j]);
            }
        }
        return result;
    }
};

int main()
{
    vector<int> nums1_1 = {1, 2, 3, 2, 1}, nums1_2 = {3, 2, 1, 4, 7};
    vector<int> nums2_1 = {0, 0, 0, 0, 0}, nums2_2 = {0, 0, 0, 0, 0};
    Solution s;
    s.findLength(nums1_1, nums1_2);
    s.findLength(nums2_1, nums2_2);
    return 0;
}