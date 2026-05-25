/* 题目难度: 困难
[原题链接](https://leetcode.cn/problems/zheng-ze-biao-da-shi-pi-pei-lcof/)
题目描述
'.' 匹配任意单个字符, '*' 匹配零或多个前一元素。判断模式串 p 是否匹配整个字符串 s。
题目样例
示例1
- 输入: article="aa", input="a"
- 输出: false
示例2
- 输入: article="aa", input="a*"
- 输出: true
示例3
- 输入: article="ab", input=".*"
- 输出: true
题目思考
1. 如何处理 '.' 和 '*'?
解决方案
思路
- 记忆化搜索 dp[i][j] 表示 s[i..] 与 p[j..] 是否匹配
- p[j+1]=='*': 可跳过 (j+2) 或当前字符匹配时 i+1
- p[j+1]!='*': 当前字符必须匹配, i+1, j+1
复杂度
- 时间复杂度 O(MN): M/N 为 s/p 长度
- 空间复杂度 O(MN): memo 数组
 */
#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution
{
    string s, p;
    vector<vector<int>> memo;
    // 返回 1=true, 0=false, -1=未计算
    bool match(int i, int j)
    {
        if (memo[i][j] != -1) return memo[i][j];
        bool res;
        if (j == (int)p.size())
        {
            res = (i == (int)s.size());
        }
        else if (i == (int)s.size())
        {
            res = (j + 1 < (int)p.size() && p[j + 1] == '*' && match(i, j + 2));
        }
        else
        {
            bool curMatch = (s[i] == p[j] || p[j] == '.');
            if (j + 1 < (int)p.size() && p[j + 1] == '*')
                res = match(i, j + 2) || (curMatch && match(i + 1, j));
            else
                res = curMatch && match(i + 1, j + 1);
        }
        return memo[i][j] = res;
    }
public:
    bool articleMatch(string article, string input)
    {
        s = article; p = input;
        memo.assign((int)s.size() + 1, vector<int>((int)p.size() + 1, -1));
        return match(0, 0);
    }
};

int main()
{
    Solution sol;
    cout << boolalpha;
    cout << sol.articleMatch("aa", "a")   << endl; // false
    cout << sol.articleMatch("aa", "a*")  << endl; // true
    cout << sol.articleMatch("ab", ".*")  << endl; // true
    return 0;
}
