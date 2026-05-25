/* 题目难度: 中等
[原题链接](https://leetcode.cn/problems/vEAB3K/)
题目描述
给定无向图 graph (邻接表), 判断是否为二分图 (能否将节点分成两个独立子集使每条边连接不同子集)。
题目样例
示例1
- 输入: graph=[[1,2,3],[0,2],[0,1,3],[0,2]]
- 输出: false
示例2
- 输入: graph=[[1,3],[0,2],[1,3],[0,2]]
- 输出: true ({0,2} 和 {1,3})
题目思考
1. 用什么方法判断节点所属集合?
解决方案
思路
- 染色法 BFS: color[node]=0/1 表示所属集合, 相邻节点染相反色
- 若相邻节点已染色且与当前颜色相同则非二分图
复杂度
- 时间复杂度 O(N): 每个节点染一次色
- 空间复杂度 O(N): color 数组
 */
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Solution
{
public:
    bool isBipartite(vector<vector<int>> &graph)
    {
        int n = graph.size();
        vector<int> color(n, -1);
        for (int start = 0; start < n; ++start)
        {
            if (color[start] != -1) continue;
            queue<int> q;
            q.push(start);
            color[start] = 0;
            while (!q.empty())
            {
                int cur = q.front(); q.pop();
                for (int nxt : graph[cur])
                {
                    if (color[nxt] == -1)
                    {
                        color[nxt] = 1 - color[cur];
                        q.push(nxt);
                    }
                    else if (color[nxt] == color[cur]) return false;
                }
            }
        }
        return true;
    }
};

int main()
{
    Solution sol;
    cout << boolalpha;
    vector<vector<int>> g1 = {{1,2,3},{0,2},{0,1,3},{0,2}};
    cout << sol.isBipartite(g1) << endl; // false
    vector<vector<int>> g2 = {{1,3},{0,2},{1,3},{0,2}};
    cout << sol.isBipartite(g2) << endl; // true
    return 0;
}
