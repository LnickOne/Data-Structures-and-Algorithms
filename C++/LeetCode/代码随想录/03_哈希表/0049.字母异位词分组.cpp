/*
给你一个字符串数组，请你将 字母异位词 组合在一起。可以按任意顺序返回结果列表。
字母异位词 是由重新排列源单词的所有字母得到的一个新单词。
示例 1:
输入: strs = ["eat", "tea", "tan", "ate", "nat", "bat"]
输出: [["bat"],["nat","tan"],["ate","eat","tea"]]
示例 2:
输入: strs = [""]
输出: [[""]]
示例 3:
输入: strs = ["a"]
输出: [["a"]]
*/
#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
using namespace std;
class Solution
{
public:
    vector<vector<string>> groupAnagrams(vector<string> &strs)
    {
        vector<vector<string>> result;
        unordered_map<string, vector<string>> map;
        string key;
        string value;
        for (const string &str : strs)
        {
            key = str;
            value = str;
            sort(key.begin(), key.end());
            map[key].push_back(value);
        }
        for (const auto &iter : map)
            result.push_back(iter.second);
        // for (auto iter = map.begin(); iter != map.end(); iter++)
        //     result.push_back(iter->second);
        return result;
    }
};
int main()
{
    vector<string> strs = {"eat", "tea", "tan", "ate", "nat", "bat"};
    vector<string> strs1 = {""};
    vector<string> strs2 = {"a"};
    vector<vector<string>> result;
    Solution s;
    result = s.groupAnagrams(strs);
    result = s.groupAnagrams(strs1);
    result = s.groupAnagrams(strs2);
    for (const vector<string> &vec : result)
    {
        for (const string &str : vec)
            cout << str << " ";
        cout << endl;
    }
    return 0;
}