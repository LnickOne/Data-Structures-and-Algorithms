/* 题目难度: 中等
[原题链接](https://leetcode.cn/problems/jian-sheng-zi-ii-lcof/)
题目描述
将正整数 bamboo_len 的竹子砍为至少两段正整数, 返回各段长度的最大乘积对 1e9+7 取模。(2 <= bamboo_len <= 1000)
题目样例
示例1
- 输入: bamboo_len=12
- 输出: 81
题目思考
1. 数据规模变大, 找数学规律?
解决方案
思路
- 尽量多切 3: n%3==0 -> 全是3; n%3==1 -> 最后用2*2替换一个3+1; n%3==2 -> 末尾留一个2
- 快速幂 + 取模计算 3^k % MOD
复杂度
- 时间复杂度 O(logN): 快速幂
- 空间复杂度 O(1): 常数空间
 */
#include <iostream>
using namespace std;

class Solution
{
    const long long MOD = 1000000007;
    long long power(long long base, long long exp, long long mod)
    {
        long long res = 1;
        base %= mod;
        while (exp > 0)
        {
            if (exp & 1)
                res = res * base % mod;
            base = base * base % mod;
            exp >>= 1;
        }
        return res;
    }

public:
    int cuttingBamboo(int bamboo_len)
    {
        if (bamboo_len <= 3)
            return bamboo_len - 1;
        int n = bamboo_len;
        if (n % 3 == 0)
            return (int)power(3, n / 3, MOD);
        else if (n % 3 == 1)
            return (int)(power(3, n / 3 - 1, MOD) * 4 % MOD);
        else
            return (int)(power(3, n / 3, MOD) * 2 % MOD);
    }
};

int main()
{
    Solution sol;
    cout << sol.cuttingBamboo(12) << endl; // 81
    cout << sol.cuttingBamboo(2) << endl;  // 1
    cout << sol.cuttingBamboo(10) << endl; // 36
    return 0;
}
