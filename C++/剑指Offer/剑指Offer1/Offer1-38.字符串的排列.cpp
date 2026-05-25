/*
> 题目难度: 中等
> [原题链接](https://leetcode-cn.com/problems/zi-fu-chuan-de-pai-lie-lcof/)
题目描述
输入一个字符串，打印出该字符串中字符的所有排列。
你可以以任意顺序返回这个字符串数组，但里面不能有重复元素。
1 <= s 的长度 <= 8
题目样例
示例
输入：s = "abc"
输出：["abc","acb","bac","bca","cab","cba"]
题目思考
1. 如何不重复地得到所有排列?
解决方案
思路
- 要想不重复地得到所有排列, 我们可以定义一个方法, 来求字典序的下一个排列, 正如题目示例中的输出数组的顺序那样
- 初始化为最小的字典序, 然后当遍历到最大的字典序的时候, 就说明所有排列都被找到了
- 所以算法的核心就是如何通过一个字符串找它的字典序的下一个排列
- 排列方法使用回溯+剪枝: 排序后若当前字符与前一字符相同且前一字符未被使用, 则跳过, 避免重复
复杂度
- 时间复杂度 `O(N*N!)`
  - 最差情况下 N 个字符各不相同, 排列就有 `N!` 种, 从当前字符串转入下一个字符串最坏情况下需要 `O(N)` 时间
- 空间复杂度 `O(N)`
  - 递归栈和 visited 数组
*/

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

class Solution
{
public:
    vector<string> result;
    string path;
    vector<bool> visited;

    void backtrack(const string &s)
    {
        if ((int)path.size() == (int)s.size())
        {
            result.push_back(path);
            return;
        }
        for (int i = 0; i < (int)s.size(); i++)
        {
            if (visited[i])
            {
                continue;
            }
            // 剪枝: 跳过重复字符
            if (i > 0 && s[i] == s[i - 1] && !visited[i - 1])
            {
                continue;
            }
            visited[i] = true;
            path.push_back(s[i]);
            backtrack(s);
            path.pop_back();
            visited[i] = false;
        }
    }

    vector<string> permutation(string s)
    {
        sort(s.begin(), s.end());
        visited.assign(s.size(), false);
        backtrack(s);
        return result;
    }
};

int main()
{
    Solution sol;

    vector<string> res1 = sol.permutation("abc");
    for (const string &s : res1)
    {
        cout << s << " ";
    }
    cout << endl; // abc acb bac bca cab cba

    Solution sol2;
    vector<string> res2 = sol2.permutation("aab");
    for (const string &s : res2)
    {
        cout << s << " ";
    }
    cout << endl; // aab aba baa

    return 0;
}
