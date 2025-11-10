/*
数字 n 代表生成括号的对数，请你设计一个函数，用于能够生成所有可能的并且 有效的 括号组合。
示例 1：
输入：n = 3
输出：["((()))","(()())","(())()","()(())","()()()"]
示例 2：
输入：n = 1
输出：["()"]
*/
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
class Solution
{
public:
    vector<string> generateParenthesis(int n)
    {
        if (n == 0)
            return {};
        vector<string> result;
        string path;
        backtracking(n, 0, 0, path, result);
        return result;
    }
    void backtracking(int n, int left, int right, string &path, vector<string> &result)
    {
        if (path.size() == n * 2)
        {
            result.push_back(path);
            return;
        }
        if (left < n)
        {
            left += 1;
            path += "(";
            backtracking(n, left, right, path, result);
            path.pop_back();
            left -= 1;
        }
        if (right < left)
        {
            right += 1;
            path += ")";
            backtracking(n, left, right, path, result);
            path.pop_back();
            right -= 1;
        }
    }
};

int main()
{
    Solution s;
    vector<string> result = s.generateParenthesis(3);
    for (const auto &i : result)
    {
        cout << i << " ";
    }
    cout << endl;
    return 0;
}