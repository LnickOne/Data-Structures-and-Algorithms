/* 题目难度: 简单
[原题链接](https://leetcode.cn/problems/er-jin-zhi-zhong-1de-ge-shu-lcof/)
题目描述
输入无符号整数 n, 返回其二进制表示中 '1' 的位数 (汉明重量)。
题目样例
示例1
- 输入: n=11 (二进制 1011)
- 输出: 3
示例2
- 输入: n=128 (二进制 10000000)
- 输出: 1
题目思考
1. 如何利用位运算直接定位并清除最低位的 1?
解决方案
思路
- n &= n-1 每次消去最低位的 1, 循环次数即为 1 的个数
复杂度
- 时间复杂度 O(M): M 为 1 的个数
- 空间复杂度 O(1): 常数空间
 */
#include <iostream>
using namespace std;

class Solution
{
public:
    int hammingWeight(uint32_t n)
    {
        int res = 0;
        while (n) { n &= n - 1; ++res; }
        return res;
    }
};

int main()
{
    Solution sol;
    cout << sol.hammingWeight(11) << endl;          // 3
    cout << sol.hammingWeight(128) << endl;         // 1
    cout << sol.hammingWeight(4294967293U) << endl; // 31
    return 0;
}
