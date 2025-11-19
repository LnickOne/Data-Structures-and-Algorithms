#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
/*

*/
class Solution
{
public:
    /*
    动态规划五部曲
    1. 确定dp数组以及下标的含义
    dp[i][j] 表示str1[i:] 和 str2[j:]的最长公共子串的长度
    2. 确定递推关系
    dp[i][j] = dp[i - 1][j - 1] + 1;
    dp[i][j] = min(dp[i - 1][j], dp[i][j - 1]);
    3. 确定初始值
    dp[0][j] = 0;
    dp[i][0] = 0;
    4. 确定遍历顺序
    5. 举例推导dp数组
    */
    string LCS(string str1, string str2)
    {
        vector<vector<int>> dp(str1.size() + 1, vector<int>(str2.size() + 1, 0));
        string result;
        int max_len = 0;
        int start = 0;
        for (int i = 1; i <= str1.size(); i++)
        {
            for (int j = 1; j <= str2.size(); j++)
            {
                if (str1[i - 1] == str2[j - 1])
                    dp[i][j] = dp[i - 1][j - 1] + 1;
                else
                    dp[i][j] = min(dp[i - 1][j], dp[i][j - 1]);
                if (dp[i][j] > max_len)
                {
                    max_len = dp[i][j];
                    start = i - 1;
                }
            }
        }
        result = str1.substr(start - max_len + 1, max_len);
        return result;
    }
};

int main()
{
    string str1 = "1AB2345CD";
    string str2 = "12345EF";
    Solution s;
    cout << s.LCS(str1, str2) << endl;
    return 0;
}