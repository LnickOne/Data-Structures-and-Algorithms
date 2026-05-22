/* 题目难度: 中等
[原题链接](https://leetcode.cn/problems/a7VOhD)
题目描述
给定一个字符串 s, 请计算这个字符串中有多少个回文子字符串。
具有不同开始或结束位置的子串即使由相同字符组成也视作不同的子串。
题目样例
示例1
- 输入: s = "abc"
- 输出: 3
- 解释: 三个回文子串: "a","b","c"
示例2
- 输入: s = "aaa"
- 输出: 6
- 解释: 六个回文子串: "a","a","a","aa","aa","aaa"
题目思考
1. 如何尽可能优化时间复杂度?
解决方案
思路
- 枚举起终点再判断回文, 时间 O(N^3), 效率太低
- 中心扩散: 每个回文子串有唯一中心, 奇数长度中心是单个字符 [i,i], 偶数长度中心是相邻两字符 [i,i+1]
- 枚举每个中心向两边扩散, 当前两端字符相等则找到一个新回文子串并继续扩散, 否则停止
- 外层 O(N) 枚举中心, 内层 O(N) 扩散, 总时间 O(N^2)
复杂度
- 时间复杂度 O(N^2): 外层枚举中心 O(N), 内层中心扩散 O(N)
- 空间复杂度 O(1): 只使用了几个常数空间的变量
 */
#include <iostream>
#include <string>
using namespace std;

class Solution
{
public:
    int countSubstrings(string s)
    {
        int n = s.size(), res = 0;
        auto getCount = [&](int l, int r) {
            int cnt = 0;
            while (l >= 0 && r < n && s[l] == s[r]) { cnt++; l--; r++; }
            return cnt;
        };
        for (int i = 0; i < n; i++)
            res += getCount(i, i) + getCount(i, i + 1);
        return res;
    }
};

int main()
{
    Solution s;
    cout << s.countSubstrings("abc") << endl; // 3
    cout << s.countSubstrings("aaa") << endl; // 6
    cout << s.countSubstrings("abba") << endl; // 6
    return 0;
}
