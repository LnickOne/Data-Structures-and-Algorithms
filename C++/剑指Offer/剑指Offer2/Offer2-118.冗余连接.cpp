/* 题目难度: 中等
[原题链接](https://leetcode.cn/problems/7LpjUW/)
题目描述
n 个节点的树中添加一条多余边后给定 edges, 找出可以删去的那条边 (使剩余部分仍为树)。有多个答案则返回最后出现的那条。
题目样例
示例1
- 输入: edges=[[1,2],[1,3],[2,3]]
- 输出: [2,3]
示例2
- 输入: edges=[[1,2],[2,3],[3,4],[1,4],[1,5]]
- 输出: [1,4]
题目思考
1. 可以使用什么数据结构?
解决方案
思路
- 并查集: 逐边遍历, 若两节点已连通 (相同祖先) 则该边为冗余, 否则合并
复杂度
- 时间复杂度 O(N*logN): N 为边数, 并查集操作 O(logN)
- 空间复杂度 O(N): 并查集
 */
#include <iostream>
#include <vector>
using namespace std;

class Solution
{
    vector<int> pre;
    int find(int x)
    {
        if (pre[x] != x) pre[x] = find(pre[x]);
        return pre[x];
    }
    bool unite(int x, int y)
    {
        int px = find(x), py = find(y);
        if (px == py) return false;
        pre[px] = py;
        return true;
    }
public:
    vector<int> findRedundantConnection(vector<vector<int>> &edges)
    {
        int n = edges.size();
        pre.resize(n + 1);
        for (int i = 0; i <= n; ++i) pre[i] = i;
        for (auto &e : edges)
            if (!unite(e[0], e[1])) return e;
        return {};
    }
};

int main()
{
    Solution sol;
    vector<vector<int>> e1 = {{1,2},{1,3},{2,3}};
    auto r1 = sol.findRedundantConnection(e1);
    cout << "[" << r1[0] << "," << r1[1] << "]" << endl; // [2,3]
    vector<vector<int>> e2 = {{1,2},{2,3},{3,4},{1,4},{1,5}};
    auto r2 = sol.findRedundantConnection(e2);
    cout << "[" << r2[0] << "," << r2[1] << "]" << endl; // [1,4]
    return 0;
}
