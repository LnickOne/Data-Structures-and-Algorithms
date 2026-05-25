/* 题目难度: 中等
[原题链接](https://leetcode.cn/problems/YaVDxD/)
题目描述
给定正整数数组 nums 和整数 target, 向每个整数前添加 '+' 或 '-', 返回运算结果等于 target 的不同表达式数目。
题目样例
示例1
- 输入: nums=[1,1,1,1,1], target=3
- 输出: 5
示例2
- 输入: nums=[1], target=1
- 输出: 1
题目思考
1. 如何优化时间复杂度?
解决方案
思路
- 记忆化 DP: dp[i][sm] = 从下标 i 开始和为 target 的方案数
- 用 unordered_map<int,int> 的滚动方式: 每步对当前 map 中每个和加/减当前数字
复杂度
- 时间复杂度 O(N*C): C 是和的值域范围 2000
- 空间复杂度 O(C): map 最多 2001 个键
 */
#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution
{
public:
    int findTargetSumWays(vector<int> &nums, int target)
    {
        unordered_map<int, int> dp;
        dp[0] = 1;
        for (int x : nums)
        {
            unordered_map<int, int> ndp;
            for (auto &[sm, cnt] : dp)
            {
                ndp[sm + x] += cnt;
                ndp[sm - x] += cnt;
            }
            dp = ndp;
        }
        return dp.count(target) ? dp[target] : 0;
    }
};

int main()
{
    Solution sol;
    vector<int> n1 = {1, 1, 1, 1, 1};
    cout << sol.findTargetSumWays(n1, 3) << endl; // 5
    vector<int> n2 = {1};
    cout << sol.findTargetSumWays(n2, 1) << endl; // 1
    return 0;
}
