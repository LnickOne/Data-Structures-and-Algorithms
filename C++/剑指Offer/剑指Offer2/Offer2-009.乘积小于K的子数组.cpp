/* 题目难度: 中等
[原题链接](https://leetcode.cn/problems/ZVAVXX/)
题目描述
给定一个正整数数组 nums 和整数 k, 请找出该数组内乘积小于 k 的连续子数组的个数。
题目样例
示例1
- 输入: nums = [10,5,2,6], k = 100
- 输出: 8
- 解释: 8 个乘积小于 100 的子数组: [10],[5],[2],[6],[10,5],[5,2],[2,6],[5,2,6]
示例2
- 输入: nums = [1,2,3], k = 0
- 输出: 0
题目思考
1. 如何尽可能优化时间复杂度?
解决方案
思路
- 暴力两重循环 O(N^2), 效率较低
- 利用所有元素是正整数: [i+1,j] 的乘积可由 [i,j] 直接除以 nums[i] 得到
- 滑动窗口: 固定终点 j, 起点 i 在窗口乘积 >= k 时不断右移
- [i,j] 窗口内以 j 为终点的子数组共 j-i+1 个, 全部乘积小于 k, 累加到结果
- 注意 i 可能移动到 j+1, 此时窗口长度为 0 (即不存在以 j 为终点的有效子数组)
复杂度
- 时间复杂度 O(N): 最多遍历数组每个元素两遍
- 空间复杂度 O(1): 只使用了几个常数空间的变量
 */
#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    int numSubarrayProductLessThanK(vector<int> &nums, int k)
    {
        int res = 0, cur = 1, i = 0;
        for (int j = 0; j < (int)nums.size(); j++)
        {
            cur *= nums[j];
            while (i <= j && cur >= k)
                cur /= nums[i++];
            res += j - i + 1;
        }
        return res;
    }
};

int main()
{
    Solution s;
    vector<int> n1 = {10, 5, 2, 6};
    vector<int> n2 = {1, 2, 3};
    vector<int> n3 = {10, 9, 10, 4, 3, 8, 3, 3, 6, 2};
    cout << s.numSubarrayProductLessThanK(n1, 100) << endl; // 8
    cout << s.numSubarrayProductLessThanK(n2, 0) << endl;   // 0
    cout << s.numSubarrayProductLessThanK(n3, 19) << endl;  // 18
    return 0;
}
