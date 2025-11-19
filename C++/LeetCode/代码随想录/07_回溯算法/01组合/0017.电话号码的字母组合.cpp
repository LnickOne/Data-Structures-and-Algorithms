/*
给定一个仅包含数字 2-9 的字符串，返回所有它能表示的字母组合。答案可以按 任意顺序 返回。
给出数字到字母的映射如下（与电话按键相同）。注意 1 不对应任何字母。
示例 1：
输入：digits = "23"
输出：["ad","ae","af","bd","be","bf","cd","ce","cf"]
示例 2：
输入：digits = ""
输出：[]
示例 3：
输入：digits = "2"
输出：["a","b","c"]
*/
#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;
class Solution
{
public:
    vector<string> letterCombinations(const string &digits)
    {
        if (digits.empty())
            return {};
        vector<string> result;
        string path;
        unordered_map<char, string> map =
            {
                {'2', "abc"},
                {'3', "def"},
                {'4', "ghi"},
                {'5', "jkl"},
                {'6', "mno"},
                {'7', "pqrs"},
                {'8', "tuv"},
                {'9', "wxyz"}};
        backtracking(0, 0, digits, map, path, result);
        return result;
    }
    void backtracking(const int &start, const int &index, const string &digits, const unordered_map<char, string> &map, string &path, vector<string> &result)
    {
        if (path.size() == digits.size())
        {
            result.push_back(path);
            return;
        }
        string str = map.at(digits[index]);
        for (int i = start; i < str.size(); i++)
        {
            path.push_back(str[i]);
            backtracking(0, index + 1, digits, map, path, result);
            path.pop_back();
        }
    }
};

int main()
{
    Solution s;
    vector<string> result = s.letterCombinations("23");
    for (auto &i : result)
    {
        cout << i << " ";
    }
    cout << endl;
    return 0;
}