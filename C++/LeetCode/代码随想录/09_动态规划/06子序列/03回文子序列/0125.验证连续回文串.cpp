#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
/*
如果在将所有大写字符转换为小写字符、并移除所有非字母数字字符之后，短语正着读和反着读都一样。
则可以认为该短语是一个 回文串 。
字母和数字都属于字母数字字符。
给你一个字符串 s，如果它是 回文串 ，返回 true ；否则，返回 false 。
示例 1：
输入: s = "A man, a plan, a canal: Panama"
输出：true
解释："amanaplanacanalpanama" 是回文串。
示例 2：
输入：s = "race a car"
输出：false
解释："raceacar" 不是回文串。
示例 3：
输入：s = " "
输出：true
解释：在移除非字母数字字符之后，s 是一个空字符串 "" 。
由于空字符串正着反着读都一样，所以是回文串。
*/
class Solution
{
public:
    /*
    动态规划五部曲
    1. 确定dp数组以及下标的含义
    2. 确定递推关系
    3. 确定初始值
    4. 确定遍历顺序
    5. 举例推导dp数组
    */
    bool isPalindrome(string s)
    {
        if (s.size() == 0 || s.size() == 1)
            return true;
        string s_1;
        for (char ch : s)
            if (isalpha(ch) || isdigit(ch))
                s_1 += tolower(ch);
        vector<vector<bool>> dp(s_1.size(), vector<bool>(s_1.size(), false));
        for (int i = s_1.size() - 1; i >= 0; i--)
        {
            for (int j = i; j < s_1.size(); j++)
            {
                if (s_1[i] == s_1[j])
                {
                    if (j - i == 0)
                        dp[i][j] = true;
                    if (j - i == 1)
                        dp[i][j] = true;
                    if (j - i > 1)
                        dp[i][j] = dp[i + 1][j - 1];
                }
                if (s_1[i] != s_1[j])
                    dp[i][j] = false;
            }
        }
        return dp[0][s_1.size() - 1]; // 检验长度为[i,j]的字符串是否是回文串
    }
};

int main()
{
    Solution sol;

    cout << sol.isPalindrome("A man, a plan, a canal: Panama");

    return 0;
}