/*
给定两个单词 word1 和 word2 ，返回使得word1和word2相同所需的最小步数。
每步 可以删除任意一个字符串中的一个字符。
示例 1：
输入: word1 = "sea", word2 = "eat"
输出: 2
解释: 第一步将 "sea" 变为 "ea" ，第二步将 "eat "变为 "ea"
示例  2:
输入：word1 = "leetcode", word2 = "etco"
输出：4
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
    dp[i][j]：以下标i-1为结尾的字符串word1，和以下标j-1位结尾的字符串word2达到相等，所需要删除元素的最少次数。
    2. 确定递推关系
    因为word1和word2都可以操作，整体一共有两种情况
    当word1[i - 1] 与 word2[j - 1] 相同的时候
    因为删除word1[i - 1]，word2[j - 1]保持不变，所以dp[i][j] = dp[i - 1][j - 1];
    当word1[i - 1] 与 word2[j - 1] 不相同的时候，有三种情况：
    情况一：删word1[i - 1]，最少操作次数为dp[i - 1][j] + 1
    情况二：删word2[j - 1]，最少操作次数为dp[i][j - 1] + 1
    情况三：同时删word1[i - 1] 和word2[j - 1]，操作的最少次数为dp[i - 1][j - 1] + 2
    最后是取最小值，所以当word1[i - 1] 与 word2[j - 1] 不相同的时候，
    递推公式：dp[i][j] = min({dp[i - 1][j - 1] + 2, dp[i - 1][j] + 1, dp[i][j - 1] + 1});
    因为 dp[i][j - 1] + 1 = dp[i - 1][j - 1] + 2，所以递推公式可简化为：dp [i][j] = min(dp[i - 1][j] + 1, dp[i][j - 1] + 1);
    这里可能有点迷糊，从字面上理解 就是 当 同时删word1[i - 1] 和word2[j - 1]，dp[i][j - 1]
    本来就不考虑 word2[j - 1] 了，那么我在删 word1[i - 1]，是不是就达到两个元素都删除的效果，即 dp[i][j - 1] + 1。
    3. 确定初始值
    dp[0][0] = 1;
    for (int i = 1; i <= s.size(); i++) {
        dp[i][0] = 1;
    }
    for (int j = 1; j <= t.size(); j++) {
        dp[0][j] = 0;
    }
    4. 确定遍历顺序
    5. 举例推导dp数组
    */
    int minDistance(string word1, string word2)
    {

        vector<vector<int>> dp(word1.size() + 1, vector<int>(word2.size() + 1));
        for (int i = 1; i <= word1.size(); i++)
            dp[i][0] = i;
        for (int j = 1; j <= word2.size(); j++)
            dp[0][j] = j;
        dp[0][0] = 0;
        for (int i = 1; i <= word1.size(); i++)
        {
            for (int j = 1; j <= word2.size(); j++)
            {
                if (word1[i - 1] == word2[j - 1])
                    dp[i][j] = dp[i - 1][j - 1];
                if (word1[i - 1] != word2[j - 1])
                    dp[i][j] = min(min(dp[i - 1][j] + 1, dp[i][j - 1] + 1), dp[i - 1][j - 1] + 2);
            }
        }
        return dp[word1.size()][word2.size()];
    }
};

int main()
{
    string word1 = "sea", word2 = "eat";
    Solution s;
    cout << s.minDistance(word1, word2) << endl;
    return 0;
}