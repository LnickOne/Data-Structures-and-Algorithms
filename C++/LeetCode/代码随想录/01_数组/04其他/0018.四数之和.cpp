/*
给你一个由 n 个整数组成的数组 nums ，和一个目标值 target 。
请你找出并返回满足下述全部条件且不重复的四元组 [nums[a], nums[b], nums[c], nums[d]]
（若两个四元组元素一一对应，则认为两个四元组重复）：
0 <= a, b, c, d < n
a、b、c 和 d 互不相同
nums[a] + nums[b] + nums[c] + nums[d] == target
你可以按 任意顺序 返回答案 。
示例 1：
输入：nums = [1,0,-1,0,-2,2], target = 0
输出：[[-2,-1,1,2],[-2,0,0,2],[-1,0,0,1]]
示例 2：
输入：nums = [2,2,2,2,2], target = 8
输出：[[2,2,2,2]]
*/
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;
class Solution
{
public:
    vector<vector<int>> fourSum(vector<int> &nums, int target)
    {
        sort(nums.begin(), nums.end());
        vector<vector<int>> result;
        vector<int> path;
        for (int i = 0; i < nums.size(); ++i)
        {
            if (i > 0 && nums[i - 1] == nums[i])
                continue;
            for (int j = i + 1; j < nums.size(); ++j)
            {
                if (j > i + 1 && nums[j - 1] == nums[j])
                    continue;
                int left = j + 1;
                int right = nums.size() - 1;
                while (left < right)
                {
                    long sum = (long)nums[i] + nums[j] + nums[left] + nums[right];
                    if (sum == target)
                    {
                        path = {nums[i], nums[j], nums[left], nums[right]};
                        result.push_back(path);
                        path.clear();
                        while (left < right && nums[left] == nums[left + 1])
                            left++;
                        while (left < right && nums[right] == nums[right - 1])
                            right--;
                        left++;
                        right--;
                    }
                    if (sum > target)
                        right--;
                    if (sum < target)
                        left++;
                }
            }
        }
        return result;
    }
};

int main()
{
    vector<int> nums = {1, 0, -1, 0, -2, 2};
    Solution s;
    vector<vector<int>> result = s.fourSum(nums, 0);
    for (auto i : result)
    {
        for (auto j : i)
        {
            cout << j << " ";
        }
        cout << endl;
    }
    return 0;
}