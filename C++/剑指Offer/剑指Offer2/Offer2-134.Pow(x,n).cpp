/* 题目难度: 中等
[原题链接](https://leetcode.cn/problems/shu-zhi-de-zheng-shu-ci-fang-lcof/)
题目描述
实现 pow(x, n), 计算 x 的 n 次幂。(-2^31 <= n <= 2^31-1)
题目样例
示例1
- 输入: x=2.0, n=10
- 输出: 1024.0
示例2
- 输入: x=2.0, n=-2
- 输出: 0.25
题目思考
1. 如何利用快速幂降低时间复杂度?
解决方案
思路
- 快速幂: n 为奇数时结果乘 x, x*=x, n>>=1; n<0 时取倒数
- 注意 n 可能是 INT_MIN, 需用 long long 存
复杂度
- 时间复杂度 O(logN): n 每次减半
- 空间复杂度 O(1): 常数空间
 */
#include <iostream>
#include <cmath>
using namespace std;

class Solution
{
public:
    double myPow(double x, int n)
    {
        if (x == 0) return 0;
        long long N = n;
        if (N < 0) { x = 1.0 / x; N = -N; }
        double res = 1.0;
        while (N > 0)
        {
            if (N & 1) res *= x;
            x *= x;
            N >>= 1;
        }
        return res;
    }
};

int main()
{
    Solution sol;
    cout << sol.myPow(2.0, 10) << endl;  // 1024
    cout << sol.myPow(2.1, 3)  << endl;  // 9.261
    cout << sol.myPow(2.0, -2) << endl;  // 0.25
    return 0;
}
