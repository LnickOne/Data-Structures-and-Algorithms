/*
给定两个字符串 s 和 t ，判断它们是否是同构的。
如果 s 中的字符可以按某种映射关系替换得到 t ，那么这两个字符串是同构的。
每个出现的字符都应当映射到另一个字符，同时不改变字符的顺序。不同字符不能映射到同一个字符上，相同字符只能映射到同一个字符上，字符可以映射到自己本身。
示例 1:
输入：s = "egg", t = "add"
输出：true
示例 2：
输入：s = "foo", t = "bar"
输出：false
示例 3：
输入：s = "paper", t = "title"
输出：true
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
    bool isIsomorphic(string s, string t)
    {
        if (s.size() != t.size())
            return false;
        unordered_map<char, char> map_s;
        unordered_map<char, char> map_t;
        for (int i = 0; i < s.size(); i++)
        { // 找不到就映射,找到了就判断是否相等
            if (map_s.find(s[i]) == map_s.end())
                map_s[s[i]] = t[i];
            if (map_t.find(t[i]) == map_t.end())
                map_t[t[i]] = s[i];
            if (map_s[s[i]] != t[i])
                return false;
            if (map_t[t[i]] != s[i])
                return false;
        }
        return true;
    }
};

int main()
{
    string s_1 = "egg";
    string t_1 = "add";
    string s_2 = "foo";
    string t_2 = "bar";
    string s_3 = "paper";
    string t_3 = "title";
    Solution s;
    cout << s.isIsomorphic(s_1, t_1) << endl;
    cout << s.isIsomorphic(s_2, t_2) << endl;
    cout << s.isIsomorphic(s_3, t_3) << endl;
    return 0;
}