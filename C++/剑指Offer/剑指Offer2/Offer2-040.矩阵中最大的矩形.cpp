/* 题目难度: 困难
[原题链接](https://leetcode.cn/problems/PLYXKQ/)
题目描述
给定由 '0' 和 '1' 组成的矩阵 matrix (一维字符串数组格式), 找出只包含 1 的最大矩形, 返回其面积。
题目样例
示例1
- 输入: matrix = ["10100","10111","11111","10010"]
- 输出: 6
示例2
- 输入: matrix = []
- 输出: 0
示例3
- 输入: matrix = ["0"]
- 输出: 0
示例4
- 输入: matrix = ["1"]
- 输出: 1
题目思考
1. 如何优化时间复杂度?
解决方案
思路
- 维护高度数组 heights, 逐行累加: 当前格为 '1' 则高度加 1, 否则清零
- 每行形成一个直方图, 对每个直方图用单调栈求最大矩形面积 (同 Offer2-039)
- 所有行中最大面积即为结果
复杂度
- 时间复杂度 O(RC): R 是行数, C 是列数
- 空间复杂度 O(C): 高度数组和单调栈
 */
#include <iostream>
#include <vector>
#include <string>
#include <stack>
using namespace std;

class Solution
{
    int largestInHistogram(vector<int> &heights)
    {
        stack<int> st;
        int res = 0, n = heights.size();
        for (int r = 0; r <= n; r++)
        {
            int h = (r == n) ? 0 : heights[r];
            while (!st.empty() && heights[st.top()] > h)
            {
                int ch = heights[st.top()]; st.pop();
                int l = st.empty() ? -1 : st.top();
                res = max(res, (r - l - 1) * ch);
            }
            st.push(r);
        }
        return res;
    }
public:
    int maximalRectangle(vector<string> &matrix)
    {
        if (matrix.empty()) return 0;
        int rows = matrix.size(), cols = matrix[0].size();
        vector<int> heights(cols, 0);
        int res = 0;
        for (int r = 0; r < rows; r++)
        {
            for (int c = 0; c < cols; c++)
                heights[c] = (matrix[r][c] == '1') ? heights[c] + 1 : 0;
            res = max(res, largestInHistogram(heights));
        }
        return res;
    }
};

int main()
{
    Solution sol;
    vector<string> m1 = {"10100", "10111", "11111", "10010"};
    cout << sol.maximalRectangle(m1) << endl; // 6
    vector<string> m2 = {};
    cout << sol.maximalRectangle(m2) << endl; // 0
    vector<string> m3 = {"0"};
    cout << sol.maximalRectangle(m3) << endl; // 0
    vector<string> m4 = {"1"};
    cout << sol.maximalRectangle(m4) << endl; // 1
    return 0;
}
