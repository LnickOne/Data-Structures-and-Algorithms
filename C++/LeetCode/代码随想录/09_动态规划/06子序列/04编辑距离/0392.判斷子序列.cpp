/*
给定字符串 s 和 t ，判断 s 是否为 t 的子序列。
字符串的一个子序列是原始字符串删除一些（也可以不删除）字符而不改变剩余字符相对位置形成的新字符串。
（例如，"ace"是"abcde"的一个子序列，而"aec"不是）。
进阶：
如果有大量输入的 S，称作 S1, S2, ... , Sk 其中 k >= 10亿，你需要依次检查它们是否为 T 的子序列。在这种情况下，你会怎样改变代码？
示例 1：
输入：s = "abc", t = "ahbgdc"
输出：true
示例 2：
输入：s = "axc", t = "ahbgdc"
输出：false
*/
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
class Solution
{
public:
    /*
    动态规划五部曲
    1. 确定dp数组以及下标的含义
    对于求两个字符串里面的每一个元素是否相同可以用二维dp[i][j]数组表示
    dp[i][j]：表示以下标i-1为结尾的字符串s，和以下标j-1为结尾的字符串t，相同子序列的长度为dp[i][j]。
    2. 确定递推关系
    判断s[i-1]和t[j-1]是否相同，如果相同则dp[i][j] = dp[i-1][j-1]+1，否则dp[i][j] = max(dp[i-1][j],dp[i][j-1])
    3. 确定初始值
    4. 确定遍历顺序
    5. 举例推导dp数组
    */
    bool isSubsequence(string s, string t)
    {
        vector<vector<int>> dp(s.size() + 1, vector<int>(t.size() + 1, 0));
        for (int i = 1; i <= s.size(); i++)
        {
            for (int j = 1; j <= t.size(); j++)
            {
                if (s[i - 1] == t[j - 1])
                    dp[i][j] = max(dp[i][j], dp[i - 1][j - 1] + 1); // 如果可以删除s字符串的元素 dp[i][j]可以变为dp[i-1][j-1]，但是不可以删除S元素，所以是dp[i][j] = max(dp[i][j], dp[i - 1][j - 1] + 1)
                if (s[i - 1] != t[j - 1])
                    dp[i][j] = max(dp[i][j], dp[i][j - 1]); // 如果可以删除s字符串的元素 dp[i][j]可以变为dp[i-1][j]，但是不可以删除S元素，所以是dp[i][j] = max(dp[i][j], dp[i][j - 1])
            }
        }
        // 打印dp数组
        for (int i = 0; i <= s.size(); i++)
        {
            for (int j = 0; j <= t.size(); j++)
            {
                cout << dp[i][j] << " ";
            }
            cout << endl;
        }
        return dp[s.size()][t.size()] == s.size();
    }
};
int main()
{
    string s = "abc";
    string t = "ahbgdc";
    Solution solve;
    bool ans = solve.isSubsequence(s, t);
    cout << ans << endl;
    return 0;
}