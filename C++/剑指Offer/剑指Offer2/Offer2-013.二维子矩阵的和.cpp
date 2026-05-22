/* 题目难度: 中等
[原题链接](https://leetcode.cn/problems/O4NDxx)
题目描述
给定一个二维矩阵 matrix, 实现 NumMatrix 类支持多次查询:
NumMatrix(matrix) 用给定矩阵初始化。
sumRegion(row1,col1,row2,col2) 返回左上角 (row1,col1)、右下角 (row2,col2) 的子矩阵元素总和。
题目样例
示例1
- 输入: ["NumMatrix","sumRegion","sumRegion","sumRegion"]
         [matrix], [2,1,4,3], [1,1,2,2], [1,2,2,4]
- 输出: [null, 8, 11, 12]
题目思考
1. 如何优化时间复杂度?
解决方案
思路
- 暴力每次累加子矩阵所有元素, O(MN) 每次查询
- 类比一维前缀和, 构建二维前缀和数组 sums, sums[r+1][c+1] = 左上角 (0,0) 到 (r,c) 的矩阵和
- 下标加 1 是为了方便处理边界 (下标 0 表示空矩阵, 前缀和为 0)
- 构建: sums[r+1][c+1] = matrix[r][c] + sums[r][c+1] + sums[r+1][c] - sums[r][c]
- 查询: sums[er+1][ec+1] - sums[sr][ec+1] - sums[er+1][sc] + sums[sr][sc]
  (右下矩阵 - 上侧矩阵 - 左侧矩阵 + 左上角矩阵)
复杂度
- 时间复杂度 O(MN): 初始化构建前缀和, 每次查询 O(1)
- 空间复杂度 O(MN): 需要额外的前缀和数组
 */
#include <iostream>
#include <vector>
using namespace std;

class NumMatrix
{
    vector<vector<int>> sums;
public:
    NumMatrix(vector<vector<int>> &matrix)
    {
        int rows = matrix.size(), cols = matrix[0].size();
        sums.assign(rows + 1, vector<int>(cols + 1, 0));
        for (int r = 0; r < rows; r++)
            for (int c = 0; c < cols; c++)
                sums[r+1][c+1] = matrix[r][c] + sums[r][c+1] + sums[r+1][c] - sums[r][c];
    }
    int sumRegion(int row1, int col1, int row2, int col2)
    {
        return sums[row2+1][col2+1] - sums[row1][col2+1] - sums[row2+1][col1] + sums[row1][col1];
    }
};

int main()
{
    vector<vector<int>> matrix = {
        {3, 0, 1, 4, 2},
        {5, 6, 3, 2, 1},
        {1, 2, 0, 1, 5},
        {4, 1, 0, 1, 7},
        {1, 0, 3, 0, 5}
    };
    NumMatrix nm(matrix);
    cout << nm.sumRegion(2, 1, 4, 3) << endl; // 8
    cout << nm.sumRegion(1, 1, 2, 2) << endl; // 11
    cout << nm.sumRegion(1, 2, 2, 4) << endl; // 12
    return 0;
}
