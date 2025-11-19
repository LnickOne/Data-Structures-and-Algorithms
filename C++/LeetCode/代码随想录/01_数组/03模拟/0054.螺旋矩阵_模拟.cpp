/*
给你一个 m 行 n 列的矩阵 matrix ，请按照 顺时针螺旋顺序 ，返回矩阵中的所有元素。
示例 1：
输入：matrix = [[1,2,3],[4,5,6],[7,8,9]]
输出：[1,2,3,6,9,8,7,4,5]
示例 2：
输入：matrix = [[1,2,3,4],[5,6,7,8],[9,10,11,12]]
输出：[1,2,3,4,8,12,11,10,9,5,6,7]
 */
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
class Solution
{
public:
    vector<int> spiralOrder(vector<vector<int>> &matrix)
    {
        vector<int> result;
        // int row = 0;
        // int col = 0;
        int start_row = 0;
        int start_col = 0;
        int row_border = matrix.size() - 1;
        int col_border = matrix[0].size() - 1;
        while (start_row <= row_border && start_col <= col_border) // 遵循左闭右开的原则
        {
            // 上边从左往右
            for (int col = start_col; col <= col_border; ++col) // 遵循左闭右开的原则
                result.push_back(matrix[start_row][col]);
            ++start_col;
            // 右边从上往下
            for (int i = start_col; i <= row_border; ++i)
                result.push_back(matrix[i][col_border]);
            --col_border;
            for (int i = start_col; i <= row_border; ++i)
                result.push_back(matrix[i][col_border]);
            --col_border;
            // 下边从右往左
            if (start_col <= row_border)
                for (int i = col_border; i >= start_row; --i)
                    result.push_back(matrix[row_border][i]);
            --row_border;
            // 左边从下往上
            if (start_row <= col_border)
                for (int i = row_border; i >= start_col; --i)
                    result.push_back(matrix[i][start_row]);
            ++start_row;
        }
        return result;
    }

    vector<vector<int>> generateMatrix(int n)
    {
        vector<vector<int>> result(n, vector<int>(n, 0));
        int row = 0;
        int col = 0;
        int start_row = 0;
        int start_col = 0;
        int offset = 1;
        int count = 1;
        int loop = 1;
        while (loop <= n / 2)
        {
            // 上边从左往右遍历
            for (col = start_col; col < n - offset; col++)
            {
                result[start_row][col] = count;
                count++;
            }
            // 从右边往下遍历
            for (row = start_row; row < n - offset; row++)
            {
                result[row][col] = count;
                count++;
            }
            // 从下边往左遍历
            for (; col > start_col; col--)
            {
                result[row][col] = count;
                count++;
            }
            // 从左边往上遍历
            for (; row > start_row; row--)
            {
                result[row][col] = count;
                count++;
            }
            start_row++;
            start_col++;
            loop++;
            offset++;
        }
        if (n % 2 == 1)
            result[start_row][start_col] = count;
        return result;
    }
};

int main()
{
    Solution solution;
    vector<vector<int>> matrix = solution.generateMatrix(3);
    solution.spiralOrder(matrix);
    return 0;
}
