/* > 题目难度: 简单

> [原题链接](https://leetcode-cn.com/problems/di-yi-ge-zhi-chu-xian-yi-ci-de-zi-fu-lcof/)

题目描述

在字符串 s 中找出第一个只出现一次的字符。如果没有，返回一个单空格。 s 只包含小写字母。

0 <= s 的长度 <= 50000

题目样例

示例

- s = "abaccdeff"
- 返回 "b"

- s = ""
- 返回 " "

题目思考

1. 如何遍历一遍字符串就得到结果?

解决方案

思路

- 一个比较容易想到的思路是使用一个计数字典, 遍历一遍字符串存每个字符的数目, 然后把数目为 1 的字符单独放在集合中, 再从头遍历一遍字符串, 找第一个在集合中的字符, 没有的话就返回' '
- 但这种做法需要遍历两遍字符串, 效率不高, 如何做到只遍历一遍字符串就得到结果呢?
- 重新思考, 如果我们遍历的过程中额外存第一个下标, 然后后续遇到该字符时只更新计数, 这样是不是就无需再次遍历了呢?
- 也就是说, 将计数字典改造为 `c => [firstIndex, cnt]` 这样的 kv 组合, 最后只需要找`cnt==1` 且 firstIndex 最小的 c 即可

复杂度

- 时间复杂度 O(N+C): 只需要遍历一遍字符串, 之后遍历字典的复杂度为 O(C) (C 是字符种类数, 常数 26)
- 空间复杂度 O(C): 使用了一个字典, 存 C 个 kv
*/
#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;

class Solution
{
public:
    char firstUniqChar(string s)
    {
        // 记录每个字符的首次出现下标和出现次数
        unordered_map<char, pair<int, int>> d; // char -> {firstIndex, cnt}
        for (int i = 0; i < (int)s.size(); i++)
        {
            char c = s[i];
            if (d.count(c))
            {
                // 只更新次数
                d[c].second++;
            }
            else
            {
                d[c] = {i, 1};
            }
        }
        char res = ' ';
        int mnIndex = (int)s.size();
        for (auto &kv : d)
        {
            int firstIndex = kv.second.first;
            int cnt = kv.second.second;
            if (cnt == 1 && firstIndex < mnIndex)
            {
                mnIndex = firstIndex;
                res = kv.first;
            }
        }
        return res;
    }
};

int main()
{
    Solution sol;
    cout << sol.firstUniqChar("abaccdeff") << endl; // b
    cout << sol.firstUniqChar("") << endl;          // (space)
    cout << sol.firstUniqChar("aabb") << endl;      // (space)
    cout << sol.firstUniqChar("leetcode") << endl;  // l
    return 0;
}
