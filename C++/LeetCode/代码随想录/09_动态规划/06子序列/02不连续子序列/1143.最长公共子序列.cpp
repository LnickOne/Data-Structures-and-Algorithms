#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
/*
给定两个字符串 text1 和 text2，返回这两个字符串的最长 公共子序列 的长度。
如果不存在 公共子序列 ，返回 0 。
一个字符串的 子序列 是指这样一个新的字符串：
它是由原字符串在不改变字符的相对顺序的情况下删除某些字符（也可以不删除任何字符）后组成的新字符串。
例如，"ace" 是 "abcde" 的子序列，但 "aec" 不是 "abcde" 的子序列。
两个字符串的 公共子序列 是这两个字符串所共同拥有的子序列。
示例 1：
输入：text1 = "abcde", text2 = "ace"
输出：3
解释：最长公共子序列是 "ace" ，它的长度为 3 。
示例 2：
输入：text1 = "abc", text2 = "abc"
输出：3
解释：最长公共子序列是 "abc" ，它的长度为 3 。
示例 3：
输入：text1 = "abc", text2 = "def"
输出：0
解释：两个字符串没有公共子序列，返回 0 。
*/
class Solution
{
public:
    /*
    动态规划五部曲
    1. 确定dp数组以及下标的含义
    dp[i][j]:表示text1[0...i-1]和text2[0...j-1]的最长公共子序列的长度
    动态规划求
    2. 确定递推关系
    dp[i][j] =
    if text1[i-1] == text2[j-1]
        dp[i-1][j-1] + 1
    else max(dp[i-1][j], dp[i][j-1])
    3. 确定初始值
    4. 确定遍历顺序
    5. 举例推导dp数组
    */
    int longestCommonSubsequence(string text1, string text2)
    {
        vector<vector<int>> dp(text1.size() + 1, vector<int>(text2.size() + 1, 0));
        int result = 0;
        for (int i = 1; i <= text1.size(); i++)
        {
            for (int j = 1; j <= text2.size(); j++)
            {
                if (text1[i - 1] == text2[j - 1])
                    dp[i][j] = max(dp[i][j], dp[i - 1][j - 1] + 1);
                if (text1[i - 1] != text2[j - 1])
                    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
                result = max(result, dp[i][j]);
            }
        }
        return result;
    }
};
int main()
{
    string text1_1 = "abcde", text1_2 = "ace";
    string text2_1 = "abc", text2_2 = "abc";
    string text3_1 = "abc", text3_2 = "def";
    cout << "最长公共子序列的长度是：" << endl;
    cout << Solution().longestCommonSubsequence(text1_1, text1_2) << endl;
    cout << Solution().longestCommonSubsequence(text2_1, text2_2) << endl;
    cout << Solution().longestCommonSubsequence(text3_1, text3_2) << endl;
    return 0;
}