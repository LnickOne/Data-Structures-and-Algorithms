/* 题目难度: 简单
[原题链接](https://leetcode.cn/problems/JFETK5/)
题目描述
给定两个 01 字符串 a 和 b, 请计算它们的和, 并以二进制字符串的形式输出。
输入为非空字符串且只包含数字 1 和 0。
题目样例
示例 1
- 输入: a = "11", b = "10"
- 输出: "101"
示例 2
- 输入: a = "1010", b = "1011"
- 输出: "10101"
题目思考
1. 字符串长度可能很长, 如何处理?
2. 两个字符串长度可能不同, 如何处理?
解决方案
思路
- 字符串最大长度 10^4, 不能转成整数直接相加, 需模拟小学加法逐位计算
- 从个位 (字符串末尾) 开始逆序遍历两个字符串, 逐位相加并维护进位
- 若某个字符串已遍历完则用 0 代替该位
- 注意: 两个字符串都遍历完后若仍有进位, 需将进位追加到结果
复杂度
- 时间复杂度 O(A+B): A 和 B 分别是字符串 a 和 b 的长度
- 空间复杂度 O(1): 不计结果字符串, 只使用了几个常数空间的变量
 */
#include <iostream>
#include <string>
using namespace std;

class Solution
{
public:
    string addBinary(string a, string b)
    {
        int i = a.size() - 1, j = b.size() - 1;
        int carry = 0;
        string res = "";
        while (i >= 0 || j >= 0 || carry > 0)
        {
            int x = (i >= 0) ? (a[i--] - '0') : 0;
            int y = (j >= 0) ? (b[j--] - '0') : 0;
            int sm = x + y + carry;
            carry = sm / 2;
            res = char('0' + sm % 2) + res;
        }
        return res;
    }
};

int main()
{
    Solution s;
    cout << s.addBinary("11", "10") << endl;     // 101
    cout << s.addBinary("1010", "1011") << endl; // 10101
    cout << s.addBinary("0", "0") << endl;       // 0
    cout << s.addBinary("1111", "1111") << endl; // 11110
    return 0;
}
