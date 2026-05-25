/* 题目难度: 中等
[原题链接](https://leetcode.cn/problems/bP4bmD/)
题目描述
给定有 n 个节点的有向无环图 graph (邻接表), 找到所有从节点 0 到节点 n-1 的路径。
题目样例
示例1
- 输入: graph=[[1,2],[3],[3],[]]
- 输出: [[0,1,3],[0,2,3]]
示例2
- 输入: graph=[[4,3,1],[3,2,4],[3],[4],[]]
- 输出: [[0,4],[0,3,4],[0,1,3,4],[0,1,2,3,4],[0,1,4]]
题目思考
1. 如何利用有向无环图的特性?
解决方案
思路
- DFS 回溯: 从节点 0 开始, 沿每条边延伸, 到达 n-1 时记录路径
- 有向无环图无需 visited, 不会重复访问
复杂度
- 时间复杂度 O(N*2^N): 最多 2^N 条路径, 每条路径长 O(N)
- 空间复杂度 O(N): 递归栈
 */
#include <iostream>
#include <vector>
using namespace std;

class Solution
{
    vector<vector<int>> res;
    vector<int> path;
    void dfs(vector<vector<int>> &graph, int cur)
    {
        if (cur == (int)graph.size() - 1)
        {
            res.push_back(path);
            return;
        }
        for (int nxt : graph[cur])
        {
            path.push_back(nxt);
            dfs(graph, nxt);
            path.pop_back();
        }
    }

public:
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>> &graph)
    {
        res.clear();
        path = {0};
        dfs(graph, 0);
        return res;
    }
};

int main()
{
    Solution sol;
    vector<vector<int>> g1 = {{1, 2}, {3}, {3}, {}};
    auto r1 = sol.allPathsSourceTarget(g1);
    for (auto &v : r1)
    {
        cout << "[";
        for (int i = 0; i < (int)v.size(); ++i)
        {
            if (i)
                cout << ",";
            cout << v[i];
        }
        cout << "] ";
    }
    cout << endl; // [0,1,3] [0,2,3]
    vector<vector<int>> g2 = {{4, 3, 1}, {3, 2, 4}, {3}, {4}, {}};
    auto r2 = sol.allPathsSourceTarget(g2);
    for (auto &v : r2)
    {
        cout << "[";
        for (int i = 0; i < (int)v.size(); ++i)
        {
            if (i)
                cout << ",";
            cout << v[i];
        }
        cout << "] ";
    }
    cout << endl; // [0,4] [0,3,4] [0,1,3,4] [0,1,2,3,4] [0,1,4]
    return 0;
}
