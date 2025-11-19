/*
给你一个字符串 s ，请你去除字符串中重复的字母，使得每个字母只出现一次。
需保证 返回结果的字典序最小（要求不能打乱其他字符的相对位置）。
示例 1：
输入：s = "bcabc"
输出："abc"
示例 2：
输入：s = "cbacdcbc"
输出："acdb"
*/
#include <iostream>
#include <vector>
#include <string>
#include <stack>
#include <unordered_map>
using namespace std;

class Solution
{
public:
    string removeDuplicateLetters(string s)
    {
        if (s.empty())
            return "";
        string result;
        unordered_map<char, int> map;
        for (char ch : s)
            map[ch]++;
        int index = 0;
        for (int i = 0; i < s.size(); i++)
        {
            if (s[i] < s[index])
                index = i;
            map[s[i]]--;
            if (map[s[i]] == 0)
                break;
        }
        for (int i = index + 1; i < s.size(); i++)
        {
            if (s[i] != s[index])
                result += s[i];
        }
        return s[index] + removeDuplicateLetters(result);
    }
};
int main()
{
    Solution s;
    string str = "cbacdcbc";
    string result = s.removeDuplicateLetters(str);
    cout << result << endl;
    return 0;
}