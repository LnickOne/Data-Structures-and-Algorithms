/* 题目难度: 中等
[原题链接](https://leetcode.cn/problems/skFtm2/)
题目描述
给定只包含整数的有序数组 nums, 每个元素出现两次, 唯有一个数只出现一次, 找出这个数。
题目样例
示例1
- 输入: nums = [1,1,2,3,3,4,4,8,8]
- 输出: 2
示例2
- 输入: nums = [3,3,7,7,10,11,11]
- 输出: 10
题目思考
1. 如何优化时间复杂度?
解决方案
思路
- 二分查找: 对中点 m 比较与左右邻居的关系和下标奇偶性
- 若 nums[m]==nums[m+1]: 偶数下标时向右查找, 奇数下标时向左查找
- 若 nums[m]==nums[m-1]: 偶数下标时向左查找, 奇数下标时向右查找
- 否则 m 就是单一元素
复杂度
- 时间复杂度 O(logN): 二分查找
- 空间复杂度 O(1): 只使用了几个常数空间的变量
 */
#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    int singleNonDuplicate(vector<int> &nums)
    {
        int n = nums.size(), s = 0, e = n - 1;
        while (s <= e)
        {
            int m = (s + e) / 2;
            if (m + 1 < n && nums[m] == nums[m + 1])
            {
                if (m % 2 == 0) s = m + 1;
                else e = m - 1;
            }
            else if (m - 1 >= 0 && nums[m] == nums[m - 1])
            {
                if (m % 2 == 0) e = m - 1;
                else s = m + 1;
            }
            else return nums[m];
        }
        return -1;
    }
};

int main()
{
    Solution sol;
    vector<int> n1 = {1, 1, 2, 3, 3, 4, 4, 8, 8};
    cout << sol.singleNonDuplicate(n1) << endl; // 2
    vector<int> n2 = {3, 3, 7, 7, 10, 11, 11};
    cout << sol.singleNonDuplicate(n2) << endl; // 10
    return 0;
}
