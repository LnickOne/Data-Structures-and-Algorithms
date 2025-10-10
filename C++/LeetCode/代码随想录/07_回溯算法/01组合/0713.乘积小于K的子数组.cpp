#include <vector>
#include <iostream>
#include <numeric>
using namespace std;
/*
给你一个整数数组 nums 和一个整数 k ，请你返回子数组内所有元素的乘积严格小于 k 的连续子数组的数目。
示例 1：
输入：nums = [10,5,2,6], k = 100
输出：8
解释：8 个乘积小于 100 的子数组分别为：[10]、[5]、[2]、[6]、[10,5]、[5,2]、[2,6]、[5,2,6]。
需要注意的是 [10,5,2] 并不是乘积小于 100 的子数组。
示例 2：
输入：nums = [1,2,3], k = 0
输出：0
 */
class Solution
{
public:
    int numSubarraytotalLessThanK(vector<int> &nums, int k)
    {
        if (nums.size() == 0)
            return 0;
        vector<vector<int>> result;
        vector<int> path;
        for (int i = 0; i < nums.size(); ++i)
        {
            backtracking(i, 1, nums, k, path, result);
        }
        // for (int i = 0; i < result.size(); ++i)
        // {
        //     for (int j = 0; j < result[i].size(); ++j)
        //     {
        //         cout << result[i][j] << " ";
        //     }
        //     cout << endl;
        // }
        return result.size();
    }
    void backtracking(int start, int total, vector<int> &nums, const int &k, vector<int> &path, vector<vector<int>> &result)
    {
        if (start >= nums.size())
            return;
        total *= nums[start];
        if (total < k)
        {
            path.push_back(nums[start]);
            result.push_back(path);
            backtracking(start + 1, total, nums, k, path, result);
            path.pop_back();
        }
    }
};
int main()
{
    Solution s;
    vector<int> nums = {10, 5, 2, 6};
    int k = 100;
    int result = s.numSubarraytotalLessThanK(nums, k);
    cout << result << endl;
    return 0;
}