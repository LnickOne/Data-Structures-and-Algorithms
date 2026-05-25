/* 题目难度: 中等
[原题链接](https://leetcode.cn/problems/0i0mDW/)
题目描述
给定包含非负整数的 m×n 网格 grid, 找出从左上角到右下角的路径使路径上数字总和最小 (每次只能向下或向右)。
题目样例
示例1
- 输入: grid=[[1,3,1],[1,5,1],[4,2,1]]
- 输出: 7 (路径 1→3→1→1→1)
示例2
- 输入: grid=[[1,2,3],[4,5,6]]
- 输出: 12
题目思考
1. 如何优化算法复杂度?
解决方案
思路
- 原地 DP: grid[r][c] += min(grid[r-1][c], grid[r][c-1])
- 边界行/列只能从一个方向转移
复杂度
- 时间复杂度 O(MN): 两重循环
- 空间复杂度 O(1): 原地修改
 */
#include <iostream>
#include <vector>
#include <climits>
using namespace std;

class Solution
{
public:
    int minPathSum(vector<vector<int>> &grid)
    {
        int m = grid.size(), n = grid[0].size();
        for (int r = 0; r < m; r++)
            for (int c = 0; c < n; c++)
            {
                if (r == 0 && c == 0) continue;
                int l = c > 0 ? grid[r][c-1] : INT_MAX;
                int u = r > 0 ? grid[r-1][c] : INT_MAX;
                grid[r][c] += min(l, u);
            }
        return grid[m-1][n-1];
    }
};

int main()
{
    Solution sol;
    vector<vector<int>> g1 = {{1,3,1},{1,5,1},{4,2,1}};
    cout << sol.minPathSum(g1) << endl; // 7
    vector<vector<int>> g2 = {{1,2,3},{4,5,6}};
    cout << sol.minPathSum(g2) << endl; // 12
    return 0;
}
