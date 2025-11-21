/*
给你一个整数数组 nums ，其中可能包含重复元素，请你返回该数组所有可能的子集（幂集）。
解集 不能 包含重复的子集。返回的解集中，子集可以按 任意顺序 排列。
示例 1：
输入：nums = [1,2,2]
输出：[[],[1],[1,2],[1,2,2],[2],[2,2]]
示例 2：
输入：nums = [0]
输出：[[],[0]]
*/
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
class Solution
{
public:
    vector<vector<int>> subsetsWithDup(vector<int> &nums)
    {
        sort(nums.begin(), nums.end()); // 排序将相同元素相邻好进行树层去重
        vector<vector<int>> result;
        vector<int> path;
        vector<bool> used(nums.size(), false);
        backtracking(0, used, nums, path, result);
        return result;
    }

    void backtracking(int start, vector<bool> used, vector<int> &nums, vector<int> &path, vector<vector<int>> &result)
    {
        result.push_back(path);
        for (int i = start; i < nums.size(); i++)
        {
            if (i >= 1 && nums[i] == nums[i - 1] && used[i - 1] == false)
                continue;
            used[i] = true;
            path.push_back(nums[i]);
            backtracking(i + 1, used, nums, path, result);
            path.pop_back();
            used[i] = false;
        }
    }
};
int main()
{
    vector<int> num = {1, 2, 2};
    Solution s;
    vector<vector<int>> result = s.subsetsWithDup(num);
    for (auto i : result)
    {
        cout << "[";
        for (auto j : i)
        {
            cout << j;
        }
        cout << "]" << endl;
    }
    return 0;
}