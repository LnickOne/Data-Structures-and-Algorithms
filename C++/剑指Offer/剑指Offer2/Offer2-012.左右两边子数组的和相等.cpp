/* 题目难度: 简单
[原题链接](https://leetcode.cn/problems/tvdfij/)
题目描述
给你一个整数数组 nums, 请计算数组的中心下标。
中心下标是某个下标, 其左侧所有元素之和等于右侧所有元素之和。
最左端时左侧和视为 0, 最右端时右侧和视为 0。
若有多个中心下标返回最靠左的; 若不存在返回 -1。
题目样例
示例1
- 输入: nums = [1,7,3,6,5,6]
- 输出: 3
示例2
- 输入: nums = [1,2,3]
- 输出: -1
示例3
- 输入: nums = [2,1,-1]
- 输出: 0
题目思考
1. 如何优化时间和空间复杂度?
解决方案
思路
- 中心下标 i 满足: 左侧前缀和 == 右侧后缀和
- 初始化左侧和 lsm=0, 右侧和 rsm=整个数组之和
- 正向遍历: 先将 rsm 减去当前元素 (此时 rsm 是 i 右侧的和), 若 lsm==rsm 则找到答案
- 否则将当前元素加到 lsm 继续遍历
- 一次遍历即可, 空间 O(1)
复杂度
- 时间复杂度 O(N): 只需遍历数组一遍
- 空间复杂度 O(1): 只使用了几个常数空间的变量
 */
#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    int pivotIndex(vector<int> &nums)
    {
        int lsm = 0, rsm = 0;
        for (int x : nums) rsm += x;
        for (int i = 0; i < (int)nums.size(); i++)
        {
            rsm -= nums[i];
            if (lsm == rsm) return i;
            lsm += nums[i];
        }
        return -1;
    }
};

int main()
{
    Solution s;
    vector<int> n1 = {1, 7, 3, 6, 5, 6};
    vector<int> n2 = {1, 2, 3};
    vector<int> n3 = {2, 1, -1};
    cout << s.pivotIndex(n1) << endl; // 3
    cout << s.pivotIndex(n2) << endl; // -1
    cout << s.pivotIndex(n3) << endl; // 0
    return 0;
}
