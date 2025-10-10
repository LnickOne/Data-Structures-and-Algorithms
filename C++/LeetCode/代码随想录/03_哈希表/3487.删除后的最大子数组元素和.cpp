/*
给你一个整数数组 nums 。
你可以从数组 nums 中删除任意数量的元素，但不能将其变为 空 数组。
执行删除操作后，选出 nums 中满足下述条件的一个子数组：

1.子数组中的所有元素互不相同。
2.最大化子数组的元素和。
3.返回子数组的最大元素和 。
子数组 是数组的一个连续、非空 的元素序列。
示例 1：
输入：nums = [1,2,3,4,5]
输出：15
解释：
不删除任何元素，选中整个数组得到最大元素和。
示例 2：
输入：nums = [1,1,0,1,1]
输出：1
解释：
删除元素 nums[0] == 1、nums[1] == 1、nums[2] == 0 和 nums[3] == 1 。选中整个数组 [1] 得到最大元素和。
示例 3：
输入：nums = [1,2,-1,-2,1,0,-1]
输出：3
解释：
删除元素 nums[2] == -1 和 nums[3] == -2 ，从 [1, 2, 1, 0, -1] 中选中子数组 [2, 1] 以获得最大元素和。

提示：
1 <= nums.length <= 100
-100 <= nums[i] <= 100
*/
#include <iostream>
#include <vector>
#include <unordered_set>
#include <algorithm>
#include <numeric>
using namespace std;
class Solution
{
public:
    int maxSum(vector<int> &nums)
    {
        unordered_set<int> positiveNumsSet;
        for (int num : nums)
        {
            if (num > 0)
            {
                positiveNumsSet.emplace(num);
            }
        }
        if (positiveNumsSet.empty())
        {
            return *max_element(nums.begin(), nums.end());
        }
        return accumulate(positiveNumsSet.begin(), positiveNumsSet.end(), 0);
    }
};

int main()
{
    Solution s;
    vector<int> nums1 = {1, 2, 3, 4, 5};
    vector<int> nums2 = {1, 1, 0, 1, 1};
    vector<int> nums3 = {1, 2, -1, -2, 1, 0, -1};
    vector<int> nums4 = {-20, 20};
    vector<int> nums5 = {-17, -15};
    cout << s.maxSum(nums1) << endl;
    cout << s.maxSum(nums2) << endl;
    cout << s.maxSum(nums3) << endl;
    cout << s.maxSum(nums4) << endl;
    cout << s.maxSum(nums5) << endl;
    return 0;
}