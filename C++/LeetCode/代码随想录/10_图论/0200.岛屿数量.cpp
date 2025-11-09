/*
给你一个由 '1'（陆地）和 '0'（水）组成的的二维网格，请你计算网格中岛屿的数量。
岛屿总是被水包围，并且每座岛屿只能由水平方向和/或竖直方向上相邻的陆地连接形成。
此外，你可以假设该网格的四条边均被水包围。
示例 1：
输入：grid = [
  ["1","1","1","1","0"],
  ["1","1","0","1","0"],
  ["1","1","0","0","0"],
  ["0","0","0","0","0"]
]
输出：1
示例 2：
输入：grid = [
  ["1","1","0","0","0"],
  ["1","1","0","0","0"],
  ["0","0","1","0","0"],
  ["0","0","0","1","1"]
]
输出：3
*/
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
class Solution
{
public:
    int numIslands(vector<vector<char>> &grid)
    {
        if (grid.empty())
            return 0;
        vector<vector<bool>> visited(grid.size(), vector<bool>(grid[0].size(), false));
        int result = 0;
        for (int i = 0; i < grid.size(); i++)
        {
            for (int j = 0; j < grid[0].size(); j++)
            {
                if (visited[i][j] == false && grid[i][j] == '1')
                {
                    visited[i][j] = true;
                    result++;                 // 遇到没访问过的陆地，+1
                    dfs(i, j, visited, grid); // 将与其链接的陆地都标记上 true
                }
            }
        }
        return result;
    }
    int direction[4][2] = {0, 1, 1, 0, -1, 0, 0, -1}; // 四个方向
    void dfs(int x, int y, vector<vector<bool>> &visited, vector<vector<char>> &grid)
    {
        for (int i = 0; i < 4; i++)
        {
            int next_x = x + direction[i][0];
            int next_y = y + direction[i][1];
            if (next_x < 0 || next_x >= grid.size() || next_y < 0 || next_y >= grid[0].size())
                continue; // 越界了，直接跳过
            if (visited[next_x][next_y] == false && grid[next_x][next_y] == '1')
            {
                // 没有访问过的 同时 是陆地的
                visited[next_x][next_y] = true;
                dfs(next_x, next_y, visited, grid);
            }
        }
    }
};

int main()
{
    vector<vector<char>> grid = {
        {'1', '1', '0', '0', '0'},
        {'1', '1', '0', '0', '0'},
        {'0', '0', '1', '0', '0'},
        {'0', '0', '0', '1', '1'}};
    Solution s;
    cout << s.numIslands(grid) << endl;
    return 0;
}