/* 题目难度: 中等
[原题链接](https://leetcode.cn/problems/PzWKhm/)
题目描述
环形街道上的打家劫舍, 第一个和最后一个房屋相邻, 不能同时偷。计算不触动警报情况下能偷窃的最高金额。
题目样例
示例1
- 输入: nums=[2,3,2]
- 输出: 3
示例2
- 输入: nums=[1,2,3,1]
- 输出: 4
示例3
- 输入: nums=[0]
- 输出: 0
题目思考
1. 如何处理首尾相连的问题?
解决方案
思路
- 分两次 DP: 排除首元素 (偷 [1..n-1]) 和排除尾元素 (偷 [0..n-2]), 取两者较大值
- 单次 DP 与 089 相同, 注意 n==1 的特殊情况
复杂度
- 时间复杂度 O(N): 遍历两遍
- 空间复杂度 O(1): 常数变量
 */
#include <iostream>
#include <vector>
using namespace std;

class Solution
{
    int robRange(vector<int> &nums, int s, int e)
    {
        int ppre = 0, pre = 0;
        for (int i = s; i <= e; i++)
        {
            int cur = max(pre, ppre + nums[i]);
            ppre = pre;
            pre = cur;
        }
        return pre;
    }
public:
    int rob(vector<int> &nums)
    {
        int n = nums.size();
        if (n == 1) return nums[0];
        return max(robRange(nums, 0, n - 2), robRange(nums, 1, n - 1));
    }
};

int main()
{
    Solution sol;
    vector<int> n1 = {2, 3, 2};
    cout << sol.rob(n1) << endl; // 3
    vector<int> n2 = {1, 2, 3, 1};
    cout << sol.rob(n2) << endl; // 4
    vector<int> n3 = {0};
    cout << sol.rob(n3) << endl; // 0
    return 0;
}
