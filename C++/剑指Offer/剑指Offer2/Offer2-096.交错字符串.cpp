/* 题目难度: 中等
[原题链接](https://leetcode.cn/problems/IY6buf/)
题目描述
给定三个字符串 s1、s2、s3, 判断 s3 能否由 s1 和 s2 交错组成。
题目样例
示例1
- 输入: s1="aabcc", s2="dbbca", s3="aadbbcbcac"
- 输出: true
示例2
- 输入: s1="aabcc", s2="dbbca", s3="aadbbbaccc"
- 输出: false
示例3
- 输入: s1="", s2="", s3=""
- 输出: true
题目思考
1. 如何从 s1 s2 各取一个字符匹配 s3 的角度建立 DP?
解决方案
思路
- 二维 DP: dp[i][j] = s1 前 i 个字符和 s2 前 j 个字符能否交错组成 s3 前 i+j 个字符
- 转移: dp[i][j] |= (s1[i-1]==s3[k] && dp[i-1][j]) 或 (s2[j-1]==s3[k] && dp[i][j-1])
- 初始 dp[0][0]=true
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
    bool isInterleave(string s1, string s2, string s3)
    {
        int m = s1.size(), n = s2.size();
        if (m + n != (int)s3.size()) return false;
        vector<vector<bool>> dp(m + 1, vector<bool>(n + 1, false));
        dp[0][0] = true;
        for (int i = 0; i <= m; i++)
        {
            for (int j = 0; j <= n; j++)
            {
                int k = i + j - 1;
                if (i > 0) dp[i][j] = dp[i][j] || (s1[i-1] == s3[k] && dp[i-1][j]);
                if (j > 0) dp[i][j] = dp[i][j] || (s2[j-1] == s3[k] && dp[i][j-1]);
            }
        }
        return dp[m][n];
    }
};

int main()
{
    Solution sol;
    cout << boolalpha;
    cout << sol.isInterleave("aabcc", "dbbca", "aadbbcbcac") << endl; // true
    cout << sol.isInterleave("aabcc", "dbbca", "aadbbbaccc") << endl; // false
    cout << sol.isInterleave("", "", "") << endl;                      // true
    return 0;
}
