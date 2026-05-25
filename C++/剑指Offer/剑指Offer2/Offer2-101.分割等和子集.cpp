/* 题目难度: 简单
[原题链接](https://leetcode.cn/problems/NUPfPr/)
题目描述
给定非空正整数数组 nums, 判断能否将这些数字分成元素和相等的两部分。
题目样例
示例1
- 输入: nums=[1,5,11,5]
- 输出: true ([1,5,5] 和 [11])
示例2
- 输入: nums=[1,2,3,5]
- 输出: false
题目思考
1. 如何优化算法复杂度?
解决方案
思路
- 目标是找到总和为 sum/2 的子集, 转化为 0-1 背包问题
- dp[j] = 能否凑成和 j; 逆序遍历避免重复使用同一元素
- 初始 dp[0]=true, 若 dp[target]=true 则返回 true
复杂度
- 时间复杂度 O(N*C): C = sum/2
- 空间复杂度 O(C): 一维 DP 数组
 */
#include <iostream>
#include <vector>
#include <numeric>
using namespace std;

class Solution
{
public:
    bool canPartition(vector<int> &nums)
    {
        int sm = accumulate(nums.begin(), nums.end(), 0);
        if (sm & 1) return false;
        int target = sm / 2;
        vector<bool> dp(target + 1, false);
        dp[0] = true;
        for (int x : nums)
            for (int j = target; j >= x; --j)
                dp[j] = dp[j] || dp[j - x];
        return dp[target];
    }
};

int main()
{
    Solution sol;
    cout << boolalpha;
    vector<int> n1 = {1, 5, 11, 5};
    cout << sol.canPartition(n1) << endl; // true
    vector<int> n2 = {1, 2, 3, 5};
    cout << sol.canPartition(n2) << endl; // false
    return 0;
}
