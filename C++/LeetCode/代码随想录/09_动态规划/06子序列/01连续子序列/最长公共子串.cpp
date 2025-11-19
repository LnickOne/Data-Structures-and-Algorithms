#include <iostream>
#include <vector>
#include <string>
using namespace std;
class Solution
{
public:
    string longestCommonSubstring(vector<string> &strs)
    {
        if (strs.empty())
            return "";
        // 以第一个字符串作为初始结果
        string result = strs[0];
        for (int i = 1; i < strs.size(); i++)
        {
            result = commonSubstring(result, strs[i]);
            if (result.empty())
                break;
        }
        return result;
    }

    string commonSubstring(string s1, string s2)
    {
        // dp[i][j] 表示以 s1[i-1] 和 s2[j-1] 结尾的最长公共子串的长度
        vector<vector<int>> dp(s1.size() + 1, vector<int>(s2.size() + 1, 0));
        int max_len = 0;
        int startIndex = 0;
        for (int i = 1; i <= s1.size(); i++)
        {
            for (int j = 1; j <= s2.size(); j++)
            {
                if (s1[i - 1] == s2[j - 1])
                {
                    dp[i][j] = dp[i - 1][j - 1] + 1;
                }
                if (s1[i - 1] != s2[j - 1])
                {
                    dp[i][j] = 0;
                }
                if (dp[i][j] > max_len)
                {
                    max_len = dp[i][j];
                    startIndex = i - 1;
                }
            }
        }
        return s1.substr(startIndex - max_len + 1, max_len); // 根据最大长度和结束索引提取最长公共子串
    }
};
int main()
{
    Solution s;
    vector<string> strs = {"flower", "flow", "flight"};
    string result = s.longestCommonSubstring(strs);
    cout << result << endl;
    return 0;
}