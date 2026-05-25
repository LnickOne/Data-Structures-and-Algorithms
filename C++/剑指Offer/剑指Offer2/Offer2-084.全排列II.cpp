/* 题目难度: 中等
[原题链接](https://leetcode.cn/problems/7p8L0Z/)
题目描述
给定一个可包含重复数字的整数集合 nums, 按任意顺序返回所有不重复的全排列。
题目样例
示例1
- 输入: nums=[1,1,2]
- 输出: [[1,1,2],[1,2,1],[2,1,1]]
示例2
- 输入: nums=[1,2,3]
- 输出: [[1,2,3],[1,3,2],[2,1,3],[2,3,1],[3,1,2],[3,2,1]]
题目思考
1. 如何保证结果不重复?
解决方案
思路
- 将数组转为计数字典, 每次从计数 > 0 的 key 中选取, 自动避免重复
- DFS: 遍历所有 key, 计数 > 0 则选取, 递归后恢复计数
复杂度
- 时间复杂度 O(N!): 最差情况 N 个数字各不相同
- 空间复杂度 O(N): 递归栈和计数字典
 */
#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution
{
    vector<vector<int>> res;
    vector<int> cur;
    void dfs(unordered_map<int,int> &cnts, vector<int> &keys, int n)
    {
        if ((int)cur.size() == n) { res.push_back(cur); return; }
        for (int key : keys)
        {
            if (cnts[key] > 0)
            {
                cnts[key]--;
                cur.push_back(key);
                dfs(cnts, keys, n);
                cur.pop_back();
                cnts[key]++;
            }
        }
    }
public:
    vector<vector<int>> permuteUnique(vector<int> &nums)
    {
        res.clear(); cur.clear();
        unordered_map<int,int> cnts;
        for (int x : nums) cnts[x]++;
        vector<int> keys;
        for (auto &p : cnts) keys.push_back(p.first);
        dfs(cnts, keys, (int)nums.size());
        return res;
    }
};

int main()
{
    Solution sol;
    vector<int> n1 = {1, 1, 2};
    auto r1 = sol.permuteUnique(n1);
    for (auto &v : r1) { cout << "["; for (int i = 0; i < (int)v.size(); i++) { if (i) cout << ","; cout << v[i]; } cout << "] "; }
    cout << endl; // [1,1,2] [1,2,1] [2,1,1]
    vector<int> n2 = {1, 2, 3};
    auto r2 = sol.permuteUnique(n2);
    for (auto &v : r2) { cout << "["; for (int i = 0; i < (int)v.size(); i++) { if (i) cout << ","; cout << v[i]; } cout << "] "; }
    cout << endl; // 6 个排列
    return 0;
}
