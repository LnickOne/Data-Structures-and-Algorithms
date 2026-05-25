/* 题目难度: 简单
[原题链接](https://leetcode.cn/problems/GzCJIP/)
题目描述
每个阶梯有体力花费值 cost[i], 支付后可选择向上爬一个或两个阶梯。找出达到楼顶的最低花费, 可从下标 0 或 1 开始。
题目样例
示例1
- 输入: cost=[10,15,20]
- 输出: 15
示例2
- 输入: cost=[1,100,1,1,1,100,1,1,100,1]
- 输出: 6
题目思考
1. 第 n 个阶梯的最低花费可以根据什么得出?
解决方案
思路
- DP 滚动变量: dp[i] = min(dp[i-1], dp[i-2]) + cost[i]
- 只需两个变量 ppre/pre, 最终结果是 min(ppre, pre)
复杂度
- 时间复杂度 O(N): 遍历一遍
- 空间复杂度 O(1): 常数变量
 */
#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    int minCostClimbingStairs(vector<int> &cost)
    {
        int ppre = cost[0], pre = cost[1];
        for (int i = 2; i < (int)cost.size(); i++)
        {
            int cur = min(ppre, pre) + cost[i];
            ppre = pre;
            pre = cur;
        }
        return min(ppre, pre);
    }
};

int main()
{
    Solution sol;
    vector<int> c1 = {10, 15, 20};
    cout << sol.minCostClimbingStairs(c1) << endl; // 15
    vector<int> c2 = {1, 100, 1, 1, 1, 100, 1, 1, 100, 1};
    cout << sol.minCostClimbingStairs(c2) << endl; // 6
    return 0;
}
