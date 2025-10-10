#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
/*
给你一个整数数组 coins 表示不同面额的硬币，另给一个整数 amount 表示总金额。
请你计算并返回可以凑成总金额的硬币组合数。如果任何硬币组合都无法凑出总金额，返回 0 。
假设每一种面额的硬币有无限个。
题目数据保证结果符合 32 位带符号整数。
示例 1：
输入：amount = 5, coins = [1, 2, 5]
输出：4
解释：有四种方式可以凑成总金额：
5=5
5=2+2+1
5=2+1+1+1
5=1+1+1+1+1
示例 2：
输入：amount = 3, coins = [2]
输出：0
解释：只用面额 2 的硬币不能凑成总金额 3 。
示例 3：
输入：amount = 10, coins = [10]
输出：1
*/
class Solution
{
public:
    int change(int amount, vector<int> &coins)
    {
        int backpack_capacity = amount;
        vector<int> dp(backpack_capacity + 1, 0); // dp[j]的含义是有多少种方法，求组合数
        dp[0] = 1;
        for (int i = 0; i < coins.size(); i++) // 求组合数，先遍历物品
        {
            for (int j = coins[i]; j <= backpack_capacity; j++) // 遍历背包,要从第一个商品的重量开始
            {
                dp[j] = dp[j] + dp[j - coins[i]]; // 放物品的方法+不放物品的方法
            }
        }
        return dp[backpack_capacity];
    }
};
int main()
{
    Solution s;
    vector<int> coins{1, 2, 5};
    int amount = 5;
    cout << s.change(amount, coins);
    cout << endl;
    return 0;
}