#include <iostream>
#include <vector>
#include <string>
using namespace std;
class Solution
{
public:
    string longestCommonPrefix(vector<string> &strs)
    {
        if (strs.empty())
            return "";
        string result;
        result = strs[0];
        for (const string &str : strs)
        {
            result = common_dp(result, str);
        }
        return result;
    }

    string common_dp(string s1, string s2)
    {
        if (s1.empty() || s2.empty())
            return "";
        vector<vector<int>> dp(s1.size() + 1, vector<int>(s2.size() + 1));
        int maxlen;
        for (int i = 1; i <= max(s1.size(), s2.size()); i += 1)
        {
            if (s1[i - 1] == s2[i - 1])
                dp[i][i] = dp[i - 1][i - 1] + 1;
            if (s1[i - 1] != s2[i - 1])
                break;
            maxlen = i;
        }
        string result = s1.substr(0, maxlen);
        return result;
    }
};

int main()
{
    Solution s;
    vector<string> strs = {"flower", "flow", "flight"};
    string result = s.longestCommonPrefix(strs);
    cout << result << endl;
    return 0;
}