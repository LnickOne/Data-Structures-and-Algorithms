/* 题目难度: 中等
[原题链接](https://leetcode.cn/problems/QTMn0o/)
题目描述
给定一个整数数组和一个整数 k, 请找到该数组中和为 k 的连续子数组的个数。
题目样例
示例1
- 输入: nums = [1,1,1], k = 2
- 输出: 2
示例2
- 输入: nums = [1,2,3], k = 3
- 输出: 2
题目思考
1. 如何尽可能优化时间复杂度?
解决方案
思路
- 暴力两重循环 O(N^2), 效率较低
- 任意子数组 [i,j] 的和 = 前缀和 [0,j] - 前缀和 [0,i-1]
- 维护前缀和 sm 和计数哈希表 cnts (cnts[x] 表示前缀和等于 x 的次数)
- 遍历每个元素: 先累加 sm, 然后将 cnts[sm-k] 计入结果 (表示以当前元素结尾和为 k 的子数组数)
- 注意需要先累加结果再更新 cnts, 防止 k=0 时错误地把从下标 0 开始的子数组计入
- 初始化 cnts[0]=1 表示空数组 (前缀和为 0) 出现过一次
复杂度
- 时间复杂度 O(N): 只需遍历数组一遍
- 空间复杂度 O(N): 计数哈希表最多包含 N 个元素
 */
#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution
{
public:
    int subarraySum(vector<int> &nums, int k)
    {
        unordered_map<int, int> cnts;
        cnts[0] = 1;
        int sm = 0, res = 0;
        for (int x : nums)
        {
            sm += x;
            res += cnts.count(sm - k) ? cnts[sm - k] : 0;
            cnts[sm]++;
        }
        return res;
    }
};

int main()
{
    Solution s;
    vector<int> n1 = {1, 1, 1};
    vector<int> n2 = {1, 2, 3};
    vector<int> n3 = {1, -1, 1, -1};
    cout << s.subarraySum(n1, 2) << endl; // 2
    cout << s.subarraySum(n2, 3) << endl; // 2
    cout << s.subarraySum(n3, 0) << endl; // 4
    return 0;
}
