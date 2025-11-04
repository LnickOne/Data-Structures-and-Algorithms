/*
有效 IP 地址 正好由四个整数（每个整数位于 0 到 255 之间组成，且不能含有前导 0），整数之间用 '.' 分隔。
例如："0.1.2.201" 和 "192.168.1.1" 是 有效 IP 地址，但是 "0.011.255.245"、"192.168.1.312" 和 "192.168@1.1" 是 无效 IP 地址。
给定一个只包含数字的字符串 s ，用以表示一个 IP 地址，返回所有可能的有效 IP 地址，这些地址可以通过在 s 中插入 '.' 来形成。
你 不能 重新排序或删除 s 中的任何数字。你可以按 任何 顺序返回答案。
示例 1：
输入：s = "25525511135"
输出：["255.255.11.135","255.255.111.35"]
示例 2：
输入：s = "0000"
输出：["0.0.0.0"]
示例 3：
输入：s = "101023"
输出：["1.0.10.23","1.0.102.3","10.1.0.23","10.10.2.3","101.0.2.3"]
*/
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
class Solution
{
public:
    vector<string> restoreIpAddresses(string s)
    {
        vector<string> result;
        string path;
        backtracking(0, 0, s, path, result);
        for (auto &i : result)
            cout << i << endl;
        return result;
    }
    void backtracking(int start, int point, string s, string &path, vector<string> &result)
    {
        if (point == 3) // 逗点数量为3时，分隔结束
        {
            // 判断第四段子字符串是否合法，如果合法就放进result中
            if (isValid(s.substr(start, s.size())) && s[s.size() - 1] != '.')
            {
                result.push_back(s);
            }
            return;
        }
        for (int i = start; i < s.size(); i++)
        {
            if (isValid(s.substr(start, i - start + 1)))
            {
                s.insert(s.begin() + i + 1, '.'); // 在i的后面插入一个逗点
                point++;
                backtracking(i + 2, point, s, path, result);
                point--;
                s.erase(s.begin() + i + 1); // 回溯删掉逗点
            }
        }
    }
    bool isValid(string s)
    {
        int num = 0;
        for (int i = 0; i < s.size(); ++i)
        {
            if (s[i] > '9' || s[i] < '0') // 遇到非数字字符不合法
            {
                return false;
            }
            num = num * 10 + (s[i] - '0');
            if (num > 255) // 如果数字大于255了不合法
            {
                return false;
            }
        }
        if (s.size() > 3 || (s.size() > 1 && s[0] == '0')) // 0开头的数字不合法 && 大于三位数不合法    注意：这里是s.size() > 1 && s[0] == '0' 而不是s.size() > 1 && s[0] == 0
            return false;
        return true;
    }
};
int main()
{
    string s = "101023";
    Solution s1;
    vector<string> result = s1.restoreIpAddresses(s);
    return 0;
}