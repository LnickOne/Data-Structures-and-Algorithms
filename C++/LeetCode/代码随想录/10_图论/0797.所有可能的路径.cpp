/*
给你一个有 n 个节点的 有向无环图（DAG），请你找出所有从节点 0 到节点 n-1 的路径并输出（不要求按特定顺序）
 graph[i] 是一个从节点 i 可以访问的所有节点的列表（即从节点 i 到节点 graph[i][j]存在一条有向边）。
示例 1：
输入：graph = [[1,2],[3],[3],[]]
输出：[[0,1,3],[0,2,3]]
解释：有两条路径 0 -> 1 -> 3 和 0 -> 2 -> 3
示例 2：
输入：graph = [[4,3,1],[3,2,4],[3],[4],[]]
输出：[[0,4],[0,3,4],[0,1,3,4],[0,1,2,3,4],[0,1,4]]
*/
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
class Solution
{
public:
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>> &graph)
    {
        vector<vector<int>> result;
        vector<int> path;
        path.push_back(0);
        int n = graph.size() - 1;
        dfs(0, n, graph, path, result);
        // for (auto &i : result)
        //     for (auto &j : i)
        //         cout << j << " ";
        return result;
    }
    void dfs(int x, int n, vector<vector<int>> &graph, vector<int> path, vector<vector<int>> &result)
    {
        // 当前遍历的节点x 到达节点n就找到符合条件的一条路径
        if (x == n)
        {
            result.push_back(path);
            return;
        }
        for (int y : graph[x])
        {
            path.push_back(y);
            dfs(y, n, graph, path, result);
            path.pop_back();
        }
        // for (int i = 0; i < graph[x].size(); i++)
        // {
        //     path.push_back(graph[x][i]);
        //     dfs(graph[x][i], n, graph, path, result);
        //     path.pop_back();
        // }
    }
};

int main()
{
    vector<vector<int>> graph = {{4, 3, 1}, {3, 2, 4}, {3}, {4}, {}};
    Solution().allPathsSourceTarget(graph);
    return 0;
}