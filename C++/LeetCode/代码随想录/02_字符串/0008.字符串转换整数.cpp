/*
实现一个 myAtoi(string s) 函数，使其能将字符串转换成一个 32 位有符号整数。
函数 myAtoi(string s) 的算法如下：
空格：读入字符串并丢弃无用的前导空格（" "）
符号：检查下一个字符（假设还未到字符末尾）为 '-' 还是 '+'。如果两者都不存在，则假定结果为正。
转换：通过跳过前置零来读取该整数，直到遇到非数字字符或到达字符串的结尾。如果没有读取数字，则结果为0。
舍入：如果整数数超过 32 位有符号整数范围 [−231,  231 − 1] ，需要截断这个整数，使其保持在这个范围内。
具体来说，小于 −231 的整数应该被舍入为 −231 ，大于 231 − 1 的整数应该被舍入为 231 − 1 。
返回整数作为最终结果。
示例 1：
输入：s = "42"
输出：42
*/
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <climits>
using namespace std;
class Solution
{
public:
    int myAtoi(string s)
    {
        // 1.去除前面的空格
        int i = 0;
        while (i < s.size() && s[i] == ' ')
            i++;
        s = s.substr(i);
        // 2.去除前面的"+"或"-"号
        i = 0;
        int sign = 1;
        if (s[i] == '+')
        {
            sign = 1;
            i = 1;
        }
        if (s[i] == '-')
        {
            sign = -1;
            i = 1;
        }
        // 3.去除前面的0
        while (s[i] == '0')
            i++;
        s = s.substr(i);
        // 4.开始读取数字
        long num = 0;
        for (const char &ch : s)
        {
            if (isdigit(ch) == false) // 遇到除数字外的字符退出循环
                break;
            num = num * 10 + (ch - '0'); // 得到无符号的新数字
            long value = num * sign;     // 看带符号的新数字是否溢出或者到达最大/最小
            if (value >= INT_MAX)
                return INT_MAX;
            if (value <= INT_MIN)
                return INT_MIN;
        }
        cout << num * sign << endl;
        cout << endl;
        return num * sign;
    }
};

int main()
{
    string s_1 = "142";
    string s_2 = "-042";
    string s_3 = "4193 with words";
    string s_4 = "words and 987";
    string s_5 = "-91283472332";
    string s_6 = "0-1";
    string s_7 = "   +0 123";
    Solution s;
    s.myAtoi(s_1);
    s.myAtoi(s_2);
    s.myAtoi(s_3);
    s.myAtoi(s_4);
    s.myAtoi(s_5);
    s.myAtoi(s_6);
    s.myAtoi(s_7);
    return 0;
}