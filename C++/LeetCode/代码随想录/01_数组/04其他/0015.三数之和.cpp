/*
给你一个整数数组 nums ，
判断是否存在三元组 [nums[i], nums[j], nums[k]]
满足 i != j、i != k 且 j != k ，同时还满足 nums[i] + nums[j] + nums[k] == 0 。
请你返回所有和为 0 且不重复的三元组。
注意：答案中不可以包含重复的三元组。
示例 1：
输入：nums = [-1,0,1,2,-1,-4]
输出：[[-1,-1,2],[-1,0,1]]
解释：
nums[0] + nums[1] + nums[2] = (-1) + 0 + 1 = 0 。
nums[1] + nums[2] + nums[4] = 0 + 1 + (-1) = 0 。
nums[0] + nums[3] + nums[4] = (-1) + 2 + (-1) = 0 。
不同的三元组是 [-1,0,1] 和 [-1,-1,2] 。
注意，输出的顺序和三元组的顺序并不重要。
示例 2：
输入：nums = [0,1,1]
输出：[]
解释：唯一可能的三元组和不为 0 。
示例 3：
输入：nums = [0,0,0]
输出：[[0,0,0]]
解释：唯一可能的三元组和为 0 。
*/
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;
class Solution
{
public:
    vector<vector<int>> threeSum(vector<int> &nums)
    {
        sort(nums.begin(), nums.end());
        vector<vector<int>> result;
        vector<int> path;
        for (int i = 0; i < nums.size(); ++i)
        {
            if (i > 0 && nums[i] == nums[i - 1])
                continue;
            int left = i + 1;
            int right = nums.size() - 1;
            while (left < right)
            {
                int sum = nums[i] + nums[left] + nums[right];
                if (sum < 0)
                    left += 1;
                else if (sum > 0)
                    right -= 1;
                else if (sum == 0)
                {
                    path = {nums[i], nums[left], nums[right]};
                    result.push_back(path);
                    path.clear();
                    // 取到第一个结果后 继续对b和c去重 防止取到相同的元组结果
                    while (left < right && nums[left] == nums[left + 1]) // 用left指针和他前一个指针做对比，即对元素b去重
                        left += 1;
                    while (left < right && nums[right] == nums[right - 1]) // 用right指针和他前一个指针做对比，即对元素c去重
                        right -= 1;
                    // 找到答案后，双指针同时收缩
                    left += 1;
                    right -= 1;
                }
            }
        }
        return result;
    }
};

int main()
{
    vector<int> nums = {-1, 0, 1, 2, -1, -4};
    vector<int> nums1 = {0, 1, -1};
    Solution s;
    vector<vector<int>> result = s.threeSum(nums);
    for (const auto &iter : result)
    {
        for (const auto &j : iter)
        {
            cout << j << " ";
        }
        cout << endl;
    }
    return 0;
}