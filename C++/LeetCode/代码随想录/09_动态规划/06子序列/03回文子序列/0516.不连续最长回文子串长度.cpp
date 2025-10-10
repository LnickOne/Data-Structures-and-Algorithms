#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
/**
给你一个字符串 s ，找出其中最长的回文子序列，并返回该序列的长度。
子序列定义为：不改变剩余字符顺序的情况下，删除某些字符或者不删除任何字符形成的一个序列。
示例 1：
输入：s = "bbbab"
输出：4
解释：一个可能的最长回文子序列为 "bbbb" 。
示例 2：
输入：s = "cbbd"
输出：2
解释：一个可能的最长回文子序列为 "bb" 。
 */
class Solution
{
public:
    /*
    动态规划五部曲
    1.确定DP数组的含义
    dp[i][j]：字符串s在[i, j]范围内最长的回文子序列的长度为dp[i][j]。
    2.确定递推公式
    在判断回文子串的题目中，关键逻辑就是
    情况一：如果s[i]与s[j]相同，相同就探索中间一段字符串+2
    情况二：如果s[i]与s[j]不相同，说明s[i]和s[j]的同时加入并不能增加[i,j]区间回文子序列的长度，
    那么分别加入s[i]、s[j]看看哪一个可以组成最长的回文子序列。
    加入s[j]的回文子序列长度为dp[i + 1][j]。加入s[i]的回文子序列长度为dp[i][j - 1]。
    那么dp[i][j]一定是取最大的，即：dp[i][j] = max(dp[i + 1][j], dp[i][j - 1]);
    if (s[i] == s[j])
    dp[i][j] = dp[i + 1][j - 1] + 2;
    if (i != j)
    dp[i][j] = max(dp[i + 1][j], dp[i][j - 1]);
    3.初始化DP数组
    dp[i][i] = 1;
    4.确定遍历顺序
    5.推导DP数组
     */
    int countSubstrings(string s)
    {
        vector<vector<int>> dp(s.size(), vector<int>(s.size()));
        for (int i = 0; i < s.size(); i++) // 初始化
        {
            for (int j = 0; j < s.size(); j++)
            {
                if (i == j)
                    dp[i][j] = 1;
                if (i != j)
                    dp[i][j] = 0;
            }
        }
        for (int i = s.size() - 1; i >= 0; i--)    // 递推公式
            for (int j = i + 1; j < s.size(); j++) // j是要大于i，并且初始化的时候i=j的情况dp[i][j]==1 所以从dp[i][j+1]开始
            {
                if (s[i] == s[j])
                    dp[i][j] = dp[i + 1][j - 1] + 2;
                if (s[i] != s[j])
                    dp[i][j] = max(dp[i + 1][j], dp[i][j - 1]);
            }
        return dp[0][s.size() - 1];
    }
};

int main()
{
    string s = "aaa";
    Solution sol;
    cout << sol.countSubstrings(s);
    cout << endl;

    return 0;
}