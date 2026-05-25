/* 题目难度: 中等
[原题链接](https://leetcode.cn/problems/ur2n8P/)
题目描述
给定 [1,n] 的排列 nums 和子序列数组 sequences, 判断 nums 是否是所有 sequences 的唯一最短超序列。
题目样例
示例1
- 输入: nums=[1,2,3], sequences=[[1,2],[1,3]]
- 输出: false (有两个最短超序列 [1,2,3] 和 [1,3,2])
示例2
- 输入: nums=[1,2,3], sequences=[[1,2],[1,3],[2,3]]
- 输出: true
题目思考
1. 需要什么算法?
解决方案
思路
- 拓扑排序: 从 sequences 建立有向图 (用 set 避免重复边) 和入度表
- 每次只能有一个入度为 0 的节点且必须等于 nums[i], 否则返回 false
复杂度
- 时间复杂度 O(N+M): N 为 nums 长度, M 为 sequences 总长度
- 空间复杂度 O(N+M): 邻接表和入度表
 */
#include <iostream>
#include <vector>
#include <unordered_set>
#include <queue>
using namespace std;

class Solution
{
public:
    bool sequenceReconstruction(vector<int> &nums, vector<vector<int>> &sequences)
    {
        int n = nums.size();
        vector<unordered_set<int>> adj(n + 1);
        vector<int> indegree(n + 1, 0);
        for (auto &seq : sequences)
            for (int i = 1; i < (int)seq.size(); ++i)
            {
                int a = seq[i-1], b = seq[i];
                if (!adj[a].count(b)) { adj[a].insert(b); ++indegree[b]; }
            }
        queue<int> q;
        for (int i = 1; i <= n; ++i)
            if (indegree[i] == 0) q.push(i);
        int idx = 0;
        while (!q.empty())
        {
            if (q.size() > 1) return false;
            int cur = q.front(); q.pop();
            if (cur != nums[idx++]) return false;
            for (int nxt : adj[cur])
                if (--indegree[nxt] == 0) q.push(nxt);
        }
        return idx == n;
    }
};

int main()
{
    Solution sol;
    cout << boolalpha;
    vector<int> n1 = {1, 2, 3};
    vector<vector<int>> s1 = {{1,2},{1,3}};
    cout << sol.sequenceReconstruction(n1, s1) << endl; // false
    vector<vector<int>> s2 = {{1,2},{1,3},{2,3}};
    cout << sol.sequenceReconstruction(n1, s2) << endl; // true
    return 0;
}
