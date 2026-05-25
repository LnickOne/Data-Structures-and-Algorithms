/* 题目难度: 简单
[原题链接](https://leetcode.cn/problems/qing-wa-tiao-tai-jie-wen-ti-lcof/)
题目描述
平台有 num 个格子, 每次可跳 1 或 2 格。返回共有多少种不同跳跃方式 (结果对 1e9+7 取模)。
题目样例
示例1
- 输入: n=2
- 输出: 2
示例2
- 输入: n=5
- 输出: 8
题目思考
1. 第 n 阶跳法数目如何推导?
解决方案
思路
- dp[n]=dp[n-1]+dp[n-2], 初始 dp[0]=1, dp[1]=1
- 滚动变量 ppre/pre, O(1) 空间
复杂度
- 时间复杂度 O(N): 遍历一次
- 空间复杂度 O(1): 仅两个变量
 */
#include <iostream>
using namespace std;

class Solution
{
public:
    int trainWays(int n)
    {
        if (n <= 1) return 1;
        const int MOD = 1000000007;
        int ppre = 1, pre = 1;
        for (int i = 2; i <= n; ++i)
        {
            int cur = ((long long)ppre + pre) % MOD;
            ppre = pre; pre = cur;
        }
        return pre;
    }
};

int main()
{
    Solution sol;
    cout << sol.trainWays(2) << endl; // 2
    cout << sol.trainWays(5) << endl; // 8
    return 0;
}
