#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;
/*
给你一个 n x n 的 方形 整数数组 matrix ，请你找出并返回通过 matrix 的下降路径 的 最小和 。
下降路径 可以从第一行中的任何元素开始，并从每一行中选择一个元素。
在下一行选择的元素和当前行所选元素最多相隔一列（即位于正下方或者沿对角线向左或者向右的第一个元素）。
具体来说，位置 (row, col) 的下一个元素应当是 (row + 1, col - 1)、(row + 1, col) 或者 (row + 1, col + 1) 。
*/
class Solution
{
public:
    /*
    动态规划五部曲
    1. 确定dp数组以及下标的含义
    2. 确定递推关系
    3. 确定初始值
    4. 确定遍历顺序
    5. 举例推导dp数组
    */
    int minFallingPathSum(vector<vector<int>> &matrix)
    {
        int n = matrix.size();
        vector<vector<int>> dp(n, vector<int>(n, 0));
        int min_val = INT_MAX;
        for (int i = 0; i < n; i++)
        {
            dp[0][i] = matrix[0][i];
        }
        for (int i = 1; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                int left_up = INT_MAX;
                int left = INT_MAX;
                int left_down = INT_MAX;
                if (j - 1 >= 0)
                {
                    left = dp[i - 1][j - 1];
                }
                left_up = dp[i - 1][j];
                if (j + 1 < n)
                {
                    left_down = dp[i - 1][j + 1];
                }
                dp[i][j] = matrix[i][j] + min(left, min(left_up, left_down));
                min_val = min(dp[i][j], min_val);
            }
        }
        return *min_element(dp[n - 1].begin(), dp[n - 1].end());
    }
};

int main()
{
    vector<vector<int>> matrix = {{2, 1, 3}, {6, 5, 4}, {7, 8, 9}};
    Solution s;
    cout << s.minFallingPathSum(matrix) << endl;
    return 0;
}