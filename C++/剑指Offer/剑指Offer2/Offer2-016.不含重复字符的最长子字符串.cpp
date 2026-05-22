/* 题目难度: 中等
[原题链接](https://leetcode.cn/problems/wtcaE1)
题目描述
给定一个字符串 s, 请找出其中不含有重复字符的最长连续子字符串的长度。
题目样例
示例1
- 输入: s = "abcabcbb"
- 输出: 3
- 解释: 最长无重复子串是 "abc"
示例2
- 输入: s = "bbbbb"
- 输出: 1
示例3
- 输入: s = "pwwkew"
- 输出: 3
示例4
- 输入: s = ""
- 输出: 0
题目思考
1. 如何通过一次遍历得出结果?
解决方案
思路
- 暴力法固定起点往后扩展, 用集合统计字符, 时间 O(N*C)
- 滑动窗口优化: 遇到重复字符 c 时, 不必从起点+1 重新遍历
  - 因为以 [start+1, dup] 中任意位置为起点的子串都会在 end 处遇到重复, 且长度更短
  - 所以直接将起点推进到 dup+1 (dup 是 c 上一次出现的位置)
  - 移动起点过程中从集合中移除对应字符
- 维护字符集合, 每次更新窗口后更新最大长度
复杂度
- 时间复杂度 O(N): 起点和终点各遍历一遍
- 空间复杂度 O(1): 字符集合大小最多为字符种类数 (常数)
 */
#include <iostream>
#include <string>
#include <set>
using namespace std;

class Solution
{
public:
    int lengthOfLongestSubstring(string s)
    {
        set<char> v;
        int start = 0, res = 0;
        for (int end = 0; end < (int)s.size(); end++)
        {
            char c = s[end];
            while (v.count(c))
                v.erase(s[start++]);
            v.insert(c);
            res = max(res, end - start + 1);
        }
        return res;
    }
};

int main()
{
    Solution s;
    cout << s.lengthOfLongestSubstring("abcabcbb") << endl; // 3
    cout << s.lengthOfLongestSubstring("bbbbb") << endl;    // 1
    cout << s.lengthOfLongestSubstring("pwwkew") << endl;   // 3
    cout << s.lengthOfLongestSubstring("") << endl;         // 0
    return 0;
}
