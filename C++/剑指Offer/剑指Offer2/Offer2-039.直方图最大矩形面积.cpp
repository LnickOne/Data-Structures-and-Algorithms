/* 题目难度: 困难
[原题链接](https://leetcode.cn/problems/0ynMMM/)
题目描述
给定非负整数数组 heights, 数组中数字表示直方图各柱子高度, 每个柱子宽度为 1。
求直方图中能勾勒出来的矩形的最大面积。
题目样例
示例1
- 输入: heights = [2,1,5,6,2,3]
- 输出: 10
示例2
- 输入: heights = [2,4]
- 输出: 4
题目思考
1. 如何优化时间复杂度?
解决方案
思路
- 单调栈存柱子下标, 保证从栈顶到栈底高度单调递减
- 遍历每个柱子: 若当前高度小于栈顶则弹出栈顶, 以栈顶高度为矩形高计算面积
  - 右边界 r = 当前下标, 左边界 l = 新栈顶或 -1
  - 面积 = (r - l - 1) * 栈顶高度
- 遍历结束后处理栈中剩余元素, 右边界为数组长度
复杂度
- 时间复杂度 O(N): 每个元素最多入栈出栈各一次
- 空间复杂度 O(N): 栈最多存 N 个元素
 */
#include <iostream>
#include <vector>
#include <stack>
using namespace std;

class Solution
{
public:
    int largestRectangleArea(vector<int> &heights)
    {
        stack<int> st;
        int res = 0;
        int n = heights.size();
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
};

int main()
{
    Solution sol;
    vector<int> h1 = {2, 1, 5, 6, 2, 3};
    cout << sol.largestRectangleArea(h1) << endl; // 10
    vector<int> h2 = {2, 4};
    cout << sol.largestRectangleArea(h2) << endl; // 4
    vector<int> h3 = {1};
    cout << sol.largestRectangleArea(h3) << endl; // 1
    return 0;
}
