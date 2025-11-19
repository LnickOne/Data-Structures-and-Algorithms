#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
/*
给定一个整数数组 prices，其中 prices[i]表示第 i 天的股票价格 ；
整数 fee 代表了交易股票的手续费用。
你可以无限次地完成交易，但是你每笔交易都需要付手续费。
如果你已经购买了一个股票，在卖出它之前你就不能再继续购买股票了。
返回获得利润的最大值。
注意：这里的一笔交易指买入持有并卖出股票的整个过程，每笔交易你只需要为支付一次手续费。
示例 1：
输入：prices = [1, 3, 2, 8, 4, 9], fee = 2
输出：8
解释：能够达到的最大利润:
在此处买入 prices[0] = 1
在此处卖出 prices[3] = 8
在此处买入 prices[4] = 4
在此处卖出 prices[5] = 9
总利润: ((8 - 1) - 2) + ((9 - 4) - 2) = 8
示例 2：
输入：prices = [1,3,7,5,10,3], fee = 3
输出：6
*/
class Solution
{
public:
    /*
    动态规划五部曲
    1. 确定dp数组以及下标的含义
    2. 确定递推关系
    3. 确定初始值
    4. 确定遍历顺序
    5. 举例推导dp数组
    */
    int maxProfit(vector<int> &prices, int fee)
    {
        vector<vector<int>> dp(prices.size(), vector<int>(2));
        dp[0][0] = 0;
        dp[0][1] = 0 - prices[0] - fee; // 第0天买入股票时候也有手续费
        for (int i = 1; i < prices.size(); i++)
        {
            dp[i][0] = max(dp[i - 1][0], dp[i - 1][1] + prices[i]);       // 手续费已经包含了
            dp[i][1] = max(dp[i - 1][1], dp[i - 1][0] - prices[i] - fee); // 买入的时候，要考虑手续费
        }
        return dp[prices.size() - 1][0];
    }
};

int main()
{
    return 0;
}