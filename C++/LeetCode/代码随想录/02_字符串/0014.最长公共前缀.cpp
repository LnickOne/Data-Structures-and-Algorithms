
/*
编写一个函数来查找字符串数组中的最长公共前缀。
如果不存在公共前缀，返回空字符串 ""。
示例 1：
输入：strs = ["flower","flow","flight"]
输出："fl"
示例 2：
输入：strs = ["dog","racecar","car"]
输出：""
解释：输入不存在公共前缀。
*/
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
class Solution
{
public:
    string longestCommonPrefix(vector<string> &strs)
    {
        if (strs.empty())
            return "";
        if (strs.size() == 1)
            return strs[0];
        string result = strs[0];
        for (int i = 0; i < result.size(); ++i)
        {
            char ch = result[i];
            for (int j = 1; j < strs.size(); ++j)
            {
                if (strs[j][i] == ch)
                    continue;
                if (strs[j][i] != ch)
                    return result.substr(0, i);
            }
        }
        return result;
    }
};

int main()
{
    vector<string> strs = {"flower", "flow", "flight"};
    Solution s;
    string result = s.longestCommonPrefix(strs);
    cout << result << endl;
    return 0;
}