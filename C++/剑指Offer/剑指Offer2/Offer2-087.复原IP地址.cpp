/* 题目难度: 中等
[原题链接](https://leetcode.cn/problems/0on3uN/)
题目描述
给定一个只包含数字的字符串 s, 返回所有可能的有效 IP 地址。有效 IP 地址正好由四个 0~255 之间的整数组成, 不能含有前导 0, 整数之间用 '.' 分隔。
题目样例
示例1
- 输入: s="25525511135"
- 输出: ["255.255.11.135","255.255.111.35"]
示例2
- 输入: s="0000"
- 输出: ["0.0.0.0"]
示例3
- 输入: s="010010"
- 输出: ["0.10.0.10","0.100.1.0"]
题目思考
1. 如何高效枚举每一段?
解决方案
思路
- 回溯 DFS: 每次从 start 开始枚举长度 1~3 的段, 检查前导 0 和数值 <= 255
- 共 4 段, start == n 且 path.size() == 4 时记录结果
复杂度
- 时间复杂度 O(3^4): 4 段, 每段最多 3 种长度
- 空间复杂度 O(1): 递归深度最多 4
 */
#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution
{
    vector<string> res;
    vector<string> path;
    void dfs(const string &s, int start)
    {
        int n = s.size();
        if (start == n || (int)path.size() == 4)
        {
            if (start == n && (int)path.size() == 4)
            {
                res.push_back(path[0] + "." + path[1] + "." + path[2] + "." + path[3]);
            }
            return;
        }
        int num = 0;
        for (int end = start; end < min(n, start + 3); end++)
        {
            if (end > start && s[start] == '0') break;
            num = num * 10 + (s[end] - '0');
            if (num > 255) break;
            path.push_back(s.substr(start, end - start + 1));
            dfs(s, end + 1);
            path.pop_back();
        }
    }
public:
    vector<string> restoreIpAddresses(string s)
    {
        res.clear(); path.clear();
        dfs(s, 0);
        return res;
    }
};

int main()
{
    Solution sol;
    auto r1 = sol.restoreIpAddresses("25525511135");
    for (auto &s : r1) cout << s << " ";
    cout << endl; // 255.255.11.135 255.255.111.35
    auto r2 = sol.restoreIpAddresses("0000");
    for (auto &s : r2) cout << s << " ";
    cout << endl; // 0.0.0.0
    auto r3 = sol.restoreIpAddresses("010010");
    for (auto &s : r3) cout << s << " ";
    cout << endl; // 0.10.0.10 0.100.1.0
    return 0;
}
