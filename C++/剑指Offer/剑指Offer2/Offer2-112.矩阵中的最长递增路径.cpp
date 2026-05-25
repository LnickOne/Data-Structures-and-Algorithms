/* 题目难度: 困难
[原题链接](https://leetcode.cn/problems/fpTFWP/)
题目描述
给定 m×n 整数矩阵 matrix, 找出最长递增路径的长度 (可上下左右移动, 不能对角线)。
题目样例
示例1
- 输入: matrix=[[9,9,4],[6,6,8],[2,1,1]]
- 输出: 4 (路径 [1,2,6,9])
示例2
- 输入: matrix=[[3,4,5],[3,2,6],[2,2,1]]
- 输出: 4 (路径 [3,4,5,6])
示例3
- 输入: matrix=[[1]]
- 输出: 1
题目思考
1. 如何优化时间复杂度?
解决方案
思路
- 记忆化 DFS: memo[r][c] = 以 (r,c) 为起点的最长递增路径长度
- 从每个格子出发, 四方向递推更大的邻居, 用 memo 避免重复计算
复杂度
- 时间复杂度 O(MN): 每个格子只计算一次
- 空间复杂度 O(MN): memo 数组
 */
#include <iostream>
#include <vector>
using namespace std;

class Solution
{
    vector<vector<int>> memo;
    int dx[4] = {1,-1,0,0}, dy[4] = {0,0,1,-1};
    int dfs(vector<vector<int>> &mat, int r, int c)
    {
        if (memo[r][c]) return memo[r][c];
        memo[r][c] = 1;
        int rows = mat.size(), cols = mat[0].size();
        for (int d = 0; d < 4; ++d)
        {
            int rr = r + dx[d], cc = c + dy[d];
            if (rr >= 0 && rr < rows && cc >= 0 && cc < cols && mat[rr][cc] > mat[r][c])
                memo[r][c] = max(memo[r][c], dfs(mat, rr, cc) + 1);
        }
        return memo[r][c];
    }
public:
    int longestIncreasingPath(vector<vector<int>> &matrix)
    {
        int rows = matrix.size(), cols = matrix[0].size(), res = 0;
        memo.assign(rows, vector<int>(cols, 0));
        for (int r = 0; r < rows; ++r)
            for (int c = 0; c < cols; ++c)
                res = max(res, dfs(matrix, r, c));
        return res;
    }
};

int main()
{
    Solution sol;
    vector<vector<int>> m1 = {{9,9,4},{6,6,8},{2,1,1}};
    cout << sol.longestIncreasingPath(m1) << endl; // 4
    vector<vector<int>> m2 = {{3,4,5},{3,2,6},{2,2,1}};
    cout << sol.longestIncreasingPath(m2) << endl; // 4
    vector<vector<int>> m3 = {{1}};
    cout << sol.longestIncreasingPath(m3) << endl; // 1
    return 0;
}
