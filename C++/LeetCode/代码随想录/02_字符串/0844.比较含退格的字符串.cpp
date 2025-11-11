/*
给定 s 和 t 两个字符串，当它们分别被输入到空白的文本编辑器后，如果两者相等，返回 true 。# 代表退格字符。
注意：如果对空文本输入退格字符，文本继续为空。
示例 1：
输入：s = "ab#c", t = "ad#c"
输出：true
解释：s 和 t 都会变成 "ac"。
示例 2：
输入：s = "ab##", t = "c#d#"
输出：true
解释：s 和 t 都会变成 ""。
示例 3：
输入：s = "a#c", t = "b"
输出：false
解释：s 会变成 "c"，但 t 仍然是 "b"。
*/
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;
class Solution
{
public:
    bool backspaceCompare(string s, string t)
    {
        vector<char> s_vec;
        vector<char> t_vec;
        for (int i = 0; i < s.size(); ++i)
        {
            if (s[i] == '#')
            {
                if (!s_vec.empty())
                    s_vec.pop_back();
            }
            if (s[i] != '#')
                s_vec.push_back(s[i]);
        }
        for (int i = 0; i < t.size(); ++i)
        {
            if (t[i] == '#')
            {
                if (!t_vec.empty())
                    t_vec.pop_back();
            }
            if (t[i] != '#')
                t_vec.push_back(t[i]);
        }
        // for (int i = 0; i < s_vec.size(); ++i)
        // {
        //     cout << s_vec[i] << " ";
        // }
        // cout << endl;
        // for (int i = 0; i < t_vec.size(); ++i)
        // {
        //     cout << t_vec[i] << " ";
        // }
        // cout << endl;
        return s_vec == t_vec;
    }
};

int main()
{
    string s_1 = "ab#c", t_1 = "ad#c";
    string s_2 = "ab##", t_2 = "c#d#";
    string s_3 = "a#c", t_3 = "b";
    Solution sol;
    sol.backspaceCompare(s_1, t_1);
    return 0;
}