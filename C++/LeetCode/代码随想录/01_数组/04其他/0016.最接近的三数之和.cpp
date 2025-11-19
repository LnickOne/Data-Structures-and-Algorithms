/*
给你一个长度为 n 的整数数组 nums 和 一个目标值 target。
请你从 nums 中选出三个整数，使它们的和与 target 最接近。
返回这三个数的和。
假定每组输入只存在恰好一个解。
示例 1：
输入：nums = [-1,2,1,-4], target = 1
输出：2
解释：与 target 最接近的和是 2 (-1 + 2 + 1 = 2)。
示例 2：
输入：nums = [0,0,0], target = 1
输出：0
解释：与 target 最接近的和是 0（0 + 0 + 0 = 0）。
*/
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;
class Solution
{
public:
    int threeSumClosest(vector<int> &nums, const int &target)
    {
        sort(nums.begin(), nums.end());
        int diff;
        int sum;
        vector<int> diff_nums;
        unordered_map<int, int> map;
        int result = nums[0] + nums[1] + nums[2];
        for (int i = 0; i < nums.size(); ++i)
        {
            if (i > 0 && nums[i] == nums[i - 1])
                continue;
            int left = i + 1;
            int right = nums.size() - 1;
            while (left < right)
            {
                sum = nums[i] + nums[left] + nums[right];
                diff = abs(sum - target);
                diff_nums.push_back(diff);
                map[diff] = sum;
                if (sum < target)
                    left += 1;
                if (sum > target)
                    right -= 1;
                if (sum == target)
                    return sum;
                result = abs(result - target) < abs(sum - target) ? result : sum;
            }
        }
        // int min_diff = *min_element(diff_nums.begin(), diff_nums.end());
        return result;
    }
};

int main()
{
    vector<int> nums = {-1, 2, 1, -4};
    int target = 1;
    Solution s;
    int result = s.threeSumClosest(nums, target);
    cout << result << endl;
    return 0;
}