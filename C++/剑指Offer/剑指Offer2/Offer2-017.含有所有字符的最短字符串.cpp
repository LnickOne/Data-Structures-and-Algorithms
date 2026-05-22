/* 题目难度: 困难
[原题链接](https://leetcode.cn/problems/M1oyTv)
题目描述
给定两个字符串 s 和 t, 返回 s 中包含 t 的所有字符的最短子字符串。
若不存在则返回 ""。若有多个满足条件的子串返回任意一个。
注意: t 中重复字符, 子串中该字符数量不少于 t 中的数量。
题目样例
示例1
- 输入: s = "ADOBECODEBANC", t = "ABC"
- 输出: "BANC"
示例2
- 输入: s = "a", t = "a"
- 输出: "a"
示例3
- 输入: s = "a", t = "aa"
- 输出: ""
题目思考
1. 如何在 O(N) 时间内解决此问题?
解决方案
思路
- 与 014/015 相同的滑动窗口思路, 但窗口大小不固定, 且子串只需包含 t 的所有字符 (不要求恰好相等)
- 维护 cntt/cnts 计数哈希表和 unmatch 变量 (初始为 t 长度)
- 右边界右移: cnts[c]++, 若 cnts[c] <= cntt[c] 则找到一个有效包含字符 unmatch--
- unmatch==0 时开始移动左边界压缩窗口: cnts[pc]--, 若 cnts[pc] < cntt[pc] 则 unmatch++, 停止左移
- 此时 [l-1, r] 是以 r 为终点的最短有效子串, 与当前结果比较并更新
复杂度
- 时间复杂度 O(N): 起点和终点各遍历一遍
- 空间复杂度 O(N): 哈希表最多存储 N 个元素
 */
#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;

class Solution
{
public:
    string minWindow(string s, string t)
    {
        if (s.size() < t.size()) return "";
        unordered_map<char, int> cntt, cnts;
        for (char c : t) cntt[c]++;
        int unmatch = t.size(), l = 0;
        string res = "";
        for (int r = 0; r < (int)s.size(); r++)
        {
            char c = s[r];
            cnts[c]++;
            if (cnts[c] <= cntt[c]) unmatch--;
            if (unmatch == 0)
            {
                while (unmatch == 0)
                {
                    char pc = s[l];
                    cnts[pc]--;
                    if (cnts[pc] < cntt[pc]) unmatch++;
                    l++;
                }
                string sub = s.substr(l - 1, r - l + 2);
                if (res.empty() || sub.size() < res.size()) res = sub;
            }
        }
        return res;
    }
};

int main()
{
    Solution s;
    cout << s.minWindow("ADOBECODEBANC", "ABC") << endl; // BANC
    cout << s.minWindow("a", "a") << endl;               // a
    cout << s.minWindow("a", "aa") << endl;              // (empty)
    cout << s.minWindow("cabwefgewcwaefgcf", "cae") << endl; // cwae
    return 0;
}
