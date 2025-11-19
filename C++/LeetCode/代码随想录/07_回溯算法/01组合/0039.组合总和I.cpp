/*
给你一个 无重复元素 的整数数组 candidates 和一个目标整数 target ，
找出 candidates 中可以使数字和为目标数 target 的 所有 不同组合 ，并以列表形式返回。
你可以按 任意顺序 返回这些组合。
candidates 中的 同一个 数字可以 无限制重复被选取 。
如果至少一个数字的被选数量不同，则两种组合是不同的。
对于给定的输入，保证和为 target 的不同组合数少于 150 个。
示例 1：
输入：candidates = [2,3,6,7], target = 7
输出：[[2,2,3],[7]]
解释：
2 和 3 可以形成一组候选，2 + 2 + 3 = 7 。注意 2 可以使用多次。
7 也是一个候选， 7 = 7 。
仅有这两种组合。
示例 2：
输入: candidates = [2,3,5], target = 8
输出: [[2,2,2,2],[2,3,3],[3,5]]
示例 3：
输入: candidates = [2], target = 1
输出: []
*/
#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>
using namespace std;
class Solution
{
public:
    vector<vector<int>> combinationSum(const vector<int> &candidates, const int &target)
    {
        if (candidates.empty())
            return {};
        vector<vector<int>> result;
        vector<int> path;
        backtracking(0, candidates, target, path, result);
        return result;
    }

    void backtracking(const int &start, const vector<int> &candidates, const int &target, vector<int> &path, vector<vector<int>> &result)
    {
        if (accumulate(path.begin(), path.end(), 0) > target)
            return;
        if (accumulate(path.begin(), path.end(), 0) == target)
        {
            result.push_back(path);
            return;
        }
        for (int i = start; i < candidates.size(); i += 1) // 当前取的是i，进入下一层递归的搜索起点是i，而不是i+1，因为可以重复取同一元素
        {
            path.push_back(candidates[i]);
            backtracking(i, candidates, target, path, result);
            path.pop_back();
        }
    }
};

int main()
{
    // vector<int> candidates = {2, 3, 6, 7};
    vector<int> candidates = {2, 3, 5};
    // int target = 7;
    int target = 8;
    Solution s;
    vector<vector<int>> result = s.combinationSum(candidates, target);
    for (auto i : result)
    {
        for (auto j : i)
        {
            cout << j << " ";
        }
        cout << endl;
    }
}