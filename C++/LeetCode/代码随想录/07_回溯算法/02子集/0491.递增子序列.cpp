#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <unordered_set>
using namespace std;
/*
给你一个整数数组 nums ，找出并返回所有该数组中不同的递增子序列，递增子序列中 至少有两个元素 。你可以按 任意顺序 返回答案。
数组中可能含有重复元素，如出现两个整数相等，也可以视作递增序列的一种特殊情况。
示例 1：
输入：nums = [4,6,7,7]
输出：[[4,6],[4,6,7],[4,6,7,7],[4,7],[4,7,7],[6,7],[6,7,7],[7,7]]
示例 2：
输入：nums = [4,4,3,2,1]
输出：[[4,4]]
示例 3：
输入：nums = [4,7,6,7]
输出：[[4,7],[4,7,7],[4,6],[4,6,7],[6,7],[7,7]]
*/
class Solution
{
public:
    vector<vector<int>> findSubsequences(vector<int> &nums)
    {
        // sort(nums.begin(), nums.end());//不可以排序 如果是递增子序列 原来的顺序会被破坏 比如[4,7,6,7]排序会产生4677的递增子序列是不符合的
        if (nums.empty())
            return {};
        vector<vector<int>> result;
        vector<int> path;
        vector<bool> used(nums.size());
        backtracking(0, used, nums, path, result);
        return result;
    }
    void backtracking(int start, vector<bool> used, vector<int> &nums, vector<int> &path, vector<vector<int>> &result)
    {
        if (path.size() >= 2)
        {
            result.push_back(path);
        }
        unordered_set<int> set; // 使用set对本层元素进行去重  比如4677  第一层是4 第二层是46 第三层是467 第四层是4677  第四层的7不能再使用了 因为已经使用过了 所以需要set来记录，而不是用树层去重
        for (int i = start; i < nums.size(); i++)
        {
            // if (i > 0 && nums[i] == nums[i - 1] && used[i - 1] == false) //树层去重 只能针对相邻的相同元素进行去重,比如11231 11是相邻的相同元素，但是后面的1不是相邻的相同元素 所以不能去重
            //     continue;
            if (set.find(nums[i]) != set.end()) // 同一父节点下的同层上使用过的元素就不能再使用了
                continue;
            if (!path.empty() && nums[i] < path.back()) // 递增子序列的条件
                continue;
            used[i] = true;
            set.insert(nums[i]);
            path.push_back(nums[i]);
            backtracking(i + 1, used, nums, path, result);
            path.pop_back();
            used[i] = false;
        }
    }
};

int main()
{
    Solution s;
    //vector<int> nums = {4, 6, 7, 7};
     vector<int> nums = {4,7,6,7};
    vector<vector<int>> result = s.findSubsequences(nums);

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