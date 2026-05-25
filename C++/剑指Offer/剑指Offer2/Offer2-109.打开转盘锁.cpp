/* 题目难度: 中等
[原题链接](https://leetcode.cn/problems/zlDJc7/)
题目描述
4 位密码锁初始为 "0000", 每次只能拨动一位一格, 给定死亡数字列表 deadends, 求到达 target 的最小旋转次数。若无法到达返回 -1。
题目样例
示例1
- 输入: deadends=["0201","0101","0102","1212","2002"], target="0202"
- 输出: 6
示例2
- 输入: deadends=["8888"], target="0009"
- 输出: 1
示例3
- 输入: deadends=["0000"], target="8888"
- 输出: -1
题目思考
1. 如何处理 deadends?
解决方案
思路
- BFS 按层扩展: 将 deadends 全部加入 visited; 每次对密码每一位 +1/-1 (取模 10) 生成新密码
- 找到 target 时返回当前层数 cnt; 无法扩展则返回 -1
复杂度
- 时间复杂度 O(10^4*4): 最多 10000 个密码, 每个枚举 4 位*2 方向
- 空间复杂度 O(10^4): visited 集合
 */
#include <iostream>
#include <vector>
#include <string>
#include <unordered_set>
#include <queue>
using namespace std;

class Solution
{
public:
    int openLock(vector<string> &deadends, string target)
    {
        unordered_set<string> visited(deadends.begin(), deadends.end());
        string start = "0000";
        if (visited.count(start))
            return -1;
        if (start == target)
            return 0;
        queue<string> q;
        q.push(start);
        visited.insert(start);
        int cnt = 0;
        while (!q.empty())
        {
            int sz = q.size();
            ++cnt;
            for (int i = 0; i < sz; ++i)
            {
                string cur = q.front();
                q.pop();
                for (int j = 0; j < 4; ++j)
                {
                    int d = cur[j] - '0';
                    for (int delta : {1, -1})
                    {
                        string nxt = cur;
                        nxt[j] = '0' + (d + delta + 10) % 10;
                        if (!visited.count(nxt))
                        {
                            if (nxt == target)
                                return cnt;
                            visited.insert(nxt);
                            q.push(nxt);
                        }
                    }
                }
            }
        }
        return -1;
    }
};

int main()
{
    Solution sol;
    vector<string> d1 = {"0201", "0101", "0102", "1212", "2002"};
    cout << sol.openLock(d1, "0202") << endl; // 6
    vector<string> d2 = {"8888"};
    cout << sol.openLock(d2, "0009") << endl; // 1
    vector<string> d3 = {"0000"};
    cout << sol.openLock(d3, "8888") << endl; // -1
    return 0;
}
