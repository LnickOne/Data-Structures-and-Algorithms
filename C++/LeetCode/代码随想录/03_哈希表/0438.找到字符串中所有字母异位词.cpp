/*
给定两个字符串 s 和 p，找到 s 中所有 p 的 异位词 的子串，返回这些子串的起始索引。不考虑答案输出的顺序。
异位词 指由相同字母重排列形成的字符串（包括相同的字符串）。
示例 1:
输入: s = "cbaebabacd", p = "abc"
输出: [0,6]
解释:
起始索引等于 0 的子串是 "cba", 它是 "abc" 的异位词。
起始索引等于 6 的子串是 "bac", 它是 "abc" 的异位词。
示例 2:
输入: s = "abab", p = "ab"
输出: [0,1,2]
解释:
起始索引等于 0 的子串是 "ab", 它是 "ab" 的异位词。
起始索引等于 1 的子串是 "ba", 它是 "ab" 的异位词。
起始索引等于 2 的子串是 "ab", 它是 "ab" 的异位词。
提示:
1 <= s.length, p.length <= 3 * 104
s 和 p 仅包含小写字母
*/
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

class Solution
{
public:
    vector<int> findAnagrams(string s, string p)
    {
        // 方法一：哈希滑动窗口法
        if (p.size() > s.size())
            return {};
        vector<int> result;
        vector<int> hash_s(26, 0);
        vector<int> hash_p(26, 0);
        for (int i = 0; i < p.size(); i++)
        {
            hash_p[p[i] - 'a']++;
            hash_s[s[i] - 'a']++;
        }
        if (hash_s == hash_p)
            result.push_back(0);
        for (int i = p.size(); i < s.size(); i++)
        {
            // 窗口从p.size()起始,一边加一边清除,然后经过p.size()的长度后看看是否还和hash_p相等
            hash_s[s[i] - 'a']++;
            hash_s[s[i - p.size()] - 'a']--;
            if (hash_s == hash_p)
                result.push_back(i - p.size() + 1);
        }
        return result;
    }
};

int main()
{
    string s = "cbaebabacd";
    string p = "abc";
    string s1 = "aaaaaaaaaa";
    string p1 = "aaaaaaaaaaaaa";
    string s2 = "eklpyqrbgjdwtcaxzsnifvhmoueklpyqrbgjdwtcaxzsnifvhmoueklpyqrbg";
    string p2 = "yqrbgjdwtcaxzsnifvhmou";
    Solution sol;
    vector<int> result = sol.findAnagrams(s, p);
    for (int i = 0; i < result.size(); i++)
    {
        cout << result[i] << " ";
    }
    cout << endl;
    vector<int> result1 = sol.findAnagrams(s1, p1);
    for (int i = 0; i < result1.size(); i++)
    {
        cout << result1[i] << " ";
    }
    cout << endl;
    vector<int> result2 = sol.findAnagrams(s2, p2);
    for (int i = 0; i < result2.size(); i++)
    {
        cout << result2[i] << " ";
    }
    cout << endl;

    return 0;
}
