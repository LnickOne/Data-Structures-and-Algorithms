/* 题目难度: 中等
[原题链接](https://leetcode.cn/problems/VvJkup/)
题目描述
给定一个不含重复数字的整数数组 nums, 返回其所有可能的全排列。
题目样例
示例1
- 输入: nums=[1,2,3]
- 输出: [[1,2,3],[1,3,2],[2,1,3],[2,3,1],[3,1,2],[3,2,1]]
示例2
- 输入: nums=[0,1]
- 输出: [[0,1],[1,0]]
题目思考
1. 如果限制只能用递归或者迭代, 如何解决?
解决方案
思路
- 回溯 DFS: 维护 used 数组, 每次从未使用的数字中选取一个加入当前排列
- 当排列长度等于 nums.size() 时记录结果
复杂度
- 时间复杂度 O(N*N!): 共 N! 个排列, 每个构建需要 O(N)
- 空间复杂度 O(N): 递归栈和 used 数组
 */
#include <iostream>
#include <vector>
using namespace std;

class Solution
{
    vector<vector<int>> res;
    vector<int> cur;
    void dfs(vector<int> &nums, vector<bool> &used)
    {
        if ((int)cur.size() == (int)nums.size()) { res.push_back(cur); return; }
        for (int i = 0; i < (int)nums.size(); i++)
        {
            if (!used[i])
            {
                used[i] = true;
                cur.push_back(nums[i]);
                dfs(nums, used);
                cur.pop_back();
                used[i] = false;
            }
        }
    }
public:
    vector<vector<int>> permute(vector<int> &nums)
    {
        res.clear(); cur.clear();
        vector<bool> used(nums.size(), false);
        dfs(nums, used);
        return res;
    }
};

int main()
{
    Solution sol;
    vector<int> n1 = {1, 2, 3};
    auto r1 = sol.permute(n1);
    for (auto &v : r1) { cout << "["; for (int i = 0; i < (int)v.size(); i++) { if (i) cout << ","; cout << v[i]; } cout << "] "; }
    cout << endl; // 6 个排列
    vector<int> n2 = {0, 1};
    auto r2 = sol.permute(n2);
    for (auto &v : r2) { cout << "["; for (int i = 0; i < (int)v.size(); i++) { if (i) cout << ","; cout << v[i]; } cout << "] "; }
    cout << endl; // [0,1] [1,0]
    return 0;
}
