/* 题目难度: 中等
[原题链接](https://leetcode.cn/problems/uUsW3B/)
题目描述
给定两个整数 n 和 k, 返回 1...n 中所有可能的 k 个数的组合。
题目样例
示例1
- 输入: n=4, k=2
- 输出: [[2,4],[3,4],[2,3],[1,2],[1,3],[1,4]]
示例2
- 输入: n=1, k=1
- 输出: [[1]]
题目思考
1. 如何剪枝?
解决方案
思路
- 回溯 DFS: 从数字 i 开始选取, 选取后递归到 i+1, 不选直接递归到 i+1
- 剪枝: 若当前已选数量 + 剩余数字数 < k 则无法构成有效组合, 直接返回
复杂度
- 时间复杂度 O(C(n,k)*k): 共 C(n,k) 个组合, 每个构建需要 O(k)
- 空间复杂度 O(k): 递归栈和当前组合
 */
#include <iostream>
#include <vector>
using namespace std;

class Solution
{
    vector<vector<int>> res;
    vector<int> cur;
    void dfs(int i, int n, int k)
    {
        if ((int)cur.size() == k) { res.push_back(cur); return; }
        if ((int)cur.size() + n - i + 1 < k) return;
        cur.push_back(i);
        dfs(i + 1, n, k);
        cur.pop_back();
        dfs(i + 1, n, k);
    }
public:
    vector<vector<int>> combine(int n, int k)
    {
        res.clear(); cur.clear();
        dfs(1, n, k);
        return res;
    }
};

int main()
{
    Solution sol;
    auto r1 = sol.combine(4, 2);
    for (auto &c : r1) { cout << "["; for (int x : c) cout << x << ","; cout << "] "; }
    cout << endl; // C(4,2)=6 个组合
    auto r2 = sol.combine(1, 1);
    for (auto &c : r2) { cout << "["; for (int x : c) cout << x << ","; cout << "] "; }
    cout << endl; // [1]
    return 0;
}
