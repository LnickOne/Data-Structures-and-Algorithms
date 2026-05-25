/* 题目难度: 中等
[原题链接](https://leetcode.cn/problems/2AoeFn/)
题目描述
机器人位于 m×n 网格左上角, 每次只能向下或向右移动一步, 求到达右下角的不同路径总数。
题目样例
示例1
- 输入: m=3, n=7
- 输出: 28
示例2
- 输入: m=3, n=2
- 输出: 3
示例3
- 输入: m=3, n=3
- 输出: 6
题目思考
1. 如何优化时间和空间复杂度?
解决方案
思路
- 二维 DP: dp[r][c] = dp[r-1][c] + dp[r][c-1], 初始 dp[0][0]=1
- 等价于组合数 C(m+n-2, m-1)
复杂度
- 时间复杂度 O(MN): 两重循环
- 空间复杂度 O(MN): 二维 DP 数组
 */
#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    int uniquePaths(int m, int n)
    {
        vector<vector<int>> dp(m, vector<int>(n, 0));
        dp[0][0] = 1;
        for (int r = 0; r < m; r++)
            for (int c = 0; c < n; c++)
            {
                if (r == 0 && c == 0) continue;
                int l = c > 0 ? dp[r][c-1] : 0;
                int u = r > 0 ? dp[r-1][c] : 0;
                dp[r][c] = l + u;
            }
        return dp[m-1][n-1];
    }
};

int main()
{
    Solution sol;
    cout << sol.uniquePaths(3, 7) << endl; // 28
    cout << sol.uniquePaths(3, 2) << endl; // 3
    cout << sol.uniquePaths(3, 3) << endl; // 6
    return 0;
}
