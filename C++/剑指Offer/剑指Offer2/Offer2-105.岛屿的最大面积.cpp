/* 题目难度: 中等
[原题链接](https://leetcode.cn/problems/ZL6zAn/)
题目描述
给定 0/1 二维数组 grid, 求最大岛屿面积 (1 表示土地, 0 表示水, 相邻土地连通形成岛屿)。
题目样例
示例1
- 输入: grid=[[0,0,1,...],[0,1,1,0,...],...]
- 输出: 6
示例2
- 输入: grid=[[0,0,0,0,0,0,0,0]]
- 输出: 0
题目思考
1. 如何得到哪些土地相互连通?
解决方案
思路
- BFS + 原地标记: 从每个未访问的 1 开始 BFS, 访问后将其置为 0 避免重复
- 每次 BFS 的队列长度即为当前岛屿面积, 取最大值
复杂度
- 时间复杂度 O(RC): 每个格子访问常数次
- 空间复杂度 O(RC): BFS 队列
 */
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Solution
{
public:
    int maxAreaOfIsland(vector<vector<int>> &grid)
    {
        int rows = grid.size(), cols = grid[0].size(), res = 0;
        int dx[] = {1, -1, 0, 0}, dy[] = {0, 0, 1, -1};
        for (int sr = 0; sr < rows; ++sr)
        {
            for (int sc = 0; sc < cols; ++sc)
            {
                if (grid[sr][sc] == 1)
                {
                    queue<pair<int, int>> q;
                    q.push({sr, sc});
                    grid[sr][sc] = 0;
                    int area = 0;
                    while (!q.empty())
                    {
                        auto [r, c] = q.front();
                        q.pop();
                        ++area;
                        for (int d = 0; d < 4; ++d)
                        {
                            int rr = r + dx[d], cc = c + dy[d];
                            if (rr >= 0 && rr < rows && cc >= 0 && cc < cols && grid[rr][cc] == 1)
                            {
                                grid[rr][cc] = 0;
                                q.push({rr, cc});
                            }
                        }
                    }
                    res = max(res, area);
                }
            }
        }
        return res;
    }
};

int main()
{
    Solution sol;
    vector<vector<int>> g1 = {
        {0, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 0, 0, 0},
        {0, 1, 1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 1, 0, 0, 1, 1, 0, 0, 1, 0, 1, 0, 0},
        {0, 1, 0, 0, 1, 1, 0, 0, 1, 1, 1, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0}};
    cout << sol.maxAreaOfIsland(g1) << endl; // 6
    vector<vector<int>> g2 = {{0, 0, 0, 0, 0, 0, 0, 0}};
    cout << sol.maxAreaOfIsland(g2) << endl; // 0
    return 0;
}
