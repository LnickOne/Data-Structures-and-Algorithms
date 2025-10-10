/*
给你一个整数数组 nums ，你可以对它进行一些操作。
每次操作中，选择任意一个 nums[i] ，删除它并获得 nums[i] 的点数。
之后，你必须删除 所有 等于 nums[i] - 1 和 nums[i] + 1 的元素。
开始你拥有 0 个点数。返回你能通过这些操作获得的最大点数。
示例 1：
输入：nums = [3,4,2]
输出：6
解释：
删除 4 获得 4 个点数，因此 3 也被删除。之后，删除 2 获得 2 个点数。总共获得 6 个点数。
示例 2：
输入：nums = [2,2,3,3,3,4]
输出：9
解释：
删除 3 获得 3 个点数，接着要删除两个 2 和 4 。
之后，再次删除 3 获得 3 个点数，再次删除 3 获得 3 个点数。
总共获得 9 个点数。
提示：
1 <= nums.length <= 2 * 104
1 <= nums[i] <= 104
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
    dp[i]:表示以nums[i]结尾的数组能获得的最大点数
    2. 确定递推关系
    放i和不放i
    dp[i] = max(dp[i - 1], dp[i - 2] + nums[i])
    3. 确定初始值
    for (int i = 0; i <= n; i++)
        dp[nums[i]] += nums[i];
    4. 确定遍历顺序
    5. 举例推导dp数组
    */
    int deleteAndEarn(vector<int> &nums)
    {
        if (nums.size() == 0)
            return 0;
        if (nums.size() == 1)
            return nums[0];
        sort(nums.begin(), nums.end());
        int n = nums.back() + 1;
        vector<int> dp(n + 1, 0);
        for (int i = 0; i <= n; i++)
            dp[nums[i]] += nums[i];
        for (int i = 2; i <= n; i++)
        {
            dp[i] = max(dp[i - 1], dp[i - 2] + dp[i]);
        }

        return dp[n - 1];
    }
};

int main()
{
    return 0;
}