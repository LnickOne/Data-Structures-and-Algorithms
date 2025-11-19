/*
给你两个字符串 s 和 t ，统计并返回在 s 的 子序列 中 t 出现的个数
示例 1：
输入：s = "rabbbit", t = "rabbit"
输出：3
解释：
如下所示, 有 3 种可以从 s 中得到 "rabbit" 的方案。
rabbbit
rabbbit
rabbbit
示例 2：
输入：s = "babgbag", t = "bag"
输出：5
解释：
如下所示, 有 5 种可以从 s 中得到 "bag" 的方案。
babgbag
babgbag
babgbag
babgbag
babgbag
 */
#include <vector>
#include <iostream>
#include <algorithm>
#include <cstdint>
using namespace std;
class Solution
{
public:
    /*
    动态规划五部曲
    1. 确定dp数组以及下标的含义
    dp[i][j]：表示以i-1为结尾的字符串s中有以j-1为结尾的字符串t的个数
    2. 确定递推关系
    dp[i][j] =dp[i-1][j] + dp[i][j-1] else dp[i][j]=dp[i-1][j]
    3. 确定初始值
    dp[0][0] = 1;
    for (int i = 1; i <= s.size(); i++) {
    dp[i][0] = 1;
    }
    for (int j = 1; j <= t.size(); j++) {
    dp[0][j] = 0;
    4. 确定遍历顺序
    5. 举例推导dp数组
    */
    int numDistinct(string s, string t)
    {
        vector<vector<uint64_t>> dp(s.size() + 1, vector<uint64_t>(t.size() + 1));
        for (int i = 1; i < s.size(); i++) // t为0的话那么下标就是-1就是空字符串,则s有1种方法变为空字符串，所以s变成t的方法是1种
            dp[i][0] = 1;
        for (int j = 1; j < t.size(); j++) // s为0的话就是s是空字符串，那么t有0种方法，所以s变成t的方法是j种
            dp[0][j] = 0;
        dp[0][0] = 1; // 此时t 0-1是空字符串，s有1个""空字符串,所以初始化为1
        for (int i = 1; i <= s.size(); i++)
        {
            for (int j = 1; j <= t.size(); j++)
            {
                // 题目的意思是s有多少种删除元素的方法变成t，所以只对s字符串进行考虑
                if (s[i - 1] == t[j - 1])
                    dp[i][j] = dp[i - 1][j - 1] + dp[i - 1][j]; // 这里是分两种情况，使用s[i-1]和不使用s[i-1]两种情况都考虑了才是总数
                if (s[i - 1] != t[j - 1])                       // 如果不相等就是s模拟将这个元素删除了
                    dp[i][j] = dp[i - 1][j];
            }
        }
        return dp[s.size()][t.size()];
    }
};

int main()
{
    string s = "rabbbit";
    string t = "rabbit";
    Solution().numDistinct(s, t);
    cout << Solution().numDistinct(s, t) << endl;
    return 0;
}