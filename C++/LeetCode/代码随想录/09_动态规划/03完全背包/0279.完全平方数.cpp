#include <vector>
#include <iostream>
#include <algorithm>
#include <climits>
using namespace std;
/*
给你一个整数 n ，返回 和为 n 的完全平方数的最少数量 。
完全平方数 是一个整数，其值等于另一个整数的平方；换句话说，其值等于一个整数自乘的积。
例如，1、4、9 和 16 都是完全平方数，而 3 和 11 不是。
示例 1：
输入：n = 12
输出：3
解释：12 = 4 + 4 + 4
示例 2：
输入：n = 13
输出：2
解释：13 = 4 + 9
*/
class Solution
{
public:
    /*
    动态规划五部曲
    1. 确定dp数组以及下标的含义
    dp[j]表示整数j的完全平方数的最少数量
    2. 确定递推关系
    dp[j] = min(dp[j],dp[j-i*i]+1)
    3. 确定初始值
    dp[0] = 0
    4. 确定遍历顺序
    求的是组合数，所以是先遍历物品再遍历背包。
    5. 举例推导dp数组
    */
    int numSquares(int n)
    {
        int backpack_capacity = n;
        vector<int> dp(backpack_capacity + 1, INT_MAX);
        dp[0] = 0;
        for (int i = 1; i * i <= n; i++) // 遍历物品,物品的容量最大为n
        {
            for (int j = i * i; j <= backpack_capacity; j++) // 遍历背包,从物品的重量开始,每个物品的重量是(i*i)
            {
                dp[j] = min(dp[j], dp[j - i * i] + 1);
            }
        }
        return dp[n];
    }
};

int main()
{
    int n = 12;
    Solution s;
    cout << s.numSquares(n);
    cout << endl;
}