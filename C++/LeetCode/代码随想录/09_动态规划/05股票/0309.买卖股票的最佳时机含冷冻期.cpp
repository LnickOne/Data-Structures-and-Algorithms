#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
/*
给定一个整数数组prices，其中第prices[i]表示第i天的股票价格 。​
设计一个算法计算出最大利润。
在满足以下约束条件下，你可以尽可能地完成更多的交易（多次买卖一支股票）:
卖出股票后，你无法在第二天买入股票 (即冷冻期为 1 天)。
注意：你不能同时参与多笔交易（你必须在再次购买前出售掉之前的股票）。
示例 1:
输入: prices = [1,2,3,0,2]
输出: 3
解释: 对应的交易状态为: [买入, 卖出, 冷冻期, 买入, 卖出]
示例 2:
输入: prices = [1]
输出: 0
*/
class Solution
{
public:
    /*
    动态规划五部曲
    1. 确定dp数组以及下标的含义
    dp[i][0]：第i天的最大现金,这个状态可以理解为第i天不持有股票，也不处于冷冻期两种状态下的最大现金
    dp[i][1]：第i天持有股票的最大现金
    dp[i][2]：第i天不持有股票的最大现金
    dp[i][3]：第i天进入冷冻期的最大现金
    2. 确定递推关系
    dp[i][0] = max(dp[i-1][0], dp[i-1][2]);  //第i天不持有股票，并且不在冷冻期
    dp[i][1] = max(dp[i-1][1], dp[i-1][0] - prices[i]); //第i天持有股票，并且不处于冷冻期
    dp[i][2] = dp[i-1][1] + prices[i]; //第i天不持有股票，并且处于冷冻期
    dp[i][3] = dp[i-1][2]; //第i天不持有股票，并且处于冷冻期
    3. 确定初始值
    dp[0][0] = 0;
    dp[0][1] = -prices[0];
    dp[0][2] = 0;
    dp[0][3] = 0;
    4. 确定遍历顺序
    5. 举例推导dp数组
    */
    int maxProfit(vector<int> &prices)
    {
        if (prices.size() == 0)
            return 0;
        vector<vector<int>> dp(prices.size(), vector<int>(4));
        dp[0][0] = 0;
        dp[0][1] = -prices[0];
        dp[0][2] = 0;
        dp[0][3] = 0;
        for (int i = 1; i < prices.size(); i++)
        {
            /*
            冷冻期是发生在卖出股票的第二天
            dp[i][0]：第i天的最大现金,不处于冷冻期
            dp[i][1]：第i天买入股票的最大现金,不处于冷冻期
            dp[i][2]：第i天卖出股票的最大现金,处于冷冻期
            dp[i][3]：第i天的最大现金,处于冷冻期
            */
            dp[i][0] = max(dp[i - 1][0], dp[i - 1][2]);             // 第i天不持有股票的最大现金，可能发生过冷冻期，也可能没有发生
            dp[i][1] = max(dp[i - 1][1], dp[i - 1][0] - prices[i]); // 第i天买入股票的最大现金
            dp[i][2] = dp[i - 1][1] + prices[i];                    // 第i天卖出股票的最大现金
            dp[i][3] = dp[i - 1][2];                                // 第i天处于冷冻期的最大现金
        }
        return max(dp[prices.size() - 1][0], dp[prices.size() - 1][2]);
    }
};

int main()
{
    return 0;
}