/* 题目难度: 中等
[原题链接](https://leetcode.cn/problems/QA2IGt/)
题目描述
共 numCourses 门课 (编号 0~numCourses-1), prerequisites[i]=[ai,bi] 表示先修 bi 才能学 ai, 返回可行修课序列。若不可能完成则返回空数组。
题目样例
示例1
- 输入: numCourses=2, prerequisites=[[1,0]]
- 输出: [0,1]
示例2
- 输入: numCourses=4, prerequisites=[[1,0],[2,0],[3,1],[3,2]]
- 输出: [0,1,2,3]
题目思考
1. 需要什么算法?
解决方案
思路
- 拓扑排序: 构建入度表和邻接表; 将入度为 0 的节点加入结果队列
- 每处理一个节点, 将其邻居入度减 1, 若为 0 则加入队列
- 最终结果长度 == numCourses 则有效, 否则返回空数组
复杂度
- 时间复杂度 O(M+N): M 为先修关系数, N 为课程数
- 空间复杂度 O(M+N): 邻接表和入度表
 */
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Solution
{
public:
    vector<int> findOrder(int numCourses, vector<vector<int>> &prerequisites)
    {
        vector<int> indegree(numCourses, 0);
        vector<vector<int>> adj(numCourses);
        for (auto &p : prerequisites)
        {
            ++indegree[p[0]];
            adj[p[1]].push_back(p[0]);
        }
        vector<int> res;
        queue<int> q;
        for (int i = 0; i < numCourses; ++i)
            if (indegree[i] == 0) q.push(i);
        while (!q.empty())
        {
            int cur = q.front(); q.pop();
            res.push_back(cur);
            for (int nxt : adj[cur])
                if (--indegree[nxt] == 0) q.push(nxt);
        }
        return (int)res.size() == numCourses ? res : vector<int>{};
    }
};

int main()
{
    Solution sol;
    vector<vector<int>> p1 = {{1, 0}};
    auto r1 = sol.findOrder(2, p1);
    for (int i = 0; i < (int)r1.size(); ++i) { if (i) cout << ","; cout << r1[i]; } cout << endl; // 0,1
    vector<vector<int>> p2 = {{1,0},{2,0},{3,1},{3,2}};
    auto r2 = sol.findOrder(4, p2);
    for (int i = 0; i < (int)r2.size(); ++i) { if (i) cout << ","; cout << r2[i]; } cout << endl; // 0,1,2,3 or 0,2,1,3
    return 0;
}
