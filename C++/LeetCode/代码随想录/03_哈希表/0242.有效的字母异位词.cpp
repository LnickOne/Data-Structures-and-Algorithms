/*
给定两个字符串 s 和 t ，编写一个函数来判断 t 是否是 s 的字母异位词。
示例 1:
输入: s = "anagram", t = "nagaram"
输出: true
示例 2:
输入: s = "rat", t = "car"
输出: false
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
    bool isAnagram(string s, string t)
    {
        // 方法一
        if (s.length() != t.length())
            return false;
        unordered_map<char, int> map;
        for (char ch : s)
            map[ch]++;
        for (char ch : t)
            map[ch]--;
        for (const auto &iter : map)
            if (iter.second != 0)
                return false;
        return true;

        // 方法二
        int map[26];
        for (int i = 0; i < s.length(); i++)
            map[s[i] - 'a']++;
        for (int i = 0; i < t.length(); i++)
            map[t[i] - 'a']--;
        for (int i = 0; i < sizeof(map) / sizeof(map[0]); i++)
            if (map[i] != 0)
                return false;
        return true;
    }
};

int main()
{
    string s_1 = "anagram", t_1 = "nagaram";
    string s_2 = "rat", t_2 = "car";
    bool result = Solution().isAnagram(s_2, t_2);
    cout << result << endl;
    return 0;
}