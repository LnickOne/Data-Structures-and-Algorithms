/* 题目难度: 中等
[原题链接](https://leetcode.cn/problems/JEj789/)
题目描述
n 个房子可粉刷成红/蓝/绿三色, 相邻房子不能同色, 给定 n×3 的花费矩阵 costs, 求粉刷所有房子的最小花费。
题目样例
示例1
- 输入: costs=[[17,2,17],[16,16,5],[14,3,19]]
- 输出: 10
示例2
- 输入: costs=[[7,6,2]]
- 输出: 2
题目思考
1. 如何优化时间和空间复杂度?
解决方案
思路
- DP 滚动变量: r/b/g 代表当前房子染红/蓝/绿的最小成本
- 转移: nr = min(b,g)+cr; nb = min(r,g)+cb; ng = min(r,b)+cg
- 最终结果是 min(r,b,g)
复杂度
- 时间复杂度 O(N): 遍历一遍
- 空间复杂度 O(1): 常数变量
 */
#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    int minCost(vector<vector<int>> &costs)
    {
        int r = 0, b = 0, g = 0;
        for (auto &c : costs)
        {
            int nr = min(b, g) + c[0];
            int nb = min(r, g) + c[1];
            int ng = min(r, b) + c[2];
            r = nr; b = nb; g = ng;
        }
        return min({r, b, g});
    }
};

int main()
{
    Solution sol;
    vector<vector<int>> c1 = {{17, 2, 17}, {16, 16, 5}, {14, 3, 19}};
    cout << sol.minCost(c1) << endl; // 10
    vector<vector<int>> c2 = {{7, 6, 2}};
    cout << sol.minCost(c2) << endl; // 2
    return 0;
}
