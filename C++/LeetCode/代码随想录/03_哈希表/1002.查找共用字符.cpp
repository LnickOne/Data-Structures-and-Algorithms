/*
给你一个字符串数组 words，请你找出所有在 words 的每个字符串中都出现的共用字符（包括重复字符），并以数组形式返回。
你可以按 任意顺序 返回答案。
示例 1：
输入：words = ["bella","label","roller"]
输出：["e","l","l"]
示例 2：
输入：words = ["cool","lock","cook"]
输出：["c","o"]
*/
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <unordered_map>
using namespace std;
class Solution
{
public:
    vector<string> commonChars(const vector<string> &words)
    {
        if (words.empty())
            return {};
        vector<string> result;
        result.push_back(words[0]);
        for (const string &word : words)
            result = common_element(result, word);
        return result;
    }
    vector<string> common_element(vector<string> result, string str2)
    {
        string str1;
        for (string str : result)
        {
            str1 += str;
        }
        unordered_map<char, int> map;
        for (char &ch : str1)
        {
            map[ch]++;
        }
        result.clear();
        for (char &ch : str2)
        {
            if (map[ch] > 0)
            {
                result.push_back(string(1, ch));
                map[ch]--;
            }
        }
        return result;
    }
};

int main()
{
    Solution s;
    vector<string> words = {"bella", "label", "roller"};
    vector<string> words1 = {"acabcddd", "bcbdbcbd", "baddbadb", "cbdddcac", "aacbcccd", "ccccddda", "cababaab", "addcaccd"};
    vector<string> words2 = {"abc", "bca", "cab"};
    vector<string> words3 = {"aaa", "aaa", "aa"};
    s.commonChars(words);
    s.commonChars(words1);
    s.commonChars(words2);
    s.commonChars(words3);
    vector<string> res = s.commonChars(words);
    for (string str : res)
        cout << str;
    cout << endl;
    return 0;
}