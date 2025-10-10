#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
/*
给定一个非负索引 rowIndex，返回「杨辉三角」的第 rowIndex 行。
在「杨辉三角」中，每个数是它左上方和右上方的数的和。
示例 1:
输入: rowIndex = 3
输出: [1,3,3,1]
示例 2:
输入: rowIndex = 0
输出: [1]
示例 3:
输入: rowIndex = 1
输出: [1,1]
*/
class Solution
{
public:
    /*
    动态规划五部曲
    1. 确定dp数组以及下标的含义
    dp[i][j]:表示第i行第j列的值
    2. 确定递推关系
    dp[i][j] = dp[i-1][j-1] + dp[i-1][j]
    3. 确定初始值
    dp[0][0] = 1
    4. 确定遍历顺序
    5. 举例推导dp数组
    */
    vector<int> getRow(int rowIndex)
    {
        vector<vector<int>> dp(rowIndex + 1);
        for (int i = 0; i <= rowIndex; i++)
        {
            dp[i].resize(i + 1);
            dp[i][0] = dp[i][i] = 1;
            for (int j = 1; j < i; j++)
                dp[i][j] = dp[i - 1][j - 1] + dp[i - 1][j];
        }
        return dp[rowIndex];
    }
};

int main()
{
    return 0;
}