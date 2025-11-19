#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
/*
给定一个未经排序的整数数组，找到 最长且连续递增的子序列，并返回该序列的长度。
连续递增的子序列 可以由两个下标 l 和 r（l < r）确定，
如果对于每个 l <= i < r，都有 nums[i] < nums[i + 1] ，
那么子序列 [nums[l], nums[l + 1], ..., nums[r - 1], nums[r]] 就是连续递增子序列。
示例 1：
输入：nums = [1,3,5,4,7]
输出：3
解释：最长连续递增序列是 [1,3,5], 长度为3。
尽管 [1,3,5,7] 也是升序的子序列, 但它不是连续的，因为 5 和 7 在原数组里被 4 隔开。
示例 2：
输入：nums = [2,2,2,2,2]
输出：1
解释：最长连续递增序列是 [2], 长度为1。
*/
class Solution
{
public:
    /*
    动态规划五部曲
    本题要求连续递增子序列，所以就只要比较nums[i]与nums[i - 1]，而不用去比较nums[j]与nums[i] （j是在0到i之间遍历）。 
    既然不用j了，那么也不用两层for循环，本题一层for循环就行，比较nums[i] 和 nums[i - 1]。
    1. 确定dp数组以及下标的含义
    dp[i]：表示以下标i为结尾的连续递增的子序列长度
    因为是连续的的，所以要记录每个位置的最长连续递增子序列的长度，不需要辅助数组，只需要一个变量即可
    2. 确定递推关系
    if (nums[i] >nums[i-1])
    {
        dp[i] = max(dp[i], dp[i - 1] + 1);
    }
    3. 确定初始值
    dp[0] = 1;
    4. 确定遍历顺序
    5. 举例推导dp数组
    */
    int findLengthOfLCIS(vector<int> &nums)
    {
        if (nums.size() <= 1)
            return nums.size();
        vector<int> dp(nums.size(), 1);
        for (int i = 1; i < nums.size(); i++)
        {
            if (nums[i] > nums[i - 1])
            {
                dp[i] = max(dp[i], dp[i - 1] + 1);
            }
            if (nums[i] <= nums[i - 1])
                dp[i] = 1;
        }
        return *max_element(dp.begin(), dp.end());
    }
};

int main()
{
    vector<int> nums_1 = {10, 9, 2, 5, 3, 7, 101, 18};
    vector<int> nums_2 = {0, 1, 0, 3, 2, 3};
    vector<int> nums_3 = {7, 7, 7, 7, 7, 7, 7};
    Solution s;
    cout << s.findLengthOfLCIS(nums_1) << endl;
    cout << s.findLengthOfLCIS(nums_2) << endl;
    cout << s.findLengthOfLCIS(nums_3) << endl;
    return 0;
}