/* 题目难度: 中等
[原题链接](https://leetcode.cn/problems/M99OJA/)
题目描述
给定一个字符串 s, 请将 s 分割成一些子串, 使每个子串都是回文串, 返回所有可能的分割方案。
题目样例
示例1
- 输入: s="google"
- 输出: [["g","o","o","g","l","e"],["g","oo","g","l","e"],["goog","l","e"]]
示例2
- 输入: s="aab"
- 输出: [["a","a","b"],["aa","b"]]
题目思考
1. 如何快速判断子串是否回文?
解决方案
思路
- 回溯 DFS: 从下标 i 开始枚举终点 j, 若 s[i..j] 是回文则加入当前分割, 递归到 j+1
- 用二维 memo 缓存回文判断结果, 避免重复计算
复杂度
- 时间复杂度 O(N*2^N): 最多 2^N 个分割, 每个构建需要 O(N)
- 空间复杂度 O(N^2): memo 缓存
 */
#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution
{
    vector<vector<string>> res;
    vector<string> cur;
    vector<vector<int>> memo;
    bool isPalin(const string &s, int i, int j)
    {
        if (i >= j)
            return true;
        if (memo[i][j] != -1)
            return memo[i][j];
        return memo[i][j] = (s[i] == s[j] && isPalin(s, i + 1, j - 1)) ? 1 : 0;
    }
    void dfs(const string &s, int i)
    {
        if (i == (int)s.size())
        {
            res.push_back(cur);
            return;
        }
        for (int j = i; j < (int)s.size(); j++)
        {
            if (isPalin(s, i, j))
            {
                cur.push_back(s.substr(i, j - i + 1));
                dfs(s, j + 1);
                cur.pop_back();
            }
        }
    }

public:
    vector<vector<string>> partition(string s)
    {
        res.clear();
        cur.clear();
        int n = s.size();
        memo.assign(n, vector<int>(n, -1));
        dfs(s, 0);
        return res;
    }
};

int main()
{
    Solution sol;
    auto r1 = sol.partition("google");
    for (auto &v : r1)
    {
        cout << "[";
        for (int i = 0; i < (int)v.size(); i++)
        {
            if (i)
                cout << ",";
            cout << v[i];
        }
        cout << "] ";
    }
    cout << endl; // [g,o,o,g,l,e] [g,oo,g,l,e] [goog,l,e]
    auto r2 = sol.partition("aab");
    for (auto &v : r2)
    {
        cout << "[";
        for (int i = 0; i < (int)v.size(); i++)
        {
            if (i)
                cout << ",";
            cout << v[i];
        }
        cout << "] ";
    }
    cout << endl; // [a,a,b] [aa,b]
    return 0;
}
