/* 题目难度: 中等
[原题链接](https://leetcode.cn/problems/gaM7Ch/)
题目描述
给定不同面额的硬币 coins 和总金额 amount, 计算凑成总金额所需最少的硬币个数。若无法凑成返回 -1, 每种硬币数量无限。
题目样例
示例1
- 输入: coins=[1,2,5], amount=11
- 输出: 3 (5+5+1)
示例2
- 输入: coins=[2], amount=3
- 输出: -1
示例3
- 输入: coins=[1], amount=0
- 输出: 0
题目思考
1. 如何优化时间复杂度?
解决方案
思路
- 完全背包 DP: dp[money] = 凑成 money 所需最少硬币数
- 初始 dp[0]=0, 其余为 INT_MAX; 对每枚硬币逐金额更新 dp[money] = min(dp[money], dp[money-coin]+1)
复杂度
- 时间复杂度 O(N*A): N 是硬币种数, A 是 amount
- 空间复杂度 O(A): dp 数组
 */
#include <iostream>
#include <vector>
#include <climits>
using namespace std;

class Solution
{
public:
    int coinChange(vector<int> &coins, int amount)
    {
        vector<int> dp(amount + 1, INT_MAX);
        dp[0] = 0;
        for (int coin : coins)
            for (int money = coin; money <= amount; ++money)
                if (dp[money - coin] != INT_MAX)
                    dp[money] = min(dp[money], dp[money - coin] + 1);
        return dp[amount] == INT_MAX ? -1 : dp[amount];
    }
};

int main()
{
    Solution sol;
    vector<int> c1 = {1, 2, 5};
    cout << sol.coinChange(c1, 11) << endl; // 3
    vector<int> c2 = {2};
    cout << sol.coinChange(c2, 3) << endl;  // -1
    vector<int> c3 = {1};
    cout << sol.coinChange(c3, 0) << endl;  // 0
    return 0;
}
