/* 题目难度: 中等
[原题链接](https://leetcode.cn/problems/4sjJUc/)
题目描述
给定一个可能有重复数字的整数数组 candidates 和目标数 target, 找出所有可以使数字和为 target 的组合。candidates 中每个数字在每个组合中只能使用一次, 解集不含重复组合。
题目样例
示例1
- 输入: candidates=[10,1,2,7,6,1,5], target=8
- 输出: [[1,1,6],[1,2,5],[1,7],[2,6]]
示例2
- 输入: candidates=[2,5,2,1,2], target=5
- 输出: [[1,2,2],[5]]
题目思考
1. 如何避免重复组合?
解决方案
思路
- 将相同数字聚合为计数字典, 对每个唯一 key 选取 0~cnt 个, 避免因位置不同导致重复
- DFS: 对第 i 个 key 尝试选 0..cnts[i] 次, 然后递归到 i+1
复杂度
- 时间复杂度 O(2^N): 每个数字选或不选
- 空间复杂度 O(N): 递归栈
 */
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution
{
    vector<vector<int>> res;
    vector<int> cur;
    void dfs(vector<pair<int,int>> &kc, int i, int sm, int target)
    {
        if (sm == target) { res.push_back(cur); return; }
        if (i >= (int)kc.size() || sm > target) return;
        for (int cnt = 0; cnt <= kc[i].second; cnt++)
        {
            dfs(kc, i + 1, sm + cnt * kc[i].first, target);
            if (cnt < kc[i].second) cur.push_back(kc[i].first);
        }
        for (int cnt = 0; cnt < kc[i].second; cnt++) cur.pop_back();
    }
public:
    vector<vector<int>> combinationSum2(vector<int> &candidates, int target)
    {
        res.clear(); cur.clear();
        sort(candidates.begin(), candidates.end());
        vector<pair<int,int>> kc;
        for (int x : candidates)
        {
            if (kc.empty() || kc.back().first != x) kc.push_back({x, 1});
            else kc.back().second++;
        }
        dfs(kc, 0, 0, target);
        return res;
    }
};

int main()
{
    Solution sol;
    vector<int> c1 = {10, 1, 2, 7, 6, 1, 5};
    auto r1 = sol.combinationSum2(c1, 8);
    for (auto &v : r1) { cout << "["; for (int x : v) cout << x << ","; cout << "] "; }
    cout << endl; // [1,1,6] [1,2,5] [1,7] [2,6]
    vector<int> c2 = {2, 5, 2, 1, 2};
    auto r2 = sol.combinationSum2(c2, 5);
    for (auto &v : r2) { cout << "["; for (int x : v) cout << x << ","; cout << "] "; }
    cout << endl; // [1,2,2] [5]
    return 0;
}
