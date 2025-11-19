/*
给定一个 m x n 二维字符网格 board 和一个字符串单词 word 。
如果 word 存在于网格中，返回 true ；否则，返回 false 。
单词必须按照字母顺序，通过相邻的单元格内的字母构成，其中“相邻”单元格是那些水平相邻或垂直相邻的单元格。
同一个单元格内的字母不允许被重复使用。
输入：board = [["A","B","C","E"],["S","F","C","S"],["A","D","E","E"]], word = "ABCCED"
输出：true
输入：board = [["A","B","C","E"],["S","F","C","S"],["A","D","E","E"]], word = "SEE"
输出：true
输入：board = [["A","B","C","E"],["S","F","C","S"],["A","D","E","E"]], word = "ABCB"
输出：false
*/
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
class Solution
{
public:
    int m, n;
    bool exist(vector<vector<char>> &board, string word)
    {
        m = board.size();
        n = board[0].size();
        for (int i = 0; i < m; i += 1)
        {
            for (int j = 0; j < n; j += 1)
            {
                if (board[i][j] == word[0])
                {
                    dfs(board, 0, word, i, j);
                    if (isExist)
                        return true;
                }
            }
        }
        return false;
    }
    bool isExist = false;
    vector<vector<int>> di = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
    void dfs(vector<vector<char>> &board, int index, string &word, int i, int j)
    {
        if (index + 1 == word.length())
        {
            isExist = true;
        }
        else
        {
            auto &board_val = board[i][j];
            board[i][j] = '0';
            for (int d = 0; d < 4; d += 1)
            {
                int newi = i + di[d][0];
                int newj = j + di[d][1];
                if (newi >= 0 && newi < m && newj >= 0 && newj < n)
                {
                    if (board[newi][newj] == word[index + 1])
                    {
                        dfs(board, index + 1, word, newi, newj);
                    }
                }
            }
            board[i][j] = board_val;
        }
    }
};

int main()
{
    vector<vector<char>> board = {{'A', 'B', 'C', 'E'}, {'S', 'F', 'C', 'S'}, {'A', 'D', 'E', 'E'}};
    string word = "ABCCED";
    Solution s;
    bool ans = s.exist(board, word);
    cout << ans << endl;
    return 0;
}