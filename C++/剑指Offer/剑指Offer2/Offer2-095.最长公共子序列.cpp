/* 题目难度: 中等
[原题链接](https://leetcode.cn/problems/qJnOS7/)
题目描述
给定两个字符串 text1 和 text2, 返回最长公共子序列的长度。不存在则返回 0。
题目样例
示例1
- 输入: text1="abcde", text2="ace"
- 输出: 3 (公共子序列 "ace")
示例2
- 输入: text1="abc", text2="abc"
- 输出: 3
示例3
- 输入: text1="abc", text2="def"
- 输出: 0
题目思考
1. 如何从单个字符角度推导出转移方程?
解决方案
思路
- 二维 DP: dp[i][j] = text1 前 i 字符与 text2 前 j 字符的 LCS 长度
- text1[i-1]==text2[j-1]: dp[i][j] = dp[i-1][j-1]+1
- 否则: dp[i][j] = max(dp[i-1][j], dp[i][j-1])
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
    int longestCommonSubsequence(string text1, string text2)
    {
        int m = text1.size(), n = text2.size();
        vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));
        for (int i = 1; i <= m; i++)
            for (int j = 1; j <= n; j++)
                dp[i][j] = text1[i-1] == text2[j-1]
                    ? dp[i-1][j-1] + 1
                    : max(dp[i-1][j], dp[i][j-1]);
        return dp[m][n];
    }
};

int main()
{
    Solution sol;
    cout << sol.longestCommonSubsequence("abcde", "ace") << endl; // 3
    cout << sol.longestCommonSubsequence("abc", "abc") << endl;   // 3
    cout << sol.longestCommonSubsequence("abc", "def") << endl;   // 0
    return 0;
}
