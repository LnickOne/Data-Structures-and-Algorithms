#include <vector>
#include <iostream>
using namespace std;
/*
一个机器人位于一个 m x n 网格的左上角 （起始点在下图中标记为 “Start” ）。
机器人每次只能向下或者向右移动一步。机器人试图达到网格的右下角（在下图中标记为 “Finish” ）。
问总共有多少条不同的路径？
*/
class Solution
{
public:
    /*
    动态规划五部曲
    1. 确定dp数组以及下标的含义
    dp[i][j]：从[0,0]位置到达终点[i-1,j-1]位置(即grid[m - 1][n - 1]),有dp[i][j]种方法路径
    2. 确定递推关系
    机器人每次只能从上向下或者从左向右移动一步，
    dp[i-1][j]：表示[0,0]位置走到坐标[i-1,j]有这么多种路径
    dp[i][j-1]：表示[0,0]位置走到坐标[i,j-1]有这么多种路径
    所以dp[i][j]种路径可以由dp[i-1][j]和dp[i][j-1]的总和，递推推导得到
    递推关系为：dp[i][j] = dp[i - 1][j] + dp[i][j - 1] ;
    3. 确定初始值
    for (int i = 0; i < m; i++)
        dp[i][0] = 1;
    for (int i = 0; i < n; i++)
        dp[0][i] = 1;
    4. 确定遍历顺序
    5. 举例推导dp数组
    */
    int uniquePaths(int m, int n)
    {
        vector<vector<int>> dp(m, vector<int>(n));
        for (int i = 0; i < m; i++)
            dp[i][0] = 1;
        for (int i = 0; i < n; i++)
            dp[0][i] = 1;
        for (int i = 1; i < m; i++)
        {
            for (int j = 1; j < n; j++)
                dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
        }
        return dp[m - 1][n - 1];
    }
};

int main()
{
    Solution s;
    cout << s.uniquePaths(3, 7) << endl;
    return 0;
}