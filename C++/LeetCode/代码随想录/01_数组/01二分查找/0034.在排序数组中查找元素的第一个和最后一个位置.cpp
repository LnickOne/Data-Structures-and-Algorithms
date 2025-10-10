/*
给你一个按照非递减顺序排列的整数数组 nums，和一个目标值 target。
请你找出给定目标值在数组中的开始位置和结束位置。
如果数组中不存在目标值 target，返回 [-1, -1]。
你必须设计并实现时间复杂度为 O(log n) 的算法解决此问题。
示例 1：
输入：nums = [5,7,7,8,8,10], target = 8
输出：[3,4]
示例 2：
输入：nums = [5,7,7,8,8,10], target = 6
输出：[-1,-1]
示例 3：
输入：nums = [], target = 0
输出：[-1,-1]
*/
#include <vector>
#include <iostream>
using namespace std;
class Solution
{
public:
    // 方法一
    vector<int> searchRange(const vector<int> &nums, int target)
    {
        int left = Left(nums, target);
        int right = Right(nums, target);
        return {left, right};
    }
    int Left(const vector<int> &nums, int target)
    {
        // 寻找元素第一次出现的地方
        int left = 0;
        int right = nums.size() - 1;
        while (left <= right)
        {
            int mid = left + (right - left) / 2;
            if (nums[mid] >= target) // >= 的都要缩小 因为要找第一个元素
                right = mid - 1;
            if (nums[mid] < target)
                left = mid + 1;
        }
        // right = left - 1
        // 如果存在答案 right是首选
        if (right >= 0 && right < nums.size() && nums[right] == target)
            return right;
        if (left >= 0 && left < nums.size() && nums[left] == target)
            return left;
        return -1;
    }
    int Right(const vector<int> &nums, int target)
    {
        // 寻找元素最后一次出现的地方
        int left = 0;
        int right = nums.size() - 1;
        while (left <= right)
        {
            int mid = left + (right - left) / 2;
            if (nums[mid] <= target) // <= 的都要更新 因为我们要找最后一个元素
            {
                left = mid + 1;
            }
            if (nums[mid] > target)
            {
                right = mid - 1;
            }
        }
        // left = right + 1
        // 要找最后一次出现 如果有答案 优先找left
        if (left >= 0 && left < nums.size() && nums[left] == target)
            return left;
        if (right >= 0 && right <= nums.size() && nums[right] == target)
            return right;
        return -1;
    }
    // 方法二:
    vector<int> searchRange_2(const vector<int> &nums, int target)
    {
        if (nums.empty())
            return {-1, -1};
        vector<int> result;
        for (int i = 0; i < nums.size(); i++)
        {
            if (nums[i] > target)
            {
                result.push_back(-1);
                result.push_back(-1);
                return result;
            }
            if (nums[nums.size() - 1] < target)
            {
                result.push_back(-1);
                result.push_back(-1);
                return result;
            }
            if (nums[i] == target)
            {
                result.push_back(i);
                break;
            }
        }
        for (int i = result.front(); i < nums.size(); ++i)
        {
            if (nums[i] == target)
            {
                result.push_back(i);
                break;
            }
            if (i == nums.size() - 1)
            {
                result.push_back(i);
            }
        }
        return result;
    }
};

int main()
{
    vector<int> nums_1 = {5, 7, 7, 8, 8, 10};
    vector<int> nums_2 = {5, 7, 7, 8, 8, 10};
    vector<int> nums_3 = {1};
    int target_1 = 8;
    int target_2 = 6;
    int target_3 = 0;
    Solution s;
    vector<int> result_1 = s.searchRange(nums_1, target_1);
    vector<int> result_2 = s.searchRange(nums_2, target_2);
    vector<int> result_3 = s.searchRange(nums_3, target_3);
    for (auto &i : result_1)
        cout << i << " ";
    cout << endl;
    for (auto &i : result_2)
        cout << i << " ";
    cout << endl;
    for (auto &i : result_3)
        cout << i << " ";
    cout << endl;
    return 0;
}