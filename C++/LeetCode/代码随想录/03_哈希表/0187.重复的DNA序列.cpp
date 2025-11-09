/*
DNA序列 由一系列核苷酸组成，缩写为 'A', 'C', 'G' 和 'T'.。
例如，"ACGAATTCCG" 是一个 DNA序列 。
在研究 DNA 时，识别 DNA 中的重复序列非常有用。
给定一个表示 DNA序列 的字符串 s ，返回所有在 DNA 分子中出现不止一次的 长度为 10 的序列(子字符串)。
示例 1：
输入：s = "AAAAACCCCCAAAAACCCCCCAAAAAGGGTTT"
输出：["AAAAACCCCC","CCCCCAAAAA"]
示例 2：
输入：s = "AAAAAAAAAAAAA"
输出：["AAAAAAAAAA"]
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
    vector<string> findRepeatedDnaSequences(string s)
    {
        if (s.size() < 10)
            return {};
        vector<string> result;
        unordered_map<string, int> map;
        for (int i = 0; i <= s.size() - 10; i++) // 使用滑动窗口，每次取10个字符
        {
            string substr = s.substr(i, 10);
            map[substr]++;
        }
        for (const auto &iter : map)
            if (iter.second > 1)
                result.push_back(iter.first);
        return result;
    }
};

int main()
{
    Solution s;
    string s1 = "AAAAACCCCCAAAAACCCCCCAAAAAGGGTTT";
    vector<string> res = s.findRepeatedDnaSequences(s1);
    for (const auto &str : res)
    {
        cout << str << endl;
    }
    return 0;
}
