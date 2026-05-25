/* 题目难度: 中等
[原题链接](https://leetcode.cn/problems/biao-shi-shu-zhi-de-zi-fu-chuan-lcof/)
题目描述
判断字符串 s 是否为有效数字。格式: [空格] (小数|整数) [e/E 整数] [空格]。
小数: [+/-] (数字. | 数字.数字 | .数字); 整数: [+/-] 数字。
题目样例
示例1
- 输入: s="0"
- 输出: true
示例2
- 输入: s="e"
- 输出: false
示例3
- 输入: s="."
- 输出: false
题目思考
1. 按 e/E 拆分左右, 分别验证?
解决方案
思路
- 去首尾空格后找 e/E 位置
- isValid(s, allowDot): 检查 +/- 只在开头, '.' 最多一个且在 e 前, 至少有一个数字
复杂度
- 时间复杂度 O(N): 遍历一次
- 空间复杂度 O(1): 常数空间
 */
#include <iostream>
#include <string>
using namespace std;

class Solution
{
    bool isValid(const string &s, bool allowDot)
    {
        bool hasNum = false, hasDot = false;
        for (int i = 0; i < (int)s.size(); ++i)
        {
            char c = s[i];
            if (c == '+' || c == '-')
            {
                if (i != 0)
                    return false;
            }
            else if (c == '.')
            {
                if (!allowDot || hasDot)
                    return false;
                hasDot = true;
            }
            else if (c >= '0' && c <= '9')
            {
                hasNum = true;
            }
            else
                return false;
        }
        return hasNum;
    }

public:
    bool validNumber(string s)
    {
        int l = 0, r = (int)s.size() - 1;
        while (l <= r && s[l] == ' ')
            ++l;
        while (r >= l && s[r] == ' ')
            --r;
        s = s.substr(l, r - l + 1);
        int e = -1;
        for (int i = 0; i < (int)s.size(); ++i)
            if (s[i] == 'e' || s[i] == 'E')
            {
                e = i;
                break;
            }
        if (e == -1)
            return isValid(s, true);
        return isValid(s.substr(0, e), true) && isValid(s.substr(e + 1), false);
    }
};

int main()
{
    Solution sol;
    cout << boolalpha;
    cout << sol.validNumber("0") << endl;      // true
    cout << sol.validNumber("e") << endl;      // false
    cout << sol.validNumber(".") << endl;      // false
    cout << sol.validNumber("2e10") << endl;   // true
    cout << sol.validNumber("99e2.5") << endl; // false
    cout << sol.validNumber("+3.14") << endl;  // true
    return 0;
}
