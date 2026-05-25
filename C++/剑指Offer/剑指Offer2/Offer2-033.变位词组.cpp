/* 题目难度: 中等
[原题链接](https://leetcode.cn/problems/sfvd7V/)
题目描述
给定一个字符串数组 strs, 将变位词组合在一起。可以按任意顺序返回结果列表。
注意: 若两个字符串中每个字符出现的次数都相同, 则称它们互为变位词。
题目样例
示例1
- 输入: strs = ["eat","tea","tan","ate","nat","bat"]
- 输出: [["bat"],["nat","tan"],["ate","eat","tea"]]
示例2
- 输入: strs = [""]
- 输出: [[""]]
示例3
- 输入: strs = ["a"]
- 输出: [["a"]]
题目思考
1. 变位词有什么特点?
解决方案
思路
- 将每个字符串排序后得到的字符串作为 key 存入 unordered_map<string, vector<string>>
- 同组变位词排序后的字符串相同
- 最终返回 map 中所有 value 列表
复杂度
- 时间复杂度 O(NMlogM): N 是字符串数目, M 是字符串长度
- 空间复杂度 O(NM): 额外使用了一个字典包含所有字符串
 */
#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <algorithm>
using namespace std;

class Solution
{
public:
    vector<vector<string>> groupAnagrams(vector<string> &strs)
    {
        unordered_map<string, vector<string>> mp;
        for (auto &s : strs)
        {
            string key = s;
            sort(key.begin(), key.end());
            mp[key].push_back(s);
        }
        vector<vector<string>> res;
        for (auto &[k, v] : mp) res.push_back(v);
        return res;
    }
};

int main()
{
    Solution sol;
    vector<string> s1 = {"eat", "tea", "tan", "ate", "nat", "bat"};
    auto r1 = sol.groupAnagrams(s1);
    for (auto &g : r1)
    {
        for (auto &w : g) cout << w << " ";
        cout << "| ";
    }
    cout << endl; // bat | nat tan | eat tea ate | (顺序不定)
    vector<string> s2 = {""};
    auto r2 = sol.groupAnagrams(s2);
    cout << r2[0][0] << endl; // (空字符串)
    return 0;
}
