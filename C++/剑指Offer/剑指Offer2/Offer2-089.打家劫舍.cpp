/* 题目难度: 中等
[原题链接](https://leetcode.cn/problems/Gu0c2T/)
题目描述
不能偷相邻房屋, 给定每间房屋存放金额的数组 nums, 计算不触动警报装置情况下能偷窃的最高金额。
题目样例
示例1
- 输入: nums=[1,2,3,1]
- 输出: 4
示例2
- 输入: nums=[2,7,9,3,1]
- 输出: 12
题目思考
1. 偷窃第 n 个房屋的最大金额如何由前面状态得出?
解决方案
思路
- DP 滚动变量: dp[i] = max(dp[i-1], dp[i-2] + nums[i])
- ppre/pre 分别记录前两个 dp 值, 最终返回 pre
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
    int rob(vector<int> &nums)
    {
        int ppre = 0, pre = 0;
        for (int x : nums)
        {
            int cur = max(pre, ppre + x);
            ppre = pre;
            pre = cur;
        }
        return pre;
    }
};

int main()
{
    Solution sol;
    vector<int> n1 = {1, 2, 3, 1};
    cout << sol.rob(n1) << endl; // 4
    vector<int> n2 = {2, 7, 9, 3, 1};
    cout << sol.rob(n2) << endl; // 12
    return 0;
}
