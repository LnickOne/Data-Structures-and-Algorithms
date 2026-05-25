/* 题目难度: 中等
[原题链接](https://leetcode.cn/problems/ji-qi-ren-de-yun-dong-fan-wei-lcof/)
题目描述
m×n 矩阵从 (0,0) 出发, 每次只能向右或向下移动, 不能进入 digit(i)+digit(j) > cnt 的格子。返回可整理的格子数。
题目样例
示例1
- 输入: m=4, n=7, cnt=5
- 输出: 18
题目思考
1. 只向右或向下, 可以用 DP 递推可达性。
解决方案
思路
- dp[r][c] = (数位和<=cnt) && (dp[r-1][c] || dp[r][c-1])
- 统计 dp 为 true 的格子数
复杂度
- 时间复杂度 O(MN): 遍历整个矩阵
- 空间复杂度 O(MN): dp 数组
 */
#include <iostream>
#include <vector>
using namespace std;

class Solution
{
    int digitSum(int x)
    {
        int s = 0;
        while (x) { s += x % 10; x /= 10; }
        return s;
    }
public:
    int wardrobeFinishing(int m, int n, int cnt)
    {
        vector<vector<bool>> dp(m, vector<bool>(n, false));
        dp[0][0] = true;
        int res = 1;
        for (int r = 0; r < m; ++r)
            for (int c = 0; c < n; ++c)
            {
                if (r == 0 && c == 0) continue;
                if (digitSum(r) + digitSum(c) > cnt) continue;
                if ((r > 0 && dp[r-1][c]) || (c > 0 && dp[r][c-1]))
                {
                    dp[r][c] = true;
                    ++res;
                }
            }
        return res;
    }
};

int main()
{
    Solution sol;
    cout << sol.wardrobeFinishing(4, 7, 5) << endl; // 18
    cout << sol.wardrobeFinishing(3, 3, 1) << endl; // 5
    return 0;
}
