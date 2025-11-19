#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
/*
给定三个字符串 s1、s2、s3，请你帮忙验证 s3 是否是由 s1 和 s2 交错 组成的。
两个字符串 s 和 t 交错 的定义与过程如下，其中每个字符串都会被分割成若干 非空子字符串：
s = s1 + s2 + ... + sn
t = t1 + t2 + ... + tm
|n - m| <= 1
交错 是 s1 + t1 + s2 + t2 + s3 + t3 + ... 或者 t1 + s1 + t2 + s2 + t3 + s3 + ...
注意：a + b 意味着字符串 a 和 b 连接。
示例 1：
输入：s1 = "aabcc", s2 = "dbbca", s3 = "aadbbcbcac"
输出：true
示例 2：
输入：s1 = "aabcc", s2 = "dbbca", s3 = "aadbbbaccc"
输出：false
示例 3：
输入：s1 = "", s2 = "", s3 = ""
输出：true
*/
class Solution
{
public:
    /*
    动态规划五部曲
    1. 确定dp数组以及下标的含义
    dp[i][j]表示s1[0...i]和s2[0...j]是否能组成s3[0...i+j]
    2. 确定递推关系
    dp[i][j] = dp[i-1][j] && s1[i] == s3[i+j] || dp[i][j-1] && s2[j] == s3[i+j]
    3. 确定初始值
    dp[0][0] = true
    4. 确定遍历顺序
    5. 举例推导dp数组
    */
    bool isInterleave(string s1, string s2, string s3)
    {
        int n = s1.size();
        int m = s2.size();
        int t = s3.size();
        if (n + m != t)
            return false;
        if (n == 0 && m == 0)
            return true;
        if (n == 0)
            return s2 == s3;
        if (m == 0)
            return s1 == s3;
        vector<vector<bool>> dp(n + 1, vector<bool>(m + 1, false));
        dp[0][0] = true;
        for (int i = 1; i <= n; i++)
        {
            dp[i][0] = dp[i - 1][0] && s1[i - 1] == s3[i - 1];
            for (int j = 1; j <= m; j++)
            {
                dp[0][j] = dp[0][j - 1] && s2[j - 1] == s3[j - 1];
                dp[i][j] = dp[i - 1][j] && s1[i - 1] == s3[i + j - 1] || dp[i][j - 1] && s2[j - 1] == s3[i + j - 1];
            }
        }
        return dp[n][m];
    }
};

int main()
{
    
    return 0;
}