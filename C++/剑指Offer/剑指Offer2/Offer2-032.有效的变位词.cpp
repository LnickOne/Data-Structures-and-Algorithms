/* 题目难度: 简单
[原题链接](https://leetcode.cn/problems/dKk3P7/)
题目描述
给定两个字符串 s 和 t, 判断它们是不是一组变位词 (字母异位词)。
注意: 若 s 和 t 中每个字符出现的次数都相同且字符顺序不完全相同, 则称互为变位词。
题目样例
示例1
- 输入: s = "anagram", t = "nagaram"
- 输出: true
示例2
- 输入: s = "rat", t = "car"
- 输出: false
示例3
- 输入: s = "a", t = "a"
- 输出: false
题目思考
1. 如何统计字符串的字符出现次数?
解决方案
思路
- 先判断长度是否相等以及字符串本身是否相同, 任一条件不满足则直接返回
- 用长度为 26 的数组统计 s 中字符次数, 遍历 t 时减去对应次数
- 最后检查数组中所有计数是否均为 0
复杂度
- 时间复杂度 O(N): 需要统计每个字符
- 空间复杂度 O(1): 固定大小的计数数组
 */
#include <iostream>
using namespace std;

class Solution
{
public:
    bool isAnagram(string s, string t)
    {
        if (s.size() != t.size() || s == t) return false;
        int cnt[26] = {};
        for (char c : s) cnt[c - 'a']++;
        for (char c : t) cnt[c - 'a']--;
        for (int x : cnt) if (x != 0) return false;
        return true;
    }
};

int main()
{
    Solution sol;
    cout << boolalpha;
    cout << sol.isAnagram("anagram", "nagaram") << endl; // true
    cout << sol.isAnagram("rat", "car") << endl;         // false
    cout << sol.isAnagram("a", "a") << endl;             // false
    return 0;
}
