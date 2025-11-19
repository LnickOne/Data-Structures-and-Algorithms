/*
假设你正在爬楼梯。需要 n 阶你才能到达楼顶。
每次你可以爬 1 或 2 个台阶。你有多少种不同的方法可以爬到楼顶呢？
示例 1：
输入：n = 2
输出：2
解释：有两种方法可以爬到楼顶。
1. 1 阶 + 1 阶
2. 2 阶
示例 2：
输入：n = 3
输出：3
解释：有三种方法可以爬到楼顶。
1. 1 阶 + 1 阶 + 1 阶
2. 1 阶 + 2 阶
3. 2 阶 + 1 阶
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
    dp[i]表示：从起始0阶或者起始1阶爬到第i阶,有dp[i]种方法。
    2. 确定递推关系
    dp[i] = dp[i-1] + dp[i-2]
    3. 确定初始值
    dp[0] = 1;
    dp[1] = 1;
    4. 确定遍历顺序
    5. 举例推导dp数组
    */
    int climbStairs(int n)
    {
        vector<int> dp(n + 1, 0);
        dp[0] = 1;
        dp[1] = 1;
        for (int i = 2; i <= n; i++)
        {
            dp[i] = dp[i - 1] + dp[i - 2];
        }
        return dp[n];
    }
};
int main()
{
    Solution s;
    cout << s.climbStairs(5) << endl;
    
}