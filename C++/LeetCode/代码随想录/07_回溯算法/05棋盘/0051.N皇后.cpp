/*
按照国际象棋的规则，皇后可以攻击与之处在同一行或同一列或同一斜线上的棋子。
n 皇后问题 研究的是如何将 n 个皇后放置在 n×n 的棋盘上，并且使皇后彼此之间不能相互攻击。
给你一个整数 n ，返回所有不同的 n 皇后问题 的解决方案。
每一种解法包含一个不同的 n 皇后问题 的棋子放置方案，该方案中 'Q' 和 '.' 分别代表了皇后和空位。

示例 1：
输入：n = 4
输出：[[".Q..","...Q","Q...","..Q."],["..Q.","Q...","...Q",".Q.."]]
解释：如上图所示，4 皇后问题存在两个不同的解法。

示例 2：
输入：n = 1
输出：[["Q"]]
*/
#include <iostream>
#include <vector>
using namespace std;
class Solution
{
public:
    vector<vector<string>> solveNQueens(int n)
    {
        vector<vector<string>> result;
        vector<string> chessboard(n, string(n, '.'));
        backtracking(0, n, chessboard, result);
        return result;
    }

    void backtracking(int row, int n, vector<string> &chessboard, vector<vector<string>> &result)
    {
        // 递归终止条件,每一层for循环是行，如果row==n,说明已经到了最后一行,可以将当前棋盘加入结果集
        if (row == n)
        {
            result.push_back(chessboard);
            return;
        }
        // 遍历每一列
        for (int col = 0; col < n; col += 1)
        {
            if (isValid(row, col, n, chessboard)) // 判断该行该列是否可以放置皇后
            {
                chessboard[row][col] = 'Q';
                backtracking(row + 1, n, chessboard, result);
                chessboard[row][col] = '.';
            }
        }
    }
    bool isValid(int row, int col, int n, vector<string> &chessboard) // 检查同行，同列，45度角，135度角是否有皇后
    {
        // 检查同列是否有皇后，即检查在当前列 col 的上方（之前的行）是否已经放置了皇后
        for (int i = 0; i < row; i += 1)
        {
            if (chessboard[i][col] == 'Q')
                return false;
        }
        // 检查45度角是否有皇后
        for (int i = row - 1, j = col - 1; i >= 0 && j >= 0; i -= 1, j -= 1)
        {
            if (chessboard[i][j] == 'Q')
                return false;
        }
        // 检查135度角是否有皇后
        for (int i = row - 1, j = col + 1; i >= 0 && j < n; i -= 1, j += 1)
        {
            if (chessboard[i][j] == 'Q')
                return false;
        }
        return true;
    }
};
int main()
{
    int n = 4;
    Solution s;
    vector<vector<string>> result = s.solveNQueens(n);
    for (int i = 0; i < result.size(); i += 1)
    {
        for (int j = 0; j < result[i].size(); j += 1)
        {
            cout << result[i][j] << endl;
        }
        cout << endl;
    }
    return 0;
}