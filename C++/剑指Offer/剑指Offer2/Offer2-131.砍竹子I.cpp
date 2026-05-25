/* 题目难度: 中等
[原题链接](https://leetcode.cn/problems/jian-sheng-zi-lcof/)
题目描述
将正整数 bamboo_len 的竹子砍为至少两段正整数, 返回各段长度的最大乘积。(2 <= bamboo_len <= 58)
题目样例
示例1
- 输入: bamboo_len=12
- 输出: 81
题目思考
1. 如何避免重复计算?
解决方案
思路
- 记忆化搜索: dp[n] 为长度 n 可拆分的最大乘积 (作为整体, 不强制再拆)
- n<=3 时直接返回 n; 外层对 n<=3 特判 (必须拆分故乘积为 n-1)
- dp[n] = max(i * dp[n-i]) for i in [2, n-2]
复杂度
- 时间复杂度 O(N^2): N 个状态各需 O(N) 转移
- 空间复杂度 O(N): memo 数组
 */
#include <iostream>
#include <vector>
using namespace std;

class Solution
{
    vector<int> memo;
    int cut(int n)
    {
        if (n <= 3) return n;
        if (memo[n]) return memo[n];
        int mx = 0;
        for (int i = 2; i <= n - 2; ++i)
            mx = max(mx, i * cut(n - i));
        return memo[n] = mx;
    }
public:
    int cuttingBamboo(int bamboo_len)
    {
        if (bamboo_len <= 3) return bamboo_len - 1;
        memo.assign(bamboo_len + 1, 0);
        return cut(bamboo_len);
    }
};

int main()
{
    Solution sol;
    cout << sol.cuttingBamboo(2)  << endl; // 1
    cout << sol.cuttingBamboo(12) << endl; // 81
    return 0;
}
