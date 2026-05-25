/* 题目难度: 中等
[原题链接](https://leetcode.cn/problems/IDBivT/)
题目描述
正整数 n 代表生成括号的对数, 生成所有可能的并且有效的括号组合。
题目样例
示例1
- 输入: n=3
- 输出: ["((()))","(()())","(())()","()(())","()()()"]
示例2
- 输入: n=1
- 输出: ["()"]
题目思考
1. 如何保证生成的括号是合法的?
解决方案
思路
- 回溯 DFS: 记录已用左括号数 left 和右括号数 right
- left < n 时可加 '('; left > right 时可加 ')'
- left == right == n 时记录结果
复杂度
- 时间复杂度 O(2^N): 每步两种选择
- 空间复杂度 O(N): 递归栈
 */
#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution
{
    vector<string> res;
    void dfs(int left, int right, int n, string &cur)
    {
        if (left == n && right == n) { res.push_back(cur); return; }
        if (left < n) { cur += '('; dfs(left + 1, right, n, cur); cur.pop_back(); }
        if (left > right) { cur += ')'; dfs(left, right + 1, n, cur); cur.pop_back(); }
    }
public:
    vector<string> generateParenthesis(int n)
    {
        res.clear();
        string cur;
        dfs(0, 0, n, cur);
        return res;
    }
};

int main()
{
    Solution sol;
    auto r1 = sol.generateParenthesis(3);
    for (auto &s : r1) cout << s << " ";
    cout << endl; // ((()))  (()())  (())()  ()(())  ()()()
    auto r2 = sol.generateParenthesis(1);
    for (auto &s : r2) cout << s << " ";
    cout << endl; // ()
    return 0;
}
