#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
/*
给定一个数组 prices ，它的第 i 个元素 prices[i] 表示一支给定股票第 i 天的价格。
你只能选择 某一天 买入这只股票，并选择在 未来的某一个不同的日子 卖出该股票。
设计一个算法来计算你所能获取的最大利润。
返回你可以从这笔交易中获取的最大利润。如果你不能获取任何利润，返回 0 。
示例 1：
输入：[7,1,5,3,6,4]
输出：5
解释：在第 2 天（股票价格 = 1）的时候买入，在第 5 天（股票价格 = 6）的时候卖出，最大利润 = 6-1 = 5 。
     注意利润不能是 7-1 = 6, 因为卖出价格需要大于买入价格；同时，你不能在买入前卖出股票。
示例 2：
输入：prices = [7,6,4,3,1]
输出：0
解释：在这种情况下, 没有交易完成, 所以最大利润为 0。
*/
class Solution
{
public:
    /*
    动态规划五部曲
    1. 确定dp数组以及下标的含义
    第i天有两个状态，一个是持有这支股票，一个是不持有这支股票。
    持有相当于买入，不持有相当于卖出
    0表示不持有状态，1表示持有状态
    dp[i][0]：表示第i天状态0：(不持有）卖出这支股票所拥有的最大现金
    dp[i][1]：表示第i天状态1：（持有）买入这支股票所拥有的最大现金
    2. 确定递推关系
    dp[i][0] = max(dp[i - 1][0], dp[i - 1][1] + price[i]);
    dp[i][1] = max(dp[i - 1][1], -price[i]);
    3. 确定初始值
    dp[0] = 0
    4. 确定遍历顺序
    5. 举例推导dp数组
    */
    int maxProfit(vector<int> &prices)
    {
        if (prices.size() == 0)
            return 0;
        vector<vector<int>> dp(prices.size(), vector<int>(2));
        dp[0][0] = 0;          // 第0天卖出股票的最大现金是dp[0][0]，手上没有股票无法卖出所以现金为0
        dp[0][1] = -prices[0]; // 第0天买入股票的最大现金是dp[0][1]，值为-price[0]
        for (int i = 1; i < prices.size(); i++)
        {
            dp[i][0] = max(dp[i - 1][0], dp[i - 1][1] + prices[i]); // dp[i][0]表示第i天(卖出)不持有股票的状态，由dp[i-1][0]不持有股票的现金和dp[i-1][1]+price[i]，前i-1天都持有，但是第[i]天卖掉股票才是不持有的状态
            dp[i][1] = max(dp[i - 1][1], 0 - prices[i]);            // dp[i][1]表示第i天(买入)持有股票的状态，由dp[i-1][1]持有股票的现金和0-price[i]，前i-1天都持有，但是第[i]天买入股票才是持有股票的状态
        }
        return dp[prices.size() - 1][0]; // 不持有股票的时候现金肯定是最多的
    }
}

;

int main()
{
    vector<int> prices = {7, 1, 5, 3, 6, 4};
    Solution solve;
    cout << solve.maxProfit(prices) << endl;
    return 0;
}