#include <iostream>
#include <vector>
using namespace std;
/*
给你一个整数数组 nums ，数组中的元素 互不相同 。返回该数组所有可能的
子集（幂集）。
解集 不能 包含重复的子集。你可以按 任意顺序 返回解集。
示例 1：
输入：nums = [1,2,3]
输出：[[],[1],[2],[1,2],[3],[1,3],[2,3],[1,2,3]]
示例 2：
输入：nums = [0]
输出：[[],[0]]
*/
class Solution
{
public:
    vector<vector<int>> subsets(vector<int> &nums)
    {
        vector<vector<int>> result;
        vector<int> path;
        backtracking(0, nums, path, result);
        return result;
    }
    void backtracking(int start, vector<int> &nums, vector<int> &path, vector<vector<int>> &result)
    {
        result.push_back(path);
        for (int i = start; i < nums.size(); i++)
        {
            path.push_back(nums[i]);
            backtracking(i + 1, nums, path, result);
            path.pop_back();
        }
    }
};
int main()
{
    vector<int> num = {1, 2, 3};
    Solution s;
    vector<vector<int>> result = s.subsets(num);
    // 打印数组元素
    for (int i = 0; i < result.size(); ++i)
    {
        for (int j = 0; j < result[i].size(); ++j)
        {
            // 打印元素，并在每个元素后面加上一个空格
            cout << result[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}