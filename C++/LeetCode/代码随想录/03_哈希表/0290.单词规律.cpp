/*
给定一种规律 pattern 和一个字符串 s ，判断 s 是否遵循相同的规律。
这里的 遵循 指完全匹配，例如， pattern 里的每个字母和字符串 s 中的每个非空单词之间存在着双向连接的对应规律。
示例1:
输入: pattern = "abba", s = "dog cat cat dog"
输出: true
示例 2:
输入:pattern = "abba", s = "dog cat cat fish"
输出: false
示例 3:
输入: pattern = "aaaa", s = "dog cat cat dog"
输出: false
*/
#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
using namespace std;
class Solution
{
public:
    bool wordPattern(string pattern, string s)
    {
        char space = ' ';
        vector<string> s_vec;
        string path;
        for (int i = 0; i < s.size(); i++)
        {
            if (s[i] != space)
                path += s[i];
            if (s[i] == space || i == s.size() - 1)
            {
                s_vec.push_back(path);
                path.clear();
            }
        }
        if (pattern.size() != s_vec.size())
            return false;
        unordered_map<char, string> map_p;
        unordered_map<string, char> map_s;
        for (int i = 0; i < pattern.size(); i++)
        {
            if (map_p.find(pattern[i]) == map_p.end())
                map_p[pattern[i]] = s_vec[i];
            if (map_s.find(s_vec[i]) == map_s.end())
                map_s[s_vec[i]] = pattern[i];
            if (map_s[s_vec[i]] != pattern[i])
                return false;
            if (map_p[pattern[i]] != s_vec[i])
                return false;
        }
        return true;
    }
};

int main()
{
    string pattern = "abba";
    string s = "dog cat cat dog";
    Solution sol;
    cout << sol.wordPattern(pattern, s) << endl;
    return 0;
}