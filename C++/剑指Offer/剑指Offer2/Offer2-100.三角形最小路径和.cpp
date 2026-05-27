/* 题目难度: 中等
[原题链接](https://leetcode.cn/problems/IlPe0q/)
题目描述
给定三角形 triangle, 找出自顶向下的最小路径和。每步只能移动到下一行中相邻的结点 (下标 i 或 i+1)。
题目样例
示例1
- 输入: triangle=[[2],[3,4],[6,5,7],[4,1,8,3]]
- 输出: 11 (路径 2+3+5+1)
示例2
- 输入: triangle=[[-10]]
- 输出: -10
题目思考
1. 如何优化到 O(N) 空间?
解决方案
思路
- 滚动 DP: pdp 存储上一行的最小路径和, 每行从 pdp[i] 更新 dp[i] 和 dp[i+1]
- 最终结果是最后一行 dp 的最小值
复杂度
- 时间复杂度 O(N^2): 两重循环
- 空间复杂度 O(N): 滚动数组
 */
#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>
using namespace std;

class Solution
{
public:
    int minimumTotal(vector<vector<int>> &triangle)
    {
        int n = triangle.size();
        vector<int> pdp = triangle[0];
        for (int r = 1; r < n; ++r)
        {
            vector<int> dp(triangle[r].size(), INT_MAX);
            for (int i = 0; i < (int)pdp.size(); ++i)
            {
                dp[i] = min(dp[i], triangle[r][i] + pdp[i]);
                dp[i + 1] = min(dp[i + 1], triangle[r][i + 1] + pdp[i]);
            }
            pdp = dp;
        }
        return *min_element(pdp.begin(), pdp.end());
    }
};

int main()
{
    Solution sol;
    vector<vector<int>> t1 = {{2}, {3, 4}, {6, 5, 7}, {4, 1, 8, 3}};
    cout << sol.minimumTotal(t1) << endl; // 11
    vector<vector<int>> t2 = {{-10}};
    cout << sol.minimumTotal(t2) << endl; // -10
    return 0;
}
