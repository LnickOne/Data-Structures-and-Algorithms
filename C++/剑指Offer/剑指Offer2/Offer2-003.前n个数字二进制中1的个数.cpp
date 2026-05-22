/* 题目难度: 简单
[原题链接](https://leetcode.cn/problems/w3tCBm/)
题目描述
给定一个非负整数 n, 请计算 0 到 n 之间每个数字的二进制表示中 1 的个数, 并输出一个数组。
题目样例
示例1
- 输入: n = 2
- 输出: [0,1,1]
示例2
- 输入: n = 5
- 输出: [0,1,1,2,1,2]
题目思考
1. 如何做到线性时间一趟扫描?
2. 前后数字之间是否有关联?
解决方案
思路
- 朴素做法: 对每个数逐位右移统计 1 的数目, 时间复杂度 O(N*sizeof(int)), 较慢
- 利用 n&(n-1) 的性质: 它将 n 最低位的 1 变成 0, 所以 n 的 1 的数目 = n&(n-1) 的 1 的数目 + 1
- 从 1 遍历到 n, 利用 dp[n] = dp[n&(n-1)] + 1 即可在 O(N) 线性时间内一趟扫描求出所有结果
复杂度
- 时间复杂度 O(N): 线性时间, 一趟扫描
- 空间复杂度 O(N): 最终结果数组需要存 N+1 个数字
 */
#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    vector<int> countBits(int n)
    {
        vector<int> res(n + 1, 0);
        for (int i = 1; i <= n; ++i)
            res[i] = res[i & (i - 1)] + 1;
        return res;
    }
};

int main()
{
    Solution s;
    auto print = [](vector<int> &v) {
        cout << "[";
        for (int i = 0; i < (int)v.size(); ++i)
        {
            if (i) cout << ",";
            cout << v[i];
        }
        cout << "]" << endl;
    };
    auto r1 = s.countBits(2);
    print(r1); // [0,1,1]
    auto r2 = s.countBits(5);
    print(r2); // [0,1,1,2,1,2]
    return 0;
}
