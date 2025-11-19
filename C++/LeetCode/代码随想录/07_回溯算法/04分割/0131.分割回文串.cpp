#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
/*
给你一个字符串 s，请你将 s 分割成一些子串，使每个子串都是 回文串
返回 s 所有可能的分割方案。
示例 1：
输入：s = "aab"
输出：[["a","a","b"],["aa","b"]]
示例 2：
输入：s = "a"
输出：[["a"]]
*/
class Solution
{
public:
    vector<vector<string>> partition(string s)
    {
        vector<vector<string>> result;
        vector<string> path;
        backtracking(0, s, path, result);
        return result;
    }
    void backtracking(int start, string s, vector<string> path, vector<vector<string>> &result)
    {
        if (start == s.size()) // 如果起始位置等于s的大小，说明已经找到了一组分割方案了
        {
            result.push_back(path);
            return;
        }
        for (int i = start; i < s.size(); i++)
        {
            if (isPalindrome(s.substr(start, i - start + 1)))
            {
                path.push_back(s.substr(start, i - start + 1));
                backtracking(i + 1, s, path, result);
                path.pop_back();
            }
        }
    }
    bool isPalindrome(string s)
    {
        vector<vector<bool>> dp(s.size(), vector<bool>(s.size(), false));
        for (int i = s.size() - 1; i >= 0; i--)
        {
            for (int j = i; j < s.size(); j++)
            {
                if (s[i] == s[j])
                {
                    if (j - i == 0)
                        dp[i][j] = true;
                    if (j - i == 1)
                        dp[i][j] = true;
                    if (j - i > 1 && dp[i + 1][j - 1] == true)
                        dp[i][j] = true;
                }
            }
        }
        return dp[0][s.size() - 1];
    }
    bool isPalindrome2(string s)
    {
        int left = 0;
        int right = s.size() - 1;
        while (left < right)
        {
            if (s[left] != s[right])
                return false;
            left++;
            right--;
        }
        return true;
    }
};

int main()
{
    return 0;
}