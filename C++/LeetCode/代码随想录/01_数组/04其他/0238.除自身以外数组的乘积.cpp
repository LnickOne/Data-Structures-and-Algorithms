
/*
给你一个整数数组 nums，返回 数组 answer ，其中 answer[i] 等于 nums 中除 nums[i] 之外其余各元素的乘积 。
题目数据 保证 数组 nums之中任意元素的全部前缀元素和后缀的乘积都在  32 位 整数范围内。
请 不要使用除法，且在 O(n) 时间复杂度内完成此题。
示例 1:
输入: nums = [1,2,3,4]
输出: [24,12,8,6]
示例 2:
输入: nums = [-1,1,0,-3,3]
输出: [0,0,9,0,0]
*/
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;
class Solution
{
public:
    vector<int> productExceptSelf(vector<int> &nums)
    {
        // 思路：从左向右求前缀积, 再从右向左求积, 两个积再求积, 即得到结果
        int n = nums.size();
        vector<int> result(n);
        result[0] = 1;
        for (int i = 1; i < n; ++i)
        {
            result[i] = result[i - 1] * nums[i - 1];
        }
        int R = 1;
        for (int i = n - 1; i >= 0; --i)
        {
            result[i] = result[i] * R;
            R *= nums[i];
        }
        return result;
    }
};

int main()
{
    vector<int> nums = {1, 2, 3, 4};
    Solution s;
    vector<int> result = s.productExceptSelf(nums);
    for (auto &i : result)
    {
        cout << i << " ";
    }
    cout << endl;
    return 0;
}