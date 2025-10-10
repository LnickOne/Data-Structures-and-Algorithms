#include <iostream>
#include <numeric>
#include <vector>
#include <algorithm>
using namespace std;
/*
给定一个整数数组  nums 和一个正整数 k，找出是否有可能把这个数组分成 k 个非空子集，其总和都相等。
示例 1：
输入： nums = [4, 3, 2, 3, 5, 2, 1], k = 4
输出： True
说明： 有可能将其分成 4 个子集（5），（1,4），（2,3），（2,3）等于总和。
示例 2:
输入: nums = [1,2,3,4], k = 3
输出: false
*/

class Solution
{
public:
    bool canPartitionKSubsets(vector<int> &nums, int k)
    {
        int sum = accumulate(nums.begin(), nums.end(), 0);
        if (sum % k != 0)
            return false;
        int target = sum / k;
        sort(nums.rbegin(), nums.rend()); // 降序排序优化剪枝
        vector<vector<int>> result;
        vector<bool> used(nums.size(), false);
        vector<int> path;
        backtracking(0, nums, k, target, used, path, result);
        return result.size() == k;
    }

    void backtracking(int start, vector<int> &nums, int k, int target, vector<bool> &used, vector<int> &path, vector<vector<int>> &result)
    {
        int currentSum = accumulate(path.begin(), path.end(), 0);
        if (currentSum > target) // 若当前子集的和超过目标值，停止当前分支的搜索
            return;
        if (currentSum == target)
        {
            result.push_back(path);
            path.clear();
            if (result.size() == k)
            {
                return;
            }
            // 找到一个子集后，从头开始找下一个子集
            backtracking(0, nums, k, target, used, path, result);
            return;
        }
        for (int i = start; i < nums.size(); ++i)
        {
            if (used[i] == true)
                continue;
            if (currentSum + nums[i] > target)
                continue;
            if (i > 0 && nums[i] == nums[i - 1] && used[i - 1] == false)
                continue;
            path.push_back(nums[i]);
            used[i] = true;
            backtracking(i + 1, nums, k, target, used, path, result);
            used[i] = false;
            path.pop_back();
        }
    }
};