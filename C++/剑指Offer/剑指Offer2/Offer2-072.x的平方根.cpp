/* 题目难度: 简单
[原题链接](https://leetcode.cn/problems/jJ0w9p/)
题目描述
给定非负整数 x, 计算并返回 x 的平方根 (只保留整数部分)。
题目样例
示例1
- 输入: x = 4
- 输出: 2
示例2
- 输入: x = 8
- 输出: 2 (8的平方根约为2.828, 取整得2)
题目思考
1. 如何优化时间复杂度?
解决方案
思路
- 二分查找 [0, x], 找平方值 <= x 的最大整数
- 注意使用 long long 防止 m*m 溢出
复杂度
- 时间复杂度 O(logX): 二分查找
- 空间复杂度 O(1): 只使用了几个常数空间的变量
 */
#include <iostream>
using namespace std;

class Solution
{
public:
    int mySqrt(int x)
    {
        long long s = 0, e = x, res = 0;
        while (s <= e)
        {
            long long m = (s + e) / 2;
            if (m * m <= x) { res = m; s = m + 1; }
            else e = m - 1;
        }
        return (int)res;
    }
};

int main()
{
    Solution sol;
    cout << sol.mySqrt(4) << endl;  // 2
    cout << sol.mySqrt(8) << endl;  // 2
    cout << sol.mySqrt(0) << endl;  // 0
    cout << sol.mySqrt(1) << endl;  // 1
    cout << sol.mySqrt(2147483647) << endl; // 46340
    return 0;
}
