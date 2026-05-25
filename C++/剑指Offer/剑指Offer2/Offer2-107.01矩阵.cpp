/* 题目难度: 中等
[原题链接](https://leetcode.cn/problems/2bCMpM/)
题目描述
给定 0/1 矩阵 mat, 输出每个格子到最近 0 的距离。
题目样例
示例1
- 输入: mat=[[0,0,0],[0,1,0],[0,0,0]]
- 输出: [[0,0,0],[0,1,0],[0,0,0]]
示例2
- 输入: mat=[[0,0,0],[0,1,0],[1,1,1]]
- 输出: [[0,0,0],[0,1,0],[1,2,1]]
题目思考
1. 如何优化时间空间复杂度?
解决方案
思路
- 多源 BFS: 将所有 0 的格子加入队列, dist 初始化为 -1
- BFS 逐层扩展, 每个格子的 dist = 相邻格子 dist + 1
复杂度
- 时间复杂度 O(RC): 每个格子遍历两次
- 空间复杂度 O(RC): dist 矩阵和队列
 */
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Solution
{
public:
    vector<vector<int>> updateMatrix(vector<vector<int>> &mat)
    {
        int rows = mat.size(), cols = mat[0].size();
        vector<vector<int>> dist(rows, vector<int>(cols, -1));
        queue<pair<int,int>> q;
        for (int r = 0; r < rows; ++r)
            for (int c = 0; c < cols; ++c)
                if (mat[r][c] == 0) { dist[r][c] = 0; q.push({r, c}); }
        int dx[] = {1,-1,0,0}, dy[] = {0,0,1,-1};
        while (!q.empty())
        {
            auto [r, c] = q.front(); q.pop();
            for (int d = 0; d < 4; ++d)
            {
                int rr = r + dx[d], cc = c + dy[d];
                if (rr >= 0 && rr < rows && cc >= 0 && cc < cols && dist[rr][cc] == -1)
                {
                    dist[rr][cc] = dist[r][c] + 1;
                    q.push({rr, cc});
                }
            }
        }
        return dist;
    }
};

int main()
{
    Solution sol;
    vector<vector<int>> m1 = {{0,0,0},{0,1,0},{0,0,0}};
    auto r1 = sol.updateMatrix(m1);
    for (auto &row : r1) { for (int i = 0; i < (int)row.size(); ++i) { if (i) cout << ","; cout << row[i]; } cout << endl; }
    // 0,0,0 / 0,1,0 / 0,0,0
    vector<vector<int>> m2 = {{0,0,0},{0,1,0},{1,1,1}};
    auto r2 = sol.updateMatrix(m2);
    for (auto &row : r2) { for (int i = 0; i < (int)row.size(); ++i) { if (i) cout << ","; cout << row[i]; } cout << endl; }
    // 0,0,0 / 0,1,0 / 1,2,1
    return 0;
}
