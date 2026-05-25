/* 题目难度: 简单
[原题链接](https://leetcode.cn/problems/da-yin-cong-1dao-zui-da-de-nwei-shu-lcof/)
题目描述
按从小到大返回从 1 到最大的 cnt 位正整数组成的数列。
题目样例
示例1
- 输入: cnt=2
- 输出: [1,2,...,99]
题目思考
1. 最大值为 10^cnt - 1
解决方案
思路
- 从 1 循环到 10^cnt - 1, 依次加入结果
复杂度
- 时间复杂度 O(10^N): 输出所有数
- 空间复杂度 O(1): 不含输出
 */
#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    vector<int> printNumbers(int cnt)
    {
        int mx = 1;
        for (int i = 0; i < cnt; ++i) mx *= 10;
        vector<int> res;
        for (int i = 1; i < mx; ++i) res.push_back(i);
        return res;
    }
};

int main()
{
    Solution sol;
    auto r = sol.printNumbers(1);
    cout << "[";
    for (int i = 0; i < (int)r.size(); ++i) { if (i) cout << ","; cout << r[i]; }
    cout << "]" << endl; // [1,2,...,9]
    return 0;
}
