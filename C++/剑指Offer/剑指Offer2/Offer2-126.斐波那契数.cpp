/* 题目难度: 简单
[原题链接](https://leetcode.cn/problems/fei-bo-na-qi-shu-lie-lcof/)
题目描述
F(0)=0, F(1)=1, F(n)=F(n-1)+F(n-2)。给定 n, 计算 F(n) 对 1e9+7 取模的结果。
题目样例
示例1
- 输入: n=2
- 输出: 1
示例2
- 输入: n=4
- 输出: 3
题目思考
1. 如何利用递推条件优化空间?
解决方案
思路
- 滚动变量 prepre/pre 存 F(n-2)/F(n-1), 每步更新: cur=(prepre+pre)%MOD
复杂度
- 时间复杂度 O(N): 遍历一次
- 空间复杂度 O(1): 仅两个变量
 */
#include <iostream>
using namespace std;

class Solution
{
public:
    int fib(int n)
    {
        if (n < 2) return n;
        const int MOD = 1000000007;
        int ppre = 0, pre = 1;
        for (int i = 2; i <= n; ++i)
        {
            int cur = ((long long)ppre + pre) % MOD;
            ppre = pre; pre = cur;
        }
        return pre;
    }
};

int main()
{
    Solution sol;
    cout << sol.fib(2) << endl; // 1
    cout << sol.fib(3) << endl; // 2
    cout << sol.fib(4) << endl; // 3
    return 0;
}
