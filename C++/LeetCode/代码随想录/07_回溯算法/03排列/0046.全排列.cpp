/*
给定一个不含重复数字的数组 nums ，返回其 所有可能的全排列 。你可以 按任意顺序 返回答案。
示例 1：
输入：nums = [1,2,3]
输出：[[1,2,3],[1,3,2],[2,1,3],[2,3,1],[3,1,2],[3,2,1]]
示例 2：
输入：nums = [0,1]
输出：[[0,1],[1,0]]
示例 3：
输入：nums = [1]
输出：[[1]]
*/
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
class Solution
{
public:
    vector<vector<int>> permute(vector<int> &nums)
    {
        vector<vector<int>> result;
        vector<int> path;
        vector<bool> used(nums.size());
        backtracking(0, nums, used, path, result);
        return result;
    }
    void backtracking(int start, vector<int> &nums, vector<bool> used, vector<int> &path, vector<vector<int>> &result)
    {
        if (path.size() == nums.size())
        {
            result.push_back(path);
            return;
        }
        for (int i = 0; i < nums.size(); ++i)
        {
            if (used[i] == true) // 树枝上的元素不能重复使用，如果不用树枝去重，就会出现相同元素的排列
                continue;        // 比如[1,2,3] 出现[111],[112],[113],[121],[122],[123]等，这样就会出现重复的排列
            used[i] = true;      // 题目要求是不含重复数字的排列，所以需要树枝去重
            path.push_back(nums[i]);
            backtracking(0, nums, used, path, result);
            path.pop_back();
            used[i] = false;
        }
    }
};

int main()
{
    Solution s;
    vector<int> nums = {1, 2, 3};
    vector<vector<int>> result = s.permute(nums);
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