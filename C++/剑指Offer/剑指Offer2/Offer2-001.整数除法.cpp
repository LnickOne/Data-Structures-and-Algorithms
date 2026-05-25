/* 题目难度: 简单
[原题链接](https://leetcode.cn/problems/xoh6Oh/)
题目描述
给定两个整数 a 和 b, 求它们的除法的商 a/b, 要求不得使用乘号 '*'、除号 '/' 以及求余符号 '%'。
注意:
- 整数除法的结果应当截去 (truncate) 其小数部分
- 假设环境只能存储 32 位有符号整数, 若除法结果溢出则返回 2^31-1
题目样例
示例1
- 输入: a = 15, b = 2
- 输出: 7
示例2
- 输入: a = 7, b = -3
- 输出: -2
示例3
- 输入: a = 0, b = 1
- 输出: 0
题目思考
1. 除法的本质是什么?
2. 可以利用哪些其他操作符?
解决方案
思路
- 最直接的思路是用减法代替除法: 循环减去除数并计数, 但复杂度与商成正比, 若被除数是 2^31、除数是 2 则需循环 2^30 次, 效率过低
- 利用位运算: 商转成二进制后可表示为多个 2 的幂之和, 例如 128/3 可分解为 3*(32+8+2)
- 具体做法: 初始化 2 的幂为 1、除数乘积为除数, 不断左移直到除数乘积最接近且不超过被除数, 将 2 的幂累加到商, 被除数减去对应乘积, 继续下一轮
- 额外处理正负号及 INT_MIN/-1 溢出边界
复杂度
- 时间复杂度 O(logA): 每次内层循环将除数翻倍逼近被除数, 最多 logA 次
- 空间复杂度 O(1): 只使用了几个常数空间的变量
 */
#include <iostream>
#include <climits>
using namespace std;

class Solution
{
public:
    int divide(int dividend, int divisor)
    {
        if (dividend == INT_MIN && divisor == -1)
            return INT_MAX;
        bool neg = (dividend < 0) ^ (divisor < 0);
        long long dvd = llabs((long long)dividend);
        long long dvs = llabs((long long)divisor);
        int res = 0;
        while (dvd >= dvs)
        {
            long long mi = 1, cur = dvs;
            while (dvd >= (cur << 1))
            {
                cur <<= 1;
                mi <<= 1;
            }
            res += mi;
            dvd -= cur;
        }
        return neg ? -res : res;
    }
};

int main()
{
    Solution s;
    cout << s.divide(15, 2) << endl;       // 7
    cout << s.divide(7, -3) << endl;       // -2
    cout << s.divide(0, 1) << endl;        // 0
    cout << s.divide(1, 1) << endl;        // 1
    cout << s.divide(INT_MIN, -1) << endl; // 2147483647
    return 0;
}
