/*
给定一个正整数 n ，将其拆分为 k 个 正整数 的和（ k >= 2 ），并使这些整数的乘积最大化。
返回 你可以获得的最大乘积 。
示例 1:
输入: n = 2
输出: 1
解释: 2 = 1 + 1, 1 × 1 = 1。
示例 2:
输入: n = 10
输出: 36
解释: 10 = 3 + 3 + 4, 3 × 3 × 4 = 36。
*/
#include <vector>
#include <iostream>
using namespace std;
class Solution
{
public:
    /*
    动态规划五部曲
    1. 确定dp数组以及下标的含义
    dp[i]：表示给定一个正整数 i，将其拆分为 k 个 正整数 的和（ k >= 2 ），这些整数的乘积最大值是dp[i]。
    如果i拆成两个数字，第一个数字是j，则第二个数字是i-j，乘积是j*(i-j)。
    如果i拆成三个数字，第一个数字是j，则第二个数字是i-j，乘积是j*dp[i-j]。
    2. 确定递推关系
    dp[i] = max(dp[i], max(j * (i - j), j * dp[i - j]));
    3. 确定初始值
    dp[1] = 1;
    dp[2] = 2;
    4. 确定遍历顺序
    5. 举例推导dp数组
    */
    int integerBreak(int n)
    {
        vector<int> dp(n + 1);
        dp[0] = 0;
        dp[1] = 1;
        dp[2] = 2;
        for (int i = 3; i <= n; i++)
        {
            for (int j = 1; j < i; j++)
            {
                dp[i] = max(dp[i], max(j * (i - j), j * dp[i - j]));
            }
        }
        return dp[n];
    }
};