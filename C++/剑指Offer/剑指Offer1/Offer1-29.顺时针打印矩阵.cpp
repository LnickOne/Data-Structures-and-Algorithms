/*
题目难度: 简单
[原题链接](https://leetcode-cn.com/problems/shun-shi-zhen-da-yin-ju-zhen-lcof/)
题目描述
输入一个矩阵，按照从外向里以顺时针的顺序依次打印出每一个数字。
- 0 <= matrix.length <= 100
- 0 <= matrix[i].length <= 100
题目样例
示例
输入
matrix = [[1,2,3],[4,5,6],[7,8,9]]
输出
[1,2,3,6,9,8,7,4,5]
题目思考
1. 可以有哪些遍历方式?
解决方案
方案 1
思路
- 首先一个很自然的想法就是模拟整个顺时针的过程, 逐个点遍历, 当遇到边界或者已经遍历过的点就按照顺时针方向转向即可
- 所以需要额外一个 visit 集合存储当前访问过的点
方案 2
思路
- 回顾方案 1, 它需要逐个遍历每个点, 且需要额外空间来存储访问过的点, 有没有方法可以一次性得到当前方向上的所有的有效点, 批量加入结果中呢?
- 答案也是肯定的, 我们重新思考题目, 这次尝试从整体上看遍历过程
- 考虑`右-下-左-上`这一轮遍历, 结束后应该就把所有最外层的元素都打印出了, 接下来只需要从第二层起点出发, 再按照这一顺序遍历即可, 是不是很类似**剥洋葱**?
- 使用四个边界指针 top/bottom/left/right 来模拟收缩过程
- 遍历完一圈后相应边界向内收缩, 直到 top>bottom 或 left>right 为止
复杂度
- 时间复杂度 `O(RC)`
  - 所有点只需要遍历一遍
- 空间复杂度 `O(1)`
  - 只需要常数个变量
*/
#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    vector<int> spiralOrder(vector<vector<int>> &matrix)
    {
        vector<int> res;
        if (matrix.empty() || matrix[0].empty())
            return res;

        int top = 0, bottom = (int)matrix.size() - 1;
        int left = 0, right = (int)matrix[0].size() - 1;

        while (top <= bottom && left <= right)
        {
            // 从左到右遍历上边界
            for (int j = left; j <= right; j++)
                res.push_back(matrix[top][j]);
            top++;

            // 从上到下遍历右边界
            for (int i = top; i <= bottom; i++)
                res.push_back(matrix[i][right]);
            right--;

            // 从右到左遍历下边界 (需确保仍有行)
            if (top <= bottom)
            {
                for (int j = right; j >= left; j--)
                    res.push_back(matrix[bottom][j]);
                bottom--;
            }

            // 从下到上遍历左边界 (需确保仍有列)
            if (left <= right)
            {
                for (int i = bottom; i >= top; i--)
                    res.push_back(matrix[i][left]);
                left++;
            }
        }
        return res;
    }
};

int main()
{
    Solution s;

    // 示例: matrix = [[1,2,3],[4,5,6],[7,8,9]] => [1,2,3,6,9,8,7,4,5]
    vector<vector<int>> matrix1 = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    vector<int> res1 = s.spiralOrder(matrix1);
    cout << "输入 [[1,2,3],[4,5,6],[7,8,9]] => [";
    for (int i = 0; i < (int)res1.size(); i++)
    {
        if (i)
            cout << ",";
        cout << res1[i];
    }
    cout << "]" << endl;

    // 示例: matrix = [[1,2,3,4],[5,6,7,8],[9,10,11,12]]
    vector<vector<int>> matrix2 = {{1, 2, 3, 4}, {5, 6, 7, 8}, {9, 10, 11, 12}};
    vector<int> res2 = s.spiralOrder(matrix2);
    cout << "输入 [[1,2,3,4],[5,6,7,8],[9,10,11,12]] => [";
    for (int i = 0; i < (int)res2.size(); i++)
    {
        if (i)
            cout << ",";
        cout << res2[i];
    }
    cout << "]" << endl;

    return 0;
}
