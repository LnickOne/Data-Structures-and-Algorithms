/* 题目难度: 中等
[原题链接](https://leetcode.cn/problems/Ygoe9J/)
题目描述
给定一个无重复元素的正整数数组 candidates 和一个正整数 target, 找出 candidates 中所有可以使数字和为 target 的唯一组合。candidates 中的数字可以无限制重复被选取。
题目样例
示例1
- 输入: candidates=[2,3,6,7], target=7
- 输出: [[7],[2,2,3]]
示例2
- 输入: candidates=[2,3,5], target=8
- 输出: [[2,2,2,2],[2,3,3],[3,5]]
题目思考
1. 如何用两分支 DFS 避免重复?
解决方案
思路
- 回溯 DFS: 对 candidates[i], 两种分支: 选取 (留在 i) 或不选 (移到 i+1)
- 剪枝: 当前和 > target 或下标越界时直接返回
复杂度
- 时间复杂度 O(2^M): M = sum(ceil(target/c)), 每步两种可能
- 空间复杂度 O(M): 递归栈和当前组合
 */
#include <iostream>
#include <vector>
using namespace std;

class Solution
{
    vector<vector<int>> res;
    vector<int> cur;
    void dfs(vector<int> &candidates, int i, int sm, int target)
    {
        if (sm == target)
        {
            res.push_back(cur);
            return;
        }
        if (i >= (int)candidates.size() || sm > target)
            return;
        cur.push_back(candidates[i]);
        dfs(candidates, i, sm + candidates[i], target);
        cur.pop_back();
        dfs(candidates, i + 1, sm, target);
    }

public:
    vector<vector<int>> combinationSum(vector<int> &candidates, int target)
    {
        res.clear();
        cur.clear();
        dfs(candidates, 0, 0, target);
        return res;
    }
};

int main()
{
    Solution sol;
    vector<int> c1 = {2, 3, 6, 7};
    auto r1 = sol.combinationSum(c1, 7);
    for (auto &v : r1)
    {
        cout << "[";
        for (int x : v)
            cout << x << ",";
        cout << "] ";
    }
    cout << endl; // [7] [2,2,3]
    vector<int> c2 = {2, 3, 5};
    auto r2 = sol.combinationSum(c2, 8);
    for (auto &v : r2)
    {
        cout << "[";
        for (int x : v)
            cout << x << ",";
        cout << "] ";
    }
    cout << endl; // [2,2,2,2] [2,3,3] [3,5]
    return 0;
}
