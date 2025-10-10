#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
/*
给定一个包含非负整数的 m x n 网格 grid ，请找出一条从左上角到右下角的路径，使得路径上的数字总和为最小。
说明：每次只能向下或者向右移动一步。
示例 1：
输入：grid = [[1,3,1],[1,5,1],[4,2,1]]
输出：7
解释：因为路径 1→3→1→1→1 的总和最小。
示例 2：
输入：grid = [[1,2,3],[4,5,6]]
输出：12
*/
class Solution
{
public:
    /*
    动态规划五部曲
    1. 确定dp数组以及下标的含义
    dp[i][j]：表示从位置[0,0]抵达位置[i-1,j-1]，路径上的数字总和为最小
    2. 确定递推关系
    dp[i][j]可以由dp[i-1][j]和dp[i][j-1]取最小值获得
    3. 确定初始值
    dp[0][0] = grid[0][0];
    for(int i=1;i<m;i++)
        dp[i][0] = dp[i-1][0] + grid[i][0];
    for(int j=1;j<n;j++))
        dp[0][j]=dp[0][j-1]+grid[0][j];
    4. 确定遍历顺序
    5. 举例推导dp数组
    */
    int minPathSum(vector<vector<int>> &grid)
    {
        if (grid.empty())
            return 0;
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> dp(m, vector<int>(n));
        dp[0][0] = grid[0][0];
        for (int i = 1; i < m; i++)
            dp[i][0] = dp[i - 1][0] + grid[i][0];
        for (int j = 1; j < n; j++)
            dp[0][j] = dp[0][j - 1] + grid[0][j];
        for (int i = 1; i < m; i++)
        {
            for (int j = 1; j < n; j++)
            {
                dp[i][j] = min(dp[i - 1][j], dp[i][j - 1]) + grid[i][j];
            }
        }
        return dp[m - 1][n - 1];
    }
};

int main()
{
    vector<vector<int>> grid = {{1, 3, 1}, {1, 5, 1}, {4, 2, 1}};
    Solution solve;
    cout << solve.minPathSum(grid) << endl;
    return 0;
}