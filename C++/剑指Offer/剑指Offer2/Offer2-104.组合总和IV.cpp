/* 题目难度: 中等
[原题链接](https://leetcode.cn/problems/D0F0SV/)
题目描述
给定由不同正整数组成的数组 nums 和目标整数 target, 找出总和为 target 的元素组合个数。顺序不同的序列视作不同组合, 每个数字可重复使用。
题目样例
示例1
- 输入: nums=[1,2,3], target=4
- 输出: 7
示例2
- 输入: nums=[9], target=3
- 输出: 0
题目思考
1. 如何处理顺序不同视作不同组合的问题?
解决方案
思路
- 完全背包变体: 外层枚举总和 t, 内层枚举每个数字 num 作为最后一个元素
- dp[t] += dp[t-num], 初始 dp[0]=1
复杂度
- 时间复杂度 O(N*T): N 是数组长度, T 是 target
- 空间复杂度 O(T): dp 数组
 */
#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    int combinationSum4(vector<int> &nums, int target)
    {
        vector<long long> dp(target + 1, 0);
        dp[0] = 1;
        for (int t = 1; t <= target; ++t)
            for (int num : nums)
                if (t >= num)
                    dp[t] += dp[t - num];
        return (int)dp[target];
    }
};

int main()
{
    Solution sol;
    vector<int> n1 = {1, 2, 3};
    cout << sol.combinationSum4(n1, 4) << endl; // 7
    vector<int> n2 = {9};
    cout << sol.combinationSum4(n2, 3) << endl; // 0
    return 0;
}
