/* 题目难度: 中等
[原题链接](https://leetcode.cn/problems/2VG8Kg/)
题目描述
给定一个含有 n 个正整数的数组和一个正整数 target。
找出该数组中满足其和 >= target 的长度最小的连续子数组, 并返回其长度。若不存在则返回 0。
题目样例
示例1
- 输入: target = 7, nums = [2,3,1,2,4,3]
- 输出: 2
- 解释: 子数组 [4,3] 是满足条件下的最短子数组
示例2
- 输入: target = 4, nums = [1,4,4]
- 输出: 1
示例3
- 输入: target = 11, nums = [1,1,1,1,1,1,1,1]
- 输出: 0
题目思考
1. 题目要求『连续子数组』, 如何利用这一条件?
2. 如何设计 O(NlogN) 时间复杂度的解法?
解决方案
方案1
思路
- 固定终点 j 向右扩张, 起点 i 在窗口和 >= target 时不断右移并更新最短长度
- 因为 [i+1,j] 的和可以从 [i,j] 直接减去 nums[i] 得到, 无需重新遍历
- 滑动窗口: 起点和终点各遍历一次, 时间 O(N)
复杂度
- 时间复杂度 O(N): 最多遍历数组每个元素两遍
- 空间复杂度 O(1): 只使用了几个常数空间的变量
方案2
思路
- 利用所有数字都是正整数, 前缀和数组严格递增, 可用二分查找
- 对每个 j 维护前缀和 sm, 右二分查找 sm-target 在前缀和数组中的插入位置 i
- sms[i-1] <= sm-target 即 sms[j]-sms[i-1] >= target, 区间 [i,j] 是以 j 为终点的最短子数组
复杂度
- 时间复杂度 O(NlogN): 遍历 O(N), 二分 O(logN)
- 空间复杂度 O(N): 需要存储前缀和数组
 */
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution
{
public:
    // 方案1: 滑动窗口
    int minSubArrayLen(int target, vector<int> &nums)
    {
        int n = nums.size(), i = 0, sm = 0, res = n + 1;
        for (int j = 0; j < n; j++)
        {
            sm += nums[j];
            while (sm >= target)
            {
                res = min(res, j - i + 1);
                sm -= nums[i++];
            }
        }
        return res == n + 1 ? 0 : res;
    }
    // 方案2: 前缀和+二分
    int minSubArrayLen2(int target, vector<int> &nums)
    {
        int n = nums.size(), sm = 0, res = n + 1;
        vector<int> sms;
        for (int j = 0; j < n; j++)
        {
            sm += nums[j];
            sms.push_back(sm);
            if (sm >= target)
            {
                // upper_bound 等价于 Python bisect_right
                int i = upper_bound(sms.begin(), sms.end(), sm - target) - sms.begin();
                res = min(res, j - i + 1);
            }
        }
        return res == n + 1 ? 0 : res;
    }
};

int main()
{
    Solution s;
    vector<int> n1 = {2, 3, 1, 2, 4, 3};
    vector<int> n2 = {1, 4, 4};
    vector<int> n3 = {1, 1, 1, 1, 1, 1, 1, 1};
    cout << s.minSubArrayLen(7, n1) << endl;  // 2
    cout << s.minSubArrayLen(4, n2) << endl;  // 1
    cout << s.minSubArrayLen(11, n3) << endl; // 0
    cout << s.minSubArrayLen2(7, n1) << endl;  // 2
    cout << s.minSubArrayLen2(4, n2) << endl;  // 1
    cout << s.minSubArrayLen2(11, n3) << endl; // 0
    return 0;
}
