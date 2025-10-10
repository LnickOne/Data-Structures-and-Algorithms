#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
/*
给你一个整数数组 prices 和一个整数 k ，其中 prices[i] 是某支给定的股票在第 i 天的价格。
设计一个算法来计算你所能获取的最大利润。你最多可以完成 k 笔交易。也就是说，你最多可以买 k 次，卖 k 次。
注意：你不能同时参与多笔交易（你必须在再次购买前出售掉之前的股票）。
示例 1：
输入：k = 2, prices = [2,4,1]
输出：2
解释：在第 1 天 (股票价格 = 2) 的时候买入，在第 2 天 (股票价格 = 4) 的时候卖出，这笔交易所能获得利润 = 4-2 = 2 。
示例 2：
输入：k = 2, prices = [3,2,6,5,0,3]
输出：7
解释：在第 2 天 (股票价格 = 2) 的时候买入，在第 3 天 (股票价格 = 6) 的时候卖出, 这笔交易所能获得利润 = 6-2 = 4 。
     随后，在第 5 天 (股票价格 = 0) 的时候买入，在第 6 天 (股票价格 = 3) 的时候卖出, 这笔交易所能获得利润 = 3-0 = 3 。
*/
class Solution
{
public:
    int maxProfit(int k, vector<int> &prices)
    {
        if (prices.size() == 0)
            return 0;
        vector<vector<int>> dp(prices.size(), vector<int>(2 * k + 1, 0));
        for (int i = 1; i < 2 * k + 1; i += 2) // 初始化
            dp[0][i] = -prices[0];
        for (int i = 1; i < prices.size(); i++) // i表示第几天
        {
            for (int j = 0; j < 2 * k - 1; j += 2) // j表示买入卖出相当于第k次买卖
            {
                dp[i][j + 1] = max(dp[i - 1][j + 1], dp[i - 1][j] - prices[i]);     // 第i天第k次买入股票的最大现金
                dp[i][j + 2] = max(dp[i - 1][j + 2], dp[i - 1][j + 1] + prices[i]); // 第i天第k次卖出股票的最大现金
            }
        }
        return dp[prices.size() - 1][2 * k]; // 不持有股票的时候现金且操作次数最多能获得的现金肯定是最多的
    }
};

int main()
{
    vector<int> prices = {3, 2, 6, 5, 0, 3};
    int k = 2;
    Solution s;
    cout << s.maxProfit(k, prices);
    return 0;
}