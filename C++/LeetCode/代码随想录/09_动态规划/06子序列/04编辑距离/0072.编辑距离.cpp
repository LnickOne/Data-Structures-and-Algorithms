/*
给你两个单词 word1 和 word2，请返回将 word1 转换成 word2 所使用的最少操作数  。
你可以对一个单词进行如下三种操作：
插入一个字符
删除一个字符
替换一个字符
示例 1：
输入：word1 = "horse", word2 = "ros"
输出：3
解释：
horse -> rorse (将 'h' 替换为 'r')
rorse -> rose (删除 'r')
rose -> ros (删除 'e')
示例 2：
输入：word1 = "intention", word2 = "execution"
输出：5
解释：
intention -> inention (删除 't')
inention -> enention (将 'i' 替换为 'e')
enention -> exention (将 'n' 替换为 'x')
exention -> exection (将 'n' 替换为 'c')
exection -> execution (插入 'u')
*/
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
class Solution
{
public:
    /*
    动态规划五部曲
    1. 确定dp数组以及下标的含义
    dp[i][j]：表示以下标[0,i-1]的word1和下标[0,j-1]的word2，将word1转换成word2的最少操作数
    2. 确定递推关系
    if(word1[i-1] == word2[j-1]) 
        dp[i][j] = dp[i-1][j-1]
    else
        dp[i][j] = min(dp[i-1][j] + 1, dp[i][j-1] + 1, dp[i-1][j-1] + 1)
    3. 确定初始值
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
        dp[0][0] = 0; // word1变成word2操作次数为0,和115题之前不同的地方，115题dp的含义是word1里面有多少个word2
        for (int i = 1; i <= word1.size(); i++)
        {
            for (int j = 1; j <= word2.size(); j++)
            {
                if (word1[i - 1] == word2[j - 1])
                {
                    dp[i][j] = dp[i - 1][j - 1]; // 无操作的情况就继承
                }
                else
                {
                    dp[i][j] = min(min(dp[i - 1][j] + 1, dp[i][j - 1] + 1), dp[i - 1][j - 1] + 1); // 增删换三个状态都考虑了
                }
            }
        }
        return dp[word1.size()][word2.size()];
    }
};

int main()
{
    string word1 = "horse";
    string word2 = "ros";
    Solution sol;
    cout << sol.minDistance(word1, word2) << endl;
    return 0;
}