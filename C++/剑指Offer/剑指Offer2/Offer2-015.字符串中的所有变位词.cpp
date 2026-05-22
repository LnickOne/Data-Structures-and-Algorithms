/* 题目难度: 中等
[原题链接](https://leetcode.cn/problems/VabMRr)
题目描述
给定两个字符串 s 和 p, 找到 s 中所有 p 的变位词的子串, 返回这些子串的起始索引。
变位词指字母相同但排列不同的字符串。
题目样例
示例1
- 输入: s = "cbaebabacd", p = "abc"
- 输出: [0,6]
示例2
- 输入: s = "abab", p = "ab"
- 输出: [0,1,2]
题目思考
1. 如何优化时间复杂度?
解决方案
思路
- 与上一题 014 相同的滑动窗口思路, 只是把『判断是否存在』改为『收集所有起始索引』
- 固定窗口大小为 p 长度, 维护 cntp/cnts 计数数组和 unmatch 变量
- unmatch==0 时将当前窗口起点 r-le1+1 加入结果列表
复杂度
- 时间复杂度 O(N): 只需遍历 s 一遍 (N 是 s 的长度)
- 空间复杂度 O(1): 计数数组大小固定为 26
 */
#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution
{
public:
    vector<int> findAnagrams(string s, string p)
    {
        vector<int> res;
        if (s.size() < p.size()) return res;
        int cntp[26] = {}, cnts[26] = {};
        for (char c : p) cntp[c - 'a']++;
        int unmatch = p.size();
        int le1 = p.size(), le2 = s.size();
        for (int r = 0; r < le2; r++)
        {
            int rc = s[r] - 'a';
            cnts[rc]++;
            if (cnts[rc] <= cntp[rc]) unmatch--;
            else unmatch++;
            if (r >= le1)
            {
                int lc = s[r - le1] - 'a';
                cnts[lc]--;
                if (cnts[lc] >= cntp[lc]) unmatch--;
                else unmatch++;
            }
            if (unmatch == 0) res.push_back(r - le1 + 1);
        }
        return res;
    }
};

int main()
{
    Solution s;
    auto print = [](vector<int> &v) {
        cout << "[";
        for (int i = 0; i < (int)v.size(); i++) { if (i) cout << ","; cout << v[i]; }
        cout << "]" << endl;
    };
    auto r1 = s.findAnagrams("cbaebabacd", "abc");
    auto r2 = s.findAnagrams("abab", "ab");
    print(r1); // [0,6]
    print(r2); // [0,1,2]
    return 0;
}
