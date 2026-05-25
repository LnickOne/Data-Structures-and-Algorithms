/* 题目难度: 中等
[原题链接](https://leetcode.cn/problems/Q91FMA/)
题目描述
给定严格递增的正整数数组 arr, 找到 arr 中最长斐波那契式子序列的长度 (长度至少为 3)。若不存在返回 0。
题目样例
示例1
- 输入: arr=[1,2,3,4,5,6,7,8]
- 输出: 5 (子序列 [1,2,3,5,8])
示例2
- 输入: arr=[1,3,7,11,12,14,18]
- 输出: 3
题目思考
1. 如何优化时间复杂度?
解决方案
思路
- 二维 DP + 下标字典: dp[i][j] 表示以 arr[i], arr[j] 开头的最长斐波那契子序列长度
- 逆序枚举 i, j, 若 arr[i]+arr[j] 存在于数组中 (下标 k), 则 dp[i][j] = dp[j][k]+1
- 结果取所有 dp[i][j] >= 3 的最大值
复杂度
- 时间复杂度 O(N^2): 两重循环
- 空间复杂度 O(N^2): 二维 DP 数组
 */
#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution
{
public:
    int lenLongestFibSubseq(vector<int> &arr)
    {
        int n = arr.size();
        unordered_map<int,int> idx;
        for (int i = 0; i < n; i++) idx[arr[i]] = i;
        vector<vector<int>> dp(n, vector<int>(n, 2));
        int res = 0;
        for (int i = n - 1; i >= 0; i--)
        {
            for (int j = n - 1; j > i; j--)
            {
                int nxt = arr[i] + arr[j];
                if (idx.count(nxt))
                {
                    int k = idx[nxt];
                    dp[i][j] = dp[j][k] + 1;
                }
                if (dp[i][j] >= 3) res = max(res, dp[i][j]);
            }
        }
        return res;
    }
};

int main()
{
    Solution sol;
    vector<int> a1 = {1, 2, 3, 4, 5, 6, 7, 8};
    cout << sol.lenLongestFibSubseq(a1) << endl; // 5
    vector<int> a2 = {1, 3, 7, 11, 12, 14, 18};
    cout << sol.lenLongestFibSubseq(a2) << endl; // 3
    return 0;
}
