/* 题目难度: 困难
[原题链接](https://leetcode.cn/problems/omKAoA/)
题目描述
给定字符串 s, 将 s 分割成若干回文子串, 返回最少分割次数。
题目样例
示例1
- 输入: s="aab"
- 输出: 1 (分割为 ["aa","b"])
示例2
- 输入: s="a"
- 输出: 0
示例3
- 输入: s="ab"
- 输出: 1
题目思考
1. 如何优化时间复杂度?
解决方案
思路
- 预处理 isPalin[i][j]: 从右到左遍历 i, 从左到右遍历 j, 利用 isPalin[i+1][j-1] 递推
- DP: dp[j] = 子串 [0,j] 最少分割次数; 若 [0,j] 是回文则 dp[j]=0, 否则枚举 i 找回文后缀
复杂度
- 时间复杂度 O(N^2): 两重循环
- 空间复杂度 O(N^2): isPalin 数组
 */
#include <iostream>
#include <vector>
#include <string>
#include <climits>
using namespace std;

class Solution
{
public:
    int minCut(string s)
    {
        int n = s.size();
        vector<vector<bool>> isPalin(n, vector<bool>(n, true));
        for (int i = n - 2; i >= 0; i--)
            for (int j = i + 1; j < n; j++)
                isPalin[i][j] = isPalin[i + 1][j - 1] && s[i] == s[j];
        vector<int> dp(n, INT_MAX);
        for (int j = 0; j < n; j++)
        {
            if (isPalin[0][j]) { dp[j] = 0; continue; }
            for (int i = 1; i <= j; i++)
                if (isPalin[i][j])
                    dp[j] = min(dp[j], dp[i - 1] + 1);
        }
        return dp[n - 1];
    }
};

int main()
{
    Solution sol;
    cout << sol.minCut("aab") << endl; // 1
    cout << sol.minCut("a") << endl;   // 0
    cout << sol.minCut("ab") << endl;  // 1
    return 0;
}
