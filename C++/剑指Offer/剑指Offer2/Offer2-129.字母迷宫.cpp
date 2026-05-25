/* 题目难度: 中等
[原题链接](https://leetcode.cn/problems/ju-zhen-zhong-de-lu-jing-lcof/)
题目描述
m×n 字符网格 grid, 判断是否存在按字母顺序水平/垂直相邻构成 target 的路径 (同一格不重复使用)。
题目样例
示例1
- 输入: grid=[["A","B","C","E"],["S","F","C","S"],["A","D","E","E"]], target="ABCCED"
- 输出: true
示例2
- 输入: 同上, target="ABCB"
- 输出: false
题目思考
1. DFS 回溯, 如何标记已访问?
解决方案
思路
- 从每个首字符开始 DFS, 用原地置空字符标记已访问, 回溯时恢复
- 找到完整路径 (i==target.size()) 返回 true
复杂度
- 时间复杂度 O((3^L)*RC): L 为 target 长度, RC 为网格大小
- 空间复杂度 O(L): 递归栈深度
 */
#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution
{
    int rows, cols;
    bool dfs(vector<vector<char>> &grid, const string &target, int r, int c, int i)
    {
        if (i == (int)target.size()) return true;
        int dr[] = {1, -1, 0, 0}, dc[] = {0, 0, 1, -1};
        for (int d = 0; d < 4; ++d)
        {
            int rr = r + dr[d], cc = c + dc[d];
            if (rr >= 0 && rr < rows && cc >= 0 && cc < cols && grid[rr][cc] == target[i])
            {
                grid[rr][cc] = 0;
                if (dfs(grid, target, rr, cc, i + 1)) return true;
                grid[rr][cc] = target[i];
            }
        }
        return false;
    }
public:
    bool wordPuzzle(vector<vector<char>> &grid, string target)
    {
        rows = (int)grid.size(); cols = (int)grid[0].size();
        for (int r = 0; r < rows; ++r)
            for (int c = 0; c < cols; ++c)
                if (grid[r][c] == target[0])
                {
                    grid[r][c] = 0;
                    if (dfs(grid, target, r, c, 1)) return true;
                    grid[r][c] = target[0];
                }
        return false;
    }
};

int main()
{
    Solution sol;
    cout << boolalpha;
    vector<vector<char>> g = {{'A','B','C','E'},{'S','F','C','S'},{'A','D','E','E'}};
    cout << sol.wordPuzzle(g, "ABCCED") << endl; // true
    vector<vector<char>> g2 = {{'A','B','C','E'},{'S','F','C','S'},{'A','D','E','E'}};
    cout << sol.wordPuzzle(g2, "ABCB") << endl;   // false
    return 0;
}
