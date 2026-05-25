/* 题目难度: 困难
[原题链接](https://leetcode.cn/problems/21dk04/)
题目描述
给定字符串 s 和 t, 计算在 s 的子序列中 t 出现的个数。
题目样例
示例1
- 输入: s="rabbbit", t="rabbit"
- 输出: 3
示例2
- 输入: s="babgbag", t="bag"
- 输出: 5
题目思考
1. 如何从末尾字符匹配角度建立 DP?
解决方案
思路
- 二维 DP: dp[i][j] = s 前 i 字符的子序列中 t 前 j 字符出现的次数
- s[i-1]==t[j-1]: dp[i][j] = dp[i-1][j] + dp[i-1][j-1]
- 否则: dp[i][j] = dp[i-1][j]
- 初始 dp[i][0]=1 (空串总是可以被包含)
复杂度
- 时间复杂度 O(MN): 两重循环
- 空间复杂度 O(MN): 二维 DP 数组
 */
#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution
{
public:
    int numDistinct(string s, string t)
    {
        int m = s.size(), n = t.size();
        vector<vector<long long>> dp(m + 1, vector<long long>(n + 1, 0));
        for (int i = 0; i <= m; i++) dp[i][0] = 1;
        for (int i = 1; i <= m; i++)
            for (int j = 1; j <= n; j++)
            {
                dp[i][j] = dp[i-1][j];
                if (s[i-1] == t[j-1]) dp[i][j] += dp[i-1][j-1];
            }
        return (int)dp[m][n];
    }
};

int main()
{
    Solution sol;
    cout << sol.numDistinct("rabbbit", "rabbit") << endl; // 3
    cout << sol.numDistinct("babgbag", "bag") << endl;    // 5
    return 0;
}
