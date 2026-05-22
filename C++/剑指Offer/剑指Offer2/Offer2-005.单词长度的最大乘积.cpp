/* 题目难度: 中等
[原题链接](https://leetcode.cn/problems/aseY1I/)
题目描述
给定一个字符串数组 words, 请计算当两个字符串 words[i] 和 words[j] 不包含相同字符时它们长度的乘积的最大值。
假设字符串中只包含英语的小写字母。如果没有不包含相同字符的一对字符串, 返回 0。
题目样例
示例1
- 输入: words = ["abcw","baz","foo","bar","fxyz","abcdef"]
- 输出: 16
- 解释: "abcw" 和 "fxyz" 不包含相同字符, 长度乘积 4*4 = 16
示例2
- 输入: words = ["a","ab","abc","d","cd","bcd","abcd"]
- 输出: 4
示例3
- 输入: words = ["a","aa","aaa","aaaa"]
- 输出: 0
题目思考
1. 如何利用『字符串中只包含英语的小写字母』这一条件?
2. 如何尽可能优化时间复杂度?
解决方案
思路
- 暴力两重循环判断每对字符串是否有公共字符, 时间复杂度 O(N^2*C), 结合题目规模约 10^9, 大概率超时
- 优化 1: 字符串只含 26 种小写字母, 可将每个字符串预处理成 26 位位图, 判断公共字符只需位运算求与, O(1) 完成
- 优化 2: 对于相同位图的字符串只保留最大长度 (较短的不可能构成最大乘积), 减少两重循环的枚举量
- 最终复杂度降为 O(N*C + M^2), M 为不重复位图数量, M <= min(N, 2^26)
复杂度
- 时间复杂度 O(N*C + N^2): 预处理 O(N*C), 两重循环枚举位图对 O(N^2)
- 空间复杂度 O(N): 存储位图到最大长度的映射
 */
#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
using namespace std;

class Solution
{
public:
    int maxProduct(vector<string> &words)
    {
        unordered_map<int, int> mask2len;
        for (auto &word : words)
        {
            int mask = 0;
            for (char c : word)
                mask |= 1 << (c - 'a');
            mask2len[mask] = max(mask2len[mask], (int)word.size());
        }
        vector<pair<int, int>> masks(mask2len.begin(), mask2len.end());
        int res = 0;
        for (int i = 0; i < (int)masks.size(); ++i)
            for (int j = i + 1; j < (int)masks.size(); ++j)
                if ((masks[i].first & masks[j].first) == 0)
                    res = max(res, masks[i].second * masks[j].second);
        return res;
    }
};

int main()
{
    Solution s;
    vector<string> words1 = {"abcw", "baz", "foo", "bar", "fxyz", "abcdef"};
    vector<string> words2 = {"a", "ab", "abc", "d", "cd", "bcd", "abcd"};
    vector<string> words3 = {"a", "aa", "aaa", "aaaa"};
    cout << s.maxProduct(words1) << endl; // 16
    cout << s.maxProduct(words2) << endl; // 4
    cout << s.maxProduct(words3) << endl; // 0
    return 0;
}
