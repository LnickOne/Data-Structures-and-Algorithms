/* 题目难度: 中等
[原题链接](https://leetcode.cn/problems/bLyHh0/)
题目描述
给定 n×n 的城市连通矩阵 isConnected, 求省份数量 (省份 = 直接或间接相连的城市组)。
题目样例
示例1
- 输入: isConnected=[[1,1,0],[1,1,0],[0,0,1]]
- 输出: 2
示例2
- 输入: isConnected=[[1,0,0],[0,1,0],[0,0,1]]
- 输出: 3
题目思考
1. 需要什么算法?
解决方案
思路
- BFS 求连通分量数: 遍历每个未访问城市, 从它开始 BFS 标记所有连通城市
- 每次找到新的未访问城市则省份数 +1
复杂度
- 时间复杂度 O(N^2): 每个节点遍历所有邻居
- 空间复杂度 O(N): visited 数组
 */
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Solution
{
public:
    int findCircleNum(vector<vector<int>> &isConnected)
    {
        int n = isConnected.size(), res = 0;
        vector<bool> visited(n, false);
        for (int i = 0; i < n; ++i)
        {
            if (!visited[i])
            {
                ++res;
                queue<int> q;
                q.push(i);
                visited[i] = true;
                while (!q.empty())
                {
                    int cur = q.front(); q.pop();
                    for (int j = 0; j < n; ++j)
                        if (isConnected[cur][j] && !visited[j])
                        {
                            visited[j] = true;
                            q.push(j);
                        }
                }
            }
        }
        return res;
    }
};

int main()
{
    Solution sol;
    vector<vector<int>> c1 = {{1,1,0},{1,1,0},{0,0,1}};
    cout << sol.findCircleNum(c1) << endl; // 2
    vector<vector<int>> c2 = {{1,0,0},{0,1,0},{0,0,1}};
    cout << sol.findCircleNum(c2) << endl; // 3
    return 0;
}
