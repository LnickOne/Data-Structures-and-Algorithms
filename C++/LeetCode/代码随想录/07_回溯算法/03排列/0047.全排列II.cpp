/*
给定一个可包含重复数字的序列 nums ，按任意顺序 返回所有不重复的全排列。
示例 1：
输入：nums = [1,1,2]
输出：
[[1,1,2],
 [1,2,1],
 [2,1,1]]
示例 2：
输入：nums = [1,2,3]
输出：[[1,2,3],[1,3,2],[2,1,3],[2,3,1],[3,1,2],[3,2,1]]
*/
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
class Solution
{
public:
    vector<vector<int>> permuteUnique(vector<int> &nums)
    {
        sort(nums.begin(), nums.end());
        vector<vector<int>> result;
        vector<int> path;
        vector<bool> used(nums.size());
        backtracking(0, used, nums, path, result);
        return result;
    }
    void backtracking(int start, vector<bool> &used, vector<int> &nums, vector<int> &path, vector<vector<int>> &result)
    {
        if (path.size() == nums.size())
        {
            result.push_back(path);
            return;
        }
        for (int i = start; i < nums.size(); i++)
        {
            if (used[i] == true) //  树枝去重，used[i - 1] == true，说明同一树枝nums[i - 1]使用过used[i - 1] == true，说明同一树枝nums[i - 1]使用过
                continue;
            if (i > 0 && nums[i] == nums[i - 1] && used[i - 1] == false) // 树层去重
                continue;
            used[i] = true;
            path.push_back(nums[i]);
            backtracking(0, used, nums, path, result);
            path.pop_back();
            used[i] = false;
        }
    }
};

int main()
{
    vector<int> nums = {1, 2, 3};
    vector<int> nums2 = {1, 1, 2};
    Solution s;
    vector<vector<int>> result = s.permuteUnique(nums2);
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