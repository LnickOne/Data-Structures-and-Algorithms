#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
/*
给定一个数组，它的第 i 个元素是一支给定的股票在第 i 天的价格。
设计一个算法来计算你所能获取的最大利润。
你最多可以完成 两笔 交易。
注意：你不能同时参与多笔交易（你必须在再次购买前出售掉之前的股票）。
示例 1:
输入：prices = [3,3,5,0,0,3,1,4]
输出：6
解释：在第 4 天（股票价格 = 0）的时候买入，在第 6 天（股票价格 = 3）的时候卖出，这笔交易所能获得利润 = 3-0 = 3 。
     随后，在第 7 天（股票价格 = 1）的时候买入，在第 8 天 （股票价格 = 4）的时候卖出，这笔交易所能获得利润 = 4-1 = 3 。
示例 2：
输入：prices = [1,2,3,4,5]
输出：4
解释：在第 1 天（股票价格 = 1）的时候买入，在第 5 天 （股票价格 = 5）的时候卖出, 这笔交易所能获得利润 = 5-1 = 4 。
     注意你不能在第 1 天和第 2 天接连购买股票，之后再将它们卖出。
     因为这样属于同时参与了多笔交易，你必须在再次购买前出售掉之前的股票。
示例 3：
输入：prices = [7,6,4,3,1]
输出：0
解释：在这个情况下, 没有交易完成, 所以最大利润为 0。
示例 4：
输入：prices = [1]
输出：0
*/
class Solution
{
public:
    /*
    动态规划五部曲
    1. 确定dp数组以及下标的含义
    dp[i][0]：第i天什么也不做的最大现金
    dp[i][1]：第i天第一次持有股票的最大现金
    dp[i][2]：第i天第一次不持有股票的最大现金
    dp[i][3]：第i天第二次持有股票的最大现金
    dp[i][4]：第i天第二次不持有股票的最大现金
    2. 确定递推关系
    dp[0][0] = dp[i-1][0];
    dp[i][0] = max(dp[i-1][0], dp[i-1][1] + prices[i]);
    dp[i][1] = max(dp[i-1][1], dp[i-1][0] - prices[i]);
    dp[i][2] = max(dp[i-1][2], dp[i-1][1] + prices[i]);
    dp[i][3] = max(dp[i-1][3], dp[i-1][2] - prices[i]);
    3. 确定初始值
    dp[0][0]=0;
    dp[0][1]=-prices[0];
    dp[0][2]=dp[0][1]+prices[0];
    dp[0][3]=-prices[0];
    dp[0][4]=0;
    4. 确定遍历顺序
    5. 举例推导dp数组
    */
    int maxProfit(vector<int> &prices)
    {
        if (prices.size() == 0)
            return 0;
        vector<vector<int>> dp(prices.size(), vector<int>(5));
        dp[0][0] = 0;          // 什么也不做的最大现金
        dp[0][1] = -prices[0]; // 第一次买入股票
        dp[0][2] = 0;          // 第一次卖出股票
        dp[0][3] = -prices[0]; // 第二次买入股票
        dp[0][4] = 0;          // 第二次卖出股票
        for (int i = 1; i < prices.size(); i++)
        {
            dp[i][0] = dp[i - 1][0];                                // 什么也不做的最大现金
            dp[i][1] = max(dp[i - 1][1], dp[i - 1][0] - prices[i]); // 第i天第一次买入股票的最大现金
            dp[i][2] = max(dp[i - 1][2], dp[i - 1][1] + prices[i]); // 第i天第一次卖出股票的最大现金
            dp[i][3] = max(dp[i - 1][3], dp[i - 1][2] - prices[i]); // 第i天第二次买入股票的最大现金
            dp[i][4] = max(dp[i - 1][4], dp[i - 1][3] + prices[i]); // 第i天第二次卖出股票的最大现金
        }
        return dp[prices.size() - 1][4]; // 不持有股票的时候且能操作的次数最多现金肯定是最多的
    }
};
int main()
{
    vector<int> prices = {3, 3, 5, 0, 0, 3, 1, 4};
    Solution s;
    cout << s.maxProfit(prices);
    return 0;
}